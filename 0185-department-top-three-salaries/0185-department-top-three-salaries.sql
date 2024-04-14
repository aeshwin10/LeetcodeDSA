# Write your MySQL query statement below

SELECT d.name as Department, e.name as Employee, e.salary as Salary 
FROM Employee e join Department d on e.departmentID = d.id
where 3>(select count(distinct(e2.salary))
    from Employee e2 where e2.salary > e.salary  #This runs for each record in the joined table. 
    and e2.DepartmentId = e.departmentId)

#Note that, here we have used subquery without having a in operator.
#We always no need to use subquery on columns which have a particular values.