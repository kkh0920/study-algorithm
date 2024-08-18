-- 코드를 작성해주세요

select c.ID, c.GENOTYPE, p.GENOTYPE as 'PARENT_GENOTYPE'
from ECOLI_DATA p, ECOLI_DATA c
where (c.PARENT_ID = p.ID) and (p.GENOTYPE & c.GENOTYPE = p.GENOTYPE)
order by c.ID