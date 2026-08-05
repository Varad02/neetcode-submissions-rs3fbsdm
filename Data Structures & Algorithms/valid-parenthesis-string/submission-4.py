class Solution:
    def checkValidString(self, s: str) -> bool:
        stackL = []
        stackA = []
        for i, ch in enumerate(s):
            if ch == "(":
                stackL.append(i)
            elif ch == "*":
                stackA.append(i)
            else:
                if stackL:
                    stackL.pop()
                elif stackA:
                    stackA.pop()
                else:
                    return False
        
        while stackL and stackA:
            if stackL.pop() > stackA.pop():
                return False
        return not stackL

