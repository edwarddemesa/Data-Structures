/******************************************************************************

Author: Edward DeMesa
Title: Recursion Code -- YouTube Tutorial Series

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//Function prototype
void head_recursion(int data);
void tail_recursion(int data);
void count_down(int data);
void count_up(int data);
void direct_recursion(int data);
void tree_recursion(int data);
int nested_recursion(int data);
void indirect_recursion_A(int data);
void indirect_recursion_B(int data);
void cascade_numbers(int data);
int factorial(int data);
int fibonacci(int data);
int fibonacci_m(int data);


int fib_arr[47];


int main()
{
    // initialize array values to -1
     for(int i = 0; i < 47; i++)
    {
        fib_arr[i] = -1;
    }

    int fib = fibonacci_m(47);

    printf("%d\n", fib);

    return 0;
}


/******************************************************************************
                                      head_recursion() function                                          *
******************************************************************************/
void head_recursion(int data)
{
    if(data > 0)
    {
        // First statement -- recursive call
        head_recursion(data - 1);
        printf("%d\n", data);
    }
}


/******************************************************************************
                                         tail_recursion() function                                          *
******************************************************************************/
void tail_recursion(int data)
{
    if(data > 0)
    {
         printf("%d\n", data);

         // Last statement -- recursive call
        tail_recursion(data - 1);

    }
}


/******************************************************************************
                                            count_up() function                                               *
******************************************************************************/
void count_up(int data)
{
    for(int i = 1; i <= data; i++)
    {
        printf("%d\n", i);
    }
}


/******************************************************************************
                                            count_down() function                                          *
******************************************************************************/
void count_down(int data)
{
    for(int i = data; i > 0; i--)
    {
        printf("%d\n", i);
    }
}


/******************************************************************************
                                     direct_recursion() function                                          *
******************************************************************************/
void direct_recursion(int data)
{
    if(data > 0)
    {
        printf("%d\n", data);
        direct_recursion(data/2);
        printf("%d\n", data);
    }
}


/******************************************************************************
                                   tree_recursion() function                                          *
******************************************************************************/
void tree_recursion(int data)
{
    if(data > 1)
    {
        printf("%d\n", data);
        tree_recursion(data/2);
        tree_recursion(data/2);
    }
}


/******************************************************************************
                                   nested_recursion() function                                          *
******************************************************************************/
int nested_recursion(int data)
{
    if(data < 20)
    {
        return data + 1;
    }
    else
    {
        return nested_recursion(nested_recursion(data/2));
    }
}


/******************************************************************************
                              indirect_recursion_A() function                                          *
******************************************************************************/
void indirect_recursion_A(int data)
{
    if(data >0)
    {
        printf("%d -- ", data);
        if(data%2 == 0)
            printf("even\n");
        else
            printf("odd\n");

        indirect_recursion_B(data -1);
    }
}


/******************************************************************************
                              indirect_recursion_B() function                                          *
******************************************************************************/
void indirect_recursion_B(int data)
{
    if(data >0)
    {
        printf("%d -- ", data);
        if(data%2 == 0)
            printf("even\n");
        else
            printf("odd\n");

        indirect_recursion_A(data -1);
    }
}


/******************************************************************************
                              indirect_recursion_B() function                                          *
******************************************************************************/
void cascade_numbers(int data)
{
    if(data < 10)
    {
        printf("%d\n", data);
    }
    else
    {
        printf("%d\n", data);
        cascade_numbers(data/10);
        printf("%d\n", data);
    }
}


 /******************************************************************************
                                            factorial() function                                                 *
******************************************************************************/
 int factorial(int data)
{
    // base case
    if(data == 1)
    {
        return 1;
    }

    // recursive case
    else
    {
        return data * factorial(data -1);
    }
}


/******************************************************************************
                                          fibonacci() function                                                 *
******************************************************************************/
int fibonacci(int data)
 {
     // base case
     if(data == 0 || data == 1)
     {
         return data;
     }

     // recursive case
     return (fibonacci(data - 2) + fibonacci(data -1));
 }


 /******************************************************************************
                                          fibonacci_m() function                                             *
******************************************************************************/
 int fibonacci_m(int data)
{
    // base case
    if(data == 0 || data == 1)
    {
        fib_arr[data] = data;
        return data;
    }

    // recursive case
    else
    {
        // Assign function values to array index
        if(fib_arr[data - 2] == -1)
        {
            fib_arr[data - 2] = fibonacci_m(data - 2);
        }
        if(fib_arr[data - 1] == -1)
        {
            fib_arr[data - 1] = fibonacci_m(data - 1);
        }

        return fib_arr[data - 2] + fib_arr[data -1];
    }
}




