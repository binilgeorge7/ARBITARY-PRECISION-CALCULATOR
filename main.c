/*
Name: Binil George
Date: 10-12-2025
PROJECT: Arbitrary Precision Calculator using Doubly Linked Lists
DESCRIPTION:
    This project implements a calculator capable of performing arithmetic
    operations ( +, -, x, / ) on very large integers that cannot be handled
    using standard C built-in data types like int or long long.

    It stores numbers as doubly linked lists, where each node represents
    one digit. This makes it possible to handle numbers of any size by
    performing manual digit-wise addition, subtraction, multiplication, and
    division similar to how we do calculations on paper.

FEATURES:
    -> Accepts large positive and negative integers
    -> Supports addition, subtraction, multiplication & division
    -> Proper sign handling
    -> Leading zero trimming
    -> Dynamic memory allocation for arbitrary number size
USAGE:
    ./a.out <operand1> <operator> <operand2>
Example:
        ./a.out 4321 + 123456
*/

#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include "header.h"

int main(int argc, char* argv[])
{
    //for validating arguments
    if(validate(argc, argv) == FAILURE)
    {
        printf("\n\tInvalid Arguments!!\n");
        return FAILURE;
    }

    Dlist *head1 = NULL; //initialize the header to NULL
	Dlist *tail1 = NULL; //initialize the tail to NULL

    Dlist *head2 = NULL; //initialize the header to NULL
	Dlist *tail2 = NULL; //initialize the tail to NULL

    Dlist *resh = NULL; //initialize the header to NULL
	Dlist *rest = NULL; //initialize the tail to NULL

    int sign1 = 1, sign2 = 1;
    if(argv[1][0] == '-')
    {
        sign1 = -1;
        convert_str_to_list(argv[1] + 1, &head1, &tail1);  //+1 to skip sign
    }
    else
    {
        convert_str_to_list(argv[1], &head1, &tail1);
    }
    if(argv[3][0] == '-')  // Detect sign of operand1
    {
        sign2 = -1;
        convert_str_to_list(argv[3] + 1, &head2, &tail2);  //+1 to skip sign
    }
    else
    {
        convert_str_to_list(argv[3], &head2, &tail2);
    }

    //Display inputs
    printf("\n\t RESULT\n=========================\n");
    printf("%c", sign1 == -1 ? '-' : ' ');
    print_list(head1);

    printf(" %c", argv[2][0]);

    printf("%c", sign2 == -1 ? '-' : ' ');
    print_list(head2);
    printf(" = ");

    int ressign = 1;

    switch(argv[2][0])
    {
        case '+':
            addition(&head1, &tail1, sign1, &head2, &tail2, sign2, &resh, &rest, &ressign);
            break;
        case '-':
           subtraction(&head1, &tail1, sign1, &head2, &tail2, sign2, &resh, &rest, &ressign);
            break;
        case 'x':
           multiplication(&head1, &tail1, sign1, &head2, &tail2, sign2, &resh, &rest, &ressign);
            break;
        case '/':
            division(&head1, &tail1, sign1, &head2, &tail2, sign2, &resh, &rest, &ressign);
            break;
    }

    //to print result
    trim_leading_zeroes(&resh, &rest); //trim zeros at front
    printf("%c", ressign == -1 ? '-' : ' ');
    print_list(resh);
    printf("\n\n");

}

