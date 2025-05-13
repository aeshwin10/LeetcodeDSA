impl Solution {
    pub fn length_after_transformations(s: String, t: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let mut cnt = vec![0i64;26];

        for c in s.chars() {
            cnt[(c as u8 - b'a') as usize]+=1;
        }

        for _ in 0..t {
            let mut tmp = vec![0i64; 26];
            for j in 0..26 {
                if j==25 {
                    tmp[0] = (tmp[0] + cnt[j]) % MOD;
                    tmp[1] = (tmp[1] + cnt[j]) % MOD;
                }
                else {
                    tmp[j+1] = (cnt[j] + tmp[j+1]) % MOD;
                }
            }
            cnt = tmp;
        }
        let mut ans = 0i64;
        for &val in &cnt {
            ans = (ans + val) % MOD;
        }
        ans as i32
    }
}