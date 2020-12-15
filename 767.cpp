#include <iostream>
#include <algorithm>

#include <vector>

using namespace std;

void print(vector<int>& num){
	for (int i = 0; i < num.size(); i++){
		cout << num[i] << " ";
	}
	cout << endl;
}


class Solution {
public:
    string reorganizeString(string S) {
		
    }
};

int main() {
	vector<int> vec = {1,3,7,8,5,1,4,6,9,10};
	
	make_heap(vec.begin(), vec.end());
	print(vec);
	
	sort_heap(vec.begin(), vec.end());
	print(vec);
	
	return 0;
}
