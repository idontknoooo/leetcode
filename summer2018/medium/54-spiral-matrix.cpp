// Recursive
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //旋转输出
        //起始点坐标开始迭代
        // m*n的矩阵
        //c++中临时变量不能作为非const的引用参数
        //引用绑定到类型为“struct value_type”的空指针。
        vector<int> rnt;
        int m = matrix.size();     //行数
        if ( m == 0 ) return rnt;  //*******************matrix为空则没有matrix[0]
        int n = matrix[0].size();  //列数
        help(matrix, 0, 0, rnt, m, n);
        return rnt;
    }
    void help(vector<vector<int>>& matrix, int minrow, int mincol, vector<int>& res, int maxrow, int maxcol){
        if( minrow < maxrow && mincol < maxcol ) //有新的一行
        {
            for( int i = mincol; i < maxcol; i++ )          //左->右
                res.push_back(matrix[minrow][i]);
            for( int i = minrow + 1; i < maxrow; i++ )      //右->下
                res.push_back(matrix[i][maxcol-1]);
            if ( minrow < maxrow - 1 && mincol < maxcol - 1)           //有新的两行
            {
                for( int i = maxcol - 2; i >= mincol; i-- )         //右->左
                    res.push_back(matrix[maxrow-1][i]);
                for( int i = maxrow - 2; i >= minrow + 1; i-- )     //下->上
                    res.push_back(matrix[i][mincol]);
            }
            help(matrix, minrow+1, mincol+1, res, maxrow-1, maxcol-1);
        }
        return;
    }
};


// Non recursive
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans ;
        int R = matrix.size();
        if(R==0)
            return ans;
        int C = matrix[0].size();
        int b_r = 0, b_c = 0, e_r =R-1, e_c = C-1;
        
        while(b_r<=e_r && b_c<=e_c)
        {
            for(int i=b_c;i<=e_c;i++)
                ans.push_back(matrix[b_r][i]);
            b_r ++;
            
            for(int i=b_r;i<=e_r; i++)
                ans.push_back(matrix[i][e_c]);
            e_c--;
            
            for(int i=e_c;i>=b_c&&b_r<=e_r;i--)
                ans.push_back(matrix[e_r][i]);
            e_r --; 
            
            for(int i=e_r;i>=b_r&&b_c<=e_c;i--)
                ans.push_back(matrix[i][b_c]);
            b_c ++; 
        }
        
        return ans;
    }
};
