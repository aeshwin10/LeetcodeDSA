impl Solution {
    pub fn find_words_containing(words: Vec<String>, x: char) -> Vec<i32> {
        let mut ans = Vec::new();
        
        for (i, word) in words.iter().enumerate() {
            if word.contains(x) {
                ans.push(i as i32);
            }
        }
        ans
    }
    //Learnings:
    //1) Enumerate is an iterator adapter. It wraps another iterator and yeilds (index, item) pairs.
    //2) std::iter::Enumerate<std::slice::Iter<'_, String>> - Return type of enumerate which is a nested generic type.
    //3 Iter<'a, T>  - T is a string and '_ is a lifetime. 
}