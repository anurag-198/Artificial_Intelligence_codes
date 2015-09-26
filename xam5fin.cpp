#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pdd pair<int,int>
#define pid pair<pdd, pii>

int rt2 = 1.41421;

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

		int stx, sty, enx, eny, enx1, eny1, enx2, eny2;
		while (tc--) {
			while(!pq.empty()){
				pq.pop();
			}
			int sol;
			int sol1;
			mp.clear();
			mp1.clear();
			cin >> stx >> sty >> enx >> eny >> enx1 >> eny1 >> enx2 >> eny2;
			
			int max1 = INT_MAX;

			sol1 = getdis(stx, sty, enx, eny);	
			while(!pq.empty()){
				pq.pop();
			}
			mp.clear();
			mp1.clear();

			int sol2 = getdis(enx, eny, enx1, eny1);
			while(!pq.empty()){
				pq.pop();
			}
			mp.clear();
			mp1.clear();

			int fin1 = sol1 + sol2 - board[enx][eny];


			if (max1 > fin1) {
				max1 = fin1;
			}

			
			sol1 = getdis(stx, sty, enx1, eny1);	
			while(!pq.empty()){
				pq.pop();
			}

			mp.clear();
			mp1.clear();

			sol2 = getdis(enx1, eny1, enx, eny);
			
			while(!pq.empty()){
				pq.pop();
			}

			mp.clear();
			mp1.clear();

			fin1 = sol1 + sol2 - board[enx1][eny1];

			if (max1 > fin1) {
				max1 = fin1;
			}


			sol1 = getdis(stx, sty, enx, eny);	
			while(!pq.empty()){
				pq.pop();
			}

			mp.clear();
			mp1.clear();

			sol2 = getdis(enx, eny, enx2, eny2);
			
			while(!pq.empty()){
				pq.pop();
			}

			mp.clear();
			mp1.clear();

			fin1 = sol1 + sol2 - board[enx][eny];

			if (max1 > fin1) {
				max1 = fin1;
			}



			sol1 = getdis(stx, sty, enx2, eny2);	
			while(!pq.empty()){
				pq.pop();
			}

			mp.clear();
			mp1.clear();

			sol2 = getdis(enx2, eny2, enx, eny);
			
			while(!pq.empty()){
				pq.pop();
			}

			mp.clear();
			mp1.clear();

			fin1 = sol1 + sol2 - board[enx2][eny2];

			if (max1 > fin1) {
				max1 = fin1;
			}







			sol1 = getdis(stx, sty, enx1, eny1);	
			
			while(!pq.empty()){
				pq.pop();
			}

			mp.clear();
			mp1.clear();

			sol2 = getdis(enx1, eny1, enx2, eny2);
			while(!pq.empty()){
				pq.pop();
			}

			mp.clear();
			mp1.clear();

			fin1 = sol1 + sol2 - board[enx1][eny1];

			if (max1 > fin1) {
				max1 = fin1;
			}



			sol1 = getdis(stx, sty, enx2, eny2);	
			while(!pq.empty()){
				pq.pop();
			}

			mp.clear();
			mp1.clear();

			sol2 = getdis(enx2, eny2, enx1, eny1);
			
			while(!pq.empty()){
				pq.pop();
			}

			mp.clear();
			mp1.clear();

			fin1 = sol1 + sol2 - board[enx2][eny2];

			if (max1 > fin1) {
				max1 = fin1;
			}


			cout << max1 << "\n";
		}
		return 0;
}