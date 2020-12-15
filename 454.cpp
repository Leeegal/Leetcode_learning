#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int len = A.size();
		init();
		int result = 0;
		for (int i = 0; i < len; i++){
			for (int j = 0; j < len; j++){
				update(A[i]+B[j]); 
			} 
		}
		for (int i = 0; i < len; i++){
			for (int j = 0; j < len; j++){
				result += get_value(-(C[i]+D[j]));  
			} 
		}
		return result;
    };

	void init()	{
		vec_list.resize(500);
	};

	void update(int key){
		mmap[key] += 1;
//		int index = abs(key % 500);
//		list<int> li = vec_list[index]; 
//		li.push_front(key);
//		vec_list[index] = li;
	};
	
	int get_value(int key){
		return mmap[key];
//		int index = abs(key % 500);
//		list<int> li = vec_list[index]; 
//		return count(li.begin(), li.end(), key);
		
	}

private:
	unordered_map<int, int> mmap;
	vector<list<int>> vec_list;
};
/*
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
*/
int main(){
	Solution s;
	vector<int> a = {1,2}, b = {-1,-1}, c= {-1,2}, d = {0,2};
	cout << s.fourSumCount(a,b,c,d) << endl;
	return 0;
}
