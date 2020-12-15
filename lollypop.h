#pragma once

#include"mainHeader.h"

class Lollypop : public Base
{
public:
	Lollypop() = default;
	~Lollypop() override = default;

	std::istream& read(std::istream& in) override
	{
		Base::read(in);
		in >> taste >> shape;
		return in;
	}
	std::ostream& print(std::ostream& out) const override
	{
		Base::print(out);
		out << "\nTaste: " << taste << " Shape: " << shape;
		return out;
	}

private:
	string taste;
	string shape;
};