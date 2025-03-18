use std::cmp::max;


impl Solution {
    pub fn longest_nice_subarray(nums: Vec<i32>) -> i32 {
        let n = nums.len();  //usize
        let mut ans = 1;

        let mut left = 0;
        let mut temp_or = nums[0];
//Here, temp_or does not take ownership over nums[0], becuase...
//nums[0] is i32, which is a primitive. This allows copying. Not necessarily ownership.

        for right in 1..n {                      //right is also usize.
            while (temp_or & nums[right]) != 0 {
                temp_or -= nums[left];
                left += 1;
            }
            temp_or = (temp_or | nums[right]);
            ans = max(ans, (right - left + 1) as i32);
        }
        ans    //Implicit return
    }
}