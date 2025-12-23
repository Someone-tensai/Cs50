SELECT name FROM people WHERE id in
(SELECT person_id FROM directors WHERE movie_id in
(SELECT id FROM movies JOIN ratings ON ratings.movie_id = movies.id WHERE rating>=9.0));
