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
    int matrixScore(vector<vector<int>>& A) {
		if (A.empty()){
			return 0;
		}
		
		return do_business(A);
    };

    void change(vector<vector<int>>& A, int k, bool row_flag){
		if (row_flag)
		{
			int len = A[0].size();
			for (int i = 0; i < len; i++)
			{
				A[k][i] = !A[k][i];
			}
		}
		else
		{
			int len = A.size();
			for (int i = 0; i < len; i++)
			{
				A[i][k] = !A[i][k];
			}
		}
	};

	int count(vector<vector<int>>& A)
	{
		int sum = 0;
		int row_len = A.size();
		int col_len = A[0].size();
		for (int i = 0; i < row_len; i++ )
		{
			for (int j = 0; j < col_len; j++)
			{
				sum += (A[i][j] == 1) ? pow(2,col_len - j -1) : 0;			
			}
		}

		return sum;
	};

	int do_business(vector<vector<int>>& A)
	{
		
		int row_len = A.size();
		int col_len = A[0].size();
		
		if (check_col_invalid(A,0))
		{
			change(A, 0, false);
		}
		for (int i = 0; i < row_len; i++ )
		{
			if (!A[i][0])
			{
				change(A, i, true);	
			}
		}
	
		for (int j = 1; j < col_len; j++)
		{
			if (check_col_invalid(A,j)){
				change(A, j, false);	
			}
		}
	
		return count(A);
	};

	bool check_col_invalid(vector<vector<int>>& A, int j)
	{
		int row_len = A.size();
		int count = 0;
		
		for (int i = 0; i < row_len && j < A[i].size(); i++ )
		{	
			count += A[i][j];
		}
		
		cout << "j:" << j  << count << endl;
		return count <= row_len/2;
	};

};

int main(){
	vector<int> l1 = {0};
	//vector<int> l2 = {1,0,1,0};
	//vector<int> l3 = {1,1,0,0};
	vector<vector<int>> vec;
	vec.push_back(l1);
	//vec.push_back(l2);
	//vec.push_back(l3);
	
	Solution b;
	cout << b.matrixScore(vec) << endl;
	
	int x = 1, y =0;
	cout << (!x) << endl;
	cout << (!y) << endl;
}
