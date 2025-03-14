impl Solution {
    pub fn maximum_candies(candies: Vec<i32>, k: i64) -> i32 {
        let summ: i64 = candies.iter().map(|x| (*x) as i64).sum();
// iter() -> function to iterate over the values of candies. Gives a reference.
// map() here -> closure function takes in each of the reference from iter(), then dereferences it then converts it to i64.
//sum() -> adds to the current sum. Starts from 0.
        if summ < k {
            return 0;
        }

        let mut low: i64 = 1;
        let mut high: i64 = *candies.iter().max().unwrap() as i64;
//Max Element returns an Option<&i32> since, the vector might be none.
//So, we use unwrap() to extract the value.
//Then we convert it into i64 as high here wants an i64, but unwrap retuns an i32.
        let mut ans: i64 = 1;

        while low <= high {
            let mid = (low+high)/2;
            if Self::check(mid, &candies, k){
//Why do we need Self?
// 1) What - Self refers to current impl Solution block. ~ Solution::check(...);
// 2) Why - Methods inside impl (Solution here) requires Self::fun() -> that's how RUST is written.
//        - If we don't write Self::, rust expects the fucntion to be outside of current impl, which 
//          in our case is not present and will lead to an error. So, write Self::fun() if it is in the current block         
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        ans as i32     //conversion from i64 to i32 and implicit return.
    }

    fn check(mid: i64, candies: &Vec<i32>, k: i64) -> bool {
        let mut piles: i64 = 0;
        for &c in candies.iter() {
            piles+= (c as i64)/mid;     //We cannot divide a i32 by i64. So conversion here.
        }
        piles >= k       //implicit return 
    }
}