impl Solution {
    pub fn is_zero_array(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> bool {
        let n = nums.len();
        let m = queries.len();

        let mut arr = vec![0;n+2];

        for i in 0..m {
            arr[queries[i][0] as usize] += 1;
            arr[(queries[i][1] + 1) as usize] -= 1;

        }
        for i in 1..n {
            arr[i] += arr[i-1];
        }

        for i in 0..n {
            if (nums[i] - arr[i]) > 0 {
                return false;
            }
        }
        true
    }
}