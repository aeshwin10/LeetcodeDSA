class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mp;
        for(auto it: t){
            mp[it]++;
        }
        int r=0;
        int l=0;
        int count=0;
        int sindex=-1;
        int mini=INT_MAX;
        while(r<s.size()){
            if(mp[s[r]]>0) count++;
            mp[s[r]]--;
            while(count==t.length()){
                if(r-l+1<mini){
                mini=r-l+1,mini;
                sindex=l;
                }
                
                mp[s[l]]++;
                if(mp[s[l]]>0) count--;
                l++;
            }
            r++;
        }
    return sindex==-1?"":s.substr(sindex,mini);    
    }
};
/* My Solution
    bool checkEqual(map<char,int> mpS, map<char,int> mpT){
        
        if(mpT.size()>mpS.size()){
            return false;
        }
        for(pair<char,int> e: mpT){
            if(mpS[e.first] < e.second){
                return false; 
            }
            
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        if(t.size()>s.size()){
            return "";
        }
        map<char,int> mpS;
        map<char,int> mpT;
        int leftOpti = -1;
        int rightOpti = -1;
        int mini = INT_MAX;
        int left=0;
        int right=0;
        int n = s.size();
        int m = t.size();

        for(char c : t){
            mpT[c]++;
        }
        
        while(right < n){
            mpS[s[right]]++;
            if(right>=m-1){
                while(checkEqual(mpS, mpT) && left < right){
                    if(right - left + 1 < mini){
                        leftOpti = left;
                        rightOpti = right;
                        mini = right - left + 1;
                    }
                    mpS[s[left]]--;
                    if(mpS[s[left]] == 0){
                        mpS.erase(s[left]);
                    }
                    left++;
                }
            }
            right++;
        }
        string ans = "";
        if(leftOpti==-1){
            return "";
        }
        else{
            for(int i=leftOpti; i<=rightOpti; i++){
            ans+=s[i];
            }

        }
        return ans;
        
    }
};
*/