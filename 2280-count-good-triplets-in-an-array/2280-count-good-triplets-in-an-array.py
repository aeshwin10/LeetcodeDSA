from sortedcontainers import SortedList
class Solution:
    def goodTriplets(self, A: List[int], B: List[int]) -> int:
       
        pos = [0] * len(A)               
        for idx, b in enumerate(B):
            pos[b] = idx
        
        pos_in_b, pre_a = SortedList([pos[A[0]]]), [0]      
        for a in A[1:]:       
            pos_in_b.add(pos[a])
            pre_a.append(pos_in_b.bisect_left(pos[a]))
    
        pos_in_b, suf_a = SortedList([pos[A[-1]]]), [0]
        for a in reversed(A[:len(A)-1]):
            idx = pos_in_b.bisect(pos[a])
            suf_a.append(len(pos_in_b) - idx)
            pos_in_b.add(pos[a])
        suf_a.reverse()
        
        ans = 0
        for x, y in zip(pre_a, suf_a):
            ans += x * y
        return ans