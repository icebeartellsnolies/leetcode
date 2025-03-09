#include <iostream>
#include <vector>
using namespace std;
/*
    AUTHOR     - Prince Sharma
    DATE       - 6/2/2025 14:25
    PROBLEM    - N-Queens
    NOTATION   - O -> worst case complexcity, S -> for space complexity, T -> for time complexity, n -> board height and board width, ^ -> power
    COMPLEXITY - TO(n^n), SO(n^n)
*/

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> possibilities;
        vector<string> board(n);
        empty_board(board);
        solve_board(board, n, possibilities);
        return possibilities;
    }
private:
    void empty_board(vector<string>& board)
    {
        int max_height=board.size();
        string empty_row;
        for(int width=0; width<max_height; width++) empty_row+='.';
        for(int height=0; height<max_height; height++) board[height] = empty_row;
    }

    void solve_board(vector<string>& board, int& n, vector<vector<string>>& possibilities, int iteration=0)
    {
        if(iteration>=n) {possibilities.emplace_back(board); return;}
        for(int row=0; row<n; row++)
        {
            if(can_put(board, row, iteration))
            {
                board[row][iteration]='Q';
                solve_board(board, n, possibilities, iteration+1);
                board[row][iteration]='.';
            }
        }
    }

    bool can_put(vector<string>& board, int row, int column)
    {
        int rows=board.size(), columns=board[0].size();
        // Top left
        for(int temp_row=row, temp_column=column; temp_row>=0 && temp_column>=0; temp_row--, temp_column--)
            if(board[temp_row][temp_column]=='Q') return false;
        // Same column
        for(int temp_column=column; temp_column>=0; temp_column--)
            if(board[row][temp_column]=='Q') return false;
        // Bottom left
        for(int temp_row=row, temp_column=column; temp_row<rows && temp_column>=0; temp_row++, temp_column--)
            if(board[temp_row][temp_column]=='Q') return false;
        return true;
    }
};

class Solution {
    public:
        // Function to solve the N-Queens problem
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> ans;  // To store the final solutions (boards)
            vector<string> board(n);  // To represent the chessboard. Each element will be a row of the board
            string s(n, '.');  // Create a string of length n filled with '.' representing empty spaces on the board
            
            // Initialize each row of the board as empty
            for (int i = 0; i < n; i++) {
                board[i] = s;  // Each row is initially empty ('.')
            }
    
            // Calls the recursive function `solve` to start solving the N-Queens problem
            // The first column (col=0) is considered. The board is passed as an argument and `ans` stores the valid solutions
            solve(0, board, ans, n); 
            
            // After solving, return all valid board configurations
            return ans;
        }
    
        // Recursive function that tries placing queens column by column
        void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
            // Base case: If all queens are placed (col reaches n), store the board configuration in the answer
            if (col == n) {
                ans.push_back(board);  // A valid board configuration is found, so push it to the ans vector
                return;  // Return to backtrack and explore other possibilities
            }
    
            // Try placing a queen in each row of the current column (col)
            for (int row = 0; row < n; row++) {
                // Check if it's safe to place a queen at (row, col) using the helper function isSafe
                if (isSafe(row, col, board, n)) {
                    // If placing a queen at (row, col) is safe, place it
                    board[row][col] = 'Q';  // Mark the cell as occupied by a queen
                    
                    // Recursively try to place a queen in the next column (col+1)
                    solve(col + 1, board, ans, n); 
                    
                    // Backtrack: Remove the queen and try another position in the current column
                    board[row][col] = '.';  // Reset the cell to empty
                }
            }
        }
    
        // Helper function to check if placing a queen at (row, col) is safe
        bool isSafe(int row, int col, vector<string>& board, int n) {
            int i = row;  // Save the original row value
            int j = col;  // Save the original column value
    
            // Check the upper-left diagonal (left side)
            while (row >= 0 && col >= 0) {
                if (board[row][col] == 'Q') {  // If a queen is found, return false (unsafe)
                    return false;
                }
                row--;  // Move up diagonally
                col--;  // Move left diagonally
            }
    
            // Reset row and column to check the same row on the left side
            row = i;
            col = j;
            
            // Check the same row on the left side
            while (col >= 0) {
                if (board[row][col] == 'Q') {  // If a queen is found, return false (unsafe)
                    return false;
                }
                col--;  // Move left in the same row
            }
    
            // Reset row and column to check the lower-left diagonal
            row = i;
            col = j;
    
            // Check the lower-left diagonal (left side)
            while (row < n && col >= 0) {
                if (board[row][col] == 'Q') {  // If a queen is found, return false (unsafe)
                    return false;
                }
                row++;  // Move down diagonally
                col--;  // Move left diagonally
            }
    
            return true;  // If no queens were found in the checked areas, it's safe to place the queen
        }
    };

class Solution {
    public:
        bool is_safe(vector<string>&board, int row, int col, int n){
            for(int j=0; j<n; j++){
                if(board[row][j]=='Q')
                    return false;
            }

            for(int i=0; i<n;i++){
                if(board[i][col]=='Q')
                    return false;
            }

            for(int i=row, j=col;i>=0 && j>=0;i--,j--){
                if (board[i][j]=='Q')
                    return false;
            }

            for(int i=row, j=col;i>=0 && j<n;i--,j++){
                if(board[i][j]=='Q')
                    return false;
            }
            return true;
        }
        void n_queens(vector<string>&board, int row, int n,vector<vector<string>> &ans){
            if (row==n){
                ans.push_back(board);
                return;
            }

            for(int i=0; i<n;i++){
                if(is_safe(board, row,i,n)){
                    board[row][i]='Q';
                    n_queens(board, row+1,n,ans);
                    board[row][i]='.';
                }
            }
        }

        vector<vector<string>> solveNQueens(int n) {
            vector <string> board;
            vector<vector<string>> ans;

            n_queens(board, 0, n, ans);
            return ans;
        }
    };