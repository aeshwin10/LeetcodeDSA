class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] arr = new int[]{-1,-1};
        int n = nums.length;

        int lowerIndex = findLow(nums,target, n);
        int higherIndex = findHigh(nums,target, n);

        arr[0] = lowerIndex;
        arr[1] = higherIndex;
                            
        return arr;
    }        

    static int findLow(int[] nums,int target, int n){
        int high = n-1;
        int low = 0;
        int ans = -1;


        while (low<=high){
            int mid = (low + high)/2;

            if (target<= nums[mid]){
                high = mid -1;
                
            }
            else if (target>nums[mid]){
                low = mid + 1;
            }
            if(nums[mid] == target) ans = mid;       
        }       
        return ans;        
    }

    static int findHigh(int[] nums,int target, int n){
        int high = n-1;
        int low = 0;
        int ans = -1;

        while (low<=high){
            int mid = (low + high)/2;

            if (target< nums[mid]){
                high = mid -1;                
            }
            else if (target>=nums[mid]){
                low = mid + 1;
                
            }
            if(nums[mid] == target) ans = mid;       
        }
        
        return ans;
    }        
}