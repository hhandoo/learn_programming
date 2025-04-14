-- https://datalemur.com/questions/alibaba-compressed-mean


SELECT 


round (
(
  sum(cast(item_count as decimal) * cast(order_occurrences as decimal)) 
  /
  sum(cast(order_occurrences as decimal)) 
),

1)

as mean



FROM items_per_order;