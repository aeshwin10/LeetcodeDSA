class Solution {
    public int mySqrt(int x) {
        if (x==0 || x==1){
            return x;
        }
        int low = 1;
        int high = x;

        while (low<=high){
            int mid = low +(high - low)/2;
            if(mid>(x/mid)){
                high = mid -1;
            }
            else if ((mid*mid)==x){
                return mid;
            }
            else{
                low = mid + 1;
            }
        }
        return Math.round(high);
    }
}