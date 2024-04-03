# link: https://leetcode.com/problems/word-search/?envType=daily-question&envId=2024-04-03
# difficulty: medium
# date solved: april 3, 2024

class Solution:
    def seeker(self, board, word, row, col, idx, visited):
        if idx == len(word):
            return True

        if not (0 <= row < len(board)) or not (0 <= col < len(board[0])) or board[row][col] != word[idx] or visited[row][col]:
            return False

        visited[row][col] = True
        # Explore all four directions: up, down, left, right
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            if self.seeker(board, word, row + dx, col + dy, idx + 1, visited):
                return True

        visited[row][col] = False  # Backtrack
        return False

    def exist(self, board, word):
        rows, cols = len(board), len(board[0])
        visited = [[False for _ in range(cols)] for _ in range(rows)]

        for row in range(rows):
            for col in range(cols):
                if board[row][col] == word[0]:  # Optimization to start from the first letter of the word
                    if self.seeker(board, word, row, col, 0, visited):
                        return True

        return False


if __name__ == "__main__":
    sol = Solution()
    print(sol.exist(board=[["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]], word="ABCCED"))
    print(sol.exist(board=[["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]], word="SEE"))
    print(sol.exist(board=[["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]], word="ABCB"))
