class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> set;
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board[0].size(); ++j){
                char val = board[i][j];
                if (val == '.')
                    continue;
                int key[3];
                key[0] = (i+1) * 10 + val - '0'; // row
                key[1] = (j+1) * 100 + val - '0'; // column
                key[2] = ((i/3 * 3 + j/3) + 1) * 1000 + val - '0'; // box
                for (int k = 0; k < 3; ++k){
                    if (set.find(key[k]) == set.end())
                        set.insert(key[k]);
                    else
                        return false;
                }
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int used[9][9] = {0}, used1[9][9] = {0}, used2[9][9] = {0};
      
         for(int i = 0; i < board.size(); i++) {
             for(int j = 0; j < board[i].size(); j++) {
                 if(board[i][j] != '.') {
                     int num = board[i][j]-'0'-1;
                     int k = i/3*3 + j/3;
                     
                     if(used[i][num] || used1[j][num] || used2[k][num])
                         return false;
                     used[i][num] = used1[j][num] = used2[k][num] = 1;        
                 }
             }
         }
        return true;
    }
};
