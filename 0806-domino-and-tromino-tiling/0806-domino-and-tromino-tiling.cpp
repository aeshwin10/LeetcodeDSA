class Solution {
const int MOD = 1e9+7;
public:
    int numTilings(int n) {
        long long g[1001],u[1001];
        g[0]=0; g[1]=1; g[2]=2;
        u[0]=0; u[1]=1; u[2]=2;
        
        for(int i=3;i<=n;i++){
            u[i] = (u[i-1] + g[i-1])   %MOD;
            g[i] = (g[i-1] + g[i-2] + 2*u[i-2])   %MOD;
        }
        return g[n]%MOD;tele
    }
};