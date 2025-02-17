class Solution {
public:
    vector<int> factorial;
    void factorials(int n){
        factorial.resize(n+1, 1);
        for(int i=2; i<=n; i++){
            factorial[i] = factorial[i-1] * i;
        }
    }

    int permutations(string currStr){
        unordered_map<char, int> mp;
        for(char c: currStr){
            mp[c]++;
        }
        int total = factorial[currStr.size()];
        for(auto it : mp){
            total = total/factorial[it.second];
        }
        return total;
    }

    int generate(string& tiles, const string currStr, int pos, unordered_set<string>& seen){
        if(pos==tiles.size()){
            if(seen.find(currStr) != seen.end()) return 0;
            seen.insert(currStr);
            return permutations(currStr);
        }

        return generate(tiles, currStr + tiles[pos], pos+1, seen) + 
        generate(tiles, currStr, pos+1, seen);
    }

    int numTilePossibilities(string tiles) {
        unordered_set<string> seen;
        sort(tiles.begin(), tiles.end());
        factorials(tiles.size());    
    
        return generate(tiles, "", 0, seen) - 1;
    }
};