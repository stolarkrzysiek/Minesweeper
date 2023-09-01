#pragma once
#include <vector>
#include "MinesweeperBoard.hpp"
#include "MSBoardTextView.hpp"

class MSTextController
{
    private:
        MinesweeperBoard &board_controller;
        MSBoardTextView &view_controller;
    public:
        MSTextController(MinesweeperBoard &board, MSBoardTextView &view);
        void play();

};


