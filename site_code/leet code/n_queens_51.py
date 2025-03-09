class Solution:
    def is_safe(self, board, row, col, n):
        # Check the row
        for j in range(n):
            if board[row][j] == 'Q':
                return False

        # Check the column
        for i in range(n):
            if board[i][col] == 'Q':
                return False

        # Check the upper-left diagonal
        i, j = row, col
        while i >= 0 and j >= 0:
            if board[i][j] == 'Q':
                return False
            i -= 1
            j -= 1

        # Check the upper-right diagonal
        i, j = row, col
        while i >= 0 and j < n:
            if board[i][j] == 'Q':
                return False
            i -= 1
            j += 1

        return True

    def n_queens(self, board, row, n, ans):
        if row == n:
            ans.append([row[:] for row in board])
            return

        for i in range(n):
            if self.is_safe(board, row, i, n):
                board[row][i] = 'Q'
                self.n_queens(board, row + 1, n, ans)
                board[row][i] = '.'

    def solveNQueens(self, n):
        board = [['.' for _ in range(n)] for _ in range(n)]
        ans = []
        self.n_queens(board, 0, n, ans)
        return ans

def main():
    solution = Solution()
    n = 4
    result = solution.solveNQueens(n)

    # Print all solutions
    for i, board in enumerate(result):
        print(f"Solution {i + 1}:")
        for row in board:
            print(row)
        print()


if __name__ == "__main__":
    main()