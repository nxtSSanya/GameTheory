//#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:36777216")
#define _CRT_SECURE_NO_WARNINGS
#define all(x) begin(x), end(x)
#include <iostream>
#include <functional>
#include <cstdio>
#include <climits>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <ctime>
//#include <bitset>
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define rt(x) return(x)
//#define DEBUG
using namespace std;
map <int, long long> inversions;
vector<int> Si;
const int INF = 1 << 30;
const ll LINF = 1ll << 62;
const int MAX_N = 1001;

class solve {
	vector<double> S;
	int n = 7;
	double r;
	vector<int> S_1;
public:
	void SetSequence() {
		this->S = {0.1, 0.1, 0.05, 0.02, 0.02, 0.01, 0.7};
#ifdef DEBUG
		double sum = 0.0;
		for (auto&i : S) {			
			sum += i;
		}
		cout << "SUM is: " << sum << endl;
#endif
		for (auto&i : this->S) {
			S_1.push_back(i * 1000);
		}
	}

	void GetRandomNumber() {
		srand(time(NULL));
		r = 20;//rand() % 1000;
		cout << "Rand num is: " << this->r << endl;
	}

	void BinarySearch() {
		sort(this->S_1.begin(), this->S_1.end());
		int l = 0, rg = 6;
		int mid;
		while (l < rg) {
			mid = (l + rg) / 2;
			if (this->S_1[mid] > this->r) rg = mid;
			else l = mid + 1;
		}
		rg--;
		if (this->S_1[rg] == this->r) cout << "Found number: " << this->r << " " << rg << endl;
		else cout << "Found position: " << rg + 1 << endl;
	}

	void UpperBound() {
		sort(this->S_1.begin(), this->S_1.end());
		auto upper = upper_bound(this->S_1.begin(), this->S_1.end(), this->r);
		if (upper != S_1.end())
			std::cout << *upper << " at index " << distance(S_1.begin(), upper);
		else
			std::cout << "Not found";
	}

	void GetSequence() {
		for (auto&i : this->S) {
			cout << i << endl;
		}
	}
	
	void GetS1() {
		for (auto&i : this->S_1) {
			cout << i << endl;
		}
	}
};
int main()
{
	//#ifndef ONLINE_JUDGE  
	//  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//#endif
	vector<ll> st(57);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve s;
	s.SetSequence();
	s.GetSequence();
	s.GetRandomNumber();
	s.GetS1();
	s.BinarySearch();
	//s.UpperBound();
	return 0;
}
