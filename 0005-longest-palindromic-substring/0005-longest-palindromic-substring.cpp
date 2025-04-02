struct manacher{
	vector<int> p;

	void run_manacher(string s){
		int n = s.size();
		p.assign(n, 1);
		int l=1, r=1;               //simply this values works in the start
		for(int i=1; i<n; i++){     //p[0] is always 1, since there is no left element for it.
            if(i<r) p[i] =  min((r-i), (p[l+r-i]));
            else{
                p[i] = 1;
            }
			//p[i] = max(1, min((r-i), (p[l+r-i])));
//Worst case value will be 1.
//Now, min(r-i) represents the right side bound, mainly when r = n.
//Now, p[l+r-i] simply represents the copy from the left side from the center.

			while(i - p[i] >= 0 && i + p[i] < n && s[i-p[i]] == s[i+p[i]]) {
                p[i]++;
            }
			if(i+p[i]>r){    //update the new limits. Note, we can update a value of an new p[i] 
				//with old center also, but simply it will increase the TC
				l = i-p[i];
				r = i+p[i];
			}
		}
	}

	void build(string s){
		string t;
		for(auto v : s){
			t+= string("#") + v;    //Do not do t = t + string("#") -> O(n)
		}
		run_manacher(t+"#");         //pre-processed string
	}

	int getLongest(int cen, bool odd){
		int pos = 2*cen+1+(!odd);
		return p[pos] - 1;
	}

	bool checkPalin(int l, int r){
		if((r-l+1) <= getLongest((l+r)/2, ((l&1)==(r&1)))){
			return 1;
		}
		return 0;
	}

}m;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int n = s.size();
        m.build(s);

        int maxLen = 0;
        int centerIdx = 0;

        for(int i=0; i<n; i++){
            for(bool odd : {true, false}){
                int curLen = m.getLongest(i, odd);
                if(curLen > maxLen){
                    maxLen = curLen;
                    centerIdx = i;
                }
            }
            
        }
        int start = centerIdx - (maxLen - 1) / 2;
        return s.substr(start, maxLen);
    }
};