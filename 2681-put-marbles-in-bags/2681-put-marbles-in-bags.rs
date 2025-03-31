impl Solution {
    pub fn put_marbles(weights: Vec<i32>, k: i32) -> i64 {
        let n = weights.len();
        if k==1 || k==n as i32 {  
//Presedence of as is higher than ==, so 'as i32' will be evalucated first.
            return 0;
        }

        let mut poss_weight = Vec::new();
        for i in 0..n-1 {
            poss_weight.push(weights[i] as i64 + weights[i+1] as i64) 
//weights[i+1] automatically promoted to i64 (evaluation from left to right).
        }

        poss_weight.sort();

        let mut min_poss = 0;
        let mut max_poss = 0; 
        let m = poss_weight.len();

        for i in 0..(k as usize -1) {  //i will take the type of k.
            min_poss += poss_weight[i] ;
            max_poss += poss_weight[m-1-i] ;
        }

        max_poss - min_poss
    }
}