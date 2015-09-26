#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pdd pair<int,int>
#define pid pair<pdd, pii>


priority_queue<pid, vector <pid>, greater<pid> > pq;

vector < vector <int> > board;

map <pii, int> mp;
map <pii, int> mp1;

int n, m;

int h(int stx, int sty, int enx, int eny) {
	int disx = abs(enx - stx);
	int disy = abs(eny - sty);
	
	int ans = (int)sqrt(disx * disx + disy * disy);
	
    return ans;
}


int getdis(int stx, int sty, int enx, int eny) {
	pid ex;
	
	int g = h(stx,sty,enx,eny);

	pq.push(make_pair(make_pair(g,0), make_pair(stx, sty)));

	int i;
	int j;
	
	int test;

	while (!pq.empty()) {

		ex = pq.top();
		pq.pop();

		mp1.insert(make_pair(ex.second, 1));
		mp.erase(ex.second);
		
		i = ex.second.first;
		j = ex.second.second;

		if ((ex.second.first == enx) && (ex.second.second == eny)) {
			return ex.first.second + board[stx][sty];
		}
	
		
		if ((i + 2 < n)  && (mp1.count(make_pair(i + 2, j)) == 0)) {
			if (mp.count(make_pair(i + 2, j)) == 0) {
				g = h(i + 2,j,enx,eny);
				
				pq.push(make_pair(make_pair(ex.first.second + board[i + 2][j] + 1 + g,ex.first.second +  1 + board[i + 2][j]), make_pair(i + 2, j)));
				mp.insert(make_pair(make_pair(i + 2,j),ex.first.second + board[i+2][j]  + 1));
			}
			else {
				test = mp[make_pair(i + 2, j)];
				if (test > ex.first.second + board[i + 2][j] + 1) {
					g = h(i + 2,j,enx,eny);
					
					pq.push(make_pair(make_pair(ex.first.second + board[i + 2][j] + 1 + g,ex.first.second + board[i + 2][j] + 1), make_pair(i + 2, j)));
					mp[make_pair(i + 2,j)] = ex.first.second + board[i + 2][j] + 1;
				}
			}
		}

		if ((j - 2 >= 0)  && (mp1.count(make_pair(i,j - 2)) == 0)) {
			if (mp.count(make_pair(i, j - 2)) == 0) {
				g = h(i,j - 2, enx,eny);
				
				pq.push(make_pair(make_pair(ex.first.second + board[i][j - 2] + 1 + g,ex.first.second +  1 + board[i][j - 2]), make_pair(i, j - 2)));
				mp.insert(make_pair(make_pair(i,j - 2),ex.first.second + board[i][j - 2]  + 1));
			}
			else {
				test = mp[make_pair(i, j - 2)];
				if (test > ex.first.second + board[i][j - 2] + 1) {
					g = h(i,j - 2,enx,eny);
					
					pq.push(make_pair(make_pair(ex.first.second + board[i][j - 2] + 1 + g,ex.first.second + board[i][j - 2] + 1), make_pair(i, j - 2)));
					mp[make_pair(i,j - 2)] = ex.first.second + board[i][j - 2] + 1;
				}
			}
		}

		if ((i - 2 >= 0)  && (mp1.count(make_pair(i - 2, j)) == 0)) {
			if (mp.count(make_pair(i - 2, j)) == 0) {
				g = h(i - 2,j,enx,eny);
				
				pq.push(make_pair(make_pair(ex.first.second + board[i - 2][j] + 1 + g,ex.first.second +  1 + board[i - 2][j]), make_pair(i - 2, j)));
				mp.insert(make_pair(make_pair(i - 2,j),ex.first.second + board[i-2][j]  + 1));
			}
			else {
				test = mp[make_pair(i - 2, j)];
				if (test > ex.first.second + board[i - 2][j] + 1) {
					g = h(i - 2,j,enx,eny);
					
					pq.push(make_pair(make_pair(ex.first.second + board[i - 2][j] + 1 + g,ex.first.second + board[i - 2][j] + 1), make_pair(i - 2, j)));
					mp[make_pair(i - 2,j)] = ex.first.second + board[i - 2][j] + 1;
				}
			}
		}

		if ((j + 2 < m)  && (mp1.count(make_pair(i, j+2)) == 0)) {
			if (mp.count(make_pair(i, j + 2)) == 0) {
				g = h(i,j + 2,enx,eny);
				
				pq.push(make_pair(make_pair(ex.first.second + board[i][j + 2] + 1 + g,ex.first.second +  1 + board[i][j + 2]), make_pair(i, j+2)));
				mp.insert(make_pair(make_pair(i,j + 2),ex.first.second + board[i][j + 2]  + 1));
			}
			else {
				test = mp[make_pair(i, j + 2)];
				if (test > ex.first.second + board[i][j + 2] + 1) {
					g = h(i,j + 2,enx,eny);
					
					pq.push(make_pair(make_pair(ex.first.second + board[i][j + 2] + 1 + g,ex.first.second + board[i][j + 2] + 1), make_pair(i, j+2)));
					mp[make_pair(i,j+2)] = ex.first.second + board[i][j + 2] + 1;
				}
			}
		}
		
		if ((j + 1 < m)  && (mp1.count(make_pair(i, j+1)) == 0)) {
			if (mp.count(make_pair(i, j + 1)) == 0) {
				g = h(i,j + 1,enx,eny);
				
				pq.push(make_pair(make_pair(ex.first.second + board[i][j+1] + g,ex.first.second + board[i][j+1]), make_pair(i, j+1)));
				mp.insert(make_pair(make_pair(i,j + 1),ex.first.second + board[i][j+1]));
			}
			else {
				test = mp[make_pair(i, j + 1)];
				if (test > ex.first.second + board[i][j+1]) {
					g = h(i,j + 1,enx,eny);
					
					pq.push(make_pair(make_pair(ex.first.second + board[i][j+1] + g,ex.first.second + board[i][j+1]), make_pair(i, j+1)));
					mp[make_pair(i,j+1)] = ex.first.second + board[i][j+1];
				}
			}
		}

		if (((j + 1 < m) && (i + 1 < n)) && (mp1.count(make_pair(i + 1, j+1)) == 0)) {
			if (mp.count(make_pair(i + 1, j + 1)) == 0) {
				g = h(i + 1,j + 1,enx,eny);
				
				pq.push(make_pair(make_pair(ex.first.second + board[i + 1][j + 1] + g,ex.first.second + board[i + 1][j + 1]), make_pair(i + 1, j+1)));
				mp.insert(make_pair(make_pair(i + 1,j + 1),ex.first.second + board[i + 1][j + 1]));
			}
			else {
				test = mp[make_pair(i + 1, j + 1)];
				if (test > ex.first.second + board[i + 1][j + 1]) {
					g = h(i + 1,j + 1,enx,eny);
					
					pq.push(make_pair(make_pair(ex.first.second + board[i + 1][j + 1] + g,ex.first.second + board[i + 1][j + 1]), make_pair(i+1, j+1)));
					mp[make_pair(i+1,j+1)] = ex.first.second + board[i + 1][j + 1];
				}
			}
		}

		if ((i + 1 < n)  && (mp1.count(make_pair(i + 1, j)) == 0)) {
			if (mp.count(make_pair(i + 1, j)) == 0) {
				g = h(i + 1,j,enx,eny);
				
				pq.push(make_pair(make_pair(ex.first.second + board[i+1][j] + g,ex.first.second + board[i+1][j]), make_pair(i + 1, j)));
				mp.insert(make_pair(make_pair(i + 1,j),ex.first.second + board[i+1][j]));
			}
			else {
				test = mp[make_pair(i + 1, j)];
				if (test > ex.first.second + board[i+1][j]) {
					g = h(i + 1,j,enx,eny);
					
					pq.push(make_pair(make_pair(ex.first.second + board[i+1][j] + g,ex.first.second + board[i+1][j]), make_pair(i + 1, j)));
					mp[make_pair(i+1,j)] = ex.first.second + board[i+1][j];
				}
			}
		}

		if (((j - 1 >= 0) && (i + 1 < n))  && (mp1.count(make_pair(i + 1, j-1)) == 0)) {
			if (mp.count(make_pair(i + 1, j - 1)) == 0) {
				g = h(i + 1,j - 1,enx,eny);
				
				pq.push(make_pair(make_pair(ex.first.second + board[i + 1][j - 1] + g,ex.first.second + board[i + 1][j - 1]), make_pair(i + 1, j-1)));
				mp.insert(make_pair(make_pair(i + 1,j - 1),ex.first.second + board[i + 1][j - 1]));
			}
			else {
				test = mp[make_pair(i + 1, j - 1)];
				if (test > ex.first.second + board[i + 1][j - 1]) {
					g = h(i + 1,j - 1,enx,eny);
					
					pq.push(make_pair(make_pair(ex.first.second + board[i + 1][j - 1] + g,ex.first.second + board[i + 1][j - 1]), make_pair(i+1, j-1)));
					mp[make_pair(i+1,j-1)] = ex.first.second + board[i + 1][j - 1];
					
				}
			}
		}

		if ((j - 1 >= 0)  && (mp1.count(make_pair(i, j-1)) == 0)) {
			if (mp.count(make_pair(i, j - 1)) == 0) {
				g = h(i,j - 1,enx,eny);
				
				pq.push(make_pair(make_pair(ex.first.second + board[i][j - 1] + g,ex.first.second + board[i][j - 1]), make_pair(i, j - 1)));
				mp.insert(make_pair(make_pair(i,j - 1),ex.first.second + board[i][j - 1]));
			}
			else {
				test = mp[make_pair(i, j - 1)];
				if (test > ex.first.second + board[i][j - 1]) {
					g = h(i,j - 1,enx,eny);
					
					pq.push(make_pair(make_pair(ex.first.second + board[i][j - 1] + g,ex.first.second + board[i][j - 1]), make_pair(i, j - 1)));
					mp[make_pair(i,j-1)] = ex.first.second + board[i][j - 1];
				}
			}
		}

		if (((j - 1 >= 0) && (i - 1 >= 0))  && (mp1.count(make_pair(i-1, j-1)) == 0)) {
			if (mp.count(make_pair(i - 1, j - 1)) == 0) {
				g = h(i - 1,j - 1,enx,eny);
				
				pq.push(make_pair(make_pair(ex.first.second + board[i - 1][j - 1] + g,ex.first.second + board[i - 1][j - 1]), make_pair(i - 1, j-1)));
				mp.insert(make_pair(make_pair(i - 1,j - 1),ex.first.second + board[i - 1][j - 1]));
			}
			else {
				test = mp[make_pair(i - 1, j - 1)];
				if (test > ex.first.second + board[i - 1][j - 1]) {
					g = h(i - 1,j - 1,enx,eny);
					//
					pq.push(make_pair(make_pair(ex.first.second + board[i - 1][j - 1] + g,ex.first.second + board[i - 1][j - 1]), make_pair(i-1, j-1)));
					mp[make_pair(i-1,j-1)] = ex.first.second + board[i - 1][j - 1];
				}
			}
		}

		if ((i - 1 >= 0)  && (mp1.count(make_pair(i-1, j)) == 0)) {
			if (mp.count(make_pair(i - 1, j)) == 0) {
				g = h(i - 1,j,enx,eny);
				
				pq.push(make_pair(make_pair(ex.first.second + board[i - 1][j] + g, ex.first.second + board[i - 1][j]), make_pair(i - 1, j)));
				mp.insert(make_pair(make_pair(i - 1,j),ex.first.second + board[i - 1][j]));
			}
			else {
				test = mp[make_pair(i - 1, j)];
				if (test > ex.first.second + board[i - 1][j]) {
					g = h(i - 1,j,enx,eny);
					
					pq.push(make_pair(make_pair(ex.first.second + board[i - 1][j] + g,ex.first.second + board[i - 1][j]), make_pair(i - 1, j)));
					mp[make_pair(i-1,j)] = ex.first.second + board[i - 1][j];
				}
			}
		}

		if (((j + 1 < m) && (i - 1 >= 0))  && (mp1.count(make_pair(i - 1, j+1)) == 0)) {
			if (mp.count(make_pair(i - 1, j + 1)) == 0) {
				g = h(i - 1,j + 1,enx,eny);
				
				pq.push(make_pair(make_pair(ex.first.second + board[i - 1][j + 1]  + g,ex.first.second + board[i - 1][j + 1]), make_pair(i - 1, j+1)));
				mp.insert(make_pair(make_pair(i - 1,j + 1),ex.first.second + board[i - 1][j + 1] ));
			}
			else {
				test = mp[make_pair(i - 1, j + 1)];
				if (test > ex.first.second + board[i - 1][j + 1] ) {
					g = h(i - 1,j + 1,enx,eny);
					
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