class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        j = len(arr) - 1
        cop = arr[j]
        while j >= 0 :
            if cop < arr[j-1]:
                switch = arr[j-1]
                arr[j-1] = cop
                cop = switch
            else:
                arr[j-1] = cop
            j = j-1
        arr[-1] = -1
        return arr