class Solution {
public:
    int answer = 0;
    int target = -1;
    
    // Calculate sum of the current path and return the total number of valid paths
    void dfs(TreeNode* root, long long currentSum, vector<long long>& sumNum) {
        if (root == nullptr) {
            return;
        }

        // Add current node value to the path sum
        currentSum += root->val;
        sumNum.push_back(root->val);
        
        // Check if the current path sum equals the target
        if (currentSum == target) {
            answer++;
        }
        
        // Continue DFS for left and right children
        dfs(root->left, currentSum, sumNum);
        dfs(root->right, currentSum, sumNum);
        
        // Backtrack by removing the last element from the path
        sumNum.pop_back();
    }

    // Start DFS from each node
    void startFromNode(TreeNode* node) {
        if (node == nullptr) return;
        
        vector<long long> sumNum;  // Store the current path
        dfs(node, 0, sumNum);  // Perform DFS starting from the current node
        
        // After processing the current node, recursively start DFS from its children
        startFromNode(node->left);
        startFromNode(node->right);
    }

    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        startFromNode(root);  // Start DFS from every node
        return answer;
    }
};
