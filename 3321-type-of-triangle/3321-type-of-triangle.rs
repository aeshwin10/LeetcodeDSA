impl Solution {
    pub fn triangle_type(nums: Vec<i32>) -> String {
        if nums[0] + nums[1] <= nums[2] || nums[0] + nums[2] <= nums[1] || nums[2] + nums[1] <= nums[0]{
            return "none".to_string();
        }
        else if nums[0] == nums[1] && nums[1] == nums[2] {
            return "equilateral".to_string();
        }
        else if nums[0] == nums[1] || nums[1] == nums[2] || nums[2] == nums[0] {
            return "isosceles".to_string();
        }
        return "scalene".to_string();
    }
//Learnings:
//1) " " -> always &'static str, so to convert it back to String, we use .to_string()
}