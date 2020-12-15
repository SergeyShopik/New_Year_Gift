#pragma once

#include"mainHeader.h"

class Chocolate : public Base
{
public:
	Chocolate() = default;
	~Chocolate() override = default;

	std::istream& read(std::istream& in) override
	{
		Base::read(in);
		in >> cacao >> type >> filling;
		return in;
	}
	std::ostream& print(std::ostream& out) const override
	{
		Base::print(out);
		out << "\nCacao: " << cacao << " Type: " << type << " Filling: " << filling;
		return out;
	}

private:
	double cacao;
	string type;
	bool filling;
};
