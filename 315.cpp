#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
    	int len = nums.size();
		vector<int> count(len,0);
    	
    	
		return count;
    }
};

int main(){
	Solution x;
	
	vector<int> li = {5,2,6,1,0,7,10,3};
	
	li = x.countSmaller(li);
	
	for (int i = 0; i < li.size(); i++)
	{
		cout << li[i] << " ";
	}
	
	return 0;
	
}
