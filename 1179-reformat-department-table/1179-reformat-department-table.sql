# Write your MySQL query statement below
SELECT id,
    SUM(case when month = 'jan' then revenue else null end) as Jan_Revenue,
    SUM(case when month = 'feb' then revenue else null end) as Feb_Revenue,
    SUM(case when month = 'mar' then revenue else null end) as Mar_Revenue,
    SUM(case when month = 'apr' then revenue else null end) as Apr_Revenue,
    SUM(case when month = 'may' then revenue else null end) as May_Revenue,
    SUM(case when month = 'jun' then revenue else null end) as Jun_Revenue,
    SUM(case when month = 'jul' then revenue else null end) as Jul_Revenue,
    SUM(case when month = 'aug' then revenue else null end) as Aug_Revenue,
    SUM(case when month = 'sep' then revenue else null end) as Sep_Revenue,
    SUM(case when month = 'oct' then revenue else null end) as Oct_Revenue,
    SUM(case when month = 'nov' then revenue else null end) as Nov_Revenue,
    SUM(case when month = 'dec' then revenue else null end) as Dec_Revenue
FROM department
GROUP BY id
