/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> nodes;
    int cnt = 0;
    void valsInPath(TreeNode* node, vector<int>& vec){
        // auto it = std::lower_bound(vec.begin(), vec.end(), node->val);
        // if(it == vec.end()){
        //     //meaning there is nothing greater from the path
        //     cnt +=1;
        //     std::cout << node->val << std::endl;
        // }
        bool flag = true;
        for(int i = 0; i <vec.size(); i++){
            if(vec[i] > node->val){
                flag &= false;
                break;
            }
            else{
                flag &= true;
            }
        }
        if(flag){
            cnt +=1;
        }
        
        if(node->left == nullptr && node->right == nullptr){
            
            return;
        }
        else if(node->left != nullptr && node->right == nullptr){
            vec.push_back(node->val);
            valsInPath(node->left,vec);
            vec.pop_back();
            return;
        }
        else if(node->left == nullptr && node->right != nullptr){
            vec.push_back(node->val);
            valsInPath(node->right,vec);
            vec.pop_back();
            return;
        }
        else{
            vec.push_back(node->val);
            valsInPath(node->left,vec);
            valsInPath(node->right,vec);
            vec.pop_back();
            return;
        }
    }
    int goodNodes(TreeNode* root) {
        valsInPath(root, nodes);
        return cnt;
    }
};