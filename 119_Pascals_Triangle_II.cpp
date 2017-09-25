// My solution
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> re(rowIndex+1);
        re[0] = 1; // Most left is 1
        if(!rowIndex) return re; // Level0: [1]
        for(int i = 1; i < rowIndex+1; ++i)
        {
            int tmp = re[0];
            for(int j = 1; j < i+1; ++j) // length for current level is i+1
            {
				// Most right is 1
                if(j == i)
                    re[j] = 1;
                else
                { 
					// Replace re[j] with re[j]+tmp, where tmp=re[j-1], [j-1] will be replace by last iteration, thus use tmp to store it
                    int num_val = tmp + re[j];
                    tmp = re[j];
                    re[j] = new_val;
                }
            }
        }
        return re;
    }
};

// A nicer solution, start from the end
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vi(rowIndex + 1);
       	vi[0] = 1;
        for (int i = 0; i <= rowIndex ; ++i)
        {
			// Start from the end
        	for (int j = i; j > 0; --j)
        	{
				// Eliminate the replace problem from my method
	        	vi[j] = vi[j] + vi[j-1];
        	}
        }
        return vi;
    }
};
