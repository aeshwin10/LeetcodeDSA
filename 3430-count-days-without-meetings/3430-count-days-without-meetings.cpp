class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        int ans = 0, prevEnd = 0;
        
        for(auto& meeting : meetings){
            int start = meeting[0], end = meeting[1];
            if(start > prevEnd + 1){
                ans += (start - prevEnd - 1); 
            }
            prevEnd = max(prevEnd, end); 
        }  
        ans += (days - prevEnd); 

        return ans;
    }
};