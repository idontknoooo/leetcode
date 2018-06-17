// There might be an iterative method to solve this, but it gonna be a lot of code, since there are 4 ways to start the search.
// 20ms
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() < 1 || board[0].size() < 1 || word.size() < 1)
            return false;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                // Search start from each position
                if(board[i][j] == word[0] && helper(board, word, 1, i, j))
                   return true;
            }
        }
        return false;
    }
    bool helper(vector<vector<char>> &board, string &word, int len, int row, int column)
    {
        // Check if satisfied
        if(len == word.size())
            return true;
        char tmp = board[row][column]; // Save value temporarily
        board[row][column] = '@'; // Mark as visited
        // Search in 4 directions
        if(row > 0 && board[row-1][column] == word[len] && helper(board, word, len+1, row-1, column))
            return true;
        if(column > 0 && board[row][column-1] == word[len] && helper(board, word, len+1, row, column-1))
           return true;
        if(row < board.size()-1 && board[row+1][column] == word[len] && helper(board, word, len+1, row+1, column))
            return true;
        if(column < board[0].size()-1 && board[row][column+1] == word[len] && helper(board, word, len+1, row, column+1))
            return true;
        board[row][column] = tmp;   // Recover value
        return false;
    }
};


