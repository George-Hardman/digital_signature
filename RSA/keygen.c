// https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
// https://www.cryptopals.com/sets/5/challenges/39

#include <stdio.h>


int gcd(int a, int b); // greatest common divisor

int egcd(int a, int b, int* x, int* y); //

int lcm(int a, int b);

int invmod(int A, int M);

int main()
{

    // printf("%d", lcm(17,3120));
    // printf("%d\n", invmod(17, 3120));

    int p, q; // Two large prime numbers
    p = 3;
    q = 7;

    int n = p * q;

    int et = (p-1)*(q-1);
    int e = 3;

    int d = invmod(e, et);


    return 0;
}

int gcd(int a, int b) // greatest common divisor
{
    int temp;
    while(1)
    {
        temp = a % b;
        if (temp == 0) return b;
        a = b;
        b = temp;
    }
}

int lcm(int a, int b)
{
    return (a * b)/gcd(a, b);
}


int egcd(int a, int b, int* x, int* y){
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = egcd(b % a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

int invmod(int A, int M)
{
    int x, y;
    int g = egcd(A, M, &x, &y);
    if (g != 1)
    {
        printf("Inverse does not exist");
        return 0;
    }
    else
    {
        int res = (x % M + M) % M;
        return res;
    }
}