-- https://datalemur.com/questions/non-profitable-drugs


with myloss as (

  SELECT 
  manufacturer, 
  drug,
  case when total_sales - cogs < 0 then abs(total_sales - cogs ) else 0 end as total_loss
  FROM 
  pharmacy_sales

) 


select 
manufacturer, count(drug) as drug_count,  sum(total_loss) as total_loss
from myloss
where total_loss > 0
group by manufacturer
order by count(drug) desc, sum(total_loss) desc



-- better


SELECT
  manufacturer,
  COUNT(drug) AS drug_count, 
  SUM(cogs - total_sales) AS total_loss
FROM pharmacy_sales
WHERE cogs > total_sales
GROUP BY manufacturer
ORDER BY total_loss DESC;
