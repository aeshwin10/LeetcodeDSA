class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        int range = abs(upper - lower) + 1;
        long long mini = min(0,differences[0]);
        long long maxi = max(0,differences[0]);

        long long tempSum = differences[0];
        for(int i=1; i<n; i++){
            tempSum += differences[i];
            mini = min(mini, tempSum);
            maxi = max(maxi, tempSum);
        }

        int req = (maxi - mini);
        int ans = range - req;
        return max(0,ans);

    }
};