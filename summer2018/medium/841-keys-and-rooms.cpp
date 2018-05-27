class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> s;
        queue<int> q;
        for(int i = 0; i < rooms[0].size(); ++i){
            q.push(rooms[0][i]);
        }
        while(q.size()){
            int tmp = q.front();
            q.pop();
            if(s.find(tmp) == s.end()){
                for(int i = 0; i < rooms[tmp].size(); ++i){
                    q.push(rooms[tmp][i]);
                }
                s.insert(tmp);
            }
        }
        vector<int> vec;
        for(int i = 1; i < rooms.size(); ++i) vec.push_back(i);
        vector<int> s_vec(s.begin(), s.end());
        return s_vec == vec;
    }
};
