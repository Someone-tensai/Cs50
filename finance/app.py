import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    if request.method == "POST":
        return redirect("/")

    user_id = session['user_id']
    user = db.execute("SELECT * from users WHERE id = ? ", user_id)
    user_cash = user[0]['cash']
    stocks = db.execute(
        "SELECT stock_symbol ,SUM(CASE WHEN transaction_type = 'buy' THEN quantity ELSE -quantity END) AS shares FROM stock_transactions WHERE user_id = ? GROUP BY stock_symbol", user_id)
    final_stocks = []

    if stocks is None:
        return apology("No Stocks Owned")

    total_value = int(user_cash)

    for stock in stocks:
        shares = stock['shares']
        info = (lookup(stock['stock_symbol']))
        price = info['price']
        name = info['name']
        value = shares*price
        total_value += value
        final_stocks.append({
            'name': name,
            'shares': shares,
            'price': usd(price),
            'value': usd(value),
            'user_bal': usd(user_cash),
            'symbol': stock['stock_symbol']
        })
    print(final_stocks)
    return render_template("portfolio.html", stocks=final_stocks, total=usd(total_value))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy_form.html")

    if request.method == "POST":

        sym_port = request.form.get("sym_port")
        if sym_port:
            return render_template("buy_form.html", symbol=sym_port)

        stock_symbol = request.form.get("symbol")
        number_of_shares_to_buy = request.form.get("shares")

        if not stock_symbol or not number_of_shares_to_buy:
            return apology("Stock Symbol or Shares not provided")

        stock = lookup(stock_symbol)
        if stock is None:
            return apology("Invalid Symbol")
        try:
            if int(number_of_shares_to_buy) <= 0:
                return apology("Invalid Number of Shares")
        except ValueError:
            return apology("Invalid Share type")
        user = db.execute("SELECT cash FROM users WHERE id = ? ", session['user_id'])
        price_shares = stock['price'] * int(number_of_shares_to_buy)
        cash_user = user[0]["cash"]
        if cash_user < price_shares:
            return apology("Not Enough Money")

        db.execute("INSERT INTO stock_transactions (user_id, stock_symbol, quantity, transaction_type, price_per_share) VALUES(?,?,?,?,?)",
                   session['user_id'], stock_symbol, number_of_shares_to_buy, "buy", usd(stock['price']))
        cash_user = cash_user - price_shares
        db.execute("UPDATE users SET cash = ? WHERE id = ? ", cash_user, session['user_id'])
        flash("Bought!")
        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    if request.method == "POST":
        return redirect("/history")

    user_id = session['user_id']
    history = db.execute("SELECT * FROM stock_transactions WHERE user_id = ? ", user_id)

    return render_template("history.html", transactions=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")

    elif request.method == "POST":
        stock_symbol = request.form.get("symbol")
        if not stock_symbol:
            return apology("No Symbol Provided")

        stock = lookup(stock_symbol)

        if stock is None:
            return apology("Invalid Symbol")

        stock['price'] = usd(stock['price'])
        return render_template("quoted.html", stock=stock)

    return apology("TODO")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("register.html")
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirm_password = request.form.get("confirmation")

        if not username or not password:
            return apology("Username or Password not Provided")

        if password != confirm_password:
            return apology("Different password and confirmation")
        try:
            db.execute("INSERT INTO users (username, hash) VALUES(?,?)",
                       username, generate_password_hash(password))
        except ValueError:
            return apology("Username Already Registered")
    return redirect("/")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    user_id = session['user_id']
    if request.method == "GET":

        stocks = db.execute(
            "SELECT stock_symbol, SUM(CASE WHEN transaction_type = 'buy' THEN quantity ELSE -quantity END) AS shares FROM stock_transactions WHERE user_id = ? GROUP BY stock_symbol HAVING shares > 0", user_id)
        return render_template("sell.html", stocks=stocks)

    if request.method == "POST":

        sym_port = request.form.get("sym_port")
        if sym_port:
            return render_template("sell.html", symbol=sym_port)

        stock_symbol = request.form.get("symbol")
        shares_sell = request.form.get("shares")

        if not stock_symbol or not shares_sell:
            return apology("Stock Symbol or Shares not provided")

        stock_info = lookup(stock_symbol)
        price_shares = stock_info['price']
        if stock_info is None:
            return apology("Invalid Symbol")

        if int(shares_sell) <= 0:
            return apology("Invalid Number of Shares")

        stock = db.execute(
            "SELECT SUM(CASE WHEN transaction_type = 'buy' THEN quantity ELSE -quantity END) AS shares FROM stock_transactions WHERE user_id = ? AND stock_symbol = ?", user_id, stock_symbol)

        if int(shares_sell) > int(stock[0]['shares']):
            return apology("More Shares Than User has")

        user = db.execute("SELECT cash FROM users WHERE id = ? ", session['user_id'])
        cash_user = user[0]['cash']
        db.execute("INSERT INTO stock_transactions (user_id, stock_symbol, quantity, transaction_type, price_per_share) VALUES(?,?,?,?,?)",
                   session['user_id'], stock_symbol, shares_sell, "sell", usd(price_shares))
        cash_user = cash_user + int(price_shares) * int(shares_sell)
        db.execute("UPDATE users SET cash = ? WHERE id = ? ", cash_user, session['user_id'])
        flash("Sold!")
        return redirect("/")

    return apology("TODO")
