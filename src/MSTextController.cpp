#include "MSTextController.hpp"
#include <iostream>

using namespace std;

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view) : board_controller(board), view_controller(view){}

void MSTextController::play()
{
    int x=0, y=0, wyborc=0;//wspolrzedne pola, wartosc podaje urzytkownik
  while(board_controller.getGameState()==GameState::RUNNING)
  {
    if(wyborc==0) 
    {
    cout<<"ilosc min: "<<board_controller.getMineCount()<<endl;
    view_controller.display();
    }
    x=0;
    y=0;
    wyborc=0;
    
    cout<<"podaj wspolrzedne pola"<<endl<<"wiersz: ";
    cin>>x;
    cout<<"kolumna: ";
    cin>>y;
    do
    {
    cout<<"1.ustaw flage\n2.odkryj pole\n";
    cin>>wyborc;
    }while(wyborc<1 || wyborc>2);
    switch(wyborc)
    {
        case 1:
            board_controller.toggleFlag(x-1, y-1);
            break;
        case 2:
            board_controller.revealField(x-1, y-1);
            break;
        default:
            cout<<"zly wybor";
            break;
    }
    system("clear");
    switch(board_controller.getGameState())
    {
        case GameState::RUNNING:
            cout<<"stan gry: running"<<endl;
            break;
        case GameState::FINISHED_LOSS:
            cout<<"stan gry: przegrana"<<endl;
            break;
        case GameState::FINISHED_WIN:
            cout<<"stan gry: wygrana"<<endl;
            break;
     }
    cout<<"ilosc min: "<<board_controller.getMineCount()<<endl;
    view_controller.display();
    
    }
}
