class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        if not nums: return 0
        
        copy = nums.copy()
        copy.sort()
        right, left = len(nums)-1, 0
        isRright, isLeft = False, False
        for i in range(len(nums)):
            if isRright and isLeft: break
            if copy[i] != nums[i] and not isLeft: 
                left = i
                isLeft = True            
            if copy[len(nums)-1-i] != nums[len(nums)-1-i] and not isRright: 
                right = len(nums)-1-i
                isRright = True
        
        if not isRright and not isLeft and (right - left == len(nums)-1): 
            return 0
        
        return right - left + 1
