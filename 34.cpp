#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

//        if (lower_bound(nums.begin(), nums.end(), target) != a.end()){
//			ans.push_back(lower_bound(nums.begin(), nums.end(), target) - nums.begin());
//		}else{
//			ans.push_back(-1);
//		}
//		
//		if (upper_bound(a.begin(), a.end(), 6) != a.end()){
//			cout << lower_bound(a.begin(), a.end(), 6) - a.begin()  << endl;
//		}else{
//			ans.push_back(-1);
//		}
//		return ans;
    }
};

//ÊäÈë£ºnums = [5,7,7,8,8,10], target = 8
//Êä³ö£º[3,4]
int main(){
	
	vector<int> a = {1,5,6,7,8,9,4,2,3};
	
	if (lower_bound(a.begin(), a.end(), 6) != a.end()){
		cout << lower_bound(a.begin(), a.end(), 7.5) - a.begin()  << endl;
	}else{
		
	}
	
	return 0;
	
}
