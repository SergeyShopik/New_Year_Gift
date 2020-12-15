#pragma once

#include"mainHeader.h"

class Marshmellow : public Base
{
public:
	Marshmellow() = default;
	~Marshmellow() override = default;

	std::istream& read(std::istream& in) override
	{
		Base::read(in);
		in >> inChoc >> flavor;
		return in;
	}
	std::ostream& print(std::ostream& out) const override
	{
		Base::print(out);
		out << "\ninChoc: " << inChoc << " Flavor: " << flavor;
		return out;
	}

private:
	bool inChoc;
	string flavor;
};