impl Solution {  //declation of a implementation.
    pub fn apply_operations(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut ans = Vec::new();  //mut - mutable. Default it is immutable.
        let mut count = 0;
        let mut i = 0;
        let mut lastChangedToZero = false;

        while i<n-1 {
            if nums[i] == 0 {
                count+=1;
                i+=1;
            }
            else if nums[i] == nums[i+1] {
                if i == n-2 {
                    lastChangedToZero = true;
                }
                ans.push(nums[i]*2);
                count+=1;
                i+=2;
            }
            else{
                ans.push(nums[i]);
                i+=1;
            }
        }
        if !lastChangedToZero {
            ans.push(nums[n-1]);
        }

        for _ in 0..count {
            ans.push(0);
        }
        return ans;
    }
}