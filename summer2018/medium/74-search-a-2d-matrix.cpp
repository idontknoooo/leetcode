class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (!matrix.size())
            return false;
        
        if (!matrix[0].size())
            return false;
        
        int m = matrix[0].size();
        
        
        int l = 0;
        int r = m * matrix.size() - 1;
        
        while (l < r) {
            int mid = (l + r)/2;
            
            if (matrix[mid/m][mid % m] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }

        }
        
        return matrix[r/m][r % m] == target;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0)
            return false;
        int br=matrix.size()-1,tr=0;
        int rc=matrix[tr].size()-1,lc=0;
        while(tr<=br) {
            int mr=(tr+br)/2;
            while(lc<=rc) {
                int mc=(lc+rc)/2;
                if (target==matrix[mr][mc])
                    return true;
                else if(target>=matrix[mr][lc]&&target<=matrix[mr][rc]) {
                    if(target<matrix[mr][mc])
                        rc=mc-1;
                    else if(target>matrix[mr][mc])
                        lc=mc+1;
                }
                else
                    break;
            }
            if(target<matrix[mr][lc]) {
                br=mr-1;
            }
            else if(target>matrix[mr][rc]) {
                tr=mr+1;
            }
            else break;
        }
        return false;
    }
};
