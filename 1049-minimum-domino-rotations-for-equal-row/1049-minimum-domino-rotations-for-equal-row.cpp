class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) { //TC -O(n)
        int n = tops.size();
        int val1 = tops[0];
        int val2 = bottoms[0];

        int count1 = 0;
        int count2 = 0;
        int count1b = 0;
        int count2b = 0;

        bool flag1 = true;
        bool flag2 = true;

        for(int i=0; i<n; i++){
            if(tops[i]!=val1 && bottoms[i]==val1){
                count1++;
            }
            else if(tops[i]!=val1 && bottoms[i]!=val1){
                flag1 = false;
            }
            else if(tops[i] == val1 && bottoms[i] != val1){
                count1b++;
            }

            if(tops[i]==val2 && bottoms[i]!=val2){
                count2++;
            }
            else if(tops[i]!=val2 && bottoms[i]!=val2){
                flag2 = false;
            }
            else if(bottoms[i] == val2 && tops[i] != val2){
                count2b++;
            } 

            if(!flag1  && !flag2) return -1;
        }
        
        int best1 = min(count1, count1b);
        int best2 = min(count2, count2b);

        if(flag1 && !flag2)  return best1;
        if(!flag1 && flag2)  return best2;

        return min(best1, best2);
    }
};
//Learning - Initial plan was to use DP Table of size n*6. But simple observation made it possible to use the above strategy.