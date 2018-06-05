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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> v;
        BFS(root,0,v);
        for(auto i =1 ;i<v.size();i++)
        {
            if(i%2==1)
                reverse(v[i].begin(),v[i].end());
        }
        return v;
    }
    
    void BFS(TreeNode* root,int level,vector<vector<int>> &v)
    {
        if(!root)
            return;
        if(level==v.size())
            v.push_back(vector<int>());
        v[level].push_back(root->val);
        BFS(root->left,level+1,v);
        BFS(root->right,level+1,v);
    }
};


// 4ms
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> levelT;
        if(!root)
        {
            return levelT;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool leftToRight=true;
        
        while(1)
        {
           int qSize=q.size();
            if(qSize==0)
            {
                break;
            }
            vector<int> temp(qSize);
            for(int i=0;i<qSize;i++)
            {
                TreeNode *root=q.front();
                q.pop();
                int index;
                if(leftToRight)
                {
                    index=i;
                }
                else
                {
                    index=qSize-i-1;
                }
                
                temp[index]=root->val;
                if(root->left)
                {
                    q.push(root->left);
                }
                if(root->right)
                {
                    q.push(root->right);
                }
            }
           
            leftToRight=!leftToRight;
            levelT.push_back(temp);
            
        }
        
        return levelT;
        
    }
};
