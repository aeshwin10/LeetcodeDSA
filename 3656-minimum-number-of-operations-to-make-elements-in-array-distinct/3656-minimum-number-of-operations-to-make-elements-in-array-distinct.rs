use std::collections::HashMap;

impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        let mut mp = HashMap::new();
        let mut idx = -1;
        let n = nums.len();

        for i in (0..n).rev() {
            let count = mp.entry(nums[i]).or_insert(0);
//Learnings:
//1) entry(key) -> returns an enum Entry::Occupied(entry), Entry::Vacant(entry).
//if the key exists, returns &mut V (e.g., &mut i32), else insert the value(0 here) and returns a mutable reference to it.

//2) &mut i32 is like getting a mutable reference to that value. Only 1 mutable reference to a value can exist at any point of time. (RUST Gurantees Safety). It is like borrowing the value temporarily. 

//3)Analogy: I have the key(&mut i32) to a locker — I can open it and change(*count) what’s inside, but the locker(HashMap) isn’t mine.

            *count += 1;

            if *count > 1 {
                idx = i as i32;
                break;
            }
        }

        if idx == -1 {
            return 0;
        }
        (idx + 3) / 3
    }
}