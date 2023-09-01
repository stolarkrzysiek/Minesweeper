#include <iostream>
#include "MinesweeperBoard.hpp"
#include "MSBoardTextView.hpp"
#include "MSTextController.hpp"
using namespace std;
int main()
{

    srand( time( NULL ) );
    int wybor, szerokosc, wysokosc;
    system("clear");
    do
    {
    szerokosc=0;
    wysokosc=0;
    do
    {
    cout<<"1.EASY\n2.NORMAL\n3.HARD\n4.DEBUG\n";
    cin>>wybor;
    system("clear");
    cout<<"Podaj rozmiar planszy\nSzerokosc: ";
    cin>>szerokosc;
    cout<<"wysokosc: ";
    cin>>wysokosc;
    system("clear");
    }while(wybor<1 || wybor>4 || szerokosc < 1 || szerokosc > 100 || wysokosc < 1 || wysokosc > 100);
    
    if(wybor==1)
    {
    MinesweeperBoard o(szerokosc, wysokosc, GameMode::EASY);
    MSBoardTextView view(o);
    MSTextController ctrl(o, view);
    ctrl.play();
    }
    if(wybor==2)
    {
    MinesweeperBoard o(szerokosc, wysokosc, GameMode::NORMAL);
    MSBoardTextView view(o);
    MSTextController ctrl(o, view);
    ctrl.play();
    }
    if(wybor==3)
    {
    MinesweeperBoard o(szerokosc, wysokosc, GameMode::HARD);
    MSBoardTextView view(o);
    MSTextController ctrl(o, view);
    ctrl.play();
    }
    if(wybor==4)
    {
    
    MinesweeperBoard o(szerokosc, wysokosc, GameMode::DEBUG);
    MSBoardTextView view(o);
    MSTextController ctrl(o, view);
    ctrl.play();
    }
    }while(wybor==1||wybor==2||wybor==3||wybor==4);
    
    return 0;
}
