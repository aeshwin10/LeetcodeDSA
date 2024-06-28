# Write your MySQL query statement below
SELECT T.employee_id
FROM 
(
SELECT t1.employee_id, name, salary FROM Employees t1 LEFT JOIN salaries t2
ON t1.employee_id = t2.employee_id
UNION
SELECT t2.employee_id,  name, salary FROM employees t1 RIGHT JOIN salaries t2
ON t1.employee_id = t2.employee_id
) AS T

WHERE T.name is null or T.salary is null
ORDER BY T.employee_id;
