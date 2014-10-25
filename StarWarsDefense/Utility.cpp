#include "Utility.h"

namespace Utility
{
	void itoa(int val, char* c)
	{
		int i = 0;
		do
		{
			c[i] = val % 10 + '0';
			val /= 10;
			i++;
		} while (val);
		c[i] = '\0';
		reverse(c);
	}

	char* reverse(char* c)
	{
		char tmp;

		int size = strlen(c);
		for (int i = 0; i < size / 2; i++)
		{
			tmp = c[i];
			c[i] = c[size - i - 1];
			c[size - i - 1] = tmp;
		}
		return c;
	}
}