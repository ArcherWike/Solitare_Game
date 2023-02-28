#include "game.h"
#include "deck.h"

Game::Game()
{
	Shuffle_cards();
}

void Game::Handle_event(Game_event action)
{
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
