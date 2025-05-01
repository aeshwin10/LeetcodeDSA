class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int low = 0;
        int high = min(n,m);
        int ans = 0;

        while(low<=high){
            int mid = (low+high)/2;
            int count = 0;
            bool flag = true;

            multiset<int> st(workers.begin(), workers.end());

            for(int i=mid-1; i>=0; i--){
                auto it = prev(st.end());
                if(tasks[i] <= *it){
                    st.erase(it);
                }
                else{
                    auto it = st.lower_bound(tasks[i]-strength);
                    if(it!=st.end()){
                        count++;
                        st.erase(it);
                    }
                    else{
                        flag = false;
                        break;
                    }
                }

                if(count>pills){
                    flag = false;
                    break;
                }
            }

            if(flag){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};