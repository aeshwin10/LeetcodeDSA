class Solution {
    public int[] rearrangeArray(int[] nums) {
        /*
        int i = -1;   //2pointers
        int j = 0;    //O(N), O(1) -- Not working.
        int temp = 0;

        while (j<nums.length){
            if (nums[j]>=0){
                if (j%2==0 && i<j){
                    i=i+2;
                }
                if(j%2!=0){
                    temp = nums[i+1];
                    nums[i+1] = nums[j];
                    nums[j] = temp;
                    if(i<j) i=i+2;
                }
            }
        j++;
        }
    return nums;
        */
        int[] arr = new int[nums.length];
        int p = 0;
        int n = 1;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] > 0) {
                arr[p] = nums[i];
                p += 2;
            }
            else {
                arr[n] = nums[i];
                n += 2;
            }
        }
        return arr;        
    }
}