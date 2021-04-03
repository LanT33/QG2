#ifndef ISOPERATOR_H_INCLUDED
#define ISOPERATOR_H_INCLUDED

#endif // ISOPERATOR_H_INCLUDED
#include "SqStack.h"

int IsOperator(char ch)
{
    char ops[] = "+-*/";
    int i;
    for (i = 0; i < 4; i++)
    {
        if (ch == ops[i])
            return 1;
    }
    return 0;
}


int Precedence(char op)
{
    if (op == '(')
    {
        return -1;
    }
    else if(op == '*' || op == '/')
        return 1;
    else if(op == '+' || op == '-')
        return 0;
}
