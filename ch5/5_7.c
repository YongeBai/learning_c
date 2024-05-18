#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int sp = 0;

void push(int c) {
    stack[sp] = c;
    sp++;
}

int pop() {
    return (stack[--sp]);
}

int atoi(char c[]) {
    int n = 0;
    int i = 0;
    while (c[i])
    {
        n = n*10 + c[i] - '0';
        i++;
    }
    return n;
}

int main(int argc, char const *argv[])
{    
    char op1, op2;
    while (--argc > 0) {
        switch (**++argv)        
        {
        case '*':
            op1 = pop();
            op2 = pop();
            push(op1 * op2);
            break;
        case '/':
            op1 = pop();
            op2 = pop();
            push(op1 / op2);
            break;
        case '+':
            op1 = pop();
            op2 = pop();
            push(op1 + op2);
            break;
        case '-':
            op1 = pop();
            op2 = pop();
            push(op1 - op2);
            break;
        case '=':
            printf("%d\n", pop());
            break;
        case ' ':
            break;
        default:
            push(atoi(*argv));
            break;
        }
    }
    
    return 0;
}
