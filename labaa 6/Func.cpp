#include "Libraries.h"

//�������� �� ����
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
			std::cout << "������� �������� ��������, ���������� ����" << std::endl;
		}
		else
		{
			return value;
		}
	}
}

void chooseinstr()
{
	std::cout << "������� 1 ����� ������� ��������" << std::endl;
	std::cout << "������� 2 ����� ������� �� �����" << std::endl;
	std::cout << "������� 3 ����� ������ ����� ��������" << std::endl;
	std::cout << "������� 4 ����� ������� �������� �� ������" << std::endl;
	std::cout << "������� 5 ����� ������� �������� �� ������" << std::endl;
	std::cout << "������� 6 ����� ������ ���������� ����� � ������" << std::endl;
	std::cout << "������� ����� ������ ����� ����� �����" << std::endl;
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
				std::cout << "������ ����� �����" << std::endl;
				break;
			}
			ring.Show();
			break;
		case 3:
			system("CLS");
			if (ring.empty())
			{
				std::cout << "������ ����� �����" << std::endl;
				break;
			}
			std::cout << "������� ���������� � �������� ����� �������� ������ �����" << std::endl;
			std::cin >> temp;
			std::cout << "����� ����� ��������:" << ring.Find(temp) << std::endl;
			break;
		case 4:
			system("CLS");
			if (ring.empty())
			{
				std::cout << "������ ����� �����" << std::endl;
				break;
			}
			std::cout << "����� �������� �������� ������ �������" << std::endl;
			number = getintValue();
			ring.Remove(number);
			break;
		case 5:
			system("CLS");
			if (ring.empty())
			{
				std::cout << "������ ����� �����" << std::endl;
				break;
			}
			std::cout << "������� ���������� � �������� ����� �������� ������ �������" << std::endl;
			std::cin >> temp;
			ring.Remove_by_data(temp);
			break;
		case 6:
			system("CLS");
			std::cout << "���������� �����:"<< ring.Size() << std::endl;
			break;
		default:
			system("CLS");
			return;
		}
	}
}