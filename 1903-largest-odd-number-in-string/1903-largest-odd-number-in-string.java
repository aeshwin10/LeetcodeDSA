class Solution {
    public String largestOddNumber(String num) {
        
        int n = num.length();
        String ans = "";

        for(int i = n-1; i>=0; i--){
            int character = num.charAt(i);       //Iterating in Reverse
            if (character%2==1){                 //Checking Even or Odd
                ans=num.substring(0,i+1);
                return ans;
            }
        }
        return ans;       
    }
}