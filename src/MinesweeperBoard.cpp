#include "MinesweeperBoard.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//dodać sprawdzenie czy 2 miny nie sa na jednym polu!!!

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
    this->width=width;
    this->height=height;
    int number_of_mines=0; //ilosc min do wygenerowania
    
    
    
    if(mode==GameMode::EASY) 
    {   
        number_of_mines=((width*height)*0.1);
        cout<<"tryb EASY"<<endl;
    }
    else if(mode==GameMode::NORMAL)
    { 
        number_of_mines=((width*height)*0.2);
        cout<<"tryb NORMAL"<<endl;
    }
    else if(mode==GameMode::HARD) 
    {
        number_of_mines=((width*height)*0.3);
        cout<<"tryb HARD"<<endl;
    }
    
    vector<int>tab;//tablica przetrzymujaca nr indeksow w ktorych znajduja sie miny
    
    if(mode==GameMode::EASY || mode==GameMode::NORMAL || mode==GameMode::HARD)
    {
    for(int i=0;i<number_of_mines;i++) tab.push_back(-1);
    cout<<endl;
    int licznik=0;
    int  index=0;
    while(licznik!=number_of_mines)
    { 
        licznik=0;
        int number=(rand() % (width*height));
        int check=0;
        tab[index]=number;
        while(check!=1)
        {
            check=0;
            for(int i=0;i<number_of_mines;i++)
            {
                if(tab[index]==tab[i]) check++;
            }
            if(check>1)
            {
             number=(rand() % (width*height));
             tab[index]=number;
            }
            
        }
        
        
        for(int i=0;i<number_of_mines;i++) if(tab[i]!=-1)licznik++;
        index++;
    }
    //rozstawianie min
    for(int i=0;i<(width*height);i++)
    {
        Field a;
        for(int k=0;k<number_of_mines;k++)
        {
            if(tab[k]==i) 
            {
             a.hasMine=true;
             break;
            }
            else a.hasMine=false; 
        }
        
        a.hasFlag=false;
        a.isRevealed=false;
        board.push_back(a);
    }
    } 
    else if(mode==GameMode::DEBUG) 
    {
    
     cout<<"tryb debug"<<endl;
     vector<int>tab;
     

        for(int i=0;i<(width*height);i=i+width+1)
        {
            tab.push_back(i);
            number_of_mines++;
        }

        for(int i=0;i<width;i++)
        {
            tab.push_back(i);
            number_of_mines++;
        }

        for(int i=0;i<(width*height);i=i+(2*width))
        {
            tab.push_back(i);
            number_of_mines++;
        }
        
        for(int i=0;i<(width*height);i++)
        {
        Field a;
        for(int k=0;k<number_of_mines;k++)
        {
            if(tab[k]==i) 
            {
             a.hasMine=true;
             break;
            }
            else a.hasMine=false; 
        }
        
        a.hasFlag=false;
        a.isRevealed=false;
        board.push_back(a);
        }

    }
     state=GameState::RUNNING;
}

bool MinesweeperBoard::isGameFinished() 
{
if(state == GameState::FINISHED_LOSS or state== GameState::FINISHED_WIN) return false;
else return true;
}




void MinesweeperBoard::debug_display() const
{
    int i=0;
    for(int h=0;h<height;h++)
    {
        for(int w=0;w<width;w++)
            {
                cout<<"[";
                if(board[i].hasMine==true) 
                {
                    cout<<"M";
                }
                else
                {
                    cout<<".";
                }
                if(board[i].isRevealed==true) 
                {
                    cout<<"o";
                }
                else
                {
                    cout<<".";
                }
                if(board[i].hasFlag==true) 
                {
                    cout<<"f";
                }
                else
                {
                    cout<<".";
                }
                cout<<"]";
                
                i++;
            }
            cout<<endl;   
    }
}

int MinesweeperBoard::getBoardWidth() const
{
    int a=width;
    return a;
}

int MinesweeperBoard::getBoardHeight() const
{
    int a=height;
    return a;
}

int MinesweeperBoard::getMineCount() const
{
    int Nom=0;
    for(int i=0;i<(width*height);i++)
    {
        if(board[i].hasMine==true) Nom++;
    }
    return Nom;
}

