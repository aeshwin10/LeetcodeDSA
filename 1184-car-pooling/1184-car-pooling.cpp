class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) { //TC - O(nlogn)
        map<int,int> mp;
        for(auto &i : trips){
            mp[i[1]] += i[0];
            mp[i[2]] -= i[0];
        }
        int curPassengers = 0;
        for(auto [key, value] : mp){
            curPassengers += value;
            if(curPassengers>capacity){
                return false;
            }
        }
        return true;
    }
    //Here, we did a line sweep, but we did not have to check for each positions.
    //Because, we only care about the interval as a whole and not every single point.
};