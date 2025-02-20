class Solution {
public:
    vector<char> binary = {'0', '1'};

    void generate(string currStr, unordered_map<string, int>& mp, int n, string& ans){
        if(currStr.size()==n){
            if(!mp[currStr]){
                ans = currStr; 
            }
            return;
        }

        for(int i=0; i<2; i++){
            if(ans!=""){
                return;
            }
            generate(currStr+binary[i], mp, n, ans);
        }
    }


    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_map<string, int> mp; //binStr, count
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        string ans = "";
        generate("", mp, n, ans);
        return ans;
    }
};