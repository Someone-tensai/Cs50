-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Trying to find more about what happened around the crime time and place.
SELECT description
FROM crime_scene_reports WHERE
year=2023 AND month='July' AND street='Humphrey Street';

--Seeing the interview transcripts for more clues on the thief and its actions.
SELECT transcript FROM interviews
WHERE year=2023 AND month=7
AND day=28;

--From the transcript seeing that the thief took the car from the bakery around the time of theft, querying for people who had their cars parked at around 10.
SELECT name FROM people
WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs
WHERE year=2023 AND month=7
AND day=28 AND hour=10 AND activity='exit' AND minute <=25 AND minute >=15);

-- Checking who used the ATM that morning to narrow down the suspects.
SELECT name FROM people WHERE id IN
(SELECT person_id FROM bank_accounts JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE year=2023 AND month=7 AND day=28 AND atm_location='Leggett Street' AND transaction_type='withdraw');

--To find the earliest flight
SELECT * FROM flights WHERE origin_airport_id =
(SELECT id FROM airports WHERE city='Fiftyville' ) AND
year=2023 AND month=7 AND day=29;


--Narrowing down the suspects with people in the earliest flight next morning.
SELECT name FROM people WHERE passport_number IN
(SELECT passport_number FROM passengers WHERE flight_id IN
(SELECT id FROM flights WHERE year=2023
AND month=7 AND day=29 AND hour =8 AND minute=20 AND origin_airport_id IN
(SELECT id FROM airports WHERE city='Fiftyville' )));

--Finding the list of callers
SELECT name FROM people WHERE phone_number IN
(SELECT caller FROM phone_calls
WHERE year = 2023 AND month = 7 AND day = 28
AND duration <= 60);

--Thief has been found. Bruce is the thief. Now to see who he called

--Figuring out Bruce's number
SELECT phone_number FROM people WHERE name='Bruce';

--Seeing who received the call at the time of theft.
SELECT name FROM people WHERE phone_number IN
(SELECT receiver FROM phone_calls WHERE caller='(367) 555-5533' AND year=2023 AND month=7 AND day=28 AND duration<=60)

--Robin is the Accomplice

--finding the city Bruce went to
SELECT destination_airport_id FROM flights WHERE year=2023 AND month=7 AND day=29 AND hour=8 AND minute=20 AND origin_airport_id =
(SELECT id FROM airports WHERE city='Fiftyville');

SELECT city FROM airports WHERE id=4;
--Destination is New York City
