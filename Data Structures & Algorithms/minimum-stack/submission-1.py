class MinStack:

    def __init__(self):
        self.arr = []
        self.minI = []


    def push(self, val: int) -> None:
        self.arr.append(val)
        if len(self.minI) == 0 or val <= self.minI[-1]:
            self.minI.append(val)

    def pop(self) -> None:
        if self.arr[-1] == self.minI[-1]:
            self.minI.pop()
        self.arr.pop()

    def top(self) -> int:
        return self.arr[-1]

    def getMin(self) -> int:
        return self.minI[-1]