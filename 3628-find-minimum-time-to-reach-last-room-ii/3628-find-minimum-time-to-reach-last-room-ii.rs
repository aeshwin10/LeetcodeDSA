use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    pub fn min_time_to_reach(move_time: Vec<Vec<i32>>) -> i32 {
        let n = move_time.len();
        let m = move_time[0].len();
        let mut dp = vec![vec![i32::MAX; m]; n];

        let mut pq = BinaryHeap::new(); //max-heap by default
        dp[0][0] = 0;
        pq.push(Reverse((0,0 as usize,0 as usize))); //Reverse becuase, we want a min-heap.
//Learnings:
//1) pq.pop() -> returns Option<T> in general case.
//2) pq.pop() -> returns Option<Reverse<(i32, usize, usize)>>
//3) Internal Structure of Option enum:
// enum Option<T> {
//   Some(T),
//   None,
// }

        let drow = [-1, 0, 1, 0];
        let dcol = [0, 1, 0, -1];

        while let Some(Reverse((cur_time, cur_row, cur_col))) = pq.pop() {
//Learnings:
//1) While let is a special loop construct - it's used to match the result of pq.pop() against Some(Reverse(...))
            if dp[cur_row][cur_col] < cur_time {
                continue;
            }
            if cur_row == n-1 && cur_col == m - 1 {
                return cur_time;
            }

            for i in 0..4 {
                let new_row = (cur_row as i32 + drow[i] as i32) as usize;
                let new_col = (cur_col as i32 + dcol[i] as i32)  as usize;

                if new_row >=0 && new_row<n && new_col>=0 && new_col<m {
                    let mut new_time = cur_time.max(move_time[new_row][new_col]) + 1;
                    if (new_row as i32 + new_col as i32) % 2 == 0 {
                        new_time += 1;
                    }

                    if new_time < dp[new_row][new_col] {
                        dp[new_row][new_col] = new_time;
                        pq.push(Reverse((new_time, new_row, new_col)));
                    }
                }

            }         
        }
        -1
    }
}