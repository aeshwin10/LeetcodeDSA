class Solution {
    public String reverseWords(String s) {
        if (s == null) return null;

        int left = 0;
        int N = s.length() - 1;
        int j = 0;

        String temp = "";
        String ans = "";

        
        while(left<=N){
            while (left<=N && s.charAt(left) == ' '){
                left++;
            }
            
            if (left>N) break;
            
            j = left;
            
            while (j<=N && s.charAt(j) != ' '){
                    temp = temp + s.charAt(j);
                    j++;
            }

            if (!temp.isEmpty()){
                if (ans.isEmpty()){
                    ans = temp;
                    temp = "";
                }
                else{   
                    ans = temp + ' ' + ans;
                    temp="";
                }
                left = j; 
            }
        }    
        return ans;     
    }    
}