#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pdd pair<double,double>
#define pid pair<pdd, pii>

double rt2 = 1.41421;

priority_queue<pid, vector <pid>, greater<pid> > pq;

vector < vector <int> > board;

map <pii, double> mp;
map <pii, int> mp1;

int n, m;

double h(int stx, int sty, int enx, int eny) {
	int disx = abs(enx - stx);
	int disy = abs(eny - sty);
	
	double ans = sqrt(disx * disx + disy * disy);
	/*if (disx < disy) {
	 	ans = 1.4 * disx + (eny - (sty + (disx)));
    }
    else {
	 	ans = 1.4 * disy + (enx - (stx + (disy)));
    }*/
    return ans;
}

double getdis(int stx, int sty, int enx, int eny) {
	pid ex;
	
	double g = h(stx,sty,enx,eny);

	pq.push(make_pair(make_pair(g,0), make_pair(stx, sty)));

	int i;
	int j;
	
	if ((board[stx][sty] == 1) || (board[enx][eny] == 1)) {
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
			return ex.first.second;
		}
	
		

		if ((j + 1 < m) && (board[i][j + 1] == 0) && (mp1.count(make_pair(i, j+1)) == 0)) {
			if (mp.count(make_pair(i, j + 1)) == 0) {
				g = h(i,j + 1,enx,eny);
				//g = 1;
				pq.push(make_pair(make_pair(ex.first.second + 1 + g,ex.first.second + 1), make_pair(i, j+1)));
				mp.insert(make_pair(make_pair(i,j + 1),ex.first.second + 1));
			}
			else {
				test = mp[make_pair(i, j + 1)];
				if (test > ex.first.second + 1) {
					g = h(i,j + 1,enx,eny);
					//g = 1;
					pq.push(make_pair(make_pair(ex.first.second + 1 + g,ex.first.second + 1), make_pair(i, j+1)));
					mp[make_pair(i,j+1)] = ex.first.second + 1;
				}
			}
		}

		if (((j + 1 < m) && (i + 1 < n)) && (board[i + 1][j + 1] == 0) && (mp1.count(make_pair(i + 1, j+1)) == 0)) {
			if (mp.count(make_pair(i + 1, j + 1)) == 0) {
				g = h(i + 1,j + 1,enx,eny);
				//g = 1;
				pq.push(make_pair(make_pair(ex.first.second + rt2 + g,ex.first.second + rt2), make_pair(i + 1, j+1)));
				mp.insert(make_pair(make_pair(i + 1,j + 1),ex.first.second + rt2));
			}
			else {
				test = mp[make_pair(i + 1, j + 1)];
				if (test > ex.first.second + rt2) {
					g = h(i + 1,j + 1,enx,eny);
					//g = 1;
					pq.push(make_pair(make_pair(ex.first.second + rt2 + g,ex.first.second + rt2), make_pair(i+1, j+1)));
					mp[make_pair(i+1,j+1)] = ex.first.second + rt2;
				}
			}
		}

		if ((i + 1 < n) && (board[i+1][j] == 0) && (mp1.count(make_pair(i + 1, j)) == 0)) {
			if (mp.count(make_pair(i + 1, j)) == 0) {
				g = h(i + 1,j,enx,eny);
				//g = 1;
				pq.push(make_pair(make_pair(ex.first.second + 1 + g,ex.first.second + 1), make_pair(i + 1, j)));
				mp.insert(make_pair(make_pair(i + 1,j),ex.first.second + 1));
			}
			else {
				test = mp[make_pair(i + 1, j)];
				if (test > ex.first.second + 1) {
					g = h(i + 1,j,enx,eny);
					//g = 1;
					pq.push(make_pair(make_pair(ex.first.second + 1 + g,ex.first.second + 1), make_pair(i + 1, j)));
					mp[make_pair(i+1,j)] = ex.first.second + 1;
				}
			}
		}

		if (((j - 1 >= 0) && (i + 1 < n)) && (board[i + 1][j - 1] == 0) && (mp1.count(make_pair(i + 1, j-1)) == 0)) {
			if (mp.count(make_pair(i + 1, j - 1)) == 0) {
				g = h(i + 1,j - 1,enx,eny);
				//g = 1;
				pq.push(make_pair(make_pair(ex.first.second + rt2 + g,ex.first.second + rt2), make_pair(i + 1, j-1)));
				mp.insert(make_pair(make_pair(i + 1,j - 1),ex.first.second + rt2));
			}
			else {
				test = mp[make_pair(i + 1, j - 1)];
				if (test > ex.first.second + rt2) {
					g = h(i + 1,j - 1,enx,eny);
					//g = 1;
					pq.push(make_pair(make_pair(ex.first.second + rt2 + g,ex.first.second + rt2), make_pair(i+1, j-1)));
					mp[make_pair(i+1,j-1)] = ex.first.second + rt2;
					
				}
			}
		}

		if ((j - 1 >= 0) && (board[i][j - 1] == 0) && (mp1.count(make_pair(i, j-1)) == 0)) {
			if (mp.count(make_pair(i, j - 1)) == 0) {
				g = h(i,j - 1,enx,eny);
				//g = 1;
				pq.push(make_pair(make_pair(ex.first.second + 1 + g,ex.first.second + 1), make_pair(i, j - 1)));
				mp.insert(make_pair(make_pair(i,j - 1),ex.first.second + 1));
			}
			else {
				test = mp[make_pair(i, j - 1)];
				if (test > ex.first.second + 1) {
					g = h(i,j - 1,enx,eny);
					//g = 1;
					pq.push(make_pair(make_pair(ex.first.second + 1 + g,ex.first.second + 1), make_pair(i, j - 1)));
					mp[make_pair(i,j-1)] = ex.first.second + 1;
				}
			}
		}

		if (((j - 1 >= 0) && (i - 1 >= 0)) && (board[i - 1][j - 1] == 0) && (mp1.count(make_pair(i-1, j-1)) == 0)) {
			if (mp.count(make_pair(i - 1, j - 1)) == 0) {
				g = h(i - 1,j - 1,enx,eny);
				//g = 1;
				pq.push(make_pair(make_pair(ex.first.second + rt2 + g,ex.first.second + rt2), make_pair(i - 1, j-1)));
				mp.insert(make_pair(make_pair(i - 1,j - 1),ex.first.second + rt2));
			}
			else {
				test = mp[make_pair(i - 1, j - 1)];
				if (test > ex.first.second + rt2) {
					g = h(i - 1,j - 1,enx,eny);
					//g = 1;
					pq.push(make_pair(make_pair(ex.first.second + rt2 + g,ex.first.second + rt2), make_pair(i-1, j-1)));
					mp[make_pair(i-1,j-1)] = ex.first.second + rt2;
				}
			}
		}

		if ((i - 1 >= 0) && (board[i - 1][j] == 0) && (mp1.count(make_pair(i-1, j)) == 0)) {
			if (mp.count(make_pair(i - 1, j)) == 0) {
				g = h(i - 1,j,enx,eny);
				//g = 1;
				pq.push(make_pair(make_pair(ex.first.second + 1 + g, ex.first.second + 1), make_pair(i - 1, j)));
				mp.insert(make_pair(make_pair(i - 1,j),ex.first.second + 1));
			}
			else {
				test = mp[make_pair(i - 1, j)];
				if (test > ex.first.second + 1) {
					g = h(i - 1,j,enx,eny);
					//g = 1;
					pq.push(make_pair(make_pair(ex.first.second + 1 + g,ex.first.second + 1), make_pair(i - 1, j)));
					mp[make_pair(i-1,j)] = ex.first.second + 1;
				}
			}
		}

		if (((j + 1 < m) && (i - 1 >= 0)) && (board[i - 1][j + 1] == 0) && (mp1.count(make_pair(i - 1, j+1)) == 0)) {
			if (mp.count(make_pair(i - 1, j + 1)) == 0) {
				g = h(i - 1,j + 1,enx,eny);
				//g = 1;
				pq.push(make_pair(make_pair(ex.first.second + rt2 + g,ex.first.second + rt2), make_pair(i - 1, j+1)));
				mp.insert(make_pair(make_pair(i - 1,j + 1),ex.first.second + rt2));
			}
			else {
				test = mp[make_pair(i - 1, j + 1)];
				if (test > ex.first.second + rt2) {
					g = h(i - 1,j + 1,enx,eny);
					//g = 1;
					pq.push(make_pair(make_pair(ex.first.second + rt2 + g,ex.first.second + rt2), make_pair(i-1, j+1)));
					mp[make_pair(i-1,j+1)] = ex.first.second + rt2;
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
			while(!pq.empty()){
				pq.pop();
			}
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