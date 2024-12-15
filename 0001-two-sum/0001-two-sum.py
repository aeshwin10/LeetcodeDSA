class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        v={}
        n=len(nums)
        for i in range(n):
            complement=target-nums[i]
            if nums[i] in v:
                return(v[nums[i]],i)
            v[complement]=i