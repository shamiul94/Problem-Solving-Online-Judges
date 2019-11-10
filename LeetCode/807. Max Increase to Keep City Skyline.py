import math


class Solution(object):
    def maxIncreaseKeepingSkyline(self, grid):
        rowMaxList = []
        columnMaxList = []
        inf = math.inf
        originalGrid = [row[:] for row in grid]
        newGrid = [[inf for i in range(len(grid))] for j in range(len(grid[0]))]

        for row in originalGrid:
            rowMaxList.append(max(row))

        for j in range(len(originalGrid[0])):
            maximum = 0
            for i in range(len(originalGrid)):
                maximum = max(maximum, originalGrid[i][j])
            columnMaxList.append(maximum)

        for i in range(len(rowMaxList)):
            for j in range(len(columnMaxList)):
                newGrid[i][j] = min(newGrid[i][j], rowMaxList[i], columnMaxList[j])

        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                ans += (newGrid[i][j] - originalGrid[i][j])

        return ans


if __name__ == "__main__":
    grid = [
        [3, 0, 8, 4],
        [2, 4, 5, 7],
        [9, 2, 6, 3],
        [0, 3, 1, 0]
    ]

    # grid[:, 1]
    soln = Solution()
    print(soln.maxIncreaseKeepingSkyline(grid))
    test = 999999999999999999999999999999999999
    print(test)
