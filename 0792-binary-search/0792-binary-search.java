class Solution {
    public int search(int[] nums, int target) {
        int s=0;
        int e=nums.length - 1;
        while(s<=e){
            int mid1 = (s+e)/2;
            if (target == nums[mid1]){
                return (mid1);
            }
            else if (target>nums[mid1]){
                s=mid1+1;
            }
            else if (target<nums[mid1]){
                e=mid1-1;
            }
        }
    return -1;
    }
}