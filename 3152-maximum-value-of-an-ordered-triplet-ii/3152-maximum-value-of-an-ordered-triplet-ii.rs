impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        let mut val = nums[0];
        let mut ans = (val as i64 - nums[1] as i64) * nums[n-1] as i64;

        let mut suffix_max = vec!(0; n);
        suffix_max[n-1] = nums[n-1];
        for i in (0..n-1).rev() {
            suffix_max[i] = suffix_max[i+1].max(nums[i]);
        }

        for i in (1..n-1){
            let cur_diff = val - nums[i];
            val = val.max(nums[i]);
            let mut temp = cur_diff as i64 * suffix_max[i+1] as i64;
            ans = ans.max(temp);
        }
        ans.max(0) as i64
    }
}