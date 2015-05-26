#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

vector<int> merge(vector<int> &left, vector<int> &right) {
	const int total = left.size() + right.size();
	vector<int> res(total, 0);
	auto il =  left.begin(), ir = right.begin(); 
	int k = 0;
	while (il < left.end() && ir < right.end()) {
       if (*il < *ir) {
		   res[k++] = *il;
		   il++;
	   } else { 
		   res[k++] = *ir;
		   ir++;
	   }
	}
	if (il < left.end()) copy(il, left.end(), res.begin()+k);
	else copy(ir, right.end(), res.begin()+k);
    assert(int(res.size()) == total);	
	return res;
}

vector<int> mergeSort(vector<int> &num, int start, int last) {
	const int size_n = last - start + 1;
    if (size_n == 1) return vector<int>{num[start]};	
	vector<int> left = mergeSort(num, start, start + size_n /2 - 1);
	vector<int> right = mergeSort(num, start + size_n / 2, last);
	return merge(left, right);
}

template <class T>
void dump_vector(const vector<T> &vec) {
	cout << "I am dumping vector as : "<< endl;
	for (auto item : vec) {
		cout << item << " ";
	}
	cout << endl;
}
int main(void) {
	//vector<int> nums = {9,7};
	vector<int> nums = {3,5,1,2,5,6,4,9,8,7};
	cout << "before sort!" << endl;
	dump_vector(nums);
	nums = mergeSort(nums, 0, nums.size()-1);
	cout << "after sort!" << endl;
	dump_vector(nums);
    return 0;
}
