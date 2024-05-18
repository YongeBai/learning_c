#include <stdio.h>
#include <math.h>

int htoi(s)
char s[];
{
	int n = 0, len = 0;	
	
	for (int i = 0; s[i] != '\0'; i++) {
		len++;
	}

	int c, pow, i;
	for (i = 0; s[i] != '\0'; i++)
	{
		pow = 1;
		if (s[i] <= '9' && s[i] >= '0') {
			c = s[i] - '0';
		}
		else if (s[i] <= 'Z' && s[i] >= 'A')
		{
			c = s[i] - 55;
		}
		else if (s[i] <= 'z' && s[i] >= 'a')
		{
			c = s[i] - 87;
		}
		for (int j = 0; j<len-i-1; j++){
			pow = pow * 16;
		}
		n += pow * c;
	}
	return n;
}

int main() {
	printf("%d\n", htoi("1D2a3fB"));
}