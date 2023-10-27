class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int n = nums.length;
        if(n > threshold) return -1;  
        int low = 1;      
        int high = Integer.MIN_VALUE;
        for (int i : nums){
            high = Math.max(high, i);
        }


        while(low<=high){
            int mid = (low+high)/2;
            int sumValue = findDivisor(nums, mid, n);
            if (sumValue <= threshold){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
            
        }
    return low;
    }
    
    private static int findDivisor(int[] nums, int mid, int n){
        int summ = 0;
        for (int i = 0; i< n; i++){
            summ+= Math.ceil((double)(nums[i])/(double)(mid));
        }
        return summ;  
    }
    
}