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
    	if (!root) return 0;
		m_h = get_high(root);
		if (m_h == 1) return m_h;
		m_result = pow(2,m_h-1) - 1;
		m_signal = false;
		dfs(root, 1);
		
		return m_result;
    };
    
    void dfs(TreeNode* root, int deep){
    	if (!m_signal){
    		if(deep+1 == m_h){
    			if (root->left) 
					m_result++;
    			else
    				m_signal = true;
    			if (root->right) 
					m_result++;
    			else
    				m_signal = true;
			}else{
				dfs(root->left, deep+1);
				dfs(root->right, deep+1);
			}
		}
	};
    
    int get_high(TreeNode* root){
    	int h = 1;
    	TreeNode *l = root->left; 
    	while(l){
    		h++;
    		l = l->left;
		}
		cout << "high:" << h << endl;
		return h;
	};

private:
	bool m_signal;
	int m_h;
	int m_result;
    
};
