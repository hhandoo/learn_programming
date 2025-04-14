-- https://datalemur.com/questions/total-drugs-sales



SELECT 
manufacturer,
concat('$',round(sum(total_sales) / 1000000, 0), ' million') as sale
FROM pharmacy_sales
group by manufacturer
order by sum(total_sales) desc, manufacturer asc



