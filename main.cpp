#include"mainHeader.h"


int main()
{
	std::ifstream in("treats.txt");
	Sweets candies;
	candies.readSweets(in);
	candies.print(cout);

	return 0;
}