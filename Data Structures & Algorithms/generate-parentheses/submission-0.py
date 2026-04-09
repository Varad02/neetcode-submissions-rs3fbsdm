class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def util(o, c, s):
            if len(s) == 2*n:
                res.append(s)
            if c > o: 
                return
            if o < n:
                util(o+1, c, s+"(")
            if c < n and o > c:
                util(o, c+1, s+")")

        util(0, 0, "")
        return res