#pragma once

#include"mainHeader.h"

std::shared_ptr<Base> getPtr(char marker);

class Sweets
{
public:
	Sweets() = default;
	~Sweets() = default;

	void readSweets(std::istream& in);
	void print(std::ostream& out);
	void sortWeight();
	void sortPrice();
	void sortSugar();


//private:
	vector<std::shared_ptr<Base>> sweets;
};

void Sweets::readSweets(std::istream& in)
{
	while (!in.eof())
	{
		char symbol;
		in >> symbol;
		sweets.push_back(getPtr(symbol));

		string str;
		getline(in, str);
		std::istringstream input(str);

		sweets.back()->read(input);
		sweets.back()->print(cout);
	}
}

std::shared_ptr<Base> getPtr(char marker)
{
	switch (marker)
	{
	case 'c':
		return std::make_shared<Chocolate>();
		break;
	case 'm':
		return std::make_shared<Marshmellow>();
		break;
	case 'l':
		return std::make_shared<Lollypop>();
		break;

	default:
		break;
	}
}
void Sweets::print(std::ostream& out)
{
	std::copy(sweets.begin(), sweets.end(), std::ostream_iterator<std::shared_ptr<Base>>(out, "\n"));
}
void Sweets::sortWeight()
{
	std::copy(sweets.begin(), sweets.end(),
		[](std::shared_ptr<Base>s1, std::shared_ptr<Base>s2)
		{return s1->getWeight() > s2->getWeight(); });
}
void Sweets::sortPrice()
{
	std::copy(sweets.begin(), sweets.end(),
		[](std::shared_ptr<Base>s1, std::shared_ptr<Base>s2)
		{return s1->getPrice() > s2->getPrice(); });
}
void Sweets::sortSugar()
{
	std::copy(sweets.begin(), sweets.end(),
		[](std::shared_ptr<Base>s1, std::shared_ptr<Base>s2)
		{return s1->getSugar() > s2->getSugar(); });
}