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
    int answer = 0;
    //vector<int> sumNum;
    int target = -1;
    long long sumP(vector<long long>& vec){
        long long sums =0;
        for(long long i : vec){
            //std::cout<<i<< " ";
            sums += i;
        }
        //std::cout << std::endl;
        return sums;
    }
    void dfs(TreeNode* root, bool start, vector<long long>& sumNum){
        if(!sumNum.empty()){
            if(sumP(sumNum) == target){
                // for(int i :sumNum){
                //     std::cout << i << " ";
                // }
                // std::cout << std::endl;
                answer +=1;
            }
        }
        if(root == nullptr){
            return;
        }
        if(start){
            sumNum.push_back(root->val);
            dfs(root->left,true,sumNum);
            dfs(root->right,true,sumNum);
            sumNum.pop_back();
        }
        else{
            dfs(root->left,false,sumNum);
            dfs(root->left,true,sumNum);
            dfs(root->right,false,sumNum);
            dfs(root->right,true,sumNum);
        }
        return;
    }
    int pathSum(TreeNode* root, int targetSum){
        if(root == nullptr){
            return 0;
        }
        target = targetSum;
        vector<long long> sumNum;
        dfs(root, false, sumNum);
        dfs(root, true, sumNum);
        
        std::cout << answer << std::endl;
        return answer/2;
    }
};