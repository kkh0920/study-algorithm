-- 코드를 작성해주세요
select case when convert(substring(DIFFERENTIATION_DATE, 6, 2), UNSIGNED) <= 3 then '1Q'
                when convert(substring(DIFFERENTIATION_DATE, 6, 2), UNSIGNED) <= 6 then '2Q'
                when convert(substring(DIFFERENTIATION_DATE, 6, 2), UNSIGNED) <= 9 then '3Q'
                else '4Q' end as QUARTER,
        count(*) as ECOLI_COUNT
from ECOLI_DATA
group by QUARTER
order by QUARTER
