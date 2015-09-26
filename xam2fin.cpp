#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pdd pair<int,int>
#define pid pair<pdd, pii>

int rt2 = 1.41421;

priority_queue<pid, vector <pid>, greater<pid> > pq;

map <pii, pii> parent;

vector < vector <int> > board;

map <pii, int> mp;
map <pii, int> mp1;

int n, m;

int solve (int stx, int sty, int enx, int eny) {
	
	int max = 0;
	int i = enx;
	int j = eny;
	while (i != -1 && j != -1) {
		int val = board[i][j];
		cout << val << endl;
		if (max < val) {
			max = val;
		}
		i = parent[make_pair(i,j)].first;
		j = parent[make_pair(i,j)].second;
	}
	return max;
}

int h(int stx, int sty, int enx, int eny) {
	int disx = abs(enx - stx);
	int disy = abs(eny - sty);
	
	int ans = (int)sqrt(disx * disx + disy * disy);
	
    return ans;
}


int getdis(int stx, int sty, int enx, int eny) {
	pid ex;
	
	int g = h(stx,sty,enx,eny);

	parent[make_pair(stx, sty)] = make_pair(-1, -1);


	pq.push(make_pair(make_pair(g,0), make_pair(stx, sty)));

	int i;
	int j;
	
	int test;

	int max = 0;
	while (!pq.empty()) {

		ex = pq.top();
		pq.pop();

		if (max < ex.first.second) {
			max = board[ex.second.first][ex.second.second];
		}

		mp1.insert(make_pair(ex.second, 1));
		mp.erase(ex.second);
		
		i = ex.second.first;
		j = ex.second.second;

		if ((ex.second.first == enx) && (ex.second.second == eny)) {
			cout << ex.first.second + board[stx][sty] << endl;
			return solve(stx, sty, enx, eny);
		}
	
		

		if ((j + 1 < m)  && (mp1.count(make_pair(i, j+1)) == 0)) {
			if (mp.count(make_pair(i, j + 1)) == 0) {
				g = h(i,j + 1,enx,eny);
				parent[make_pair(i, j + 1)] = make_pair(i,j);
				pq.push(make_pair(make_pair(ex.first.second + board[i][j+1] + g,ex.first.second + board[i][j+1]), make_pair(i, j+1)));
				mp.insert(make_pair(make_pair(i,j + 1),ex.first.second + board[i][j+1]));
			}
			else {
				test = mp[make_pair(i, j + 1)];
				if (test > ex.first.second + board[i][j+1]) {
					g = h(i,j + 1,enx,eny);
					parent[make_pair(i, j + 1)] = make_pair(i,j);
					pq.push(make_pair(make_pair(ex.first.second + board[i][j+1] + g,ex.first.second + board[i][j+1]), make_pair(i, j+1)));
					mp[make_pair(i,j+1)] = ex.first.second + board[i][j+1];
				}
			}
		}

		if (((j + 1 < m) && (i + 1 < n)) && (mp1.count(make_pair(i + 1, j+1)) == 0)) {
			if (mp.count(make_pair(i + 1, j + 1)) == 0) {
				g = h(i + 1,j + 1,enx,eny);
				parent[make_pair(i + 1, j + 1)] = make_pair(i,j);
				pq.push(make_pair(make_pair(ex.first.second + board[i + 1][j + 1] + g,ex.first.second + board[i + 1][j + 1]), make_pair(i + 1, j+1)));
				mp.insert(make_pair(make_pair(i + 1,j + 1),ex.first.second + board[i + 1][j + 1]));
			}
			else {
				test = mp[make_pair(i + 1, j + 1)];
				if (test > ex.first.second + board[i + 1][j + 1]) {
					g = h(i + 1,j + 1,enx,eny);
					parent[make_pair(i + 1, j + 1)] = make_pair(i,j);
					pq.push(make_pair(make_pair(ex.first.second + board[i + 1][j + 1] + g,ex.first.second + board[i + 1][j + 1]), make_pair(i+1, j+1)));
					mp[make_pair(i+1,j+1)] = ex.first.second + board[i + 1][j + 1];
				}
			}
		}

		if ((i + 1 < n)  && (mp1.count(make_pair(i + 1, j)) == 0)) {
			if (mp.count(make_pair(i + 1, j)) == 0) {
				g = h(i + 1,j,enx,eny);
				parent[make_pair(i + 1, j)] = make_pair(i,j);
				pq.push(make_pair(make_pair(ex.first.second + board[i+1][j] + g,ex.first.second + board[i+1][j]), make_pair(i + 1, j)));
				mp.insert(make_pair(make_pair(i + 1,j),ex.first.second + board[i+1][j]));
			}
			else {
				test = mp[make_pair(i + 1, j)];
				if (test > ex.first.second + board[i+1][j]) {
					g = h(i + 1,j,enx,eny);
					parent[make_pair(i + 1, j)] = make_pair(i,j);
					pq.push(make_pair(make_pair(ex.first.second + board[i+1][j] + g,ex.first.second + board[i+1][j]), make_pair(i + 1, j)));
					mp[make_pair(i+1,j)] = ex.first.second + board[i+1][j];
				}
			}
		}

		if (((j - 1 >= 0) && (i + 1 < n))  && (mp1.count(make_pair(i + 1, j-1)) == 0)) {
			if (mp.count(make_pair(i + 1, j - 1)) == 0) {
				g = h(i + 1,j - 1,enx,eny);
				parent[make_pair(i + 1, j - 1)] = make_pair(i,j);
				pq.push(make_pair(make_pair(ex.first.second + board[i + 1][j - 1] + g,ex.first.second + board[i + 1][j - 1]), make_pair(i + 1, j-1)));
				mp.insert(make_pair(make_pair(i + 1,j - 1),ex.first.second + board[i + 1][j - 1]));
			}
			else {
				test = mp[make_pair(i + 1, j - 1)];
				if (test > ex.first.second + board[i + 1][j - 1]) {
					g = h(i + 1,j - 1,enx,eny);
					parent[make_pair(i + 1, j - 1)] = make_pair(i,j);
					pq.push(make_pair(make_pair(ex.first.second + board[i + 1][j - 1] + g,ex.first.second + board[i + 1][j - 1]), make_pair(i+1, j-1)));
					mp[make_pair(i+1,j-1)] = ex.first.second + board[i + 1][j - 1];
					
				}
			}
		}

		if ((j - 1 >= 0)  && (mp1.count(make_pair(i, j-1)) == 0)) {
			if (mp.count(make_pair(i, j - 1)) == 0) {
				g = h(i,j - 1,enx,eny);
				parent[make_pair(i, j - 1)] = make_pair(i,j);
				pq.push(make_pair(make_pair(ex.first.second + board[i][j - 1] + g,ex.first.second + board[i][j - 1]), make_pair(i, j - 1)));
				mp.insert(make_pair(make_pair(i,j - 1),ex.first.second + board[i][j - 1]));
			}
			else {
				test = mp[make_pair(i, j - 1)];
				if (test > ex.first.second + board[i][j - 1]) {
					g = h(i,j - 1,enx,eny);
					parent[make_pair(i, j - 1)] = make_pair(i,j);
					pq.push(make_pair(make_pair(ex.first.second + board[i][j - 1] + g,ex.first.second + board[i][j - 1]), make_pair(i, j - 1)));
					mp[make_pair(i,j-1)] = ex.first.second + board[i][j - 1];
				}
			}
		}

		if (((j - 1 >= 0) && (i - 1 >= 0))  && (mp1.count(make_pair(i-1, j-1)) == 0)) {
			if (mp.count(make_pair(i - 1, j - 1)) == 0) {
				g = h(i - 1,j - 1,enx,eny);
				parent[make_pair(i - 1, j - 1)] = make_pair(i,j);
				pq.push(make_pair(make_pair(ex.first.second + board[i - 1][j - 1] + g,ex.first.second + board[i - 1][j - 1]), make_pair(i - 1, j-1)));
				mp.insert(make_pair(make_pair(i - 1,j - 1),ex.first.second + board[i - 1][j - 1]));
			}
			else {
				test = mp[make_pair(i - 1, j - 1)];
				if (test > ex.first.second + board[i - 1][j - 1]) {
					g = h(i - 1,j - 1,enx,eny);
					parent[make_pair(i - 1, j - 1)] = make_pair(i,j);
					pq.push(make_pair(make_pair(ex.first.second + board[i - 1][j - 1] + g,ex.first.second + board[i - 1][j - 1]), make_pair(i-1, j-1)));
					mp[make_pair(i-1,j-1)] = ex.first.second + board[i - 1][j - 1];
				}
			}
		}

		if ((i - 1 >= 0)  && (mp1.count(make_pair(i-1, j)) == 0)) {
			if (mp.count(make_pair(i - 1, j)) == 0) {
				g = h(i - 1,j,enx,eny);
				parent[make_pair(i - 1, j)] = make_pair(i,j);
				pq.push(make_pair(make_pair(ex.first.second + board[i - 1][j] + g, ex.first.second + board[i - 1][j]), make_pair(i - 1, j)));
				mp.insert(make_pair(make_pair(i - 1,j),ex.first.second + board[i - 1][j]));
			}
			else {
				test = mp[make_pair(i - 1, j)];
				if (test > ex.first.second + board[i - 1][j]) {
					g = h(i - 1,j,enx,eny);
					parent[make_pair(i - 1, j)] = make_pair(i,j);
					pq.push(make_pair(make_pair(ex.first.second + board[i - 1][j] + g,ex.first.second + board[i - 1][j]), make_pair(i - 1, j)));
					mp[make_pair(i-1,j)] = ex.first.second + board[i - 1][j];
				}
			}
		}

		if (((j + 1 < m) && (i - 1 >= 0))  && (mp1.count(make_pair(i - 1, j+1)) == 0)) {
			if (mp.count(make_pair(i - 1, j + 1)) == 0) {
				g = h(i - 1,j + 1,enx,eny);
				parent[make_pair(i - 1, j + 1)] = make_pair(i,j);
				pq.push(make_pair(make_pair(ex.first.second + board[i - 1][j + 1]  + g,ex.first.second + board[i - 1][j + 1]), make_pair(i - 1, j+1)));
				mp.insert(make_pair(make_pair(i - 1,j + 1),ex.first.second + board[i - 1][j + 1] ));
			}
			else {
				test = mp[make_pair(i - 1, j + 1)];
				if (test > ex.first.second + board[i - 1][j + 1] ) {
					g = h(i - 1,j + 1,enx,eny);
					parent[make_pair(i - 1, j + 1)] = make_pair(i,j);
					pq.push(make_pair(make_pair(ex.first.second + board[i - 1][j + 1]  + g,ex.first.second + board[i - 1][j + 1]), make_pair(i-1, j+1)));
					mp[make_pair(i-1,j+1)] = ex.first.second + board[i - 1][j + 1];
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
			int sol;
			int sol1;
			mp.clear();
			mp1.clear();
			cin >> stx >> sty >> enx >> eny;
			sol = getdis(stx, sty, enx, eny);	
			sol1 = sol;
			cout << sol1 << "\n";
		}
		return 0;
}