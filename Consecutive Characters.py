class Solution:
    def maxArea(self, h: int, w: int, a: List[int], b: List[int]) -> int:
        a=[0]+a+[h]
        b=[0]+b+[w]
        a.sort()
        b.sort()
        mh=mv=0
        for h in range(len(a)-1):
            mh=max(mh, a[h+1]-a[h])
        for h in range(len(b)-1):
            mv=max(mv, b[h+1]-b[h])
        m=10e+8+7
        return int((mh*mv)%m)
        
