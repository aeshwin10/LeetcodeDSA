class Solution {
	public int beautySum(String s) {
		int res = 0;
		for (int i = 0; i < s.length(); i++) {  
			int[] freq = new int[26];
			for (int j = i; j < s.length(); j++) {  //Each substring, we calculate max-min through helper function.
				freq[s.charAt(j) - 'a']++;
				res += helper(freq);
			}
		}
		return res;
	}

	public int helper(int[] arr) {
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < 26; i++) {  //Exclue 0, coz, then the diff will be 1 each time. 
			if (arr[i] == 0) {
				continue;
			}
			min = Math.min(min, arr[i]);
			max = Math.max(max, arr[i]);
		}
		return max - min;
	}
}