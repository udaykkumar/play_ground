# Write your MySQL query statement below
select stock_name,sum(price)-2*sum( if(operation="Buy",price,0)) as capital_gain_loss
from Stocks
group by stock_name