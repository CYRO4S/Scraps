//
// Created by Ralf Ren on 2018-12-06.
//

#include "inc/stack.h"
#include <stdio.h>

void dec2oct()
{
    SeqStack stack;
    init(stack);

    int number, result;
    scanf("%d", &number);

    while (number)
    {
        push(stack, number % 8);
        number = number / 8;
    }

    while (! isEmpty(stack))
    {
        pop(stack, result);
        printf("%d", result);
    }
}

void lineEdit()
{
    SeqStack stack;
    init(stack);

    char ch = (char)getchar();
    while (ch != EOF)
    {
        while (ch != EOF && ch != '\n')
        {
            switch (ch)
            {
                case '#': pop(stack);
                case '@': init(stack);
                default: push(stack, ch);
            }
            ch = (char)getchar();
        }
        init(stack);
        if (ch != EOF) ch = (char)getchar();
    }
    // destroy(stack);
}
