-- https://datalemur.com/questions/frequent-callers


select count (*) as policy_holder_count from (

  SELECT 
  
  policy_holder_id as policy_holder_count
  
  FROM 
  
  callers
  group by policy_holder_id
  having count(case_id) >= 3

) as tab1

