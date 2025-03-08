class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cB = 0;
        int cW = 0;
        int i=0;
        int j=0;
        int ans = INT_MAX;
        while(i<blocks.size()){
            if(blocks[i]=='W') cW++;
            if(blocks[i]=='B') cB++;
            while((i-j)>(k-1)){
                char temp = blocks[j];
                if(temp=='W') cW--;
                if(temp=='B') cB--;
                j++;
            }
            if((i-j)==(k-1)){
                ans=min(ans, k-cB);
            }
            i++;
        }
        return ans;
    }
};