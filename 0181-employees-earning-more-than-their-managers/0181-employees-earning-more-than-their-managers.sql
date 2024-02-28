# Write your MySQL query statement below
select e2.name as Employee from employee e1 Inner Join employee e2 ON e1.id = e2.managerID
WHERE
e1.salary < e2.salary