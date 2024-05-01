# Write your MySQL query statement below
SELECT d.name Department, e.name Employee, Salary
FROM Employee e INNER JOIN Department d
ON e.departmentId = d.id
WHERE (salary,departmentId) IN(
    select max(salary), departmentId
    from Employee
    group by departmentId
)

