select a.ID, a.GENOTYPE, (
        select b.GENOTYPE as p 
        from ECOLI_DATA b
        where a.PARENT_ID = b.ID
    ) as PARENT_GENOTYPE
from ECOLI_DATA a
where a.PARENT_ID is NOT NULL and a.GENOTYPE & 
    (
        select b.GENOTYPE as p 
        from ECOLI_DATA b
        where a.PARENT_ID = b.ID
    ) = (
        select b.GENOTYPE as p 
        from ECOLI_DATA b
        where a.PARENT_ID = b.ID
    )