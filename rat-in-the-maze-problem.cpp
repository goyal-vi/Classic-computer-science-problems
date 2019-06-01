/**
Problem: Consider a rat placed at (0, 0) in a square matrix m[][] of order n and has to reach the 
destination at (n-1, n-1). Your task is to complete the function printPath() which returns a sorted 
array of strings denoting all the possible directions which the rat can take to reach the destination 
at (n-1, n-1). The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).
Here 'false' in maze represents the available paths.

Solution: 


Code:
**/
#include<bits/stdc++.h>
using namespace std;

bool maze[10][10];

int dim;
int mx[] = {1,0,0,-1};
int my[] = {0,-1,1,0};


bool is_safe(int x, int y){
    return ((x >= 0) && (x < dim) && (y>= 0) && (y<dim) && (!maze[x][y]));
}

int next_move(int x, int y, vector<string> &v, string& s){
        if(x == dim-1 && y == dim-1){

            v.push_back(s);


            return 0;
        }
        for(int i=0;i<4;++i){
            if(is_safe(x + mx[i], y+my[i])){
                maze[x+mx[i]][y+my[i]] = true;
                char move;
                switch (i){
                    case 0: move = 'D';
                    break;
                    case 1: move = 'L';
                    break;
                    case 2: move = 'R';
                    break;
                    case 3: move = 'U';
                    break;
                }

                s.push_back(move);
                next_move(x+mx[i], y+my[i], v, s);
                s.pop_back();
                maze[x+mx[i]][y+my[i]] = false;
            }
        }
        return 0;
}

int jerry(){
    memset(maze,false, sizeof maze);
    vector <string> vec;
    cin>>dim;
    for(int i=0;i<dim; ++i){
        for(int j=0; j<dim; ++j){
            int temp;
            cin>>temp;
            if(temp == 0) maze[i][j] = true;
        }
    }

    string ans = string("");
    maze[0][0] = true;
    next_move(0,0,vec, ans);
    for(auto i: vec){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        jerry();
    }
    return 0;
}
