class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        ops = []
        for i in tokens:
            if i in ["+", "-", "*", "/"]:
                op1 = int (ops[-1])
                ops.pop()
                op2 = int (ops[-1])
                ops.pop()
                match i:
                    case "+":
                        ops.append(str(op1+op2))
                    case "-":
                        ops.append(str(op2-op1))
                    case "*":
                        ops.append(str(op1*op2))
                    case "/":
                        ops.append(str( int (op2/op1)))
            else:
                ops.append(i)
        return int (ops[0])