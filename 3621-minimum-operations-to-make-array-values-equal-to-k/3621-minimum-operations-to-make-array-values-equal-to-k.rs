use std::collections::HashMap;

impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        let min_ele = *nums.iter().min().unwrap();
        if k > min_ele {
            return -1;
        }

        let mut mp = HashMap::new();
        for &num in &nums {
            if num > k {
                *mp.entry(num).or_insert(0) += 1;
            }
        }

        mp.len() as i32
    }
}