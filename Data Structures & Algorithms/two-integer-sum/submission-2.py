class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        potential = {}
        for i in range(len(nums)):
            difference = target - nums[i]
            if difference in potential:
                return [potential[difference], i]
            else:
                potential[nums[i]] = i
        
