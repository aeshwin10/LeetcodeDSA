impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let n = matrix.len();
        let m = matrix[0].len();

        let mut row0 = false;
        let mut col0 = false;

        for j in 0..m {
            if matrix[0][j] == 0 {
                row0 = true;
            }
        }

        for i in 0..n {
            if matrix[i][0] == 0 {
                col0 = true;
            }
        }

        for i in 1..n {
            for j in 1..m {
                if matrix[i][j] == 0 {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for i in 1..n {
            for j in 1..m {
                if matrix[i][0] == 0 || matrix[0][j]==0 {
                    matrix[i][j] = 0;
                }
            }
        }

        if row0 {
            for j in 0..m {
                matrix[0][j] = 0;
            }
        }

        if col0 {
            for j in 0..n {
                matrix[j][0] = 0;
            }
        } 
    }
}