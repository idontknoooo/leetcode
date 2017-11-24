// My solution
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> level;
        vector<vector<int>> re;
        if(!numRows) return re;
        else
        {
            level.push_back(1);
            re.push_back(level);
            for(int i = 1; i < numRows; ++i)
            {
                vector<int> tmp = level;
                level.clear();
                for(int j = 0; j < tmp.size()+1; ++j)
                {
                    if(!j || j==tmp.size()) level.push_back(1);
                    else level.push_back(tmp[j]+tmp[j-1]);
                }
                re.push_back(level);
            }
        }
        return re;
    }
};
// Better solution 
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
		// Declare size in advance
        vector<vector<int>> r(numRows);
        for (int i = 0; i < numRows; i++) 
		{
			// Declare size in advance
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;

            for(int j = 1; j < i; j++)
                r[i][j] = r[i-1][j-1] + r[i-1][j];
        }
        return r;
    }
};

// Intuitive method
vector<vector<int>> generate(int numRows) {

    vector<vector<int> > level;
    // Only first two are not in pattern
    vector<int> level1 = {1};
    vector<int> level2 = {1,1};

    if(numRows<1) return level;
    level.push_back(level1);
    if(numRows==1) return level;
    level.push_back(level2);
    if(numRows==2) return level;

    // Pre store previous vector
    vector<int> pre = level2;
    for(int i = 2; i < numRows; ++i){
        vector<int> vec;
        vec.push_back(1);
        for(int j = 0; j < i-1; ++j){
            vec.push_back(pre[j]+pre[j+1]);
        }
        vec.push_back(1);
        pre = vec; // use previous vector to calculate current (vec)
        level.push_back(vec);
    }
    return level;
}