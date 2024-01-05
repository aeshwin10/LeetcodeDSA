class Solution {
    public int myAtoi(String s) {
        if (s.equals("")) {
			return 0;
		}
        
        int res = 0, i = 0, sign = 1;

        while (i < s.length() && s.charAt(i) == ' ') {
		    i++;
		}

        if (i < s.length() && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
			// change if negative, iterate
			if (s.charAt(i++) == '-') {
				sign = -1;
			}
		}
        while (i < s.length() && s.charAt(i) >= '0' && s.charAt(i) <= '9') {
			// check if we will go over the max
			if (res > Integer.MAX_VALUE / 10 || (res == Integer.MAX_VALUE / 10 && s.charAt(i) - '0' > 7)) {   //charAt(i) - '0' is necessary becuase, to convert into numeric
				if (sign == -1) {
					return Integer.MIN_VALUE;
				}
				return Integer.MAX_VALUE;
			}
			
			
			res = res * 10 + (s.charAt(i++) - '0');  //Multiplying by 10 and adding will not sum it up, it will add the next digit to the next place only. 
		}
		return sign * res;
        
    }
}