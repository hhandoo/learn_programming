-- https://datalemur.com/questions/sql-well-paid-employees



SELECT 
e1.employee_id, e1.name
FROM 
employee as e1
inner JOIN
employee as e2
ON
e1.manager_id = e2.employee_id
where 
e2.manager_id is null and 
e1.salary > e2.salary;