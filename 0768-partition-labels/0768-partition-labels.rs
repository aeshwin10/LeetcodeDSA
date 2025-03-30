impl Solution {
    pub fn partition_labels(s: String) -> Vec<i32> {
        let n = s.len();
        let mut first_occ = vec![usize::MAX; 26]; //macro
        let mut last_occ = vec![0; 26];  //cannot have -1 has the value becuase, later we are comparing a usize to i32(-1 that we are not declaring here)

        for (i, c) in s.chars().enumerate() {
            let idx = (c as u8 - 'a' as u8) as usize;  
//Learning 1:
//u8 -> unsigned 8-bit. All ASCII fits in 8 bits(1byte). So converting a character to u8 gives its ASCII equivalent. (u8 is a subset of u32).  
            first_occ[idx] = first_occ[idx].min(i);
            last_occ[idx] = last_occ[idx].max(i);
        }

        let mut arr = Vec::new();
        for i in 0..26 {
            if first_occ[i] != usize::MAX{
                arr.push((first_occ[i], last_occ[i]));  //vector of tuples.
            }
        }

        arr.sort();  //Also takes the second element if there is a tie.
        let mut ans = Vec::new();
        let (mut glob_min, mut glob_max) = arr[0];

        for &(cur_min, cur_max) in arr.iter().skip(1) {
            if cur_min == glob_max + 1 {
                ans.push((glob_max - glob_min + 1) as i32);
                glob_min = cur_min;
                glob_max = cur_max;
            }
            else{
                glob_max = glob_max.max(cur_max);
            }
        }
        ans.push((glob_max - glob_min + 1) as i32);

        ans  //Implicit return
    }
}