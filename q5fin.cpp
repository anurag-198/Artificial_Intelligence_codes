#include <bits/stdc++.h>

using namespace std;
int flag;
int cnt;
vector <pair <vector <vector <int> >, int > >sol;
map <vector <vector<int> >,int> mp;
vector <vector <vector <int> > > sol1;

class agent {
public :
int checkboard(vector <vector <int> > board, int n) {
int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == (n - 1) && (j == n - 1) && (board[i][j] == -1))
				return 1;
			if (board[i][j] != (i * n + j + 1)) {
				return 0;
			}
		}
	}
}

void print (vector <vector <int> > board, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if ((i == (n - 1)) && (j == (n - 1)))
				cout << board[i][j] << "\n";
			else 
				cout << board[i][j] <<" ";

		}
	}
}

void printall (int n) {
	for (int i = sol1.size() - 1; i >= 0; i--) {
		print(sol1[i], n);
	}
}

void printthem (vector <pair<vector<vector<int> >,int > > sol, int n) {
	cnt++;
	
	int i = sol.size() - 1;
	while (i >= 0) {
		sol1.push_back(sol[i].first);
		i = sol[i].second;
		
	}
	printall (n);
}

void swapi (int *a, int *b) {
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}

void printsol(vector <vector <int> > board,int i, int j, int n, int maxlevel, int level, int parent) {
	
		sol.push_back(make_pair(board, parent));
		int par = sol.size() - 1;

		if (checkboard(board, n)) {
			flag = 1;
			printthem (sol, n);
		}

		if (flag == 1) {
			return;
		}

		if (level >= maxlevel)
			return;

		mp.insert(make_pair(board,1));
		
		if ((j - 1) >= 0 && flag == 0) {
				swapi(&board[i][j], &board[i][j - 1]);
				if (mp.count(board) == 0) {
					printsol(board, i, j - 1, n, maxlevel, level + 1, par);
				}
				swapi(&board[i][j], &board[i][j - 1]);
		}
		
		if ((i - 1) >= 0 && flag == 0) {
				swapi(&board[i][j], &board[i - 1][j]);
				if (mp.count(board) == 0) {
					printsol(board, i - 1, j, n, maxlevel, level + 1, par);
				}				
				swapi(&board[i][j], &board[i - 1][j]);
		}

		if ((j + 1) < n && flag == 0) {
				swapi(&board[i][j], &board[i][j + 1]); 
				if(mp.count(board) == 0) {
					printsol(board, i, j + 1, n, maxlevel, level + 1,par);	
				}
				swapi(&board[i][j], &board[i][j + 1]);
		}
	
		if ((i + 1) < n && flag == 0) {
			
			swapi(&board[i][j], &board[i + 1][j]);
			if (mp.count(board) == 0) {
				printsol(board, i + 1, j, n, maxlevel, level + 1, par);
			}
			swapi(&board[i][j], &board[i + 1][j]);
		}		
	
}


};

class environment {
	public :
	vector <vector <int> > state;
	int loc1, loc2;
};

int main() {
	environment env;
	agent ag;

	vector <vector <int> > board;
	vector <int> row;
	int i,j,tc, loc1, loc2, n, val;
	cin >> tc;

	while (tc--) {
		cin >> n;
		board.clear();
		row.clear();
		
	
		for (i = 0; i < n; i++) {
			row.clear();
			for (j = 0; j < n; j++) {
				cin >> val;
				row.push_back(val);
				if (val == -1) {
					env.loc1 = i;
					env.loc2 = j;
				}
				
			}
			board.push_back(row);
		}

		env.state = board;

		for (i =  0; i < 50; i++) {
			flag = 0;
			mp.clear();
			sol.clear();
			sol1.clear();
			ag.printsol(env.state, env.loc1, env.loc2, n, i, 0, -1);
			if (flag == 1)
				break;
		}
	}
		return 0;
}
