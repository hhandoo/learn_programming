
-- Write an SQL query to report the second highest salary from 
-- the Employee table. If there is no second highest salary, the query should report null.

-- The query result format is in the following example

select max(salary) as 'SecondHighestSalary' from Employee where salary < (select max(salary) from Employee);