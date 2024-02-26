public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int res = 0;
        for(int i = 0; i<32; i++){
            int bit = (n>>i) & 1;    //Right shifting n by 1 place at each iteration and getting the bit.
            res = res | (bit<<(31-i)); //Accessing the res's left most bit and changing it to 'bit'.
        }
        return res;
    }
}