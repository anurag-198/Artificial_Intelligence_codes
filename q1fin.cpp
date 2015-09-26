#include <bits/stdc++.h>

#define MAX 100
using namespace std;


class environment {
	public :
	vector <vector <int> > state;
	int loc1, loc2;
};

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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i == (n - 1)) && (j == (n - 1)))
				cout << board[i][j] << "\n";
			else 
				cout << board[i][j] <<" ";

		}
	}
}

void swapi (int *a, int *b) {
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}


void printthem(vector <vector <vector <int> > > sol, int cnt, int n) {
	int i, j, k;
	cnt -= 1;
	vector <vector <vector <int> > > fin;
	
	while (cnt > 0) {
		fin.push_back(sol[cnt]);
		cnt = (cnt - 1) / 4;
		
	}
	fin.push_back(sol[0]);

	for (i = fin.size() - 1; i >= 0; i--) {
		print(fin[i], n);
	}
}

void printsol(vector <vector <int> > board,int i, int j, int n) {
	//swapi(&board[i][j], &board[i + 1][j]);
	//print(board, n);
	pair <vector <vector <int> >, pair<int, int> > ex;
	map <vector <vector<int> >,int> mp;
	
	vector<vector <int> > dummy;

	vector <int> rw;

	for (int k = 0; k < n; k++) {
		rw.clear();
		for (int l = 0; l < n; l++) {
			rw.push_back(0);
		}
		dummy.push_back(rw);
	}

	vector < vector <vector <int> > > sol;
	

	list <pair<vector<vector<int> >, pair <int, int> > > queue;

	queue.push_back(make_pair(board, make_pair(i,j)));

	int cnt = 0;

	while (!queue.empty()) {
		cnt++;
		ex = queue.front();
		sol.push_back(ex.first);
		//print(ex.first, n);

		if (checkboard(ex.first, n)) {
			printthem(sol, cnt, n);
			break;
		}

		queue.pop_front();
		mp.insert(make_pair(ex.first,1));

		i = ex.second.first;
		j = ex.second.second;
		
		if ((j - 1) >= 0) {
			
				swapi(&ex.first[i][j], &ex.first[i][j - 1]);
				if (mp.count(ex.first) == 0) {
					queue.push_back(make_pair(ex.first,make_pair(i, j - 1)));
					
				}
				else {
					queue.push_back(make_pair(dummy, make_pair(0,0)));	
				}
				swapi(&ex.first[i][j], &ex.first[i][j - 1]);
		}
		else {

			queue.push_back(make_pair(dummy, make_pair(0,0)));	
		}
		
		if ((i - 1) >= 0) {
			
				swapi(&ex.first[i][j], &ex.first[i - 1][j]);
				if (mp.count(ex.first) == 0) {
					queue.push_back(make_pair(ex.first,make_pair(i - 1, j)));
			
				}
				else {
					queue.push_back(make_pair(dummy, make_pair(0,0)));	
				}
				swapi(&ex.first[i][j], &ex.first[i - 1][j]);
			
		}
		else {
			queue.push_back(make_pair(dummy, make_pair(0,0)));	
		}

			if ((j + 1) < n) {
			
				swapi(&ex.first[i][j], &ex.first[i][j + 1]); 
				if(mp.count(ex.first) == 0) {
					queue.push_back(make_pair(ex.first,make_pair(i, j + 1)));
				
				}
				else {
					queue.push_back(make_pair(dummy, make_pair(0,0)));	
				}
				swapi(&ex.first[i][j], &ex.first[i][j + 1]);
			
		}
		else {
			queue.push_back(make_pair(dummy, make_pair(0,0)));	
		}


		if ((i + 1) < n) {
			
				swapi(&ex.first[i][j], &ex.first[i + 1][j]);
				if (mp.count(ex.first) == 0) {
					queue.push_back(make_pair(ex.first,make_pair(i + 1, j)));
					
				}
				else {
					queue.push_back(make_pair(dummy, make_pair(0,0)));	
				}
				swapi(&ex.first[i][j], &ex.first[i + 1][j]);
			
		}
		else {
			queue.push_back(make_pair(dummy, make_pair(0,0)));	
		}		
	}
	

}

};


int main() {
	int tc, n, i, j, val;
	
	agent sol;
	environment env;

	vector <vector <int> > board;
	vector <int> row;
	
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
		sol.printsol(env.state,env.loc1, env.loc2, n);
	}
	return 0;
}