class Solution {
private:
    map<int, vector<int>> mappings;
    
	// Breadth-first search
    void do_bfs(TreeNode* node, int level){
        if(node == nullptr) return;
        
        mappings[level].push_back(node->val);
        
        do_bfs(node->left, level+1);
        do_bfs(node->right, level+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        do_bfs(root, 0);
        
        // Join all the vectors
        vector<vector<int>> ret;
        transform(mappings.begin(), mappings.end(), back_inserter(ret), [](auto& pair){ return std::move(pair.second); });
        
        return ret;
    }
};
