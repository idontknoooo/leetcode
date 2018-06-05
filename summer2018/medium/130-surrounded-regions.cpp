// 21ms
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            check(board, i, 0);             // first column
            check(board, i, col - 1);       // last column
        }
        for (int j = 1; j < col - 1; ++j) {
            check(board, 0, j);             // first row
            check(board, row - 1, j);       // last row
        }
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '1') board[i][j] = 'O';
    }
    
    void check(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = '1';
            if (i > 1) check(board, i - 1, j);
            if (j > 1) check(board, i, j - 1);
            if (i + 1 < board.size()) check(board, i + 1, j);
            if (j + 1 < board[0].size()) check(board, i, j + 1);
        }
    }
};


// 19ms
class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j){
        if(board[i][j] != 'O') return;
        board[i][j] = '1';
        if(i+1 < board.size())
            dfs(board, i+1, j);
        if(j+1<board[0].size())
            dfs(board, i, j+1);
        if(i-1 >= 0)
            dfs(board, i-1, j);
        if(j-1 >= 0)
            dfs(board, i, j-1);
    }
    void solve(vector<vector<char>>& board) {
        if(board.size()==0) return;
        int row = board.size();
        int col = board[0].size();
        for(int i=0; i<row; i++){
            if(board[i][0] == 'O')
                dfs(board, i, 0);
            if(board[i][col-1]=='O')
                dfs(board, i, col-1);
        }
        for(int i=0; i<col; i++){
            if(board[0][i] =='O')
                dfs(board, 0, i);
            if(board[row-1][i] == 'O')
                dfs(board, row-1, i);
        }
       
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                //cout<<board[i][j]<<" ";
                if(board[i][j]=='1') board[i][j] = 'O';
                else if(board[i][j]=='O') board[i][j] = 'X';
            }
            //cout<<endl;
        }
        return;
    }
      
};
