select distinct D.ID, D.EMAIL, D.FIRST_NAME, D.LAST_NAME
from DEVELOPERS D 
join (select S.CODE
from SKILLCODES S
where S.NAME IN ('Python', 'C#')) S
where D.SKILL_CODE & S.CODE = S.CODE
order by D.ID
