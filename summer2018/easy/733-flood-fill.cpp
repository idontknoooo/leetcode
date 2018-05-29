// My solution 45 ms
class Solution {
public:
    void fill(vector<vector<int> >& image, int sr, int sc, int cur) {
        if(sr >= 0 && sc >= 0 && sr < image.size() && sc < image[sr].size() && image[sr][sc] == cur) {
            image[sr][sc] = -1;
            fill(image, sr+1, sc, cur);
            fill(image, sr-1, sc, cur);
            fill(image, sr, sc+1, cur);
            fill(image, sr, sc-1, cur);
        } 
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int cur = image[sr][sc];
        fill(image, sr, sc, cur);
        for(int i = 0; i < image.size(); ++i){
            for(int j = 0; j < image[i].size(); ++j)
                if(image[i][j]==-1) image[i][j] = newColor;
        }
        return image;
    }
};
// My modified solution
class Solution {
public:
    void fill(vector<vector<int> >& image, int sr, int sc, int newColor, int cur) {
        if(sr >= 0 && sc >= 0 && sr < image.size() && sc < image[sr].size() && image[sr][sc] == cur) {
            image[sr][sc] = newColor;
            fill(image, sr+1, sc, newColor, cur);
            fill(image, sr-1, sc, newColor, cur);
            fill(image, sr, sc+1, newColor, cur);
            fill(image, sr, sc-1, newColor, cur);
        } 
        return ;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int cur = image[sr][sc];
        if(cur != newColor)
            fill(image, sr, sc, newColor, cur);
        return image;
    }
};


// 31ms
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.size() == 0) return image;
        if (image[sr][sc] == newColor) return image;
        int prev = image[sr][sc];
        image[sr][sc] = newColor;
        if (sr != 0 && image[sr-1][sc] == prev)
            floodFill(image, sr-1, sc, newColor);
        if (sc != 0 && image[sr][sc-1] == prev)
            floodFill(image, sr, sc-1, newColor);
        if (sr != image.size()-1 && image[sr+1][sc] == prev)
            floodFill(image, sr+1, sc, newColor);
        if (sc != image[sr].size()-1 && image[sr][sc+1] == prev)
            floodFill(image, sr, sc+1, newColor);
        return image;
    }
};
