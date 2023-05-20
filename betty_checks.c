#include <stdio.h>
#include <unistd.h>

/**
  * add - simple additcion
  *
  * Return: reture zero (0)
  *
  */

int add (void)
{
	int a = 3;
	int b = 4;
	int c = a + b;

	if (a != 0)
	{
		printf("c equal %d\n", c);
	}

return (0);
}
