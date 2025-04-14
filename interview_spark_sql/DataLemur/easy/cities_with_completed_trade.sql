-- https://datalemur.com/questions/completed-trades



SELECT 
u.city, count(*) as total_orders
FROM 
trades as t 
left JOIN
users as u
ON
t.user_id = u.user_id
where t.status = 'Completed'
group by  u.city
order by total_orders desc
limit 3;