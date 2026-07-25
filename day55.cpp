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
    void playermove(vector<vector<char>>&grid,char symbol){
        //char symbol='X' || 'O';
        int r,c;
        while(true){
            cout<<"enter your move (row and coloumn (0-2)): ";
            cin>>r>>c;
            if (cin.fail()){
                cin.clear();
                cin.ignore(10000,'\n');
                cout<<"please enter valid integer coordinate\n";
                continue;
            }
            if (r>=0 && r<=2 && c>=0 && c<=2){
                if (grid[r][c]==' ') {
                    grid[r][c]=symbol;
                    break;
                } else {
                    cout<<"that cell already taken\n";
                }
            } else {
                cout<<"cordinates must in between 0 and 2.";
            }
        }
    }
    bool checkdraw(const vector<vector<char>>& grid){
        //int r,c;
        for (int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                if (grid[i][j]==' '){
                    return false;
                }
            }
        } return true;
    }
    bool checkwin(const vector<vector<char>>& grid,char symbol){
        for (int i=0;i<3;++i){
            if (grid[i][0]==symbol && grid[i][1]==symbol && grid[i][2]==symbol){
                return true;
            }
            if (grid[0][i]==symbol && grid[1][i]==symbol && grid[2][i]==symbol){
                return true;
            }
        }
        if (grid[0][0]==symbol && grid[1][1]==symbol && grid[2][2]==symbol){
            return true;
        }
        if (grid[0][2]==symbol && grid[1][1]==symbol && grid[2][0]==symbol){
            return true;
        }
        return false;
    }

};
int main(){
    tic_tac_toe game;
    vector<vector<char>>grid(3,vector<char>(3,' '));
    char currentplayer='X';
    while(true){
        game.printboard(grid);
        game.playermove(grid,currentplayer);
        if(game.checkwin(grid,currentplayer)){
            game.printboard(grid);
            cout<<currentplayer<<"win\n";
            break;
        }
        if (game.checkdraw(grid)){
            game.printboard(grid);
            cout<<"draw\n";
            break;
        }
        currentplayer=(currentplayer=='X')?'O':'X';
    }
    return 0;
}