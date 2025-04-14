-- https://datalemur.com/questions/duplicate-job-listings

select count (*) from (

SELECT
company_id, title, description, count(*)
from job_listings
group by company_id, title, description
having count(*) > 1

) as tab1;