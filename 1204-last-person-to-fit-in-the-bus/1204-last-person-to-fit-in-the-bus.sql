# Write your MySQL query statement below
SELECT q1.person_name 
FROM Queue q1 JOIN Queue q2 ON q1.turn>=q2.turn
GROUP BY q1.person_id
HAVING sum(q2.weight) <= 1000
ORDER BY sum(q2.weight) desc
limit 1

#Notes is Doc. OVER() solution is also there.