class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if(n <=2) return 0;

        unordered_map<int, int> mp;
        for(auto &i : arr) mp[i] = i;

        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int num1 = arr[j];
                int num2 = arr[i];
                int tempCount = 2;
                while(mp.find(num1 + num2) != mp.end()){
                    tempCount++;
                    ans = max(ans, tempCount);
                    int temp = num1;
                    num1 = num1 + num2;
                    num2 = temp;
                }
            }
        }
        return ans;
    }
};