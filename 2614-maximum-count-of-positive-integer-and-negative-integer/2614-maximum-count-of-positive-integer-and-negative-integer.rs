use std::cmp;

impl Solution {
    pub fn maximum_count(nums: Vec<i32>) -> i32 {
        let negative = nums.partition_point(|&num| num<0);
        let positives = nums.len() - nums.partition_point(|&num| num<=0);
//partition_point(|&x| condition) -> performs a binary serach and returns the first index where the condition is false.
// 1) Returns an usize
// 2) |&x| -> closure function(like lambda in C++) that takes a reference to a value. 
// 3) Partition function does not take ownership, (that's how they have written code for it)
// 

        cmp::max(negative, positives) as i32 //Conversion back to i32 from usize.

    }
}