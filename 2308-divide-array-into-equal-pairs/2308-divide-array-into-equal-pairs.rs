use std::collections::HashMap;

impl Solution {
    pub fn divide_array(nums: Vec<i32>) -> bool {
        let k = nums.len() / 2;
        let mut mp = HashMap::new();

        for num in nums.iter(){
            *mp.entry(*num).or_insert(0)+=1;
        }
//mp.entry() -> Gives mutable reference to the value of the key(num) if it is present.
//.or_insert(0) -> If the key is not present, then it inserts value of 0 and gives back the mutable reference to the value.
//Then, we need to de-reference the returned value and increase the value by 1. 
        let mut c = 0;
        for &count in mp.values() {
//mp.values() - designed for read-only access -> returns immutable references (&i32)
// &count - pattern matching trick to dereference -> (&i32 -> i32), so that we can divide by 2.
            if count % 2 != 0 {
                return false;
            }
            c+= count / 2;
        }

        c == k     //implicit return.
    }
}