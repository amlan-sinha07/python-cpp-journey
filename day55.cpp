#include <iostream>
#include <vector>
using namespace std;
class tic_tac_toe{
    public:
    void printboard(vector<vector<char>>& grid){
        for (int i=0; i<3; ++i){
            for (int j=0; j<3; ++j){
                cout<<grid[i][j];
                if (j<2){
                    cout<<" | ";
                }

            }
            cout<<"\n";
            if (i<2) cout<<"----------\n";
        } 
    }
    void playermove(vector<vector<char>>&grid){
        int r,c;
        while(true){
            cout<<"enter your move (row and coloumn (0-2)): ";
            cin>>r>>c;
            if (r>=0 && r<=2 && c>=0 && c<=2){
                if (grid[r][c]==' ') {

                }
            }
        }
    }
};