#include "game.h"
#include <algorithm>
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
	Action event = Available_move();

	switch (event)
	{
	case Action::card_flip_hidden_choose_stack:
		if (option == 1)
		{
			m_choose_card.See_card();
		}
		break;
	case Action::card_from_choose_stack:
		if (option == 1)
		{
			selected_cards.push_back(9);
		}
		break;

	case Action::nothing:
		break;
	case Action::selected_stack:
		if (option == 3)
		{
			selected_cards.clear();
			Uncheck_all_cards();
		}
		break;
	case Action::card_from_stack:
		if (option == 1)
		{
			selected_cards.push_back(selected_column);
		}
		else if (option == 2 && m_columns.at(selected_column).Size_face_up() > 1)
		{
			selected_cards.push_back(selected_column);
			selected_cards.push_back(Select_more_cards());
		}
		break;
	case Action::card_to_stack:
		if (option == 1)
		{
			selected_cards.push_back(selected_column);
			Move_cards(selected_cards);
			selected_cards.clear();
			Uncheck_all_cards();
		}
		break;
	case Action::card_from_finish_stack:
		if (option == 1)
		{
			selected_cards.push_back(8);
			selected_cards.push_back(selected_column - 2);
		}
		break;
	case Action::card_to_finish_stack:
		if (option == 1)
		{
			selected_cards.push_back(8);
			selected_cards.push_back(selected_column - 2);
			Move_cards(selected_cards);
			selected_cards.clear();
			Uncheck_all_cards();
		}
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
			Finish_stack& to_stack = m_finish_stacks.at(input_val.at(2));

			std::cout << "move choose -> finish: ";
			if (m_choose_card.Check_not_empty())
			{
				if (to_stack.Check_take_card(m_choose_card.Give_card()))
				{
					std::cout << "mozna dodac";
					to_stack.Add_card(m_choose_card.Give_card());
					m_choose_card.Remove_card();
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
		Finish_stack& from_stack = m_finish_stacks.at(input_val.at(1));
		std::cout << "move Finish -> Stack: ";
		if (from_stack.Check_not_empty())
		{
			if (m_columns.at(input_val.at(2)).Check_take_card(from_stack.Give_card()))
			{
				std::cout << "mozna dodac";
				m_columns.at(input_val.at(2)).Add_card(from_stack.Give_card());
				from_stack.Remove_card();
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
				Finish_stack& to_stack = m_finish_stacks.at(input_val.at(2));
				if (to_stack.Check_take_card(from_column.Give_card()))
				{
					std::cout << "mozna dodac";
					to_stack.Add_card(from_column.Give_card());
					from_column.Remove_card();				
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
					//from_column->Remove_card(lenght_mfrom, input_val.at(2));

			if (input_val.size() == 3)
			{
				Cards_stack& to_column = m_columns.at(input_val.at(2));
		
				int lenght_mfrom = from_column.Size_face_up();
				int transfer_index = lenght_mfrom - 1 - input_val.at(1);
				if (to_column.Check_take_card(m_columns.at(input_val.at(0)).Give_card(input_val.at(1))))
				{
					for (int i = input_val.at(1); i >= 0; i--)
					{
						to_column.Add_card(from_column.Give_card(i));
					}
					from_column.Remove_card(lenght_mfrom, transfer_index);
				}
			}
			else
			{
				Cards_stack& to_column = m_columns.at(input_val.at(1));
				if (from_column.Check_not_empty())//z ktorego biore
				{

					if (!to_column.Check_not_empty()) //Stack is empty czy pusty ten na ktory chce polozyc
					{
						to_column.Add_card(from_column.Give_card());

						from_column.Remove_card();
					}
					else
					{																					//argument -  index
						//kolumna na kt�ra chce po�o�y�
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
		Handle_event(2);
		return Game_event::select;

	case '3':
		Handle_event(3);
		return Game_event::select;
	default:
		std::cout << std::endl << " ";  // not arrow
	}
	return Game_event::select;
}

int Game::Select_more_cards()
{
	int quantity = 0;
	bool loop = true;
	m_columns.at(selected_column).SetSelect_card(true, quantity);
	while (loop)
	{
		system("cls");
		Show_user();
		std::cout << quantity;
		int key_user;
		key_user = _getch();
		switch (key_user)
		{
		case KEY_UP:
			quantity++;
			if (quantity + 1 > m_columns.at(selected_column).Size_face_up())
			{
				quantity = m_columns.at(selected_column).Size_face_up() - 1;
			}
			m_columns.at(selected_column).SetSelect_card(true,quantity);
			break;

		case KEY_DOWN:
			quantity--;
			if (quantity < 0)
			{
				quantity = 1;
			}
			m_columns.at(selected_column).SetSelect_card(false, quantity+1);
			break;
		case '1':
			loop = false;
			break;
		}
	}
	return quantity;
}

Game::Action Game::Available_move()
{
	switch (active_location)
	{
	case Location::hidden_choose_stack:
		return Action::card_flip_hidden_choose_stack;

	case Location::choose_stack:
		if (m_choose_card.Check_not_empty())
		{
			return Action::card_from_choose_stack;
		}
		else
		{
			return Action::nothing;
		}

	case Location::finish_stack:
		if (selected_cards.size() == 1)
		{
			return Action::card_to_finish_stack;
		}
		else if (selected_cards.empty() && ((m_finish_stacks.at(selected_column - 2)).Check_not_empty()))
		{
			return Action::card_from_finish_stack;
		}
		else
		{
			return Action::nothing;
		}
		break;

	case Location::stack:
		if (selected_cards.empty())
		{
			if (m_columns.at(selected_column).Check_not_empty())
			{
				return Action::card_from_stack;
			}
			else
			{
				return Action::nothing;
			}		
		}
		else
		{
			if (selected_cards.front() != selected_column)
			{
				return Action::card_to_stack;
			}
			return Action::selected_stack;
		}
	}
}

void Game::Set_location()
{	
	if (selected_row == 0)
	{
		if (selected_column == 0)
		{
			active_location = Location::hidden_choose_stack;
		}
		else if (selected_column == 1)
		{
			m_choose_card.SetSelect_card(true);
			active_location = Location::choose_stack;
		}
		else
		{
			active_location = Location::finish_stack;
			int finish_stack_index = std::min(selected_column - 2, (int)m_finish_stacks.size() - 1);
			if (m_finish_stacks.at(finish_stack_index).Check_not_empty())
			{
				m_finish_stacks.at(finish_stack_index).SetSelect_card(true);
			}
		}
	}
	else
	{
		if (m_columns.at(selected_column).Check_not_empty())
		{
			m_columns.at(selected_column).SetSelect_card(true);
		}
		active_location = Location::stack;
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
				for (int j = 0; j < m_columns.at(i).Size_face_up(); j++)
				{
					m_columns.at(i).SetSelect_card(false, j);

				}
			}
		}
		else
		{
			for (int j = 0; j < m_columns.at(i).Size_face_up(); j++)
			{
				m_columns.at(i).SetSelect_card(false, j);
			}
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
	for (int j = 0; j < 18; j++)
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
	Action option = Available_move();

	switch (option)
	{
	case Action::card_flip_hidden_choose_stack:
		if (m_choose_card.Check_hidden_stack_not_empty())
		{
			std::cout << " 1 - Flip the card";
		}
		else
		{
			std::cout << " Nothing to do... stack is empty ;/";
		}
		break;
	case Action::card_from_choose_stack:
		std::cout << "1 - Take card from choose stack";
		break;

	case Action::selected_stack:
		std::cout << " 3 - Uncheck card";
		break;
	case Action::nothing:
		std::cout << " Nothing to do... this stack is empty ;/";
		break;
	case Action::card_from_stack:
		std::cout << " 1 - Take card from " << selected_column + 1 << "stack" << std::endl;

		if (m_columns.at(selected_column).Size_face_up() > 1)
		{
			std::cout << " 2 - Select more cards";
		}
		break;
	case Action::card_to_stack:
		std::cout << " 1 - Move card to " << selected_column + 1 << " stack" << std::endl;
		break;
	case Action::card_from_finish_stack:
		std::cout << "1 - Take from finish_stack " << selected_column - 1 << " selected card";
		break;
	case Action::card_to_finish_stack:
		std::cout << "1 - Move to finish_stack " << selected_column - 1 << " selected card";
		break;
	}
}
