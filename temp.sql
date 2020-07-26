select c.name
from customers c, 
invoice i
where c.ID = i.CUSTOMER_ID
and
i.VALUE = (select max(value) from invoice)


select * from students
case
when marks > 90 then "A+" 
when marks > 70 then "A"
when marks > 50 then "B"
when marks > 40 then "C"
else "Fail"
end
as grade

