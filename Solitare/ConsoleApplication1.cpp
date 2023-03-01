#include <iostream>
#include "game.h"
#include "input_output_support.h"


int main()
{
    Input_output_support input;
    Game game;
    while (true)
    {
        Game_event action = input.Accept_input();
        game.Handle_event(action);

    }
    int a = 31;
    int& b = a;
    b = 5;
    int* c = &a;


    //Game game;
    //game.Game_option_show();
    //game.Shuffle_cards();

    /*/
    Finish_stack clubs_colour;

    Card Ten(10, Card::Colour::diamonds);

    Card Jack(11, Card::Colour::clubs);
    Card Queen(12, Card::Colour::clubs);
    Card King(13, Card::Colour::clubs);
    Card King_diamond(13, Card::Colour::diamonds);

    std::cout << clubs_colour.Add_card(Queen) << std::endl;
    std::cout << clubs_colour.Add_card(King) << std::endl; /*/
    //std::cout << clubs_colour.Add_card(Ten) << std::endl;


    //Deck deck;
     
    ////Card King(13, Card::Colour::clubs);
    //std::cout << King.m_value <<" colour: " << (int)King.m_colour << std::endl;

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
