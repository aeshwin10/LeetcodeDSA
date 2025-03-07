impl Solution {
    pub fn closest_primes(left: i32, right: i32) -> Vec<i32> {
        //Note to use snake_case as recommended by the style guide of RUST
        let right = right as usize;
        let left = left as usize;
        let mut is_prime = vec![true; right+1];  //macro to create a vec with a particular size and particular value.
        let mut primes = Vec::new();

        for i in 2..=right {  //= is used for inclusive range.
            if is_prime[i] {
                if i >=left {
                    primes.push(i as i32);
                }
                let mut j = (i as u64)* (i as u64);  //to handle overflow
                while j as usize <= right {  //convert back to usize for indexing
                    is_prime[j as usize] = false;
                    j+=(i as u64);
                }
            }
        }

        if primes.len() <=1 {
            return vec![-1, -1];
        }

        let mut diff = primes[1] - primes[0];
        let mut idx1 = 0;
        let mut idx2 = 1;

        for i in 2..primes.len(){
            let curr_diff = primes[i] - primes[i-1];
            if curr_diff < diff{
                diff = curr_diff;
                idx1 = i-1;
                idx2 = i;
            }
        }

        vec![primes[idx1], primes[idx2]]
    }
}