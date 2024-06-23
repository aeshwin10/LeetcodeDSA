class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if(k<=numOnes){
            return k;
        }
        k=k-numOnes;
        if(k<=numZeros){
            return numOnes;
        }
        k=k-numZeros;
        int sum = numOnes;
        sum = sum - min(k,numNegOnes);
        return sum;

    }
};