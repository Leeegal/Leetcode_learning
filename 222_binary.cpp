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
		m_result = 0;
		m_signal = false;
		binary(root, 0);
		
		return m_result;
    };
    
    void binary(TreeNode* root, int deep){
    	if (get_right_high(root) + deep == m_h){
    		m_result+=pow(2,m_h-deep) -1;
		}else{
			m_result+=1;
			if (root->left) binary(root->left, deep+1);
			if (root->right) binary(root->right, deep+1);
		}
	}
    
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
	
	int get_right_high(TreeNode* root){
    	int h = 1;
    	TreeNode *l = root->right; 
    	while(l){
    		h++;
    		l = l->right;
		}
		cout << "high:" << h << endl;
		return h;
	};


private:
	bool m_signal;
	int m_h;
	int m_result;
   
}
