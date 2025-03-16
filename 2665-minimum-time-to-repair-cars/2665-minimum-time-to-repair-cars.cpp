class Solution {
public:
    bool check(long long mid, vector<int>& ranks, int cars){
        long long count = 0;
        for(auto &i : ranks){
            count+= (sqrt((mid/(long long)i))/1ll);
        }
        return count >= (long long)cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        sort(ranks.begin(), ranks.end());
        //long long mini = ranks[0];
        long long maxi = ranks[n-1];
        

        long long low = 0;
        long long high = ((long long)cars * (long long)cars) * maxi;
        long long ans = high;

        while(low<=high){
            long long mid = (low+high)/2;

            if(check(mid, ranks, cars)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};