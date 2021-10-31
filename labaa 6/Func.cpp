#include "Libraries.h"

//Проверка на ввод
int getintValue()
{
	int value = 0;

	while (true)
	{
		std::cin >> value;
		if (std::cin.peek() != '\n')
		{

			std::cin.clear();
			std::cin.ignore(32767, '\n');
			system("CLS");
			std::cout << "Введено неверное значение, поврторите ввод" << std::endl;
		}
		else
		{
			return value;
		}
	}
}

void chooseinstr()
{
	std::cout << "Введите 1 чтобы добавть человека" << std::endl;
	std::cout << "Введите 2 чтобы вывести на экран" << std::endl;
	std::cout << "Введите 3 чтобы узнать номер человека" << std::endl;
	std::cout << "Введите 4 чтобы удалить человека по номеру" << std::endl;
	std::cout << "Введите 5 чтобы удалить человека по данным" << std::endl;
	std::cout << "Введите 6 чтобы узнать количество людей в кольце" << std::endl;
	std::cout << "Введите любое другое число чтобы выйти" << std::endl;
}

void perfomance(Ring<human>& ring)
{
	while (true)
	{
		chooseinstr();
		int choose = getintValue();
		human temp;
		int number;
		switch (choose)
		{
		case 1:
			system("CLS");
			std::cin >> temp;
			ring.Push(temp);
			break;
		case 2:
			system("CLS");
			if (ring.empty())
			{
				std::cout << "Кольцо людей пусто" << std::endl;
				break;
			}
			ring.Show();
			break;
		case 3:
			system("CLS");
			if (ring.empty())
			{
				std::cout << "Кольцо людей пусто" << std::endl;
				break;
			}
			std::cout << "Введите информацию о человеке номер которого хотите найти" << std::endl;
			std::cin >> temp;
			std::cout << "Номер этого человека:" << ring.Find(temp) << std::endl;
			break;
		case 4:
			system("CLS");
			if (ring.empty())
			{
				std::cout << "Кольцо людей пусто" << std::endl;
				break;
			}
			std::cout << "Номер человека которого хотите удалить" << std::endl;
			number = getintValue();
			ring.Remove(number);
			break;
		case 5:
			system("CLS");
			if (ring.empty())
			{
				std::cout << "Кольцо людей пусто" << std::endl;
				break;
			}
			std::cout << "Введите информацию о человеке номер которого хотите удалить" << std::endl;
			std::cin >> temp;
			ring.Remove_by_data(temp);
			break;
		case 6:
			system("CLS");
			std::cout << "Количество людей:"<< ring.Size() << std::endl;
			break;
		default:
			system("CLS");
			return;
		}
	}
}