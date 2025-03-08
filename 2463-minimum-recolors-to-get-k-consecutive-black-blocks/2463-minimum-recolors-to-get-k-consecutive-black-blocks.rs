use std::cmp;
impl Solution {
    pub fn minimum_recolors(blocks: String, k: i32) -> i32 {
        let mut c_w = 0;
        let mut c_b = 0;
        let mut i = 0 as usize;
        let mut j = 0 as usize;
        let mut ans = i32::MAX;
        let n = blocks.len();
        let blocks = blocks.as_bytes();

        while i < n {
            if blocks[i]== b'W' {
                c_w+=1;
            }
            if blocks[i]== b'B' {
                c_b+=1;
            }
            while (i-j) as i32 > (k-1) {
                let temp = blocks[j];
                if temp == b'W' {
                    c_w-=1;
                }
                if temp == b'B' {
                    c_b-=1;
                }
                j+=1;
            }
            if (i-j) as i32 == k-1 {
                ans = cmp::min(ans, k-c_b);
            }
            i+=1;
        }
        return ans;
    }
}