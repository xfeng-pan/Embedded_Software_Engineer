#include <stdio.h>

enum Sex
{
	MALE=6,
	FEMALE,
	SECRET
};

int main()
{
	enum Sex s = MALE;
	printf("%d\n", s);
	printf("%d\n", FEMALE);
	printf("%d\n", SECRET);
	return 0;
}