int MinesweeperBoard::countMines(int row, int col) const
{

    int licznik=0;
    if(board[row*width+col].isRevealed==false) return -1;
    if(row<0||row>height-1||col<0||col>width-1) return -1;
    
    //sprawdzanie rogow
    if(row==0&&col==0)
    {
        if(board[1].hasMine==true) licznik++;
        if(board[width].hasMine==true) licznik++;
        if(board[width+1].hasMine==true) licznik++;
    }
    else if(row==0&&col==width-1)
    {
        if(board[width-2].hasMine==true) licznik++;
        if(board[2*width-2].hasMine==true) licznik++;
        if(board[2*width-1].hasMine==true) licznik++;
    }
    else if(row==height-1&&col==0)
    {
        if(board[width*(height-2)].hasMine==true) licznik++;
        if(board[width*(height-2)+1].hasMine==true) licznik++;
        if(board[width*(height-1)+1].hasMine==true) licznik++;
    }
    else if(row==height-1&&col==0)
    {
        if(board[width*(height-2)].hasMine==true) licznik++;
        if(board[width*(height-2)+1].hasMine==true) licznik++;
        if(board[width*(height-1)+1].hasMine==true) licznik++;
    }
    else if(row==height-1&&col==width-1)
    {
        if(board[width*(height-1)+width-2].hasMine==true) licznik++;
        if(board[width*(height-1)+width-1].hasMine==true) licznik++;
        if(board[width*height-2].hasMine==true) licznik++;
    }
    else if(row==0)
    {
        for(int i=-1;i<2;i=i+2)
    {
        if(board[col+i].hasMine==true) licznik++;
    } 
        for(int i=-1;i<2;i++)
    {
        if(board[width+col+i].hasMine==true) licznik++;
    } 
    }
    else if(row==height-1)
    {
        for(int i=-1;i<2;i++)
    {
        if(board[width*(height-2)+col+i].hasMine==true) licznik++;
    } 
        for(int i=-1;i<2;i=i+2)
    {
        if(board[width*(height-1)+col+i].hasMine==true) licznik++;
    } 
    }
    else if(col==0)
    {
        if(board[(row-1)*width].hasMine==true) licznik++;
        if(board[(row-1)*width+1].hasMine==true) licznik++;
        if(board[row*width+1].hasMine==true) licznik++;
        if(board[(row+1)*width].hasMine==true) licznik++;
        if(board[(row+1)*width+1].hasMine==true) licznik++;
    }
    else if(col==width-1)
    {
        if(board[width*(row-1)+col-1].hasMine==true) licznik++;
        if(board[width*(row-1)+col].hasMine==true) licznik++;
        if(board[width*row+col-1].hasMine==true) licznik++;
        if(board[width*(row+1)+col-1].hasMine==true) licznik++;
        if(board[width*(row+1)+col].hasMine==true) licznik++;
    }
    //reszta
    else{
    for(int i=-1;i<2;i++)
    {
        if(board[(row-1)*width+col+i].hasMine==true) licznik++;
    }
    for(int i=-1;i<2;i=i+2)
    {
        if(board[row*width+col+i].hasMine==true) licznik++;
    }
    for(int i=-1;i<2;i++)
    {
        if(board[(row+1)*width+col+i].hasMine==true) licznik++;
    }
    }
    return licznik;
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if(row<0||row>height-1||col<0||col>width-1) return false;
    if(board[row*width+col].hasFlag!=true) return false;
    if(board[row*width+col].isRevealed==true) return false;
    if(board[row*width+col].hasFlag==true) return true;
    return false;
}

void MinesweeperBoard::toggleFlag(int row, int col)
{
    if(row<0||row>height-1||col<0||col>width-1) return;
    if(board[row*width+col].isRevealed==true) return;
    if(isGameFinished()!=true) return; 
    if(board[row*width+col].hasFlag==true) board[row*width+col].hasFlag=false;
    else if(board[row*width+col].hasFlag==false) board[row*width+col].hasFlag=true;
    
}

void MinesweeperBoard::revealField(int row, int col)
{
    if(row<0||row>height-1||col<0||col>width-1) return;
    if(board[row*width+col].isRevealed==true) return;
    if(board[row*width+col].hasFlag==true) return;
    if(board[row*width+col].isRevealed==false && board[row*width+col].hasMine==false) 
    {
        board[row*width+col].isRevealed=true;
    }//gra kontynuowana
    if(board[row*width+col].isRevealed==false && board[row*width+col].hasMine==true)
    {
        board[row*width+col].isRevealed=true;
        state=GameState::FINISHED_LOSS;
    }  //gra zakonczona
}

bool MinesweeperBoard::isRevealed(int row, int col) const
{
    if(board[row*width+col].isRevealed==true) return true;
    else return false;
}

GameState MinesweeperBoard::getGameState() const
{
    int licznik=0, licznik_R=0;
    
    for(int i=0;i<width*height;i++)
    {
        if(board[i].hasMine==true) licznik++;
        if(board[i].isRevealed==false) licznik_R++;
    }
    if(state==GameState::FINISHED_LOSS) return GameState::FINISHED_LOSS;
    else if(licznik==licznik_R) return GameState::FINISHED_WIN;
    else return GameState::RUNNING;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const
{
    if(row<0||row>height-1||col<0||col>width-1) return '#';
    else if(board[row*width+col].isRevealed==false && board[row*width+col].hasFlag==true) return 'F';
    else if(board[row*width+col].isRevealed==false && board[row*width+col].hasFlag==false) return '_';
    else if(board[row*width+col].isRevealed==true && board[row*width+col].hasMine==true) return 'x';
    else if(board[row*width+col].isRevealed==true && countMines( row,  col)==0) return ' ';
    else if(board[row*width+col].isRevealed==true && countMines( row,  col)>0)
    {
        char x='1';
        for(int i=1;i<9;i++)
        {
            if(countMines( row,  col)==i) return x;
            else x++;
        }
        return '0';
    } 
    else return '?';
}

