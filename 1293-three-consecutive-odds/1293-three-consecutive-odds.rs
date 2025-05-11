impl Solution {
    pub fn three_consecutive_odds(arr: Vec<i32>) -> bool {
        let n = arr.len();
        let mut cnt = 0;
        for i in 0..n {
            if arr[i]%2==0 {
                cnt=0;
            }
            else{
                cnt+=1;
            }
            if cnt == 3 {
                return true;
            }
        }
        return false;
    }
}