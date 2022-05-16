SELECT songs.name FROM songs
JOIN artists ON songs.id = artists.id
WHERE artists.name = 'Post Malone';