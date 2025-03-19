impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut ans = 0;
        let mut nums1 = nums.clone();

        for right in 0.. (n-2) {
            if nums1[right] == 0 {
//Declaring something as mut allows modification without taking ownership.
//Acessing an element using usize still gives us a &i32(reference) only.
//But, Rust's "Deref Coercion" automatically applies '*' (de-reference) where necessary for assignments and operations.
//Since we explicitly declared the value as mut, Rust knows we intend to modify it.
//Also, assignment & arithmetic & also comparision triggers auto-dereferencing.
                nums1[right] = 1;
                nums1[right + 1] ^= 1;
                nums1[right + 2] ^= 1;
                ans+=1;
            }
        }

        if (nums1[n-1]==0) || (nums1[n-2]==0) {
            return -1;
        }
        ans
    }
}