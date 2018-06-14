// 34ms beat 100%
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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int level = -1;
        int ans = 0;
        TreeNode* node = root;
        while (node){
            level++;
            node = node->left;
        }
        if(level==0) return 1;
        ans += pow(2,level)-1;
        //cout<<ans<<endl;
        TreeNode* tmp_root = root;
        int tmp_root_cnt = 0;
        int cur_cnt = 0;

        while(tmp_root_cnt<level-1){
            cur_cnt = tmp_root_cnt;
            node = tmp_root;
            node = node->right;
            cur_cnt++;
            while(node->left){
                node = node->left;
                cur_cnt++;
            }
            //cout<<cur_cnt<<endl;
            // left part
            if(cur_cnt != level){
                tmp_root = tmp_root->left;
                tmp_root_cnt++;
            }
            else{
                tmp_root = tmp_root->right;
                ans+= pow(2,level - tmp_root_cnt -1);
                tmp_root_cnt++;
            }
        }
        
        if(tmp_root->left) ans++;
        if(tmp_root->right) ans++;
        return ans;
    }
};

// 142ms
class Solution {

public:

    int countNodes(TreeNode* root) {

        if(!root) return 0;

        int hl=0, hr=0;

        TreeNode *l=root, *r=root;

        while(l) {hl++;l=l->left;}

        while(r) {hr++;r=r->right;}

        if(hl==hr) return pow(2,hl)-1;

        return 1+countNodes(root->left)+countNodes(root->right);

    }

};
