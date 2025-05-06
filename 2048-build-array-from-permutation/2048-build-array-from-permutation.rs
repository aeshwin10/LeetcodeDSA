impl Solution {
    pub fn build_array(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len() as i32;

        for i in 0..nums.len() {
            let original = nums[i];
            let new_val = nums[nums[i] as usize] % n;
            nums[i] = original + new_val * n;  //encoding both the values
        }

        for i in 0..nums.len() {
            nums[i] /= n;
        }
        nums
    }
}