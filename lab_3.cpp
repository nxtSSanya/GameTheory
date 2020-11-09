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
#include <thread>
#include <chrono>
#include <algorithm>
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

int maximum(vector<int> v, int k)
{
	int max = v[0];
	int ind_max = 0;
	for (int i = 1; i < k; i++)
		if (v[i] > max)
		{
			max = v[i];
			ind_max = i;
		}

	return ind_max;
}

int minimum(vector<int> v, int k)
{
	int min = v[0];
	int ind_min = 0;
	for (int i = 1; i < k; i++)
		if (v[i] < min)
		{
			min = v[i];
			ind_min = i;
		}

	return ind_min;
}

vector<double> GetTheCorrectAnswer(vector<double> v) {
	swap(v[0], v[3]);
	swap(v[5], v[4]);
	swap(v[1], v[5]);
	return v;
}

int main()
{
	//#ifndef ONLINE_JUDGE  
	//  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//#endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll iter;
	cin >> iter;
	const int k = 6;
	int i;
	vector<int> M1 = { 0, 0, 0, 0, 0, 0 };// m = n
	vector<int> M2 = { 0, 0, 0, 0, 0, 0 };
	vector<int> B1 = { 0, 0, 0, 0, 0, 0 };
	vector<int> B2 = { 0, 0, 0, 0, 0, 0 };

	// vector<vector<int> >a(k);
	int a[k][k] = {
		{ 25, 30, 35, 40, - 14, 50 },
		{ 30, 36, 42, 48, 54, -16 },
		{ 35, 42, 49, 56, 63, 70 },
		{ 40, 48, 56, 64, 72, 80 },
		{ -14, 54, 63, 72, 81, 90 },
		{ 50, -16, 70, 80, 90, 100 },
	};
	
	int max = a[0][0];
	int imax = 0;

	int min = 5;
	++M2[min];

	for (int q = 0; q < iter; ++q)
	{
		for (i = 0; i < k; i++)
		{
			B1[i] += a[i][min];
		}
		max = maximum(B1, k);
		++M1[max];	


		for (i = 0; i < k; i++)
		{
			B2[i] += a[max][i];
		}
		min = minimum(B2, k);
		M2[min]++;

		double gamma;
		vector<double> Sa(k), Sb(k);
		for (i = 0; i < k; i++)
		{
			Sa[i] = (double)M1[i] / (double)q;
			Sb[i] = (double)M2[i] / (double)q;
		}
		if (q == iter - 1) {
			cout << "Iteration num = " << iter << endl;

			gamma = ((long double)B1[max] / (long double)q + (long double)B2[min] / (long double)q) / 2;

			cout.precision(4);

			cout << fixed << endl << "Cost of the game: " << gamma << endl;

			cout << endl << endl << "\nStrategy of player 1 ";
			//GetTheCorrectAnswer(Sa);
			for (auto&i : Sa) {
				cout << fixed << i << " ";
			}

			cout << endl << endl << "\nStrategy of player 2: ";
			Sb = GetTheCorrectAnswer(Sb);
			for (auto&i : Sb) {
				cout << fixed << i << " ";
			}
		}
	}
	cout << endl << endl << endl << endl;
	return 0;
}
