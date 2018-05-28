/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        int count;
        double total;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(1){
            int n = q.size();
            if(n==0){
                break;
            }
            else{
                count = n;
                total = 0;
            }
            while(n>0){
                TreeNode* temp = q.front();
                q.pop();
                total += temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                n--;
            }
            ans.push_back(total/count);
        }
        return ans;
    }
};



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
        preorder(root,0);  //do pre order traversal
        for(int i=0; i<avg.size(); i++)  //avg change from running sum to average by dividing by # of elements. 
            avg[i] = avg[i]/num[i];
        return avg;
    }
    
    void preorder(TreeNode* root, int lvl)
    {
        if(!root) return;
        if(avg.size()<=lvl) avg.push_back(root->val), num.push_back(1); //if lvl doesn't exist, create it 
        else avg[lvl]+=root->val, ++num[lvl];  //avg here is the running sum, num is the number of elements in the running sum
        preorder(root->left, lvl+1);
        preorder(root->right, lvl+1);
    }
private:    
    vector<double> avg; 
    vector<int> num; //number of doubles in avg
    
};
