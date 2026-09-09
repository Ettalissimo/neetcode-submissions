class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count = 0
        max = 0
        for num in nums:
            if num == 1:
                count = count + 1
            else:
                if max < count :
                    max = count
                count = 0
        
        if max < count :
            max = count
        return max