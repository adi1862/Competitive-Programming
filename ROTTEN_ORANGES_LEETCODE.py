from queue import Queue
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        que = Queue()
        ans = 0 
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 2:
                    que.put([i,j, 0])

        while not que.empty():
            curr = que.get()
            level = curr[2]
            # top
            if ((curr[0] - 1 )>= 0) and (grid[curr[0]-1][curr[1]] == 1):
                grid[curr[0]-1][curr[1]]=2
                que.put([curr[0]-1, curr[1], level+1])
                                
            # bottom
            if (curr[0] + 1) <=(len(grid) -1) and grid[curr[0]+1][curr[1]] == 1:
                grid[curr[0]+1][curr[1]]=2
                que.put([curr[0] + 1, curr[1], level+1])
                
            # right
            if (curr[1] + 1) <= (len(grid[0])-1) and grid[curr[0]][curr[1]+1] == 1:
                grid[curr[0]][curr[1]+1]=2
                que.put([curr[0], curr[1] + 1,  level+1])
                
            # left
            if (curr[1] - 1) >= 0 and grid[curr[0]][curr[1] - 1] == 1:
                grid[curr[0]][curr[1] - 1]=2
                que.put([curr[0], curr[1] - 1,  level+1])
                
            if level > ans:
                ans=level
                
            # print(ans)
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    return -1
        return ans
            
