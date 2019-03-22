class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        buffDict = {}
        for i, val in enumerate(nums):
            if target - val in pairDict:
                return [buffDict[target - val], i]
            buffDict[val] = i
        return []
