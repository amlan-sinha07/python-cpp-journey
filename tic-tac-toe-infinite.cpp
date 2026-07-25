#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <queue>
using namespace std;
class tic_tac_toe{
    public:
    queue<pair<int,int>>playerX_moves;
    queue<pair<int,int>>playerO_moves;
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
    pair<int,int>findwinningmove(vector<vector<char>>grid,char symbol){
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                if (grid[i][j]==' '){
                    grid[i][j]=symbol;
                    bool wins=checkwin(grid,symbol);
                    grid[i][j]=' ';
                    if (wins){
                        return{i,j};
                    }
                }
            }
        }
        return {-1,-1};
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
    void applymove(vector<vector<char>>& grid,queue<pair<int,int>>&playermoves,int r,int c,char symbol){
        if (playermoves.size()==4){
            pair<int,int>oldest=playermoves.front();
            playermoves.pop();
            grid[oldest.first][oldest.second]=' ';
            cout<<"notice: player "<<symbol<<"'s oldest mark at ("<<oldest.first<<", "<<oldest.second<<") was removed\n";
        }
        grid[r][c]=symbol;
        playermoves.push({r,c});
    }
    void playermove(vector<vector<char>>&grid,queue<pair<int,int>>& moves,char symbol){
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
                    applymove(grid,moves,r,c,symbol);
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

    
    void computermove(vector<vector<char>>& grid,queue<pair<int,int>>& compmoves,char computersymbol){
        //pair<int,int>findwinningmove(vector<vector<char>> grid,char symbol);
        char playersymbol=(computersymbol=='X')? 'O':'X';
        pair<int,int>winmove=findwinningmove(grid,computersymbol);
        if (winmove.first!=-1){
            //grid[winmove.first][winmove.second]=computersymbol;
            applymove(grid,compmoves,winmove.first,winmove.second,computersymbol);
            cout<<"computer moves at "<<winmove.first<<" "<<winmove.second<<" for the WIN\n";
            return;
        }
        pair<int,int>blockmove=findwinningmove(grid,playersymbol);
        if (blockmove.first!=-1){
            //grid[blockmove.first][blockmove.second]=computersymbol;
            applymove(grid,compmoves,blockmove.first,blockmove.second,computersymbol);
            cout<<"computer blocks player at "<<blockmove.first<<" "<<blockmove.second<<"!\n";
            return;
        }
        if (grid[1][1]==' '){
            applymove(grid,compmoves,1,1,computersymbol);
            cout<<"computer takes center (1,1)\n";
            return;
        }
        vector<pair<int,int>>emptyspots;
        for(int i=0;i<3;i++){
            for (int j=0;j<3;++j){
                if (grid[i][j]==' '){
                    emptyspots.push_back({i,j});
                }
            }
        }
        if (!emptyspots.empty()){
            int randomindex=rand()%emptyspots.size();
            int i=emptyspots[randomindex].first;
            int j=emptyspots[randomindex].second;
            //grid[i][j]=computersymbol;
            applymove(grid,compmoves,i,j,computersymbol);
            cout<<"computer("<<computersymbol<<") placed at: "<<i<<" "<<j<<"\n";
        }
    }
};
int main(){
    srand(time(0));
    tic_tac_toe game;
    vector<vector<char>>grid(3,vector<char>(3,' '));
    char currentplayer='X';
    bool gameover=false;
    cout<<"===TIC-TAC-TOE: Human ('X') vs computer ('O')===\n\n";
    while(!gameover){
        game.printboard(grid);
        cout<<"\n";
        if (currentplayer=='X'){
            game.playermove(grid,game.playerX_moves,'X');
        } else {
            cout<<"computer is making move...\n";
            game.computermove(grid,game.playerO_moves,'O');
        }
        //game.playermove(grid,currentplayer);
        if(game.checkwin(grid,currentplayer)){
            game.printboard(grid);
            if (currentplayer=='X'){
                cout<<"\nCongratulation you won!\n";
            } else {
                cout<<"\nthe computer won! better luck next time\n";
            }
            gameover=true;
            //cout<<currentplayer<<"win\n";
            //break;
        }
        else if (game.checkdraw(grid)){
            game.printboard(grid);
            cout<<"\nIt is draw\n";
            gameover=true;
        } else {
        currentplayer=(currentplayer=='X')?'O':'X';
        }
        cout<<"\n--------------------\n";
    }
    return 0;
}