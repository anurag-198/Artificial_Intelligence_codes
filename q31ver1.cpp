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

	// for (i = 0; i < n; i++) {
	// 	for (j = 0; j < m; j++) {
	// 		cout << board[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	int test;

	//int cnt = 0;
	while (!pq.empty()) {
	//	cnt++;

		ex = pq.top();
		pq.pop();
		// cout << ex.first << " ";
		// cout << ex.second.first <<"   " << ex.second.second << endl;	
		mp1.insert(make_pair(ex.second, 1));
		mp.erase(ex.second);


		// if (cnt == 20) {			
		// 	break;
		// 	return 0;
		// }

		i = ex.second.first;
		j = ex.second.second;

		if ((ex.second.first == enx) && (ex.second.second == eny)) {
	//		cout << ex.first << "  " << ex.second.first << "  " << ex.second.second << endl; 
			return ex.first;
		}
	
		if ((j + 1 < m) && (board[i][j + 1] == 0) && (mp1.count(make_pair(i, j+1)) == 0)) {
			if (mp.count(make_pair(i, j + 1)) == 0) {

				// if ((i == 1) && (j + 1 == 0))
				// 	cout << "1a\n"; 

				pq.push(make_pair(ex.first + 1, make_pair(i, j+1)));
				mp.insert(make_pair(make_pair(i,j + 1),ex.first + 1));
			}
			else {
				test = mp[make_pair(i, j + 1)];
				if (test > ex.first + 1) {
					// if ((i == 1) && (j + 1 == 0))
					// cout << "1b\n";
					pq.push(make_pair(ex.first + 1, make_pair(i, j+1)));
				}
			}
		}

		if (((j + 1 < m) && (i + 1 < n)) && (board[i + 1][j + 1] == 0) && (mp1.count(make_pair(i + 1, j+1)) == 0)) {
			if (mp.count(make_pair(i + 1, j + 1)) == 0) {

				// if ((i + 1 == 1) && (j + 1 == 0))
				// 	cout << "2a\n";

				pq.push(make_pair(ex.first + rt2, make_pair(i + 1, j+1)));
				mp.insert(make_pair(make_pair(i + 1,j + 1),ex.first + rt2));
			}
			else {
				test = mp[make_pair(i + 1, j + 1)];
				if (test > ex.first + rt2) {

					// if ((i + 1 == 1) && (j + 1 == 0))
					// cout << "2b\n";


					pq.push(make_pair(ex.first + rt2, make_pair(i+1, j+1)));
				}
			}
		}

		if ((i + 1 < n) && (board[i+1][j] == 0) && (mp1.count(make_pair(i + 1, j)) == 0)) {
			if (mp.count(make_pair(i + 1, j)) == 0) {

				// if ((i + 1 == 1) && (j == 0))
				// 	cout << "3a\n";


				pq.push(make_pair(ex.first + 1, make_pair(i + 1, j)));
				mp.insert(make_pair(make_pair(i + 1,j),ex.first + 1));
			}
			else {
				test = mp[make_pair(i + 1, j)];
				if (test > ex.first + 1) {

					// if ((i + 1 == 1) && (j == 0))
					// cout << "3b\n";

					pq.push(make_pair(ex.first + 1, make_pair(i + 1, j)));
				}
			}
		}

		if (((j - 1 >= 0) && (i + 1 < n)) && (board[i + 1][j - 1] == 0) && (mp1.count(make_pair(i + 1, j-1)) == 0)) {
			if (mp.count(make_pair(i + 1, j - 1)) == 0) {

				// if ((i + 1 == 1) && (j - 1 == 0))
				// 	cout << "4a\n";

				pq.push(make_pair(ex.first + rt2, make_pair(i + 1, j-1)));
				mp.insert(make_pair(make_pair(i + 1,j - 1),ex.first + rt2));
			}
			else {
				test = mp[make_pair(i + 1, j - 1)];
				if (test > ex.first + rt2) {

					// if ((i + 1 == 1) && (j - 1 == 0))
					// cout << "4b\n";

					pq.push(make_pair(ex.first + rt2, make_pair(i+1, j-1)));
				}
			}
		}

		if ((j - 1 >= 0) && (board[i][j - 1] == 0) && (mp1.count(make_pair(i, j-1)) == 0)) {
			if (mp.count(make_pair(i, j - 1)) == 0) {

				// if ((i == 1) && (j - 1 == 0))
				// 	cout << "5a\n";

				pq.push(make_pair(ex.first + 1, make_pair(i, j - 1)));
				mp.insert(make_pair(make_pair(i,j - 1),ex.first + 1));
			}
			else {
				test = mp[make_pair(i, j - 1)];
				if (test > ex.first + 1) {

					// if ((i == 1) && (j - 1 == 0))
					// cout << "5b\n";

					pq.push(make_pair(ex.first + 1, make_pair(i, j - 1)));
				}
			}
		}

		if (((j - 1 >= 0) && (i - 1 >= 0)) && (board[i - 1][j - 1] == 0) && (mp1.count(make_pair(i-1, j-1)) == 0)) {
			if (mp.count(make_pair(i - 1, j - 1)) == 0) {

				// if ((i - 1 == 1) && (j - 1 == 0))
				// 	cout << "6a\n";

				pq.push(make_pair(ex.first + rt2, make_pair(i - 1, j-1)));
				mp.insert(make_pair(make_pair(i - 1,j - 1),ex.first + rt2));
			}
			else {
				test = mp[make_pair(i - 1, j - 1)];
				if (test > ex.first + rt2) {

					// if ((i - 1 == 1) && (j - 1 == 0))
					// cout << "6b\n";

					pq.push(make_pair(ex.first + rt2, make_pair(i-1, j-1)));
				}
			}
		}

		if ((i - 1 >= 0) && (board[i - 1][j] == 0) && (mp1.count(make_pair(i-1, j)) == 0)) {
			if (mp.count(make_pair(i - 1, j)) == 0) {

				// if ((i - 1 == 1) && (j == 0))
				// 	cout << "7a\n";

				pq.push(make_pair(ex.first + 1, make_pair(i - 1, j)));
				mp.insert(make_pair(make_pair(i - 1,j),ex.first + 1));
			}
			else {
				test = mp[make_pair(i - 1, j)];
				if (test > ex.first + 1) {

					// if ((i - 1 == 1) && (j == 0))
					// cout << "7b\n";

					pq.push(make_pair(ex.first + 1, make_pair(i - 1, j)));
				}
			}
		}

		if (((j + 1 < m) && (i - 1 >= 0)) && (board[i - 1][j + 1] == 0) && (mp1.count(make_pair(i - 1, j+1)) == 0)) {
			if (mp.count(make_pair(i - 1, j + 1)) == 0) {
				
				// if ((i - 1 == 1) && (j + 1 == 0))
				// 	cout << "8a\n";

				pq.push(make_pair(ex.first + rt2, make_pair(i - 1, j+1)));
				mp.insert(make_pair(make_pair(i - 1,j + 1),ex.first + rt2));
			}
			else {
				test = mp[make_pair(i - 1, j + 1)];
				if (test > ex.first + rt2) {

					// if ((i - 1 == 1) && (j + 1 == 0))
					// cout << "8b\n";

					pq.push(make_pair(ex.first + rt2, make_pair(i-1, j+1)));
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
			double sol;
			int sol1;
			mp.clear();
			mp1.clear();
			cin >> stx >> sty >> enx >> eny;
			sol = getdis(stx, sty, enx, eny);	
			sol1 = (int)(sol + 0.5);
			cout << sol1 << "\n";
		}
		return 0;
}