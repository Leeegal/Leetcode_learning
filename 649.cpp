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
    string predictPartyVictory(string senate) {
    	if (senate.empty()) return senate;
    	
		string r = "Radiant";
		string d = "Dire";
		int len = senate.size(); 
		vector<int> vis(len,0);
		int r_count = count(senate.begin(), senate.end(), 'R');
		int d_count = count(senate.begin(), senate.end(), 'D');
		if (r_count == 0 || d_count >= 2*r_count) return d;
		if (d_count == 0 || r_count >= 2*d_count) return r;
		
		
		int pre_r = 0;
		int pre_d = 0;
		
		int step = 0;
		while(d_count != 0 && r_count != 0){
			//cout << senate[step] << endl;
			if (vis[step] == 0){
				if (senate[step] == 'R'){
					if (pre_d > 0){
						vis[step] = 1;
						r_count--;
						pre_d--;
					}else{
						pre_r++;
					}
				}else{
					if (pre_r > 0){
						vis[step] = 1;
						d_count--;
						pre_r--;
					}else{
						pre_d++;
					}
				}
				cout << "pre:" << pre_r << endl;
			}
			step += 1;
			if(step >= len) step = 0;
			//cout << "step:" << step << endl;
			//print(vis); 
			//count++;
		}
	
		if (r_count == 0 ) return d;
		if (d_count == 0 ) return r;
	
		return  r;
    }

};


int main(){
	string req = "DDRRDDRD";
	
	Solution b;
	cout << b.predictPartyVictory(req) << endl;
	
	return 0; 
};
