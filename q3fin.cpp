#include <bits/stdc++.h>

#define MAX 100
using namespace std;

class environment {
public :
	vector <vector <int> > state;
	int loc1, loc2, loc3, loc4;
};

class agent {
public :
int checkboard(vector <vector <int> > board, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == (n - 1) && (j == n - 2) && (board[i][j] == -1) && (board[i][j + 1] == -1))
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

void printsol(vector <vector <int> > board,int i, int j, int loc3, int loc4, int n) {
	pair <vector <vector <int> >, pair <pair<int, int>, pair <int, int> > > ex;
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

	list <pair<vector<vector<int> >, pair <pair <int, int>, pair <int, int> > > > queue;

	queue.push_back(make_pair(board, make_pair(make_pair(i,j) , make_pair (loc3, loc4)) ));

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

		i = ex.second.first.first;
		j = ex.second.first.second;

		loc3 = ex.second.second.first;
		loc4 = ex.second.second.second;

		if (i < loc3) {
			if ((j - 1) >= 0) {
			
				swapi(&ex.first[i][j], &ex.first[i][j - 1]);
				if (mp.count(ex.first) == 0) {
					queue.push_back(make_pair(ex.first,make_pair(make_pair(i, j - 1), make_pair(loc3, loc4)) ));
					
				}
				else {
					queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0)) ));	
				}
				swapi(&ex.first[i][j], &ex.first[i][j - 1]);
			}
			else {

				queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0)) ));	
			}
		
			if ((i - 1) >= 0) {
			
				swapi(&ex.first[i][j], &ex.first[i - 1][j]);
				if (mp.count(ex.first) == 0) {
					queue.push_back(make_pair(ex.first,make_pair (make_pair(i - 1, j), make_pair(loc3, loc4)) ));
			
				}
				else {
					queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0)) ));	
				}
				swapi(&ex.first[i][j], &ex.first[i - 1][j]);
			
			}
			else {
				queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0)) ));	
			}

			if ((j + 1) < n) {
			
				swapi(&ex.first[i][j], &ex.first[i][j + 1]); 
				if(mp.count(ex.first) == 0) {
					queue.push_back(make_pair(ex.first, make_pair (make_pair(i, j + 1), make_pair(loc3, loc4)) ));
				
				}
				else {
					queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0)) ));	
				}
				swapi(&ex.first[i][j], &ex.first[i][j + 1]);
			
			}
			else {
				queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0)) ));	
			}


			if ((i + 1) < n) {
			
				swapi(&ex.first[i][j], &ex.first[i + 1][j]);
				if (mp.count(ex.first) == 0) {
					queue.push_back(make_pair(ex.first,make_pair (make_pair(i + 1, j), make_pair(loc3, loc4)) ));
					
				}
				else {
					queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0)) ));	
				}
				swapi(&ex.first[i][j], &ex.first[i + 1][j]);
			
			}
			else {
				queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0)) ));	
			}	
	
		}
		else if (loc3 < i){
			if ((loc4 - 1) >= 0) {
			
				swapi(&ex.first[loc3][loc4], &ex.first[loc3][loc4 - 1]);
				if (mp.count(ex.first) == 0) {
					queue.push_back(make_pair(ex.first,make_pair(make_pair(i,j),make_pair(loc3, loc4 - 1)) ));
					
				}
				else {
					queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0)) ));	
				}
				swapi(&ex.first[loc3][loc4], &ex.first[loc3][loc4 - 1]);
			}
			else {

				queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0)) ));	
			}
		
			if ((loc3 - 1) >= 0) {
			
				swapi(&ex.first[loc3][loc4], &ex.first[loc3 - 1][loc4]);
				if (mp.count(ex.first) == 0) {
					queue.push_back(make_pair(ex.first,make_pair (make_pair(i,j) ,make_pair(loc3 - 1, loc4)) ));
			
				}
				else {
					queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0)) ));	
				}
				swapi(&ex.first[loc3][loc4], &ex.first[loc3 - 1][loc4]);
			
			}
			else {
				queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0)) ));	
			}

			if ((loc4 + 1) < n) {
			
				swapi(&ex.first[loc3][loc4], &ex.first[loc3][loc4 + 1]); 
				if(mp.count(ex.first) == 0) {
					queue.push_back(make_pair(ex.first,make_pair (make_pair(i, j) ,make_pair(loc3, loc4 + 1)) ));
				
				}
				else {
					queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
				}
				swapi(&ex.first[loc3][loc4], &ex.first[loc3][loc4 + 1]);
			
			}
			else {
				queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
			}


			if ((loc3 + 1) < n) {
			
				swapi(&ex.first[loc3][loc4], &ex.first[loc3 + 1][loc4]);
				if (mp.count(ex.first) == 0) {
					queue.push_back(make_pair(ex.first,make_pair (make_pair(i,j), make_pair(loc3 + 1, loc4)) ));
					
				}
				else {
					queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
				}
				swapi(&ex.first[loc3][loc4], &ex.first[loc3 + 1][loc4]);
			
			}
			else {
				queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
			}	

		}
		else if (loc3 == i){
			if (j < loc4) {

				if ((j - 1) >= 0) {
			
					swapi(&ex.first[i][j], &ex.first[i][j - 1]);
					if (mp.count(ex.first) == 0) {
						queue.push_back(make_pair(ex.first,make_pair (make_pair(i, j - 1), make_pair(loc3, loc4)) ));
					
					}
					else {
						queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
					}
					swapi(&ex.first[i][j], &ex.first[i][j - 1]);
				}
				else {

					queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
				}
		
				if ((i - 1) >= 0) {
			
					swapi(&ex.first[i][j], &ex.first[i - 1][j]);
					if (mp.count(ex.first) == 0) {
						queue.push_back(make_pair(ex.first,make_pair (make_pair(i - 1, j), make_pair(loc3, loc4)) ));
			
					}
					else {
						queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
					}
					swapi(&ex.first[i][j], &ex.first[i - 1][j]);
			
				}
				else {
					queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
				}

				if ((j + 1) < n) {
			
					swapi(&ex.first[i][j], &ex.first[i][j + 1]); 
					if(mp.count(ex.first) == 0) {
						queue.push_back(make_pair(ex.first,make_pair(make_pair(i, j + 1), make_pair(loc3, loc4)) ));
				
					}
					else {
						queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
					}
					swapi(&ex.first[i][j], &ex.first[i][j + 1]);
			
				}
				else {
					queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
				}


				if ((i + 1) < n) {
				
					swapi(&ex.first[i][j], &ex.first[i + 1][j]);
					if (mp.count(ex.first) == 0) {
						queue.push_back(make_pair(ex.first,make_pair (make_pair(i + 1, j), make_pair(loc3, loc4)) ));
					
					}
					else {
						queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
					}
					swapi(&ex.first[i][j], &ex.first[i + 1][j]);
			
				}
				else {
					queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
				}	

			}
			else {
				if ((loc4 - 1) >= 0) {
			
					swapi(&ex.first[loc3][loc4], &ex.first[loc3][loc4 - 1]);
					if (mp.count(ex.first) == 0) {
						queue.push_back(make_pair(ex.first,make_pair (make_pair(i,j), make_pair(loc3, loc4 - 1)) ));
					
					}
					else {
						queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
					}
					swapi(&ex.first[loc3][loc4], &ex.first[loc3][loc4 - 1]);
				}
				else {

					queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
				}
		
				if ((loc3 - 1) >= 0) {
			
					swapi(&ex.first[loc3][loc4], &ex.first[loc3 - 1][loc4]);
					if (mp.count(ex.first) == 0) {
						queue.push_back(make_pair(ex.first,make_pair (make_pair(i,j), make_pair(loc3 - 1, loc4)) ));
			
					}
					else {
						queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
					}
					swapi(&ex.first[loc3][loc4], &ex.first[loc3 - 1][loc4]);
			
				}
				else {
					queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
				}

				if ((loc4 + 1) < n) {
			
					swapi(&ex.first[loc3][loc4], &ex.first[loc3][loc4 + 1]); 
					if(mp.count(ex.first) == 0) {
						queue.push_back(make_pair(ex.first,make_pair (make_pair(i,j) , make_pair(loc3, loc4 + 1)) ));
				
					}
					else {
						queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
					}
					swapi(&ex.first[loc3][loc4], &ex.first[loc3][loc4 + 1]);
			
				}
				else {
					queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
				}


				if ((loc3 + 1) < n) {
			
					swapi(&ex.first[loc3][loc4], &ex.first[loc3 + 1][loc4]);
					if (mp.count(ex.first) == 0) {
						queue.push_back(make_pair(ex.first,make_pair (make_pair(i, j) ,make_pair(loc3 + 1, loc4)) ));
					
					}
					else {
						queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
					}
					swapi(&ex.first[loc3][loc4], &ex.first[loc3 + 1][loc4]);
			
				}
				else {
					queue.push_back(make_pair(dummy, make_pair (make_pair(0,0), make_pair(0,0))));	
				}	

			}

		}

	}
	
}	


};












int main() {
	agent ag;
	environment env;

	int tc, n, i, j, val;
	int loc1, loc2, loc3, loc4;
	vector <vector <int> > board;
	vector <int> row;
	
	int flag = 0;

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

				if ((val == -1) && (flag == 1)) {
					env.loc3 = i;
					env.loc4 = j;
					
				}

				if ((val == -1) && (flag != 1)) {
					env.loc1 = i;
					env.loc2 = j;
					flag = 1;

				}
				
			}
			board.push_back(row);
		}

		env.state = board;
		
		ag.printsol(env.state,env.loc1, env.loc2, env.loc3, env.loc4, n);
	}
	return 0;
}