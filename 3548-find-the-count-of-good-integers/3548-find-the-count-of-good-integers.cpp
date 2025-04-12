class Solution {
    long long kPalindromes = 0;
    unordered_set<long long> st;
    vector<long long> fact;

    void preComputeFact(int& n){
        fact[0] = 1;
        fact[1] = 1;
        for(long long i=2; i<=10; i++){
            fact[i] = i*fact[i-1];
        }
    }

    long long countAllPermutations(vector<long long>& freq, int n){
        long long count = fact[n];
        for(int i=0; i<=9; i++){
            count /= fact[freq[i]];
        }
        return count;
    }

    long long allArrangements(string number, int& n){
        sort(number.begin(), number.end());
        if(st.count(stoll(number))){
            return 0;
        }
        st.insert(stoll(number));
        vector<long long> freq(10);
        for(char& c : number){
            freq[c-'0']++;
        }
        long long totalPermutations = countAllPermutations(freq, n);
        long long invalidPermutations = 0;
        if(freq[0]>0){
            freq[0]--;
            invalidPermutations = countAllPermutations(freq, n-1);
        }
        return totalPermutations - invalidPermutations;
    }


    bool isKPalindrome(string& number, int& n, int& k){
        return (stoll(number)%k == 0);
    }
    
    void generatePalindromes(int pos, int& n, string& number, int& k){
        if(pos >= (n+1)/2){
            if(isKPalindrome(number, n, k)){
                kPalindromes += allArrangements(number, n);
            }
            return;
        }

        char start = pos==0? '1':'0';
        while(start <= '9'){
            number[pos] = start;
            number[n-pos-1] = start;
            generatePalindromes(pos+1, n, number, k);
            start++;
        }
        number[pos] = ' ';
    }

public:
    long long countGoodIntegers(int n, int k) {
        fact = vector<long long> (11);
        preComputeFact(n);
        string number(n, ' ');
        generatePalindromes(0, n, number, k);
        return kPalindromes;
    }
};