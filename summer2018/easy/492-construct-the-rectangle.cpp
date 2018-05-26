class Solution {
public:
    vector<int> constructRectangle(int area) {
        int tmp = floor(sqrt(area));
        while(area%tmp!=0) --tmp;
        return {area/tmp, tmp};
    }
};
