# Write your MySQL query statement below
SELECT e1.employee_id, e1.name, count(e2.employee_id) as reports_count, 
ROUND(avg(e2.age)) as average_age
FROM Employees e1 INNER JOIN Employees e2
ON e1.employee_id = e2.reports_to
GROUP BY employee_id
ORDER BY employee_id

