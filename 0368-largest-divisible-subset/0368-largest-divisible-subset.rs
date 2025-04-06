impl Solution {
    pub fn largest_divisible_subset(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        if(n==1){
            return nums;
        }
        let mut nums1 = nums; //moves ownership from nums to nums1, does not make a new copy.
        //no new memory is allocated. Internally both nums and nums1 point to the same heap allocation - but only nums1 is allowed to use it becuase nums is moved and becomes invalid.
        nums1.sort();         //becuase, the original nums was not mutable, and sorting requires a mutable vec

        let mut dp = vec![1; n];
        let mut prev = vec![-1; n];
        let mut max_idx = 0;    //RUST uses type inference, its type is inferred based on how it is used next.

        for i in 1..n {
            for j in 0..i {
                if nums1[i] % nums1[j] == 0 && dp[j] + 1 > dp[i] {
                    dp[i] = dp[j] + 1;
                    prev[i] = j as i32;
                }
            }
            if dp[i] > dp[max_idx] {
                max_idx = i;        //here, max_idx is inferred as usize.
            }
        }

        let mut ans = Vec::new();
        let mut idx = max_idx as i32;
        while idx != -1 {
            ans.push(nums1[idx as usize]);
            idx = prev[idx as usize];
        }

        ans   //implicit return
    }
}