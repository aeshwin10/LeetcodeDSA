class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> mp(10, 0);
        for(auto &ele : digits) mp[ele]++;

        vector<int> ans;

        for(int num=100; num<999; num+=2){
            map<int,int> tempMp;
            int curNum = num;

            while(curNum){
                tempMp[curNum%10]++;
                curNum/=10;
            }
            bool flag = true;
            for(auto [key, val] : tempMp){
                if(val > mp[key]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(num);
        }
        return ans;
        
    }
};