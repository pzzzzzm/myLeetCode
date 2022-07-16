# There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that have been painted last summer should not be painted again.

# A neighborhood is a maximal group of continuous houses that are painted with the same color.

# For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2}, {3,3}, {2}, {1,1}].
# Given an array houses, an m x n matrix cost and an integer target where:

# houses[i]: is the color of the house i, and 0 if the house is not painted yet.
# cost[i][j]: is the cost of paint the house i with the color j + 1.

# Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods. If it is not possible, return -1.

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