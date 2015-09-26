#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pid pair<double, pii>

#define rt2 1.41421

priority_queue<pid, vector <pid>, greater<pid> > pq;
vector < vector <int> > board;

map <pii, double> mp;
map <pii, int> mp1;

int n, m;

double getdis(int stx, int sty, int enx, int eny) {
	pid ex;
	pq.push(make_pair(0, make_pair(stx, sty)));

	int i;
	int j;
	
	if (board[stx][sty] == 1) {
		return 0;
	}

	int test;

	while (!pq.empty()) {
		ex = pq.top();
		pq.pop();
		mp1.insert(make_pair(ex.second, 1));
		mp.erase(ex.second);
		i = ex.second.first;
		j = ex.second.second;

		if ((ex.second.first == enx) && (ex.second.second == eny)) {
			return ex.first;
		}
	
		if ((j + 1 < m) && (board[i][j + 1] == 0) && (mp1.count(make_pair(i, j+1)) == 0)) {
			if (mp.count(make_pair(i, j + 1)) == 0) {
				pq.push(make_pair(ex.first + 1, make_pair(i, j+1)));
				mp.insert(make_pair(make_pair(i,j + 1),ex.first + 1));
			}
			else {
				test = mp[make_pair(i, j + 1)];
				if (test > ex.first + 1) {
					pq.push(make_pair(ex.first + 1, make_pair(i, j+1)));
					mp[make_pair(i,j+1)] = ex.first + 1;
				}
			}
		}

		if (((j + 1 < m) && (i + 1 < n)) && (board[i + 1][j + 1] == 0) && (mp1.count(make_pair(i + 1, j+1)) == 0)) {
			if (mp.count(make_pair(i + 1, j + 1)) == 0) {
				pq.push(make_pair(ex.first + rt2, make_pair(i + 1, j+1)));
				mp.insert(make_pair(make_pair(i + 1,j + 1),ex.first + rt2));
			}
			else {
				test = mp[make_pair(i + 1, j + 1)];
				if (test > ex.first + rt2) {
					pq.push(make_pair(ex.first + rt2, make_pair(i+1, j+1)));
					mp[make_pair(i+1,j+1)] = ex.first + rt2;
				}
			}
		}

		if ((i + 1 < n) && (board[i+1][j] == 0) && (mp1.count(make_pair(i + 1, j)) == 0)) {
			if (mp.count(make_pair(i + 1, j)) == 0) {
				pq.push(make_pair(ex.first + 1, make_pair(i + 1, j)));
				mp.insert(make_pair(make_pair(i + 1,j),ex.first + 1));
			}
			else {
				test = mp[make_pair(i + 1, j)];
				if (test > ex.first + 1) {
					pq.push(make_pair(ex.first + 1, make_pair(i + 1, j)));
					mp[make_pair(i+1,j)] = ex.first + 1;
				}
			}
		}

		if (((j - 1 >= 0) && (i + 1 < n)) && (board[i + 1][j - 1] == 0) && (mp1.count(make_pair(i + 1, j-1)) == 0)) {
			if (mp.count(make_pair(i + 1, j - 1)) == 0) {
				pq.push(make_pair(ex.first + rt2, make_pair(i + 1, j-1)));
				mp.insert(make_pair(make_pair(i + 1,j - 1),ex.first + rt2));
			}
			else {
				test = mp[make_pair(i + 1, j - 1)];
				if (test > ex.first + rt2) {
					pq.push(make_pair(ex.first + rt2, make_pair(i+1, j-1)));
					mp[make_pair(i+1,j-1)] = ex.first + rt2;
				}
			}
		}

		if ((j - 1 >= 0) && (board[i][j - 1] == 0) && (mp1.count(make_pair(i, j-1)) == 0)) {
			if (mp.count(make_pair(i, j - 1)) == 0) {
				pq.push(make_pair(ex.first + 1, make_pair(i, j - 1)));
				mp.insert(make_pair(make_pair(i,j - 1),ex.first + 1));
			}
			else {
				test = mp[make_pair(i, j - 1)];
				if (test > ex.first + 1) {
					pq.push(make_pair(ex.first + 1, make_pair(i, j - 1)));
					mp[make_pair(i,j-1)] = ex.first + 1;
				}
			}
		}

		if (((j - 1 >= 0) && (i - 1 >= 0)) && (board[i - 1][j - 1] == 0) && (mp1.count(make_pair(i-1, j-1)) == 0)) {
			if (mp.count(make_pair(i - 1, j - 1)) == 0) {
				pq.push(make_pair(ex.first + rt2, make_pair(i - 1, j-1)));
				mp.insert(make_pair(make_pair(i - 1,j - 1),ex.first + rt2));
			}
			else {
				test = mp[make_pair(i - 1, j - 1)];
				if (test > ex.first + rt2) {
					pq.push(make_pair(ex.first + rt2, make_pair(i-1, j-1)));
					mp[make_pair(i-1,j-1)] = ex.first + rt2;
				}
			}
		}

		if ((i - 1 >= 0) && (board[i - 1][j] == 0) && (mp1.count(make_pair(i-1, j)) == 0)) {
			if (mp.count(make_pair(i - 1, j)) == 0) {
				pq.push(make_pair(ex.first + 1, make_pair(i - 1, j)));
				mp.insert(make_pair(make_pair(i - 1,j),ex.first + 1));
			}
			else {
				test = mp[make_pair(i - 1, j)];
				if (test > ex.first + 1) {
					pq.push(make_pair(ex.first + 1, make_pair(i - 1, j)));
					mp[make_pair(i-1,j)] = ex.first + 1;
				}
			}
		}

		if (((j + 1 < m) && (i - 1 >= 0)) && (board[i - 1][j + 1] == 0) && (mp1.count(make_pair(i - 1, j+1)) == 0)) {
			if (mp.count(make_pair(i - 1, j + 1)) == 0) {
				pq.push(make_pair(ex.first + rt2, make_pair(i - 1, j+1)));
				mp.insert(make_pair(make_pair(i - 1,j + 1),ex.first + rt2));
			}
			else {
				test = mp[make_pair(i - 1, j + 1)];
				if (test > ex.first + rt2) {
					pq.push(make_pair(ex.first + rt2, make_pair(i-1, j+1)));
					mp[make_pair(i-1,j+1)] = ex.first + rt2;
				}
			}
		}


	}
}

