#include <iostream>
#include <vector>
#include <algorithm>

#define lowbit(k) k&-k

using namespace std;

bool comp(int a, int b){
	return a<b;
}

void print(vector<int>& num){
	for (int i = 0; i < num.size(); i++){
		cout << num[i] << " ";
	}
	cout << endl;
}

int binary(vector<int> & vec, int key){
	int st = 0,en = vec.size();
	int pos = 0;
	while (st <= en){
		int mid = (st+en)/2;
		if (vec[mid] == key){
			pos = mid;
			break;
		}else if (vec[mid] < key){
			st = mid;
		}else if (vec[mid] > key){
			en = mid;
		}
	}
	return pos+1;
}

class TreeArray{
	
public:
	TreeArray(vector<int> & vec){
		len = vec.size();
		tree = vector<int> (len+1,0);
		for (int i =0; i < len; i++)
			add(i+1,vec[i]);
		
		for (int i =1; i < len+1; i++)
			cout << tree[i] << " | ";
		
		cout << endl;
	}
	
	int find_range(int i, int j){
		return find(j) - find(i-1);
	}
		
	
	int find(int k){
		int sum=0;
		while(k)
		{
			sum+=tree[k];
			k-=lowbit(k);
		}
		return sum;
	}
	
	
	void add(int k , int num){
		while(k<=len+1)
		{
			tree[k]+=num;
			k+=lowbit(k);
			//cout << k << endl;
		}
	}
	

private:
	vector<int> tree;
	int len ;
};

class Solution {
private:
    vector<int> c;
    vector<int> a;

    void Init(int length) {
        c.resize(length, 0);
    }

    int LowBit(int x) {
        return x & (-x);
    }

    void Update(int pos) {
        while (pos < c.size()) {
            c[pos] += 1;
            pos += LowBit(pos);
        }
    }

    int Query(int pos) {
        int ret = 0;

        while (pos > 0) {
            ret += c[pos];
            pos -= LowBit(pos);
        }

        return ret;
    }

    void Discretization(vector<int>& nums) {
        a.assign(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
    }
    
    int getId(int x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> resultList;

        Discretization(nums);

        Init(nums.size() + 5);
        
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            int id = getId(nums[i]);
            resultList.push_back(Query(id - 1));
            Update(id);
        }

        reverse(resultList.begin(), resultList.end());

		print(resultList);
        return resultList;
    }
};


int main(){
	
	vector<int> vec = {1,5,6,7,8,9,4,2,3};
	vector<int> v1 = vec;
	
	TreeArray *a = new TreeArray(vec);
	Solution b;
	
	cout << a->find(5) << endl;
	cout << a->find_range(3,5) << endl;
	
	sort(v1.begin(), v1.end(), comp);
	
	//print(vec);
	//print(v1);
	
//	for (int j = 0; j< vec.size(); j++){
//		cout << binary(v1, vec[j]) << " * "; 
//	}
//	cout << endl;
	
	//cout << b.find(3, vec) << endl;
	
    vector<int> c = b.countSmaller(vec);
	
	return 0;
	
}
