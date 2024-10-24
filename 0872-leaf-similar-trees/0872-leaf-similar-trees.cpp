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
    vector<int> node1, node2;
    void getLeaf(TreeNode* node, vector<int>& nodes){
        if(node->left == nullptr && node->right == nullptr){
            nodes.push_back(node->val);
            return;
        }
        else if(node->left != nullptr && node->right == nullptr){
            return getLeaf(node->left,nodes);
        }
        else if(node->left == nullptr && node->right != nullptr){
            return getLeaf(node->right,nodes);
        }
        else if(node->left != nullptr && node->right != nullptr){
            getLeaf(node->left,nodes);
            getLeaf(node->right,nodes);
            return;
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        getLeaf(root1,node1);
        getLeaf(root2,node2);
        bool answer = true;
        //std::cout << node1.size() << "    " << node2.size() << std::endl;
        if(node1.size() != node2.size()){
            return false;
        }
        for(int i = 0; i < node1.size(); i++){
            
            //std::cout << node1[i] << "     " << node2[i] << std::endl;
            if(node1[i] != node2[i]){
                answer &= false;
            }
            else{
                answer &= true;
            }
            if(answer == false){
                break;
            }
        }
        return answer;
        
    }
    
};