#include <stdio.h>

// function declaration
int swap(int *, int *);  /*  we can also write void swap(int *x, int *y);  */

int main()
{
    int a, b;
    a= 10; 
    b= 20;
    printf("Before in main: a= %d, b= %d\n", a, b);

    // function call
    swap(&a, &b); /* the address of a and b is passed to pointers x and y */

    printf("After in main: a= %d, b= %d", a, b);
    return 0;
}

//function definition
int swap(int *x, int *y)
{
    int t;
    t= *x;  /* here the value at pointer x (which actually points to the value stored in a) is copied to the int temp. */
    *x= *y;  /* The swapping done here affects the actual parameter's value */
    *y= t;
    printf("In Function: x= %d, y= %d\n", *x, *y);
}
