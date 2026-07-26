// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <ctime>
// #include <utility>
// #include <queue>
// using namespace std;
// class tic_tac_toe{
//     public:
//     queue<pair<int,int>>playerX_moves;
//     queue<pair<int,int>>playerO_moves;
//     void printboard(vector<vector<char>>& grid){
//         for (int i=0; i<3; ++i){
//             for (int j=0; j<3; ++j){
//                 cout<<grid[i][j];
//                 if (j<2){
//                     cout<<" | ";
//                 }

//             }
//             cout<<"\n";
//             if (i<2) cout<<"----------\n";
//         } 
//     }
//     pair<int,int>findwinningmove(vector<vector<char>>grid,char symbol){
//         for(int i=0;i<3;++i){
//             for(int j=0;j<3;++j){
//                 if (grid[i][j]==' '){
//                     grid[i][j]=symbol;
//                     bool wins=checkwin(grid,symbol);
//                     grid[i][j]=' ';
//                     if (wins){
//                         return{i,j};
//                     }
//                 }
//             }
//         }
//         return {-1,-1};
//     }
//     bool checkwin(const vector<vector<char>>& grid,char symbol){
//         for (int i=0;i<3;++i){
//             if (grid[i][0]==symbol && grid[i][1]==symbol && grid[i][2]==symbol){
//                 return true;
//             }
//             if (grid[0][i]==symbol && grid[1][i]==symbol && grid[2][i]==symbol){
//                 return true;
//             }
//         }
//         if (grid[0][0]==symbol && grid[1][1]==symbol && grid[2][2]==symbol){
//             return true;
//         }
//         if (grid[0][2]==symbol && grid[1][1]==symbol && grid[2][0]==symbol){
//             return true;
//         }
//         return false;
//     }
//     void applymove(vector<vector<char>>& grid,queue<pair<int,int>>&playermoves,int r,int c,char symbol){
//         if (playermoves.size()==4){
//             pair<int,int>oldest=playermoves.front();
//             playermoves.pop();
//             grid[oldest.first][oldest.second]=' ';
//             cout<<"notice: player "<<symbol<<"'s oldest mark at ("<<oldest.first<<", "<<oldest.second<<") was removed\n";
//         }
//         grid[r][c]=symbol;
//         playermoves.push({r,c});
//     }
//     void playermove(vector<vector<char>>&grid,queue<pair<int,int>>& moves,char symbol){
//         //char symbol='X' || 'O';
//         int r,c;
//         while(true){
//             cout<<"enter your move (row and coloumn (0-2)): ";
//             cin>>r>>c;
//             if (cin.fail()){
//                 cin.clear();
//                 cin.ignore(10000,'\n');
//                 cout<<"please enter valid integer coordinate\n";
//                 continue;
//             }
//             if (r>=0 && r<=2 && c>=0 && c<=2){
//                 if (grid[r][c]==' ') {
//                     applymove(grid,moves,r,c,symbol);
//                     break;
//                 } else {
//                     cout<<"that cell already taken\n";
//                 }
//             } else {
//                 cout<<"cordinates must in between 0 and 2.";
//             }
//         }
//     }
//     bool checkdraw(const vector<vector<char>>& grid){
//         //int r,c;
//         for (int i=0;i<3;++i){
//             for(int j=0;j<3;++j){
//                 if (grid[i][j]==' '){
//                     return false;
//                 }
//             }
//         } return true;
//     }

    
//     void computermove(vector<vector<char>>& grid,queue<pair<int,int>>& compmoves,char computersymbol){
//         //pair<int,int>findwinningmove(vector<vector<char>> grid,char symbol);
//         char playersymbol=(computersymbol=='X')? 'O':'X';
//         pair<int,int>winmove=findwinningmove(grid,computersymbol);
//         if (winmove.first!=-1){
//             //grid[winmove.first][winmove.second]=computersymbol;
//             applymove(grid,compmoves,winmove.first,winmove.second,computersymbol);
//             cout<<"computer moves at "<<winmove.first<<" "<<winmove.second<<" for the WIN\n";
//             return;
//         }
//         pair<int,int>blockmove=findwinningmove(grid,playersymbol);
//         if (blockmove.first!=-1){
//             //grid[blockmove.first][blockmove.second]=computersymbol;
//             applymove(grid,compmoves,blockmove.first,blockmove.second,computersymbol);
//             cout<<"computer blocks player at "<<blockmove.first<<" "<<blockmove.second<<"!\n";
//             return;
//         }
//         if (grid[1][1]==' '){
//             applymove(grid,compmoves,1,1,computersymbol);
//             cout<<"computer takes center (1,1)\n";
//             return;
//         }
//         vector<pair<int,int>>emptyspots;
//         for(int i=0;i<3;i++){
//             for (int j=0;j<3;++j){
//                 if (grid[i][j]==' '){
//                     emptyspots.push_back({i,j});
//                 }
//             }
//         }
//         if (!emptyspots.empty()){
//             int randomindex=rand()%emptyspots.size();
//             int i=emptyspots[randomindex].first;
//             int j=emptyspots[randomindex].second;
//             //grid[i][j]=computersymbol;
//             applymove(grid,compmoves,i,j,computersymbol);
//             cout<<"computer("<<computersymbol<<") placed at: "<<i<<" "<<j<<"\n";
//         }
//     }
// };
// int main(){
//     srand(time(0));
//     tic_tac_toe game;
//     vector<vector<char>>grid(3,vector<char>(3,' '));
//     char currentplayer='X';
//     bool gameover=false;
//     cout<<"===TIC-TAC-TOE: Human ('X') vs computer ('O')===\n\n";
//     while(!gameover){
//         game.printboard(grid);
//         cout<<"\n";
//         if (currentplayer=='X'){
//             game.playermove(grid,game.playerX_moves,'X');
//         } else {
//             cout<<"computer is making move...\n";
//             game.computermove(grid,game.playerO_moves,'O');
//         }
//         //game.playermove(grid,currentplayer);
//         if(game.checkwin(grid,currentplayer)){
//             game.printboard(grid);
//             if (currentplayer=='X'){
//                 cout<<"\nCongratulation you won!\n";
//             } else {
//                 cout<<"\nthe computer won! better luck next time\n";
//             }
//             gameover=true;
//             //cout<<currentplayer<<"win\n";
//             //break;
//         }
//         else if (game.checkdraw(grid)){
//             game.printboard(grid);
//             cout<<"\nIt is draw\n";
//             gameover=true;
//         } else {
//         currentplayer=(currentplayer=='X')?'O':'X';
//         }
//         cout<<"\n--------------------\n";
//     }
//     return 0;
// }
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>

