-- https://datalemur.com/questions/sql-histogram-tweets


with mycte as (
  SELECT 
  *,
  extract(year from DATE(tweet_date)) as tweet_year
  FROM tweets
),
mycte2 as (
  SELECT 
  tweet_year,user_id, count(user_id	) as tweet_count_per_user
  from 
  mycte
  where tweet_year = 2022
  group by tweet_year, user_id	
  order by user_id asc
)
SELECT 
  tweet_count_per_user AS tweet_bucket, 
  COUNT(user_id) AS users_num 
FROM mycte2 
GROUP BY tweet_count_per_user;
