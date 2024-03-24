# Write your MySQL query statement below
select ROUND(count(distinct player_id)/
(select  count(distinct player_id) from Activity),2) AS fraction
FROM 
    Activity 
WHERE
    (player_id, DATE_SUB(event_date, INTERVAL 1 DAY)) IN(
        SELECT player_id, min(event_date) FROM Activity
        GROUP BY player_id
    );
    
#The date_sub function takes two arguement. The date column
#and subtracts the current day by 1 day. -> INTERVAL 1 DAY.

#We cannot use datediff function directly becuase, it will not only
#count the initial login and its consecutive, but also next ith 
#consecutive days.