#pragma once
#include <vector>
#include "MinesweeperBoard.hpp"

class MSBoardTextView
{
    private:
        /*std::vector<char> player_board;
        int width;
        int height;*/
        MinesweeperBoard &gamev;
    public:
        MSBoardTextView(MinesweeperBoard &game);
        void display();
        /*void check(MinesweeperBoard board);*/
};