const int SIZE = 3;
const int CELL_SIZE = 200;
const int WINDOW_SIZE = SIZE * CELL_SIZE;

struct MoveQueue {
    std::deque<std::pair<int,int>> moves;
    int maxlen;
    MoveQueue(int m):maxlen(m){}
    void apply(std::vector<std::vector<char>>& grid,int r,int c,char symbol){
        if((int)moves.size()==maxlen){
            auto oldest=moves.front();
            moves.pop_front();
            grid[oldest.first][oldest.second]=' ';
        }
        grid[r][c]=symbol;
        moves.push_back({r,c});
    }
};

bool checkWin(const std::vector<std::vector<char>>& grid,char symbol){
    for(int i=0;i<SIZE;i++){
        if(grid[i][0]==symbol && grid[i][1]==symbol && grid[i][2]==symbol) return true;
        if(grid[0][i]==symbol && grid[1][i]==symbol && grid[2][i]==symbol) return true;
    }
    if(grid[0][0]==symbol && grid[1][1]==symbol && grid[2][2]==symbol) return true;
    if(grid[0][2]==symbol && grid[1][1]==symbol && grid[2][0]==symbol) return true;
    return false;
}

bool checkDraw(const std::vector<std::vector<char>>& grid){
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            if(grid[i][j]==' ') return false;
    return true;
}

