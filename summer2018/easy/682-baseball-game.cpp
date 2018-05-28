// My solution 10ms
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> score;
        for(int i = 0; i < ops.size(); ++i) {
            if(ops[i][0] == 'C') 
                score.pop_back();
            else if(ops[i][0] == 'D') 
                score.push_back(2*score.back());
            else if(ops[i][0] == '+')
                score.push_back(score.back() + score[score.size()-2]);
            else 
                score.push_back(stoi(ops[i]));
        }
        return accumulate(score.begin(), score.end(), 0);
    }
};
