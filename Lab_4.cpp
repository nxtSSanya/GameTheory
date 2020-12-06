#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:36777216")
#define _CRT_SECURE_NO_WARNINGS
#define all(x) begin(x), end(x)
#include <iostream>
#include <fstream>
#include <functional>
#include <cstdio>
#include <climits>
#include <cmath>
#include <map>
#include <set>
#include <thread>
#include <chrono>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
//#include <bitset>
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define rt(x) return(x)
using namespace std;
map <int, long long> inversions;
vector<int> Si;
const int INF = 1 << 30;
const ll LINF = 1ll << 62;

class Lab_4 {
	vector< vector <int> > m;

public:
	void set_matrix() {
		vector<int> a1 = { 5,5,7 }, a2 = { 3, 4, 6 }, a3 = { 2, 4 ,8 };
		m.reserve(3);
		this->m.push_back(a1);
		this->m.push_back(a2);
		this->m.push_back(a3);
	}
	void get_matrix() {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				cout << this->m[i][j] << " ";
			}
			cout << endl;
		}
	}
	void Kriteriy_Valda() {
		vector<int> mx(3, INF);
			for (int j = 0; j < 3; ++j) {
				mx[0] = min(this->m[0][j], mx[0]);
				mx[1] = min(this->m[1][j], mx[1]);
				mx[2] = min(this->m[2][j], mx[2]);
			}
			cout << "maximum of income: " << *max_element(mx.begin(), mx.end()) << endl;
	}
	void Kriteriy_Gurvitsa() {
		const double A = 0.3;
		vector<int> mx(3, -INF), mn(3, INF);
		vector<double> res(3);
		for (int i = 0; i < 3; ++i) {
			mn[0] = min(this->m[0][i], mn[0]);
			mn[1] = min(this->m[1][i], mn[1]);
			mn[2] = min(this->m[2][i], mn[2]);
			mx[0] = max(this->m[0][i], mx[0]);
			mx[1] = max(this->m[1][i], mx[1]);
			mx[2] = max(this->m[2][i], mx[2]);
		}
		for (int q = 0; q < 3; ++q) {
			res[q] = A * mx[q] + (1 - A)*mn[q];
		}
		cout << "maximum of income: " << *max_element(res.begin(), res.end()) << endl;
	}
};
int main()
{
	//#ifndef ONLINE_JUDGE  
	//  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//#endif
	Lab_4 example;
	example.set_matrix();
	example.get_matrix();
	example.Kriteriy_Valda();
	example.Kriteriy_Gurvitsa();
	return 0;
}
