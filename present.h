#pragma once

#include"mainHeader.h"

class Present
{
public:
	Present() = default;
	~Present() = default;

	double getWeight() const { return weight; }
	double getPrice() const { return price; }

	void createByWeight(double, Sweets&);

	void print(std::ostream&);

private:
	vector<std::shared_ptr<Base>> present;
	double weight = 0;
	double price = 0;
};

void Present::createByWeight(double w, Sweets& s)
{
	Present p;

	bool flag = true;

	s.sortWeight();

	while (w > 0 && flag)
	{
		std::for_each(s.sweets.begin(), s.sweets.end(),
			[&w, &p, &flag, s](std::shared_ptr<Base> cur)
			{
				if (cur->getWeight() < w)
				{
					w -= cur->getWeight();
					p.price += cur->getPrice();
					p.present.push_back(cur);
				}
				else if (w < s.sweets.back()->getWeight())
					flag = false;
			});
	}
	*this = p;
}

void Present::print(std::ostream&out)
{
	std::copy(present.begin(), present.end(), 
		std::ostream_iterator<std::shared_ptr<Base>>(out));
}

