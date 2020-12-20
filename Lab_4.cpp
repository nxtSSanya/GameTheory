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
	vector< vector <double> > m;

public:
	void set_matrix() {
		vector<double> a1 = { 3, 3.3, 5.04 }, a2 = { 1.35, 1.155, 1.26 }, a3 = { 0.09, 0.0975 ,0.12 };
		m.reserve(3);
		this->m.push_back(a1);
		this->m.push_back(a2);
		this->m.push_back(a3);
	}
	void get_matrix() {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				cout << this->m[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void Kriteriy_Valda() {
		cout << "----------------------" << endl;
		cout << "KRITERIY VALDA" << endl;
		vector<double> mx(3, INF);
		vector< pair <int, int > > ind(3);
		for (int j = 0; j < 3; ++j) {
			mx[0] = min(this->m[0][j], mx[0]);
			mx[1] = min(this->m[1][j], mx[1]);
			mx[2] = min(this->m[2][j], mx[2]);
		}
		ind = this->GetIndex(m, mx);
		cout << "For A1: " << mx[0] << endl;
		cout << "For A2: " << mx[1] << endl;
		cout << "For A3: " << mx[2] << endl;
		cout << "maximum of {" << mx[0] << ", " << mx[1] << ", " << mx[2] << "}: " << *max_element(mx.begin(), mx.end()) << endl;
		cout << "----------------------" << endl;
	}
	void Kriteriy_Gurvitsa() {
		cout << "KRITERIY GURVITSA" << endl;
		const double A = 0.3;
		vector<double> mx(3, -INF), mn(3, INF);
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
		cout << "For A1: " << A << "*" << mx[0] << "+" << (1 - A) << "*" << mn[0] << " = " << res[0] << endl;
		cout << "For A2: " << A << "*" << mx[1] << "+" << (1 - A) << "*" << mn[1] << " = " << res[1] << endl;
		cout << "For A3: " << A << "*" << mx[2] << "+" << (1 - A) << "*" << mn[2] << " = " << res[2] << endl;
		cout << "maximum of {" << res[0] << ", " << res[1] << ", " << res[2] << "}: " << *max_element(res.begin(), res.end()) << endl;
		cout << "----------------------" << endl;
	}
	void Kriteriy_Sevidzha() {
		cout << "KRITERIY SEVIDZHA" << endl;
		vector<double> mx(3, -INF);
		vector<int> ind(3);
		double res(3);
		for (int i = 0; i < 3; ++i) {
			mx[0] = max(this->m[0][i], mx[0]);
			mx[1] = max(this->m[1][i], mx[1]);
			mx[2] = max(this->m[2][i], mx[2]);
		}
		cout << "For A1: " << mx[0] << endl;
		cout << "For A2: " << mx[1] << endl;
		cout << "For A3: " << mx[2] << endl;
		cout << "minimum of {" << mx[0] << ", " << mx[1] << ", " << mx[2] << "}: " << *min_element(mx.begin(), mx.end()) << endl;
		cout << "----------------------" << endl;
	}
	void Kriteriy_max() {
		cout << "KRITERIY MAXIMUMA" << endl;
		vector<double> mx(3, -INF);
		for (int i = 0; i < 3; ++i) {
			mx[0] = max(this->m[0][i], mx[0]);
			mx[1] = max(this->m[1][i], mx[1]);
			mx[2] = max(this->m[2][i], mx[2]);
		}
		cout << "For A1: " << mx[0] << endl;
		cout << "For A2: " << mx[1] << endl;
		cout << "For A3: " << mx[2] << endl;
		cout << "maximum of {" << mx[0] << ", " << mx[1] << ", " << mx[2] << "}: " << *max_element(mx.begin(), mx.end()) << endl;
		cout << "----------------------" << endl;
	}
	void Kriteriy_Laplasa() {
		double q = 0.33;
		vector<double> res(3, 0);
		for (int i = 0; i < 3; ++i) {
			res[0] = this->m[0][i] * q;
			res[1] = this->m[1][i] * q;
			res[2] = this->m[2][i] * q;
		}
		cout << "For A1: " << m[0][0] << " * " << q << " + " << m[0][1] << " * " << q << " + " << m[0][2] << " * " << q << " = " << res[0] << endl;
		cout << "For A2: " << m[1][0] << " * " << q << " + " << m[1][1] << " * " << q << " + " << m[1][2] << " * " << q << " = " << res[1] << endl;
		cout << "For A3: " << m[2][0] << " * " << q << " + " << m[2][1] << " * " << q << " + " << m[2][2] << " * " << q << " = " << res[2] << endl;
		cout << "maximum of {" << res[0] << ", " << res[1] << ", " << res[2] << "}: " << *max_element(res.begin(), res.end()) << endl;
	}
private:
	vector<pair <int, int> > GetIndex(vector< vector<double> > a, vector<double> track) {
		vector<pair<int, int> > ind(3);
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (track[i] == a[i][j]) {
					ind[i].first = i;
					ind[j].second = j;
				}
			}
		}
		return ind;
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
	example.Kriteriy_Sevidzha();
	example.Kriteriy_max();
	example.Kriteriy_Laplasa();
	return 0;
}
