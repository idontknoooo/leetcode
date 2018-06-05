// 20ms
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() < 1 || board[0].size() < 1 || word.size() < 1)
            return false;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == word[0] && helper(board, word, 1, i, j))
                   return true;
            }
        }
        return false;
    }
    bool helper(vector<vector<char>> &board, string &word, int len, int row, int column)
    {
        if(len == word.size())
            return true;
        char tmp = board[row][column];
        board[row][column] = '@';
        if(row > 0 && board[row-1][column] == word[len] && helper(board, word, len+1, row-1, column))
            return true;
        if(column > 0 && board[row][column-1] == word[len] && helper(board, word, len+1, row, column-1))
           return true;
        if(row < board.size()-1 && board[row+1][column] == word[len] && helper(board, word, len+1, row+1, column))
            return true;
        if(column < board[0].size()-1 && board[row][column+1] == word[len] && helper(board, word, len+1, row, column+1))
            return true;
        board[row][column] = tmp;
        return false;
    }
};


// 19ms dfs
class Solution {
public:
  string w;
  int row,col,l;
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0)
        {
          if(word=="")
          return 1;
          else
          return 0;
    }
    w=word;
    row=board.size();
    col=board[0].size();
    l=word.length();
    for(int i=0;i<row;i++)
    {
      for(int j=0;j<col;j++)
      {
        if(board[i][j]==word[0])
        if(dfs(board,0,i,j))
        return true;
      }
    }
    return false;
    }
    bool dfs(vector<vector<char>>& board,int current,int r,int c)
    {
      
      if(l==current+1)
      return true;
      char s=board[r][c];
      board[r][c]='0';
      //cout<<r<<c<<endl;
      if(r+1<row&&board[r+1][c]==w[current+1])
    {
      if(dfs(board,current+1,r+1,c))
      return true;
    }
    if(r-1>=0&&board[r-1][c]==w[current+1])
    {
      if(dfs(board,current+1,r-1,c))
      return true;
    }
    if(c-1>=0&&board[r][c-1]==w[current+1])
    {
      if(dfs(board,current+1,r,c-1))
      return true;
    }
    if(c+1<col&&board[r][c+1]==w[current+1])
    {
      if(dfs(board,current+1,r,c+1))
      return true;
    }
    board[r][c]=s;
     return false;
  }
};
