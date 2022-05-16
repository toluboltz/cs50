SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE people.name = 'Johnny Depp' OR people.name = 'Helena Bonham Carter'
ORDER BY title;