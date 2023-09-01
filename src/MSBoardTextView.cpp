#include "MSBoardTextView.hpp"
#include <iostream>

using namespace std;


MSBoardTextView::MSBoardTextView(MinesweeperBoard &game) : gamev(game){}//lista inicjalizacyjna 

/*for(int i=0;i<board.getBoardHeight();i++)
    {
        for(int j=0;j<board.getBoardWidth();j++)
        {
            player_board.push_back(board.getFieldInfo(i, j));
        }
    }
    width=board.getBoardWidth();
    height=board.getBoardHeight();*/

/*void MSBoardTextView::check(MinesweeperBoard  board)
{
int index=0;
    for(int i=0;i<board.getBoardHeight();i++)
    {
        for(int j=0;j<board.getBoardWidth();j++)
        {
            player_board[index++]=board.getFieldInfo(i, j);
        }
    }
}*/

void MSBoardTextView::display()
{
    
    cout<<endl;
    for(int i=0;i<gamev.getBoardHeight();i++)
    {
        
        for(int j=0;j<gamev.getBoardWidth();j++)
        {
            cout<<gamev.getFieldInfo(i, j);
        }
        cout<<"|"<<i+1;
        cout<<endl;
    }

/*int indeks=0;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)cout<<player_board[indeks++];
        cout<<endl;
        
    }*/
}

