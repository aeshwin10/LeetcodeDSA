class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> mp;
        for(int i=0; i<bills.size(); i++){
            mp[bills[i]]++;
            int diff = bills[i]-5;

            if(diff==5){
                if(mp[5]>0){
                    mp[5]--;
                }
                else{
                    return false;
                }
            }
            if(diff==15){
                if(mp[10]>0 && mp[5]>0){
                    mp[10]--;
                    mp[5]--;
                }
                else if(mp[5]>2){
                    mp[5]-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};