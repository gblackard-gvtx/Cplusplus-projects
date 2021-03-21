#include "Die.h" // for rand and srand
#include <cstdlib> //for the time function
#include <ctime>
using namespace std;
Die::Die(int numSides)
{
	// get the system time
	unsigned seed = time(0);

	// seed the random number gen
	srand(seed);
	// set the number of sides
	sides = numSides;

	// proform the initail roll
	roll();
	


}
void Die::roll() 
{
	// constant for the min die value
	const int MIN_VALUE = 1;

	value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;

}

int Die::getValue()
{
	return value;
}

int Die::getSides()
{
	return sides;
}

