#include "Libraries.h"

int main()
{
	setlocale(0, "");
	Ring <int> copy(1);
	copy.Push(2);
	copy.Push(3);
	copy.Push(4);
	copy.Push(5);
	copy.Show();
	Ring <int> copy2 = copy;
	copy2.Show();
	//Ring<human> x;
	//perfomance(x);
	return 0;
}