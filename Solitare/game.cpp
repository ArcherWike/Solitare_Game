#include "game.h"
#include "deck.h"

Game::Game()
{
	Shuffle_cards();
}

void Game::Handle_event(Game_event action)
{
	if (action == Game_event::debug_board)
	{
		std::cout << ".					     __________ " << std::endl;
		std::cout << ".						DEBUG  |" << std::endl;
		std::cout << ".					    |__________|" << std::endl;
		//++
		Card King(13, Card::Colour::clubs);
		//std::cout << m_choose_card.Check_take_card(King);

		std::cout << "===============[  Choose_Stack  ]===============" << std::endl;
		m_choose_card.Show_choose_stack();
		std::cout << std::endl;

		std::cout << "_______________________________________" << std::endl;

		std::cout << "===============[ m_columns ]===============" << std::endl;
		for (int i = 0; i < m_columns.size(); i++)
		{
			std::cout << "m_columns " << i+1 << ":  ";
			m_columns.at(i).Show_cards_stack();
			std::cout << std::endl;
		}
		std::cout << "===============[ finish_stack ]===============" << std::endl;
		for (int j = 0; j < m_finish_stacks.size(); j++)
		{
			std::cout << "finish_stack " << j + 1 << ":  ";
			m_finish_stacks.at(j).Show_finish_stack();
			std::cout << std::endl;
		}
		
		std::cout << "____________________________________________" << std::endl;//++
	}
}

void Game::Shuffle_cards()
{
	m_deck = Deck();
	m_columns.clear();
	m_finish_stacks.clear();

	for (int i = 0; i < 7; i++)
	{
		m_columns.push_back(Cards_stack(i, m_deck));
	}
	for (int i = 0; i < 4; i++)
	{
		m_finish_stacks.push_back(Finish_stack());
	}
	m_choose_card = Choose_stack(m_deck);
	//m_choose_card.Xxx(m_deck);


		/*/Task:
		1[-] create cards_stack (number_of_stack -> 1-7)

		2[-] create finish_stack (colour 1-4)- colour is setting with first card

		3[-] create shuffle_stack with other cards
		/*/
}
