# Write your MySQL query statement below

# Write your MySQL query statement below

SELECT  MAX(SALARY) AS SecondHighestSalary FROM EMPLOYEE WHERE SALARY <>(SELECT MAX(SALARY) FROM EMPLOYEE);

#SELECT NULLIF(e2.salary, 0 ) as SecondHighestSalary FROM employee e1 JOIN employee e2
#ON e2.id - e1.id = 1
#ORDER BY e2.id limit 1;
