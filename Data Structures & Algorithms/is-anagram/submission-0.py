class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        ds , dt = {} , {}
        slist = list(s)
        tlist =list(t)
        for cs in slist:
            if cs in ds:
                ds[cs] += 1
            else :
                ds[cs] = 1
        for ct in tlist:
            if ct in dt:
                dt[ct] += 1
            else :
                dt[ct] = 1
        if ds == dt:
            return True
        return False 
