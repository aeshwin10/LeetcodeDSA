class Solution {
    public void rotate(int[][] matrix) {              
        for (int i = 0; i<matrix.length; i++){           //Taking the transpose
            for (int j = i; j<matrix[0].length; j++){
                int temp = 0;
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i = 0;i<matrix.length;i++){             //Reversing each list in the 2D list using 2 pointers.
            int s = 0, e = matrix[0].length-1;
            while (s<e){
                int temp = 0;
                temp = matrix[i][e];
                matrix[i][e] = matrix[i][s];
                matrix[i][s] = temp;
                s++;
                e--;
            }

        }  
    }
}