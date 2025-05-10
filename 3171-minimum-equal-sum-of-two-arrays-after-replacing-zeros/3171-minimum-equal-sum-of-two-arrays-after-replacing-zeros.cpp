class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0ll);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0ll);

        int zeroCnt1 = 0, zeroCnt2 = 0;
        for(auto &ele : nums1){
            if(ele == 0) zeroCnt1++;
        }
        for(auto &ele : nums2){
            if(ele == 0) zeroCnt2++;
        }

        if(!zeroCnt1){
            if(zeroCnt2 + sum2 > sum1) return -1;
        }
        if(!zeroCnt2){
            if(zeroCnt1 + sum1 > sum2) return -1;
        }
        
        return max(zeroCnt1 + sum1, zeroCnt2 + sum2);
    }
};