std::pair<int,int> findWinningMove(std::vector<std::vector<char>>& grid,char symbol){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(grid[i][j]==' '){
                grid[i][j]=symbol;
                bool win=checkWin(grid,symbol);
                grid[i][j]=' ';
                if(win) return {i,j};
            }
        }
    }
    return {-1,-1};
}

void computerMove(std::vector<std::vector<char>>& grid,MoveQueue& compMoves){
    char comp='O', player='X';
    auto win=findWinningMove(grid,comp);
    if(win.first!=-1){
        compMoves.apply(grid,win.first,win.second,comp);
        return;
    }
    auto block=findWinningMove(grid,player);
    if(block.first!=-1){
        compMoves.apply(grid,block.first,block.second,comp);
        return;
    }
    if(grid[1][1]==' '){
        compMoves.apply(grid,1,1,comp);
        return;
    }
    std::vector<std::pair<int,int>> empty;
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            if(grid[i][j]==' ') empty.push_back({i,j});
    if(!empty.empty()){
        auto choice=empty[rand()%empty.size()];
        compMoves.apply(grid,choice.first,choice.second,comp);
    }
}

int main(){
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE,WINDOW_SIZE),"Tic Tac Toe SFML");

    std::vector<std::vector<char>> grid(SIZE,std::vector<char>(SIZE,' '));
    MoveQueue playerX(4); // human keeps 4 marks
    MoveQueue playerO(3); // computer keeps 3 marks

    char current='X';
    bool gameover=false;

    sf::Font font;
    font.loadFromFile("arial.ttf"); // ensure you have a font file

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed) window.close();
            if(!gameover && current=='X' && event.type==sf::Event::MouseButtonPressed){
                int col=event.mouseButton.x/CELL_SIZE;
                int row=event.mouseButton.y/CELL_SIZE;
                if(row>=0 && row<3 && col>=0 && col<3 && grid[row][col]==' '){
                    playerX.apply(grid,row,col,'X');
                    if(checkWin(grid,'X')){
                        std::cout<<"You win!\n";
                        gameover=true;
                    } else if(checkDraw(grid)){
                        std::cout<<"Draw!\n";
                        gameover=true;
                    } else current='O';
                }
            }
        }

        if(!gameover && current=='O'){
            computerMove(grid,playerO);
            if(checkWin(grid,'O')){
                std::cout<<"Computer wins!\n";
                gameover=true;
            } else if(checkDraw(grid)){
                std::cout<<"Draw!\n";
                gameover=true;
            } else current='X';
        }

        window.clear(sf::Color::White);

        // Draw grid lines
        for(int i=1;i<SIZE;i++){
            sf::RectangleShape lineH(sf::Vector2f(WINDOW_SIZE,2));
            lineH.setPosition(0,i*CELL_SIZE);
            lineH.setFillColor(sf::Color::Black);
            window.draw(lineH);

            sf::RectangleShape lineV(sf::Vector2f(2,WINDOW_SIZE));
            lineV.setPosition(i*CELL_SIZE,0);
            lineV.setFillColor(sf::Color::Black);
            window.draw(lineV);
        }

        // Draw marks
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                if(grid[i][j]=='X'){
                    sf::Text text("X",font,100);
                    text.setFillColor(sf::Color::Red);
                    text.setPosition(j*CELL_SIZE+50,i*CELL_SIZE+30);
                    window.draw(text);
                } else if(grid[i][j]=='O'){
                    sf::Text text("O",font,100);
                    text.setFillColor(sf::Color::Blue);
                    text.setPosition(j*CELL_SIZE+50,i*CELL_SIZE+30);
                    window.draw(text);
                }
            }
        }

        window.display();
    }
    return