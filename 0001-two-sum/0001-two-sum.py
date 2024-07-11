class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict={}
        for i in range(len(nums)):
            n=nums[i]
            if n in dict:
                return dict[n],i
            else:
                dict[target-n]=i
            