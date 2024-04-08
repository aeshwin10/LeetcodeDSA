# Write your MySQL query statement below
(SELECT name AS results
FROM MovieRating JOIN Users USING(user_id)
GROUP BY name
ORDER BY COUNT(*) DESC, name
LIMIT 1)

UNION ALL
(
SELECT title  AS results
FROM MovieRating JOIN Movies USING(movie_id)
WHERE created_at > '2020-01-31' and created_at < '2020-03-01'
GROUP BY title
ORDER BY avg(rating) DESC, title limit 1
)