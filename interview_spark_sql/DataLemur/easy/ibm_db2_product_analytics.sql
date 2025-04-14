with groupby1 as (

  select 
  e.employee_id, 
  COALESCE(COUNT(DISTINCT q.query_id), 0) AS unique_queries
  FROM
  employees as e 
  left JOIN
  queries as q
  ON
  e.employee_id = q.employee_id
  AND  q.query_starttime >= '2023-07-01T00:00:00Z'
  AND  q.query_starttime < '2023-10-01T00:00:00Z'
  group by e.employee_id

)

select 
unique_queries,
count(employee_id) as employee_count
FROM
groupby1
group by unique_queries
order by unique_queries asc
