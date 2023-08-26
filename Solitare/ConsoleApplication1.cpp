#include <iostream>
#include "game.h"


int main()
{
    //Input_output_support input;
    Game game;
    while (true)
    {
        system("cls");
        game.Set_location();
        game.Show_user();
        game.Show_user_option();

        Game_event action = game.Choose_action();
        if (action == Game_event::exit)
        {
            std::cout << "exit";
            return 0;
        }
    }
}