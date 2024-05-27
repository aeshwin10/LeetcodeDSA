class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = 0;
        int inserts=0;
        for(int i=0; i<n; i++){
            int ele = nums2[i];
            while(idx<m+n){
                if(ele<nums1[idx] || ((nums1[idx]==0) && idx>=m+inserts)){
                    nums1.pop_back();
                    nums1.insert(nums1.begin()+idx,ele);
                    idx+=1;

                    inserts++;
                    break;
                }
                else{
                    idx++;
                }
            }
        }
    }
};