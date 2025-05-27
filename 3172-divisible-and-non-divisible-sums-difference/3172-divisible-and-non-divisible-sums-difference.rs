impl Solution {
    pub fn difference_of_sums(n: i32, m: i32) -> i32 {
        let total_sum: i64 = n as i64*(n as i64 + 1)/2;
        let mut sum2: i64 = 0 as i64;
        for i in 1..=((n/m)) {      //Here, i is automatically inferred as i32 because of m and n
            sum2 += (i*m) as i64;
        }

        let sum1: i64 = total_sum - sum2;
        (sum1 - sum2) as i32
    }
}