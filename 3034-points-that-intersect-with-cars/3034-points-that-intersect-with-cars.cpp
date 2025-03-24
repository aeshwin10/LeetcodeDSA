class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> line(102);
        for(auto& p : nums){
            line[p[0]]++;
            line[p[1]+1]--;
        }
        int ans =0;
        int count =0;
        for(int i=0; i <102; ++i){
            count += line[i];
            if(count > 0){
                ++ans;
            }
        }
        return ans;
    }
};

//Learning:
// 1) When we try to find the no.of intersections, we do something like a difference array
// 2) whenever the count is greater than 1, then we say that this interval is occupied.