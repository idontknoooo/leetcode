// with explaination
// You don't need to know the order of each node, all you need to know is that what nodes are on left(right) subtree. Then build them recursively.
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
    vector<TreeNode*> doGenTree( int begin, int end ) {
       vector<TreeNode*> ret;
       if( begin > end ) return ret; // Break condition
       if( begin == end ) ret.push_back(new TreeNode(begin)); // if same nodes
       else {
         // Iterate through each node between begin & end, each of these can be used as a root
         // then recursively build tree
         for(int mid = begin; mid <= end; mid++ ) {
           auto leftNodes  = doGenTree(begin, mid-1); // valid left  nodes for current begin & end
           auto rightNodes = doGenTree(mid+1, end);   // valid right nodes for current begin & end
  
           if(leftNodes.empty())  leftNodes.push_back(nullptr);
           if(rightNodes.empty()) rightNodes.push_back(nullptr);
  
           for( const auto ln : leftNodes ) {
             for( const auto rn : rightNodes ) {
               // create subtree for current node, add all valid left & right tree to it
               TreeNode* newP = new TreeNode(mid); 
               newP->left = ln;
               newP->right = rn;
               // add valid subtree to "valid-subtree-vector-for-current-node"
               ret.push_back(newP);
             }
           }
         }
       }
       return ret;
    }

    vector<TreeNode*> generateTrees(int n) {
      return doGenTree(1, n);
    }
};

// 16ms beat 98%
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        unordered_map<int, unordered_map<int, vector<TreeNode *>>> mp;
        return solve(1, n, mp);
    }
    
    vector<TreeNode *> solve(int n1, int n2, unordered_map<int,  unordered_map<int, vector<TreeNode *>>> &mp) {
        if (n1 > n2) return {nullptr};
        if (n1 == n2) return {new TreeNode(n1)};
        vector<TreeNode *> ans;
        if (mp.find(n1) != mp.end() and mp[n1].find(n2) != mp[n1].end()) return mp[n1][n2];
        for(int i=n1; i<=n2; i++) {
            vector<TreeNode *> left = solve(n1, i - 1, mp);
            vector<TreeNode *> right = solve(i + 1, n2, mp);
            for (auto l: left) {
                for (auto r: right){
                    TreeNode *nd = new TreeNode(i);
                    nd->left = l;
                    nd->right = r;
                    ans.push_back(nd);
                }
            }
        }
        mp[n1][n2] = ans;
        return ans;
    }
};

