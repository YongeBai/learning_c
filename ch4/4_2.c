#include <stdio.h>
#include <math.h>

double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; s[i] == ' ' || s[i] == '\n' || s[i] == '\t'; i++){;}

    sign = 1;
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i++] == '+') ? 1 : -1;
    }
    for (val=0; s[i] >= '0' && s[i] <= '9'; i++) {
        val = 10 * val + s[i]-'0';        
    }
    if (s[i] == '.') {
        i++;
    }
    for (power=1; s[i] >= '0' && s[i] <= '9'; i++) {
        val = 10 * val + s[i] - '0';
        power *= 10;
    }

    if (s[i] == 'e' || s[i] == 'E') {
        i++;
    }
    
    int div = 1, expo;
    if (s[i] == '-') {
        div = -1;
        i++;
    }
    for (expo=0; s[i] >= '0' && s[i] <= '9'; i++) {
        expo = 10 * expo + s[i] - '0';
    }
    val = sign * val / power;
    return (val * pow(10, div*expo));
    
}

int main(int argc, char const *argv[])
{
    char s[] = "123.123e3";
    printf("%f\n", atof(s));
    return 0;
}
