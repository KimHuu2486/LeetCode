# Write your MySQL query statement below
with temp as (
    select customer_id,
            case 
                when order_date = customer_pref_delivery_date then "i"
                else "s"
            end as status
    from Delivery
    where (customer_id, order_date) in (
        select customer_id, min(order_date)
        from Delivery
        group by customer_id
    )
)
SELECT 
    ROUND(
        SUM(CASE WHEN status = 'i' THEN 1 ELSE 0 END) * 100 / COUNT(*), 
        2
    ) AS immediate_percentage
FROM temp;