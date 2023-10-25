class Solution {
    public int findPeakElement(int[] nums) {       
        int n = nums.length;        
        if (n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        int low = 1;
        int high = n-2;

        while(low<=high){
            int mid = (low+high)/2;
            
            // check if mid is a peak element
            if ((nums[mid - 1] < nums[mid]) && (nums[mid+1] < nums[mid])){
                return mid;
            }
            
            // move low or high pointer based on the slope
            else if (nums[mid - 1] > nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        // no peak element found
        return -1;                
    }
}


