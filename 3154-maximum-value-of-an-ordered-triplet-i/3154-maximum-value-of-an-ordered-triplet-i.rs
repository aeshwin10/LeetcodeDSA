impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let n = nums.len() as usize;
        let mut val1 = nums[0];
        let mut max_diff = val1 - nums[1];

        let mut ans = max_diff as i64 * nums[n-1] as i64; 

        let mut max_suffix = vec![0; n];
        max_suffix[n-1] = nums[n-1];
        for i in (0..n-1).rev() {
            max_suffix[i] = max_suffix[i+1].max(nums[i]);
        }

        for i in 1..n-1 {
            max_diff = max_diff.max(val1 - nums[i]);
            val1 = val1.max(nums[i]);
            ans = ans.max(max_diff as i64 * max_suffix[i+1] as i64);
        }

        ans.max(0)
    }
}