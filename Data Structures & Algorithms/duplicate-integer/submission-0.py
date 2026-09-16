class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        d = {}
        for n in nums:
            key = n
            if key in d:
                d[key]+=1
            else:
                d[key]=1

        for value in d.values():
            if value > 1 :
                return True
        
        return False