class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans = 0;
        int right = n-1;
        int leftSum=0;
        int rightSum=0;

        for(int i = 0; i<k; i++){
            ans+=cardPoints[i];
        }
        leftSum=ans;

        for(int i=k-1; i>=0; i--){
            leftSum-=cardPoints[i];
            rightSum+=cardPoints[right];
            int temp = leftSum+rightSum;
            ans=max(ans,temp);
            right--;
        }
        return ans;
    }
};