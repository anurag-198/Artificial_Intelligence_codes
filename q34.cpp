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

int main() {
		int tc, i, j,x;
		cin >> n >> m;
		
		vector <int> row;

		for (i = 0; i < n; i++) {
			row.clear();
			for (j = 0; j < m; j++) {
				cin >> x;
				row.push_back(x);
			}
			board.push_back(row);
		}



		cin >> tc;

		int stx, sty, enx, eny;
		while (tc--) {
			double sol = 0;;
			int sol1;
			mp.clear();
			mp1.clear();
			cin >> stx >> sty >> enx >> eny;
			
			while (!pq.empty())
				pq.pop();
			
			sol = getdis(stx, sty, enx, eny);
		//	cout << sol << endl;
		// 	mp.clear();
		// 	mp1.clear();

		// 	while (!pq.empty())
		// 		pq.pop();
		// 	enx = 0;
		// 	eny = m - 1;
		// 	stx = 0;
		// 	sty = 0;
		// 	sol += getdis(stx, sty, enx, eny);
		// //	cout << sol << endl;
		// 	mp.clear();
		// 	mp1.clear();

		// 	while (!pq.empty())
		// 		pq.pop();
		// 	enx = n - 1;
		// 	eny = m - 1;
		// 	stx = 0;
		// 	sty = m - 1;
		// 	sol += getdis(stx, sty, enx, eny);
		// //	cout << sol << endl;
		// 	mp.clear();
		// 	mp1.clear();

		// 	while (!pq.empty())
		// 		pq.pop();
		// 	enx = n - 1;
		// 	eny = 0;
		// 	stx = n - 1;
		// 	sty = m - 1;
		// 	sol += getdis(stx, sty, enx, eny);
		// 	//cout << sol << endl;
			mp.clear();
			mp1.clear();

			sol1 = (int)sol ;
			cout << sol1 << "\n";
		}
		return 0;
}