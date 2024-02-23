class Solution {
    public int titleToNumber(String columnTitle) {
        int n = columnTitle.length();

        if(n==1){
            return (columnTitle.charAt(0) - 'A' + 1);
        }

        int ans = 0;

        for (int i = 1; i<n; i++){
            ans += (int)Math.pow(26, i);
        }  //Adding the n-1 digit's last value then finding the addition in the below loop.

        for (int i = 0; i<n; i++){
            char ch = columnTitle.charAt(i);
            int value = (ch - 'A');
            ans += value * (int)Math.pow(26, n - i - 1);
        }
        return (ans+1);    
    }
}