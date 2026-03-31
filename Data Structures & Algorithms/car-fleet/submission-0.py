class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        car = [[position[i], speed[i]] for i in range(len(position))]
        car.sort(reverse=True)
        res = []
        for i, (posi, spee) in enumerate(car):
            time = (target-posi)/spee
            if res and res[-1] >= time:
                continue
            res.append(time)
        return len(res)