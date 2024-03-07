# Write your MySQL query statement below
select b.unique_id as unique_id, a.name as name
FROM Employees a LEFT JOIN EmployeeUNI b
on a.id = b.id;

