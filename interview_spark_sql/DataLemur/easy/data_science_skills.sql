-- http://datalemur.com/questions/matching-skills



select 
candidate_id
from candidates
WHERE skill IN ('Python', 'Tableau', 'PostgreSQL')
group by candidate_id
HAVING count(skill) = 3
order by candidate_id asc;
