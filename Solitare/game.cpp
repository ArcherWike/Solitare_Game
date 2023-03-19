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
		m_columns.at(6).Remove_card(1,0);
	}
}

void Game::Move_cards(std::vector<int> input_val)
{
	//choose_stack -> X
	if (input_val.front() == 9)  //Take from choose_stack
	{
		if (input_val.at(1) == 8) //To Finish_stack
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
	else if (input_val.front() == 8) //From Finish_Stack
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
		if (input_val.at(1) == 8) //To Finish Stack
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
						m_columns.at(input_val.at(0)).Remove_card(1, 0);
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

			if (input_val.size() == 3)
			{
				int lenght_mfrom = m_columns.at(input_val.at(0)).Size_face_up();
				if (m_columns.at(input_val.at(1)).Check_take_card(m_columns.at(input_val.at(0)).Give_card(input_val.at(2))))
				{
					for (int i = input_val.at(2); i < lenght_mfrom; i++)
					{
						m_columns.at(input_val.at(1)).Add_card(m_columns.at(input_val.at(0)).Give_card(i));
					}
					m_columns.at(input_val.at(0)).Remove_card(lenght_mfrom, input_val.at(2));
				}
			}
			else
			{
				if (m_columns.at(input_val.at(0)).Check_not_empty())//z ktorego biore
				{

					if (!m_columns.at(input_val.at(1)).Check_not_empty()) //Stack is empty czy pusty ten na ktory chce polozyc
					{
						m_columns.at(input_val.at(1)).Add_card(m_columns.at(input_val.at(0)).Give_card(0));

						m_columns.at(input_val.at(0)).Remove_card(0, 1);
					}
					else
					{																					//argument -  index
						std::cout << m_columns.at(input_val.at(1)).Check_take_card(m_columns.at(input_val.at(0)).Give_card(0));//kolumna na która chce po³o¿yæ
						if (m_columns.at(input_val.at(1)).Check_take_card(m_columns.at(input_val.at(0)).Give_card(0)))
						{
							m_columns.at(input_val.at(1)).Add_card(m_columns.at(input_val.at(0)).Give_card(0));
							m_columns.at(input_val.at(0)).Remove_card(0, 1);
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
}

void Game::Show_debug() const
{
	std::cout << ".					     __________ " << std::endl;
	std::cout << ".						DEBUG  |" << std::endl;
	std::cout << ".					    |__________|" << std::endl;

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
