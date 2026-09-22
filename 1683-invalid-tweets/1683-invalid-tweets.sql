# Write your MySQL query statement below
select distinct tweet_id from tweets
where length(content) > 15
