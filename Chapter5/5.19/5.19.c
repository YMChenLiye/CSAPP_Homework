#include<stdint.h>

typedef int size_t;
void *memset1(void *s, int c, size_t n)
{
	size_t cnt = 0;
	size_t k = sizeof(unsigned long);
	size_t i, j;
	unsigned long cl;
	unsigned char * schar = s;
	unsigned char * cchar = (char *)&cl;
	size_t limit;

	for (i = 0; i < k; i++)
		cchar[i] = (unsigned char)c;

	if (n < k)
	{
		limit = 0;
		while (cnt < n)
		{
			*schar++ = (unsigned char)c;
			cnt++;
		}
	}
	else
	{
		while ((size_t)schar%k)
		{
			*schar++ = (unsigned char)c;
			cnt++;
		}
		limit = n - cnt - k + 1;
		for (i = 0; i < limit; i += k)
			for (j = 0; j < k / 4; j++)
			{
				schar[0] = cchar[0];
				schar[1] = cchar[1];
				schar[2] = cchar[2];
				schar[3] = cchar[3];
				schar += 4;
				cnt += 4;
			}
		for (; cnt < n; cnt++)
		{
			*schar++ = (unsigned char)c;
			cnt++;
		}
	}
	return s;
}