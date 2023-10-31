import java.util.ArrayList;
public class Solution {
    public static int findPages(ArrayList<Integer> arr, int n, int m) {
        if (m>n) return -1;
        
        int low = Integer.MIN_VALUE;
        int high = 0;
        for (int i : arr){
            high = high + i;         //The range of the answer will lie between max ele and summation.
            low = Math.max(low, i);
        }

        while(low<=high){
            int mid = (low + high)/2;
            int Students = findStudents(arr, n, mid);

            if (Students <= m){
                high = mid - 1;
            }
            else if (Students > m){
                low = mid + 1;
            }
        }
        return low;    
    }

    static int findStudents(ArrayList<Integer> arr, int n, int mid){
        int student = 1;
        int pages = 0;

        for (int i: arr){
            if (pages + i <=mid){
                pages = pages + i;
            }
            else{
                student++;
                pages = i;
            }
        }
        return student;    
    }
}
