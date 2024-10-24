class Solution {
public:
    int answer = 0;  // Holds the longest ZigZag path length

    // DFS returns a pair: (longest path starting left, longest path starting right)
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {-1, -1};  // Base case: return -1 since we're counting edges
        }
        
        // Recursively get ZigZag paths from the left and right children
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        
        // Calculate longest ZigZag paths starting from this node
        int leftPath = left.second + 1;  // ZigZag path if we go left first
        int rightPath = right.first + 1; // ZigZag path if we go right first
        
        // Update the global answer with the maximum ZigZag length so far
        answer = std::max(answer, std::max(leftPath, rightPath));
        
        // Return the pair of values representing the current longest paths
        return {leftPath, rightPath};
    }
    
    int longestZigZag(TreeNode* root) {
        dfs(root);  // Perform DFS traversal starting from the root
        return answer;  // Return the maximum ZigZag path found
    }
};
