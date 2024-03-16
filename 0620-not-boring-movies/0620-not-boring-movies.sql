# Write your MySQL query statement below
select c1.id, c1.movie, c1.description, c1.rating
FROM cinema c1
where  (((c1.id-1)%2)=0) and 
c1.description != 'boring'  
ORDER BY c1.rating desc;