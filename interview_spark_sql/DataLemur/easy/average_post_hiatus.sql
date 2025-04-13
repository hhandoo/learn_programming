-- https://datalemur.com/questions/sql-average-post-hiatus-1

select 

user_id,
    MAX(post_date::DATE) - MIN(post_date::DATE) AS days_between
from 
posts
WHERE DATE_PART('year', post_date::DATE) = 2021 

group by user_id
HAVING COUNT(post_id)>1;
