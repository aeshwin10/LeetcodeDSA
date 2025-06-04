impl Solution {
    pub fn answer_string(word: String, num_friends: i32) -> String {
        if num_friends == 1 {
            return word;
        }
        let n = word.len();
        let mut cur = String::new();
        let mut m = String::new();
        let split_length = n - num_friends as usize;
        for i in 0..n {
            let end = std::cmp::min(n, i + split_length + 1);
            cur = word[i..end].to_string();
            if cur > m {
                m = cur;
            }
        }
        m
    }
}