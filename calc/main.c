//
// Created by Nick Duncan on 2/10/16.
// Main portion for calculator portion of book.
//
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

int main() {
    int type;
    double opTwo;
    char s[MAXOP];

    while((type = getop(s)) != EOF) {
        switch (type) {

            case NUMBER:
                push(atof(s));
                break;

            case '+':
                push(pop() + pop());
                break;

            case '*':
                push(pop() * pop());
                break;

            case '-':
                opTwo = pop();
                push(pop() - opTwo);
                break;

            case '/':
                opTwo = pop();
                if (opTwo != 0.0)
                    push(pop() / opTwo);
                else
                    printf("error: zero divisor\n");
                    break;

            case '\n':
                printf("\t%.8g\n", pop());
                break;

            default:
                printf("error: unknown passed in value: %s\n", s);
                break;
        }
    }

    return 0;

}


