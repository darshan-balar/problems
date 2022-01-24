//PROBLEM LINK: https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

/* ALGORITHM

1) FIND THE LCM OF FIRST SET (SINCE THE LCM OF THE SET IS DIVISIBLE BY ALL THE NUMBERS OF THE SET)

2) FIND THE GCD OF SECOND SET (SINCE ALL THE NUMBERS OF THE SET ARE DIVISIBLE BY THE GCD OF THE SET)

3) OUR ANSWER NOW LIES BETWEEN LCM AND GCD (INCLUSIVE) THAT WE HAVE FOUND

*/

#include<stdio.h>

int fun(int, int*, int, int*);
int gcd(int, int);

int main()
{
    int a[100], b[100], a_count, b_count;

    printf("\n\nEnter no. of elements in a and b: ");
    scanf("%d%d",&a_count,&b_count);

    printf("\n\nEnter the elements of a: ");
    for(int i = 0; i < a_count; i++)
        scanf("%d",&a[i]);

    printf("\n\nEnter the elements of b: ");
    for(int i = 0; i < b_count; i++)
        scanf("%d",&b[i]);

    int answer = fun(a_count, a, b_count, b);
    
    printf("\n\n%d\n\n",answer);
}

int fun(int a_count, int* a, int b_count, int* b) {

    int lcm = a[0], gcd_value = b[0], count = 0;

    //FINDING LCM OF 1ST SET
    for(int i = 1; i < a_count; i++)
        lcm = ( lcm * a[i] ) / gcd(lcm, a[i]);

    //FINDING GCD OF 2ND SET
    for(int i = 1; i < b_count; i++)
        gcd_value = gcd(gcd_value, b[i]);
        
    for(int i = lcm; i <= gcd_value; i = i+lcm)
    {
        if(i % lcm == 0 && gcd_value % i == 0)
            count++;
    }
    return count;
}

//FINDING GCD
int gcd(int a, int b)
{
    if(b == 0)
        return a;

    return gcd(b , a%b);
}