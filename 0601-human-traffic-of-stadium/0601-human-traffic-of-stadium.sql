# Write your MySQL query statement below
SELECT id, visit_date, people
FROM(
    SELECT ID, visit_date, people,
    LEAD(people, 1) OVER() nxt,
    LEAD(people, 2) OVER() nxt2,
    LAG(people, 1) OVER() prev,
    LAG(people, 2) OVER() prev2  #Lag is necessary for last two rows.
    FROM Stadium
) cte
WHERE 
    (cte.people>=100 and cte.nxt >= 100 and cte.nxt2>=100) or
    (cte.people>=100 and cte.prev >=100 and cte.prev2 >=100) or
    (cte.people >=100 and cte.prev>=100 and cte.nxt >=100)
 #Last two where conditions are required for the last and second last rows.
