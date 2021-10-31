#include "Person.h"

human::human(const human& human)
{
	this->name = human.name;
	this->pathranomic = human.pathranomic;
	this->age = human.age;
}
human::human()
{
	age = 0;
	this->name = "none";
	this->pathranomic = "none";
}
human::human(std::string name, std::string pathranomic, int age)
{
	this->name = name;
	this->pathranomic = pathranomic;
	this->age = age;
}

std::string human::getname()
{
	return this->name;
}

std::string human::getpathranomic()
{
	return this->pathranomic;
}

int human::getage()
{
	return age;
}

void human::setname(std::string name)
{
	this->name = name;
}
void human::setpathranomic(std::string pathranomic)
{
	this->pathranomic = pathranomic;
}

void human::setage(int age)
{
	this->age = age;
}

bool human::operator==(const human& man)
{
	if(this->name == man.name && this->pathranomic == man.pathranomic && this->age == man.age)
		return true;
	return false;
}


std::ostream& operator<<(std::ostream& out, const human& man)
{
	out << "Name:" << man.name << std::endl;
	out << "Surname:" << man.pathranomic << std::endl;
	out << "Age:" << man.age << std::endl;
	return out;
}

std::istream& operator >> (std::istream& in, human& man)
{
	std::cout << "Enter name:";
	in >> man.name;
	std::cout << "Etner surname:";
	in >> man.pathranomic;
	std::cout << "Enter age:";
	man.age = getintValue();
	return in;
}