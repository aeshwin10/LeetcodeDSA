class Solution {
public:
    vector<char> given = {'a', 'b', 'c'};
    void generate(string currStr, char parent,  vector<string>& arr, int n){
        if(currStr.size()==n){
            arr.push_back(currStr);
            return;
        }
        for(int i=0; i<3; i++){
            if(given[i] == parent) continue;
            int size = currStr.size();
            generate(currStr + given[i], given[i], arr, n);
        }
    }

    string getHappyString(int n, int k) {
        vector<string> arr;
        generate("", 'z', arr, n);
        if(k>arr.size()){
            return "";
        }
        return arr[k-1];

    }
};