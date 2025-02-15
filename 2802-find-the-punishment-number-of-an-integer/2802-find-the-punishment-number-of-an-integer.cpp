class Solution {
public:
    bool check(string nums, int index, int target){
        if(index == nums.size()) return target == 0;

        int sum = 0;
        for(int i=index; i<nums.length(); i++){
            sum = sum*10 + (nums[i]- '0');
            if(sum>target) break;
            if(check(nums, i+1, target - sum)){
                return true;
            }
        }
        return false;
    }
    
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(check(to_string(i*i), 0, i)){ //num, index, targer
                ans+=(i*i);
            } 
        }
        return ans;
    } 
};