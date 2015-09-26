#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pid pair<double, pii>

#define rt2 1.41421

priority_queue<pid, vector <pid>, greater<pid> > pq;
priority_queue<pid, vector <pid>, greater<pid> > pq1;

vector < vector <int> > board;

map <pii, double> mp; // fringe from top
map <pii, int> mp1;  // closed from top
map <pii, int> mp3;  // closed from bottom 
map <pii, double> mp2; // fringe from bottom 

int n, m;

double getdis(int stx, int sty, int enx, int eny) {
	pid ex;
	pq.push(make_pair(0, make_pair(stx, sty)));
	pq1.push(make_pair(0, make_pair(enx, eny)));

	mp.insert(make_pair(make_pair(stx,sty), 0));
	mp2.insert(make_pair(make_pair(enx,eny), 0));
	
	int i;
	int j;
	
	if ((board[stx][sty] == 1) || (board[enx][eny] == 1)) {
		return 0;
	}

	int test;

	while ((!pq.empty()) && (!pq1.empty())) {
		ex = pq.top();
		pq.pop();

		if (mp3.count(ex.second) > 0) {
			return ex.first + mp3[ex.second];
		}

		mp1.insert(make_pair(ex.second, 1));
		mp.erase(ex.second);
		i = ex.second.first;
		j = ex.second.second;
	
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

	
	/*****************************************************MOVING UP***************************************************/

		ex = pq1.top();
		pq1.pop();
		mp3.insert(make_pair(ex.second, 1)); // for closed from bottom

		if (mp1.count(ex.second) > 0) {
			return ex.first + mp1[ex.second];
		}

		mp2.erase(ex.second); // for fringe from bottom
		i = ex.second.first;
		j = ex.second.second;
 	
		if ((j + 1 < m) && (board[i][j + 1] == 0) && (mp3.count(make_pair(i, j+1)) == 0)) {
			if (mp2.count(make_pair(i, j + 1)) == 0) {
				pq1.push(make_pair(ex.first + 1, make_pair(i, j+1)));
				mp2.insert(make_pair(make_pair(i,j + 1),ex.first + 1));
			}
			else {
				test = mp2[make_pair(i, j + 1)];
				if (test > ex.first + 1) {
					pq1.push(make_pair(ex.first + 1, make_pair(i, j+1)));
					mp2[make_pair(i,j+1)] = ex.first + 1;
				}
			}
		}

		if (((j + 1 < m) && (i + 1 < n)) && (board[i + 1][j + 1] == 0) && (mp3.count(make_pair(i + 1, j+1)) == 0)) {
			if (mp2.count(make_pair(i + 1, j + 1)) == 0) {
				pq1.push(make_pair(ex.first + rt2, make_pair(i + 1, j+1)));
				mp2.insert(make_pair(make_pair(i + 1,j + 1),ex.first + rt2));
			}
			else {
				test = mp2[make_pair(i + 1, j + 1)];
				if (test > ex.first + rt2) {
					pq1.push(make_pair(ex.first + rt2, make_pair(i+1, j+1)));
					mp2[make_pair(i+1,j+1)] = ex.first + rt2;
				}
			}
		}

		if ((i + 1 < n) && (board[i+1][j] == 0) && (mp3.count(make_pair(i + 1, j)) == 0)) {
			if (mp2.count(make_pair(i + 1, j)) == 0) {
				pq1.push(make_pair(ex.first + 1, make_pair(i + 1, j)));
				mp2.insert(make_pair(make_pair(i + 1,j),ex.first + 1));
			}
			else {
				test = mp2[make_pair(i + 1, j)];
				if (test > ex.first + 1) {
					pq1.push(make_pair(ex.first + 1, make_pair(i + 1, j)));
					mp2[make_pair(i+1,j)] = ex.first + 1;
				}
			}
		}

		if (((j - 1 >= 0) && (i + 1 < n)) && (board[i + 1][j - 1] == 0) && (mp3.count(make_pair(i + 1, j-1)) == 0)) {
			if (mp2.count(make_pair(i + 1, j - 1)) == 0) {
				pq1.push(make_pair(ex.first + rt2, make_pair(i + 1, j-1)));
				mp2.insert(make_pair(make_pair(i + 1,j - 1),ex.first + rt2));
			}
			else {
				test = mp2[make_pair(i + 1, j - 1)];
				if (test > ex.first + rt2) {
					pq1.push(make_pair(ex.first + rt2, make_pair(i+1, j-1)));
					mp2[make_pair(i+1,j-1)] = ex.first + rt2;
				}
			}
		}

		if ((j - 1 >= 0) && (board[i][j - 1] == 0) && (mp3.count(make_pair(i, j-1)) == 0)) {
			if (mp2.count(make_pair(i, j - 1)) == 0) {
				pq1.push(make_pair(ex.first + 1, make_pair(i, j - 1)));
				mp2.insert(make_pair(make_pair(i,j - 1),ex.first + 1));
			}
			else {
				test = mp2[make_pair(i, j - 1)];
				if (test > ex.first + 1) {
					pq1.push(make_pair(ex.first + 1, make_pair(i, j - 1)));
					mp2[make_pair(i,j-1)] = ex.first + 1;
				}
			}
		}

		if (((j - 1 >= 0) && (i - 1 >= 0)) && (board[i - 1][j - 1] == 0) && (mp3.count(make_pair(i-1, j-1)) == 0)) {
			if (mp2.count(make_pair(i - 1, j - 1)) == 0) {
				pq1.push(make_pair(ex.first + rt2, make_pair(i - 1, j-1)));
				mp2.insert(make_pair(make_pair(i - 1,j - 1),ex.first + rt2));
			}
			else {
				test = mp2[make_pair(i - 1, j - 1)];
				if (test > ex.first + rt2) {
					pq1.push(make_pair(ex.first + rt2, make_pair(i-1, j-1)));
					mp2[make_pair(i-1,j-1)] = ex.first + rt2;
				}
			}
		}

		if ((i - 1 >= 0) && (board[i - 1][j] == 0) && (mp3.count(make_pair(i-1, j)) == 0)) {
			if (mp2.count(make_pair(i - 1, j)) == 0) {
				pq1.push(make_pair(ex.first + 1, make_pair(i - 1, j)));
				mp2.insert(make_pair(make_pair(i - 1,j),ex.first + 1));
			}
			else {
				test = mp2[make_pair(i - 1, j)];
				if (test > ex.first + 1) {
					pq1.push(make_pair(ex.first + 1, make_pair(i - 1, j)));
					mp2[make_pair(i-1,j)] = ex.first + 1;
				}
			}
		}

		if (((j + 1 < m) && (i - 1 >= 0)) && (board[i - 1][j + 1] == 0) && (mp3.count(make_pair(i - 1, j+1)) == 0)) {
			if (mp2.count(make_pair(i - 1, j + 1)) == 0) {
				pq1.push(make_pair(ex.first + rt2, make_pair(i - 1, j+1)));
				mp2.insert(make_pair(make_pair(i - 1,j + 1),ex.first + rt2));
			}
			else {
				test = mp2[make_pair(i - 1, j + 1)];
				if (test > ex.first + rt2) {
					pq1.push(make_pair(ex.first + rt2, make_pair(i-1, j+1)));
					mp2[make_pair(i-1,j+1)] = ex.first + rt2;
				}
			}
		}
		
	
		/**************************************************************************************************************************/

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
			
			while (!pq.empty()) {
				pq.pop();
			}
			while (!pq1.empty()) {
				pq1.pop();
			}

			double sol;
			int sol1;
			mp.clear();
			mp1.clear();
			mp2.clear();
			cin >> stx >> sty >> enx >> eny;
			sol = getdis(stx, sty, enx, eny);	
			sol1 = (int)(sol + 0.5);
			cout << sol1 << "\n";
		}
		return 0;
}