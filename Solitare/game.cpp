#include "game.h"

#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC 27

Game::Game()
{
	Shuffle_cards();
}
void Game::Handle_event(int option)
{
	Game_event event = Available_move();

	switch (event)
	{
	case Game_event::hidden_choose_stack:
		if (option == 1)
		{
			m_choose_card.See_card();
		}
		break;
	case Game_event::card_from_choose_stack:
		if (option == 1)
		{
			selected_cards.push_back(9);
		}
		break;

	case Game_event::nothing:
		break;
	case Game_event::selected_stack:
		if (option == 3)
		{
			selected_cards.clear();
			Uncheck_all_cards();
		}
		break;
	case Game_event::card_from_stack:
		if (option == 1)
		{
			selected_cards.push_back(selected_column);
		}
		break;
	case Game_event::card_to_stack:
		if (option == 1)
		{
			selected_cards.push_back(selected_column);
			Move_cards(selected_cards);
			selected_cards.clear();
			Uncheck_all_cards();
		}
		break;
	case Game_event::card_from_finish_stack:
		if (option == 1)
		{
			selected_cards.push_back(8);
			selected_cards.push_back(selected_column - 2);
		}
		break;
	case Game_event::card_to_finish_stack:
		if (option == 1)
		{
			selected_cards.push_back(8);
			Move_cards(selected_cards);
			selected_cards.clear();
			Uncheck_all_cards();
		}
		break;
	case Game_event::test:
		break;
	default:
		break;
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
			Cards_stack& to_column = m_columns.at(input_val.at(1));
			std::cout << "move choose -> stack: ";
			if (m_choose_card.Check_not_empty())
			{
				if (!to_column.Check_not_empty()) //is Empty
				{
					to_column.Add_card(m_choose_card.Give_card());
					m_choose_card.Remove_card();
				}
				else
				{
					std::cout << to_column.Check_take_card(m_choose_card.Give_card());
					if (to_column.Check_take_card(m_choose_card.Give_card()))
					{
						to_column.Add_card(m_choose_card.Give_card());
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
		Cards_stack& from_column = m_columns.at(input_val.at(0));
		if (input_val.at(1) == 8) //To Finish Stack
		{
			std::cout << "move stack -> finish: ";
			if (from_column.Check_not_empty())
			{
				for (int j = 0; j < m_finish_stacks.size(); j++)
				{
					if (m_finish_stacks.at(j).Check_take_card(from_column.Give_card(0)))
					{
						std::cout << "mozna dodac";
						m_finish_stacks.at(j).Add_card(from_column.Give_card(0));
						from_column.Remove_card(1, 0);
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
			Cards_stack& from_column = m_columns.at(input_val.at(0));
			//Cards_stack *from_column = &m_columns.at(input_val.at(0));

			Cards_stack& to_column = m_columns.at(input_val.at(1));

			if (input_val.size() == 3)
			{
				/*std::cout << m_columns.at(input_val.at(0)).Check_has_card(input_val.at(2));
				std::cout << m_columns.at(input_val.at(0)).Give_index(input_val.at(2));*/
				int lenght_mfrom = m_columns.at(input_val.at(0)).Size_face_up();
				if (to_column.Check_take_card(m_columns.at(input_val.at(0)).Give_card(input_val.at(2))))
				{
					for (int i = input_val.at(2); i < lenght_mfrom; i++)
					{
						to_column.Add_card(m_columns.at(input_val.at(0)).Give_card(i));
					}
					//from_column->Remove_card(lenght_mfrom, input_val.at(2));
					from_column.Remove_card(lenght_mfrom, input_val.at(2));
				}
			}
			else
			{
				if (from_column.Check_not_empty())//z ktorego biore
				{

					if (!to_column.Check_not_empty()) //Stack is empty czy pusty ten na ktory chce polozyc
					{
						to_column.Add_card(from_column.Give_card());

						from_column.Remove_card();
					}
					else
					{																					//argument -  index
						//kolumna na która chce po³o¿yæ
						if (to_column.Check_take_card(from_column.Give_card()))
						{
							to_column.Add_card(from_column.Give_card());
							from_column.Remove_card();
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

Game_event Game::Choose_action()
{
	Uncheck_all_cards();

	int key_user;
	key_user = _getch();
	switch (key_user)
	{
	case KEY_UP:
		selected_row = 0;
		return Game_event::move;

	case KEY_DOWN:
		selected_row = 1;
		return Game_event::move;

	case KEY_LEFT:
		selected_column -= 1;
		if (selected_column < 0)
		{
			selected_column = 0;
		}
		return Game_event::move;

	case KEY_RIGHT:
		selected_column += 1;
		if (selected_row == 1 && selected_column > 6)
		{
			selected_column = 6;
		}
		else if (selected_row == 0 && selected_column > 5)
		{
			selected_column = 5;
		}
		return Game_event::move;

	case ESC:
		std::cout << std::endl << "EXIT";  // esc
		return Game_event::exit;

	case '1':
		Handle_event(1);
		return Game_event::select;
	case '2':
		Show_debug();

	case '3':
		Handle_event(3);
		return Game_event::select;
	default:
		std::cout << std::endl << " ";  // not arrow
	}
	return Game_event::select;
}

Game_event Game::Available_move()
{
	switch (active_event)
	{
	case Game_event::hidden_choose_stack:
		return Game_event::hidden_choose_stack;

	case Game_event::choose_stack:
		if (m_choose_card.Check_not_empty())
		{
			return Game_event::card_from_choose_stack;
		}
		else
		{
			return Game_event::nothing;
		}

	case Game_event::finish_stack:
		if (selected_cards.size() == 1)
		{
			return Game_event::card_to_finish_stack;
		}
		else if (selected_cards.empty() && ((m_finish_stacks.at(selected_column - 2)).Check_not_empty()))
		{
			return Game_event::card_from_finish_stack;
		}
		else
		{
			return Game_event::nothing;
		}
		break;

	case Game_event::stack:
		if (selected_cards.empty())
		{
			if (m_columns.at(selected_column).Check_not_empty())
			{
				return Game_event::card_from_stack;
			}
			else
			{
				return Game_event::nothing;
			}		
		}
		else
		{
			if (selected_cards.front() != selected_column)
			{
				return Game_event::card_to_stack;
			}
			return Game_event::selected_stack;
		}
	}
}

void Game::Set_event()
{	
	if (selected_row == 0)
	{
		if (selected_column == 0)
		{
			active_event = Game_event::hidden_choose_stack;
		}
		else if (selected_column == 1)
		{
			m_choose_card.SetSelect_card(true);
			active_event = Game_event::choose_stack;
		}
		else
		{
			active_event = Game_event::finish_stack;
			if (m_finish_stacks.at(selected_column - 2).Check_not_empty())
			{
				m_finish_stacks.at(selected_column - 2).SetSelect_card(true);		
			}
		}
	}
	else
	{
		m_columns.at(selected_column).SetSelect_card(true);
		active_event = Game_event::stack;
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

void Game::Uncheck_all_cards()
{
	//unset checked colour
	m_choose_card.SetSelect_card(false);
	for (int i = 0; i < 7; i++)
	{
		if (!selected_cards.empty())
		{
			if (selected_cards.at(0) != i)
			{
				m_columns.at(i).SetSelect_card(false);
			}
		}
		else
		{
			m_columns.at(i).SetSelect_card(false);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (m_finish_stacks.at(i).Check_not_empty())
		{
			m_finish_stacks.at(i).SetSelect_card(false);
		}
	}
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

void Game::Show_user() const
{
	m_choose_card.Show_user();

	std::cout << " ";
	for (int j = 0; j < m_finish_stacks.size(); j++)
	{
		std::cout << "" << j + 1 ;
		m_finish_stacks.at(j).Show_user();
	}

	std::cout << std::endl;
	std::cout << std::endl;
	for (int j = 0; j < 7; j++)
	{
		for (int i = 0; i < m_columns.size(); i++)
		{
			m_columns.at(i).Show_card(j);
		}
		std::cout << std::endl;
	}
	std::cout << "[ " << selected_row << "." << selected_column << " ]" << std::endl;
}

void Game::Show_user_option()
{
	//User game option
	Game_event option = Available_move();

	switch (option)
	{
	case Game_event::hidden_choose_stack:
		std::cout << " 1 - Flip the card";
		break;
	case Game_event::card_from_choose_stack:
		std::cout << "1 - Take card from choose stack";
		break;

	case Game_event::stack:
		std::cout << " 1 - Take card from " << selected_column + 1 << " stack" << std::endl;
		std::cout << " 2 - Select more cards";
		break;
	case Game_event::selected_stack:
		std::cout << " 3 - Uncheck card";
		break;
	case Game_event::nothing:
		std::cout << " Nothing to do... this stack is empty ;/";
		break;
	case Game_event::card_from_stack:
		std::cout << " 1 - Take card from " << selected_column + 1 << " stack" << std::endl;
		break;
	case Game_event::card_to_stack:
		std::cout << " 1 - Move card to " << selected_column + 1 << " stack" << std::endl;
		break;
	case Game_event::card_from_finish_stack:
		std::cout << "1 - Take from finish_stack " << selected_column - 2 << " selected card";
		break;
	case Game_event::card_to_finish_stack:
		std::cout << "1 - Move to finish_stack " << selected_column - 2 << " selected card";
		break;
	}
}
