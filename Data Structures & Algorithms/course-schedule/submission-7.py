class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if len(prerequisites) == 0:
            return True
        adj = defaultdict(list)
        cStat = defaultdict(int)
        cPre = defaultdict(int)
        for [i, j] in prerequisites:
            adj[i].append(j)
            cStat[j] = 2
            cPre[j] += 1
            if not cStat[i]:
                cStat[i] = 1

        queue = deque()
        visited = [0] * numCourses
        for i in range(numCourses):
            if i not in cStat:
                visited[i] = 1
            if cStat[i] == 1:
                queue.append(i)
        
        if len(queue) == 0:
            return False

        
        while len(queue) != 0:
            sub = queue.popleft()
            if visited[sub] == 1:
                return False
            visited[sub] = 1
            for j in adj[sub]:
                cPre[j]-=1
                if cPre[j] == 0:
                    queue.append(j)
        
        for i in range(numCourses):
            if visited[i] == 0:
                return False
        return True
