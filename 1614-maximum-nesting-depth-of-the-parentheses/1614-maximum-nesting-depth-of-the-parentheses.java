class Solution {
    public int maxDepth(String s) {
        char open = '(';
        char close = ')';

        int maxi = 0;
        int temp = 0;
        for (int i = 0; i<s.length(); i++){
            if (s.charAt(i) == open){
                temp+=1;
                if (temp>maxi){
                    maxi = temp;
                }
            }
            else if (s.charAt(i) == close){
                temp-=1;
            }
        }
    return maxi;
    }
}