double sol(pair <int, int> p[4], int stx ,int sty) {

			double sol = 0;
			mp.clear();
			mp1.clear();
			int enx, eny;
			
			while (!pq.empty())
				pq.pop();
			enx = p[0].first;
			eny = p[0].second;
			sol += getdis(stx, sty, enx, eny);
		//	cout << sol << endl;
			mp.clear();
			mp1.clear();

			while (!pq.empty())
				pq.pop();
			
			stx = enx;
			sty = eny;
			enx = p[1].first;
			eny = p[1].second;

			sol += getdis(stx, sty, enx, eny);
		//	cout << sol << endl;
			mp.clear();
			mp1.clear();

			while (!pq.empty())
				pq.pop();
			
			stx = enx;
			sty = eny;
			enx = p[2].first;
			eny = p[2].second;
			sol += getdis(stx, sty, enx, eny);
		//	cout << sol << endl;
			mp.clear();
			mp1.clear();

			while (!pq.empty())
				pq.pop();
			stx = enx;
			sty = eny;
			enx = p[3].first;
			eny = p[3].second;
			sol += getdis(stx, sty, enx, eny);
		
			mp.clear();
			mp1.clear();
			return sol;
}

int main() {
		int tc, i, j,x;
		cin >> n >> m;
		pair <int, int> p[4];

		p[0].first = 0;
		p[0].second = 0;
		p[1].first = 0;
		p[1].second = m - 1;
		p[2].first = n - 1;
		p[2].second = m - 1;
		p[3].first = n - 1;
		p[3].second = 0;
		
		vector <int> row;

		for (i = 0; i < n; i++) {
			row.clear();
			for (j = 0; j < m; j++) {
				cin >> x;
				row.push_back(x);
			}
			board.push_back(row);
		}

		double sol1;

		cin >> tc;

		int stx, sty, enx, eny;
		while (tc--) {
			cin >> stx >> sty;
			double ans;
			double min = FLT_MAX;
			while (	next_permutation(p, p+4)) {
				ans = sol(p, stx, sty);
				if (min > ans) {
					min = ans;
				}
			}

			sol1 = (int)(min + 0.5);
			cout << sol1 << "\n";
		}
		return 0;
}