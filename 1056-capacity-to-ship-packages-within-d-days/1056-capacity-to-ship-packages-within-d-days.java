class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int n = weights.length;
        int low = Integer.MIN_VALUE;
        int high = 0;
        for (int i: weights){
            low = Math.max(low, i);
            high = high + i;
        }

        while(low<=high){
            int mid = (high + low)/2;
            int daysAns = findDays(weights, mid, n);
            if (daysAns > days){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }

    private static int findDays(int[] weights, int mid, int n){
        int weight = 0;
        int daays = 1;

        for (int i: weights){
            weight = weight + i;
            if (weight > mid){
                weight = i;
                daays = daays + 1;
            }
        }
        return daays;
    }
}