// My solution 24ms
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    // Save in hash_map and use queue to count total importance
    int getImportance(vector<Employee*> employees, int id) {
        queue<int> ids;
        unordered_map<int, Employee*> um;
        for(int i = 0; i < employees.size(); ++i){
            um[employees[i]->id] = employees[i];
            
        ids.push(id);
        int sum = 0;
        while(ids.size()) {
            int tmp_id = ids.front();
            ids.pop();
            sum += um[tmp_id]->importance;
            vector<int> tmp_vec = um[tmp_id]->subordinates;
            for(int i = 0; i < tmp_vec.size(); ++i)
                ids.push(tmp_vec[i]);
        }
        return sum;
    }
};

// 21ms
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
    int dfs(Employee* ptrs[2000], int id) {
        int sum = ptrs[id]->importance;
        for (int i = 0; i < ptrs[id]->subordinates.size(); i++)
            sum += dfs(ptrs, ptrs[id]->subordinates[i]);
        return sum;
    }
    
public:
    int getImportance(vector<Employee*> employees, int id) {
        Employee* ptrs[2000] = {nullptr};
        for (int i = 0; i < employees.size(); i++)
            ptrs[employees[i]->id] = employees[i];
        return dfs(ptrs, id);
    }
};
