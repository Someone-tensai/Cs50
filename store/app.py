from cs50 import SQL
from flask import Flask, render_template, redirect, request, session
from flask_session import Session

app =Flask(__name__)

db = SQL("sqlite:///store.db")

app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    books = db.execute("SELECT * FROM books")
    return render_template("books.html" , books=books)

@app.route("/cart", methods=["POST" , "GET"])
def cart():

    if "cart" not in session:
        session["cart"] = []
        print(session["cart"])
    print(session["cart"])
    if request.method == "POST":
        book_id = request.form.get("book_id")
        if book_id:
            session["cart"].append(book_id)

        return redirect("/cart")
    print(session["cart"])
    books = db.execute("SELECT * FROM books WHERE id IN (?)", session["cart"])
    return render_template("cart.html", books=books)

@app.route("/clear")
def clear():
    session.clear()
    return redirect("/")
