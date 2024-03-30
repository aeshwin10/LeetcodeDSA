# Write your MySQL query statement below
SELECT employee_id, department_id
FROM Employee 
WHERE employee_id in(
    select employee_id from employee
    group by employee_id
    having count(primary_flag) = 1
) OR
primary_flag = 'Y'
