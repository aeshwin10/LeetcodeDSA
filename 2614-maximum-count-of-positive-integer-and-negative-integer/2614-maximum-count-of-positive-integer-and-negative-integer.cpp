class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int low1 = 0;
        int high1 = n-1;
        int low2 = 0;
        int high2 = n-1; 


        int leftMostPos = n;
        int rightMostNeg = -1;

        while(low1<=high1){
            int mid = (low1+high1)/2;
            if(nums[mid]>0){
                leftMostPos = mid;
                high1 = mid - 1;
            }
            else{
                low1 = mid + 1;
            }
        }


        while(low2<=high2){
            int mid = (low2+high2)/2;
            if(nums[mid]>=0){
                high2 = mid - 1;
            }
            else{
                rightMostNeg = mid;
                low2 = mid + 1;
            }
        }

        return max((rightMostNeg+1), (n-leftMostPos));
    }
};