class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        arr = [[1, 0], [0, 1], [-1, 0], [0, -1]]
        n = len(grid)
        m = len(grid[0])
        def dfs(i, j):
            nonlocal n, m
            if i < 0 or i >= n or j < 0 or j >= m or grid[i][j] == '0':
                return
            grid[i][j] = '0'
            for ni, nj in arr:
                nr = ni+i
                nc = nj+j
                if nr < 0 or nr >= n or nc < 0 or nc >= m:
                    continue
                if grid[nr][nc] == '1':
                    dfs(nr, nc)
            return
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    dfs(i, j)
                    count += 1
        return count
                
