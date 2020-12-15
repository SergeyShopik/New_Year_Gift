#pragma once

#include"mainHeader.h"
//empty parent class for creating heir candies
class Base
{
public:
	Base() = default;
	virtual ~Base() = default;

	void setName(string _name) { name = _name; }
	void setWeight(double _weight) { weight = _weight; }
	void setPrice(double _price) { price = _price; }
	void setSugar(double _sugar) { sugar = _sugar; }

	string getName() const { return name; }
	double getWeight() const { return weight; }
	double getPrice() const { return price; }
	double getSugar() const { return sugar; }

	virtual std::istream& read(std::istream& in)
	{
		in >> name >> weight >> price >> sugar;
		return in;
	}
	virtual std::ostream& print(std::ostream& out) const
	{
		out << "\nName: " << name << "\nWeight: " << weight << "\nPrice: " << price
			<< "\nSugar: " << sugar;
		return out;
	}

private:
	string name;
	double weight;
	double price;
	double sugar;
};

std::ostream& operator<<(std::ostream& out, std::shared_ptr<Base> s1)
{
	s1->print(out);
	return out;
}
