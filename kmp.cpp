#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> KMP(string S, string K) {
	vector<int> T(K.size(), 0);
	vector<int> matches;

	if (K.size() == 0) {
		matches.push_back(0);
		return matches;
	}
	T[0] = 0;
	for (int i = 1; i < K.size(); i++) {
		int pos = T[i-1];
		while(pos > 0 && K[pos] != K[i]) pos = T[pos-1];
		if (K[pos] == K[i]) T[i] = pos + 1;
	}

	int sp = 0;
	int kp = 0;
	while(sp < S.size()) {
		while (kp > 0 && K[kp] != S[sp]) kp = T[kp];
		if (K[kp] == S[sp]) {
			kp++;
		}
			sp++;
		if (kp == K.size()) matches.push_back(sp - K.size());
	}
	return matches;
}

template<class T>
void dump_vector(vector<T> &vec) {
	cout << endl;
	for (auto item : vec) {
		cout << item << " , " << endl;
	}
	cout << endl;
}
int main(void) {
	string S = "ababababceaabababceaeabcabd";
	string K = "abababcea";
	cout << "the S is " << S << endl;
	cout << "the K is " << K << endl;
	vector<int> res = KMP(S, K);
	dump_vector(res);

}
