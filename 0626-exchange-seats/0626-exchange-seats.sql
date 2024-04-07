# Write your MySQL query statement below
select  
      case 
        when id % 2 = 0 then id - 1
        when id % 2 = 1 and id < (select count(*) from seat)then id + 1
        else id
      end as id, 
    student from seat
    order by id; #Note that, here basically swapping places is done by 2 steps.
    #1. First using case when
    #2. Using the order by - Order by swaps the names essentially.
	