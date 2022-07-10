from typing import List


class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        
        prev = [[1000001 for i in range(target)] for j in range(n)]
        
        if houses[0] == 0:
            for i in range(n):
                prev[i][0] = cost[0][i]
        else:
            prev[houses[0]-1][0] = 0
        
        # each house 
        for i in range(1, m):
            curr = [[1000001 for i in range(target)] for j in range(n)]
            
            # each color 
            for j in range(n):
                
                # for painted curr
                if houses[i] != 0 and houses[i]-1 != j:
                    continue
                
                # each num of neighbors
                for k in range(target):
                    
                    currMin = 1000001

                    # each color of prev
                    for l in range(n):
                        
                        # for painted prev
                        if houses[i-1] != 0 and houses[i-1]-1 != l:
                            continue
                        
                        if l == j:
                            currMin = min(currMin, prev[l][k])
                        else:
                            if k > 0:
                                currMin = min(currMin, prev[l][k-1])
                    if houses[i] == 0:
                        curr[j][k] = currMin + cost[i][j]
                    else:
                        curr[j][k] = currMin
            
            prev = curr
        
        res = curr[0][target-1]
        for i in range(n):
            res = min(res, curr[i][target-1])
        if res <= 1000000:
            return res
        else:
            return -1
                    

if __name__ == '__main__':
    sol = Solution()
    houses = [2, 3, 0]
    # houses = [0,0,0,0,0]
    cost = [[5,2,3],[3,4,1],[1,2,1]]
    m = 3
    n = 3
    target = 3
    
    print(sol.minCost(houses, cost, m, n, target))
    

# use dp check minimal cost for every color
# each house only consider the previous one, use arrays only for two houses to save space