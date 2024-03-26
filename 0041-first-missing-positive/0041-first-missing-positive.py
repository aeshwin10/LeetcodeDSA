class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.append(0)
        n=len(nums)
        for i in range(0,n):
            if(nums[i]>=n or nums[i]<0):
                nums[i]=0
        for i in range(0,n):
            nums[nums[i]%n]+=n  #Incrementing by n becuase, we need the information of the next value
            #as well, this can be taken by mod n. Just try thinking replacing with True False, you will get it.
        for i in range(1,len(nums)):
            if nums[i]//n==0:
                return i
        return n
        