
class Solution {
    struct Hash{
        const long long MOD = 1e9+7;
        const long long BASE1 = 5689;
        const long long BASE2 = 8861;

        vector<pair<long long,long long>> hashes, Pow;

        Hash(string s){
            hashes.assign(s.size()+1, {0,0});
            Pow.assign(s.size()+1, {1,1});

            for(long long i=0; i<s.size(); i++){
                hashes[i+1] = {(1ll * hashes[i].first * BASE1 + (s[i]-'a')%MOD + MOD)%MOD,
                            (1ll * hashes[i].second * BASE2 + (s[i]-'a')%MOD + MOD) % MOD};

                Pow[i+1] = { (1ll * Pow[i].first * BASE1) % MOD,
                            (1ll * Pow[i].second * BASE2) % MOD};				       
            }
        }

        pair<long long,long long> get(long long l, long long r){
            l++, r++;

            long long hash1 = (hashes[r].first-(1ll * hashes[l-1].first * Pow[r-l+1].first) % MOD + MOD) % MOD;
            long long hash2 = (hashes[r].second-(1ll * hashes[l-1].second * Pow[r-l+1].second)% MOD + MOD) % MOD;

            return {hash1, hash2};
        }
    };
public:
    string longestPrefix(string s) {
        int n=s.size();
        int ans = 0;

        Hash stringHash(s);

        for(int i=0; i<n-1; i++){
            pair<int,int> hash1 = stringHash.get(0,i);
            pair<int,int> hash2 = stringHash.get(n-1-i, n-1);

            if(hash1==hash2){
                ans = i+1;
            }
        }

        return s.substr(0,ans);
    }
};