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
		Show_debug();
	}
	else if(action == Game_event::flip_choose_stack)
	{
		m_choose_card.See_card();
	}
	else if (action == Game_event::test)
	{
		m_columns.at(6).Remove_card(1);
	}
}

void Game::Move_cards(std::vector<int> input_val)
{
	bool Continue = true;
	//validate data parameter - input_val
	std::cout << input_val.size() << "INPUT VAL:" << std::endl;
	for (int j = 0; j < input_val.size(); j++)
	{
		std::cout << input_val.at(j)<< ", ";
		if (input_val.at(j) < 0)
		{
			Continue = false;
		}
	}
	std::cout <<std::endl;
	if (Continue)
	{	//choose_stack -> X
		if (input_val.front() == 8)  //Take from choose_stack
		{
			if (input_val.at(1) == 9) //To Finish_stack
			{
				std::cout << "move choose -> finish: ";
				if (m_choose_card.Check_not_empty())
				{
					for (int j = 0; j < m_finish_stacks.size(); j++)
					{
						if (m_finish_stacks.at(j).Check_take_card(m_choose_card.Give_card()))
						{
							std::cout << "mozna dodac";
							m_finish_stacks.at(j).Add_card(m_choose_card.Give_card());
							m_choose_card.Remove_card();
							break;
						}
					}
				}
				else
				{
					std::cout << "pusty!";
				}
			}//choose_stack -> stack
			else
			{
				std::cout << "move choose -> stack: ";
				if (m_choose_card.Check_not_empty())
				{
					if (!m_columns.at(input_val.at(1)).Check_not_empty()) //is Empty
					{
						m_columns.at(input_val.at(1)).Add_card(m_choose_card.Give_card());
						m_choose_card.Remove_card();
					}
					else
					{
						std::cout << m_columns.at(input_val.at(1)).Check_take_card(m_choose_card.Give_card());
						if (m_columns.at(input_val.at(1)).Check_take_card(m_choose_card.Give_card()))
						{
							m_columns.at(input_val.at(1)).Add_card(m_choose_card.Give_card());
							m_choose_card.Remove_card();
						}
					}
				}
				std::cout << "pusty!";
			}
		}//Finish_Stack -> X
		else if (input_val.front() == 9) //From Finish_Stack
		{
			std::cout << "move Finish -> Stack: ";
			if (m_finish_stacks.at(input_val.at(1)).Check_not_empty())
			{
				if (m_columns.at(input_val.at(2)).Check_take_card(m_finish_stacks.at(input_val.at(1)).Give_card()))
				{
					std::cout << "mozna dodac";
					m_columns.at(input_val.at(2)).Add_card(m_finish_stacks.at(input_val.at(1)).Give_card());
					m_finish_stacks.at(input_val.at(1)).Remove_card();
				}
			}
			else 
			{
				std::cout << "pusty!";
			}
		}//Cards_stack (Columns) -> X
		else
		{	
			if (input_val.at(1) == 9) //To Finish Stack
			{
				std::cout << "move stack -> finish: ";
				if (m_columns.at(input_val.at(0)).Check_not_empty())
				{
					for (int j = 0; j < m_finish_stacks.size(); j++)
					{
						if (m_finish_stacks.at(j).Check_take_card(m_columns.at(input_val.at(0)).Give_card(0)))
						{
							std::cout << "mozna dodac";
							m_finish_stacks.at(j).Add_card(m_columns.at(input_val.at(0)).Give_card(0));
							m_columns.at(input_val.at(0)).Remove_card(1);
							break;
						}
					}
				}
				else
				{
					std::cout << "Ej! stack jest pusty";
				}
			}
			else //Stack -> Stack
			{
				std::cout << "move stack -> stack: ";
				if (m_columns.at(input_val.at(0)).Check_not_empty())
				{

				if (!m_columns.at(input_val.at(1)).Check_not_empty()) //Stack is empty
				{
					m_columns.at(input_val.at(1)).Add_card(m_columns.at(input_val.at(0)).Give_card(0));
					m_columns.at(input_val.at(0)).Remove_card(1);
				}
				else
				{																					//argument -  index
					std::cout << m_columns.at(input_val.at(1)).Check_take_card(m_columns.at(input_val.at(0)).Give_card(0));//kolumna na która chce po³o¿yæ
					if (m_columns.at(input_val.at(1)).Check_take_card(m_columns.at(input_val.at(0)).Give_card(0)))
					{
						m_columns.at(input_val.at(1)).Add_card(m_columns.at(input_val.at(0)).Give_card(0));
						m_columns.at(input_val.at(0)).Remove_card(1);
					}
					std::cout << "xx" << std::endl;
				}
				}
				else
				{
					std::cout << "Ej! stack jest pusty";
				}
			}
		}
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

void Game::Show_debug() const
{
	std::cout << ".					     __________ " << std::endl;
	std::cout << ".						DEBUG  |" << std::endl;
	std::cout << ".					    |__________|" << std::endl;
	//++
	Card King(13, Card::Colour::clubs);
	//std::cout << m_choose_card.Check_take_card(King);

	std::cout << "===============[  Choose_Stack  ]===============" << std::endl;
	m_choose_card.Show_debug();
	std::cout << std::endl;

	std::cout << "_______________________________________" << std::endl;

	std::cout << "===============[ m_columns ]===============" << std::endl;
	for (int i = 0; i < m_columns.size(); i++)
	{
		std::cout << "m_columns " << i + 1 << ":  ";
		m_columns.at(i).Show_debug();
		std::cout << std::endl;
	}
	std::cout << "===============[ finish_stack ]===============" << std::endl;
	for (int j = 0; j < m_finish_stacks.size(); j++)
	{
		std::cout << "finish_stack " << j + 1 << ":  ";
		m_finish_stacks.at(j).Show_debug();
		std::cout << std::endl;
	}

	std::cout << "____________________________________________" << std::endl;//++
}
