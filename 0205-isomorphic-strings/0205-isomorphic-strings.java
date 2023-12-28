class Solution {
    public boolean isIsomorphic(String s, String t) {
        int[] sArr = new int[127];   //This is an empty array filled with zeros.
        int[] tArr = new int[127];   //Explicitly 128 becuase there are 127 ascii values.
                                     //200 is also possible.
        for(int i = 0; i<s.length(); i++){
            if (sArr[s.charAt(i)]!=tArr[t.charAt(i)]){
                return false;
            }
            sArr[s.charAt(i)] = i+1;
            tArr[t.charAt(i)] = i+1;
        }
        return true;   
    }
}