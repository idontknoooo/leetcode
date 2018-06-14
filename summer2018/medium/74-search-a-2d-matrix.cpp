// binary search | serilized vector
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (!matrix.size() || !matrix[0].size())
            return false;
        
        int m = matrix[0].size();
        int l = 0;
        int r = m * matrix.size() - 1;
        
        while (l + 1 < r) {
            int mid = (l + r)/2;
            if (matrix[mid/m][mid % m] < target) {
                l = mid;
            } else {
                r = mid;
            }

        }
        if(matrix[r/m][r%m] == target || matrix[l/m][l%m] == target) return true;
        else return false;
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

// my solution 13ms beat 78% | 2 binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size() || !matrix[0].size()) return false;
        int low = 0, high = matrix.size(), mid = low + (high-low)/2;
        while(low + 1 < high) {
            mid = low + (high-low)/2;
            if(target == matrix[mid][0]) return true;
            else if(target < matrix[mid][0]) high = mid;
            else low = mid;
        }
        int row = 0;
        if(high < matrix.size() && matrix[high][0] < target) row = high;
        else {
            if(matrix[low][0] > target) return false;
            else row = low;
        }
        int left = 0, right = matrix[0].size();
        while(left + 1 < right) {
            mid = left + (right-left)/2;
            if(target == matrix[row][mid]) return true;
            else if(target < matrix[row][mid]) right = mid;
            else left = mid;
        }
        if(matrix[row][left] == target || matrix[row][right] == target) return true;
        else return false;
    }
};
