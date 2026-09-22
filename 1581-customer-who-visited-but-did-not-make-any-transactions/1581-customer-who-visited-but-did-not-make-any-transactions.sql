select v.customer_id , count(*) as count_no_trans
from visits v
left join transactions t
ON v.visit_id = t.visit_id
where t.transaction_id is NULL
GROUP BY v.customer_id;