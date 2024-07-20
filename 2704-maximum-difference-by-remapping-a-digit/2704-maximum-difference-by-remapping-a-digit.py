class Solution:
    def minMaxDifference(self, num: int) -> int:
        s = str(num)
        v_min = int(s.replace(s[0], '0'))
        for c in s:
            if c != '9':
                s = s.replace(c, '9')
                break
        v_max = int(s)
        return v_max - v_min