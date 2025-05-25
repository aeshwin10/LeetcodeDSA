use std::collections::HashMap;

impl Solution {
    pub fn longest_palindrome(words: Vec<String>) -> i32 {
        let mut mp: HashMap<String, i32> = HashMap::new();
        let mut ans = 0;
        let mut rev = false;

        // Count frequency of each word
        for word in &words {
            *mp.entry(word.clone()).or_insert(0) += 1;
            // cloning - allocates a new heap mem and copies the content - doing it because String does not have a Copy Trait
            // We also cannot do a ownership iteration because, then the strings in the Vec are invalidated
            // (moved to the iterator and consumed in iteration). So we cannot use it later.
            // We cannot use &String as the key for our mp because it would then run into a lifetime issue.
            // Lifetime issue for me is a black-box.
            // So, we clone &String which returns an owned String, which is then the key of our mp.
            // Clone can take both &String and String
            // We need to dereference it because the return type of both entry and insert is a reference to a value,
            // which is then incremented by 1.
        }

        for (word, &val) in mp.clone().iter() {
            if val == 0 {
                continue;
            }

            let rev_word: String = word.chars().rev().collect();

            if word == &rev_word {
                if val % 2 == 1 {
                    rev = true;
                    ans += (val - 1) * 2;
                } else {
                    ans += val * 2;
                }
                mp.insert(word.clone(), 0);
            } 
            else if let Some(&rev_val) = mp.get(&rev_word) { //Some(&rev_val) matches when the key exists (i.e., it's not None)
                let pairs = val.min(rev_val);
                ans += pairs * 4;
                mp.insert(word.clone(), 0);
                mp.insert(rev_word.clone(), 0);
            }
        }

        if rev {
            ans += 2;
        }

        ans
    }
}

// Learning:

// Various kinds of iterators:
// 1) for x in vec -> eleType: String, ownership: moved
// 2) for x in &vec -> eleType: &String, ownership: Immutable ref
// 3) for &x in &mut vec -> eleType: String, ownership: Mutable ref
// 4) for &x in &vec -> eleType: i32(Copy), ownership: Copied value. This is not possible with Strings.

// Copy trait:
// 1) Types with Copy trait are duplicated on assignment instead of moved.
// 2) Only simple, stack-only types like i32, bool, char, etc., can be Copy; heap-allocated types like String cannot.

//Options and Enums:
// 1) Option<T> is a type (an enum with variants).
// 2) Some(val) is one of the possible values of that type.
// 3) None is the other possible value.

//if let:
// 1) It is a special control flow construct in RUST.
// 2) It's not a regular assigment or regular conditional check.
// 3) It tries to match a pattern(Some) against an expression(get).
// 4) If the match succeeds, the block runs 