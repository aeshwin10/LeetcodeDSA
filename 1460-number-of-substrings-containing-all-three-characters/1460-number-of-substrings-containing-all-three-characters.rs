use std::collections::HashMap;

impl Solution {
    pub fn number_of_substrings(s: String) -> i32 {
        let n = s.len();
        let mut left = 0;
        let mut ans = 0;
        let mut mp: HashMap<char, i32> = HashMap::new();
        let s: Vec<char> = s.chars().collect(); //Convert `s` to Vec<char> for O(1) indexing

        for (right, ch) in s.iter().enumerate() { 
            //(right, ch) -> tuple, enumerate expects a tuple declaration.
            *mp.entry(*ch).or_insert(0) += 1; 
//entry(ch).or_insert(0) -> takes ch by ownership and returns a mutable reference to 
    //a) existing value of newly inserted value 
    //b)already present value if the key exists.

//Rust’s HashMap stores keys by ownership, and get() only borrows the key for lookup instead of taking ownership.

            while mp.len() >= 3 {
                ans += (n - right); //doubt, what will be the type of ans
                
                let left_char = s[left]; // ✅ Directly access s[left] in O(1)
//nth returns an Option<char> (which is slow, so we avoid using it)
    //a) returns Some(T), which holds a value or the char
    //b) None if string is out of bounds.. -> because, RUST should not panic.
//After getting the option, we are unwrapping the Some(T) in that Option<T>.

// Instead of using `nth(left)`, we use direct indexing `s[left]`, which is O(1).

                *mp.get_mut(&left_char).unwrap() -= 1;
//get_mut(&left_char) because we need to decrement the value, so, we are taking a mutable reference
//get(&key) takes a reference to the key and returns a reference to the value.

                if *mp.get(&left_char).unwrap() == 0 {
                    mp.remove(&left_char);
                } 
                left += 1; 
            }
        }
        ans as i32   //Convert the answer from usize to i32 and implicitly return it.
    }
}
