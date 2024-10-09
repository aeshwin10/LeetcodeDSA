class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int summ1 = accumulate(nums1.begin(), nums1.end(), 0);
        int summ2 = accumulate(nums2.begin(), nums2.end(), 0);

        int maxGain1 = 0;
        int maxGain2 = 0;
        maxGain1 = findMaxGain(nums1, nums2);
        maxGain2 = findMaxGain(nums2, nums1);
        return max((maxGain1+summ1), (maxGain2+summ2));
    }

    int findMaxGain(vector<int>& arr1, vector<int>& arr2){
        int maxi = 0;
        int summ = 0;
        int n = arr1.size();
        for(int i=0; i<n; i++){
            summ+=(arr2[i] - arr1[i]);
            if(summ<=0){
                summ = 0;
            }
            maxi = max(maxi, summ);
        }
        return maxi;
    }
};