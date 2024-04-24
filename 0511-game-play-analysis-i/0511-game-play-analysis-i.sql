# Write your MySQL query statement below
SELECT player_id, event_date AS first_login
FROM Activity WHERE (player_id, event_date) IN(
    select player_id, min(event_date)
    from Activity 
    group by player_id
)
group by player_id