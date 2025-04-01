impl Solution {
    pub fn most_points(questions: Vec<Vec<i32>>) -> i64 {
        let n = questions.len();
        let mut dp = vec![0i64; n];

        dp[n-1] = questions[n-1][0] as i64;

        for i in (0..n-1).rev() {
            let look_after = i + questions[i][1] as usize + 1;
            if(look_after < n){
                dp[i] = dp[i+1].max(questions[i][0] as i64 + dp[look_after]);
            }
            else{
                dp[i] = dp[i+1].max(questions[i][0] as i64);
            }
        }

        dp[0]
    }
}