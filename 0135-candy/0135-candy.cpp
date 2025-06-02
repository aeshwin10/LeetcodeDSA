class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 1;
        int i=1;
        while(i<n){
            while(i<n && ratings[i]==ratings[i-1]){
                i++;
                ans+=1;
                //continue;
            }
            int peak = 1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                ans+=peak;
                i++;
            }
            int down = 1;
            while(i<n && ratings[i]<ratings[i-1]){
                ans+=down;
                i++;
                down++;
            }
            if(peak<down){
                ans+=(down-peak);
            }
        }
        return ans;
    }
};