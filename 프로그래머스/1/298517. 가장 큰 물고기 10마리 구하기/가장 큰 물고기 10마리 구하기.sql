select ID, LENGTH
from FISH_INFO
where LENGTH is NOT NULL
order by LENGTH desc, ID
LIMIT 10