#include <stdio.h>

int sp = 0;
double val[10];

double push(double f)
{
    return (val[sp++] = f);
}

double pop()
{
    return val[sp--];
}

double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; s[i] == ' ' || s[i] == '\n' || s[i] == '\t'; i++)
    {
        ;
    }

    sign = 1;
    if (s[i] == '+' || s[i] == '-')
    {
        sign = (s[i++] == '+') ? 1 : -1;
    }
    for (val = 0; s[i] >= '0' && s[i] <= '9'; i++)
    {
        val = 10 * val + s[i] - '0';
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1; s[i] >= '0' && s[i] <= '9'; i++)
    {
        val = 10 * val + s[i] - '0';
        power *= 10;
    }
    val = sign * val / power;
    return val;
}

int main()
{
    int type;
    char s[] = "1 2 - 4 5 + * =";
    double op2, atof(), pop(), push();
    int i = 0;

    while (s[i] != '\0')
    {
        printf("%c", s[i]);
        switch (s[i])
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            char tmp[2] = {s[i], '\0'};
            push(atof(tmp));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            push(pop() / op2);
            break;
        case '%':
            op2 = pop();
            push((int)pop() % (int)op2);
            break;
        case 'e':
            pop();
            break;
        case '=':
            printf("%f\n", pop());
            break;
        default:
            break;
        }
        i++;
    }
}