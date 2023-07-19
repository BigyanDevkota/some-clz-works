#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quad();
int comp(float x1,float x2);

int main()
{
    quad();
    return 0;
}

int comp(float x1, float x2)
{
    double tolerance = 0.0001;

    if ((x1 - (int)x1) < tolerance && (x2 - (int)x2) < tolerance)
     {
        printf("The roots are: x = %.0f and %.0f\n", x1, x2);
    } 
    else if ((x1 - (int)x1) < tolerance)
     {
        printf("The roots are: x = %.0f and %.2f\n", x1, x2);
    } 
    else if ((x2 - (int)x2) < tolerance) 
    {
        printf("The roots are: x = %.2f and %.0f\n", x1, x2);
    } 
    else
    {
        printf("The roots are: x = %.2f and %.2f\n", x1, x2);
    }
}

void quad()
{

    int a, b, c;
    float dis, act_dis;
    float imag_part, real_part;

    printf("enter the coefficient of x^2 (a):\n ");
    scanf("%d", &a);

    printf("enter the coefficient of x (b):\n ");
    scanf("%d", &b);

    printf("enter the coefficient of x^0 (c):\n ");
    scanf("%d", &c);

    dis = (pow(b, 2) - 4 * a * c);
    act_dis = sqrt(dis);

    float x1 = (-b + act_dis) / (2 * a);
    float x2 = (-b - act_dis) / (2 * a);

    if (dis > 0)
    {
        comp(x1,x2);
        printf("roots are real and unequal\n ");
    }
    else if (dis == 0)
    {
        comp(x1,x2);
        printf("roots are real and equal\n ");
    }
    else
    {
        real_part = -b / (2 * a);
        imag_part = sqrt(abs(dis)) / (2 * a);

        if (real_part == (int)real_part && imag_part == (int)imag_part)
        {
            printf("the roots are: x = %.0f + %.0fi and %.0f - %.0fi \n ", real_part, imag_part, real_part, imag_part);
        }

        else if (real_part == (int)real_part && imag_part == (float)imag_part)
        {
            printf("the roots are: x = %.0f + %.2fi and %.0f - %.2fi \n ", real_part, imag_part, real_part, imag_part);
        }

        else if (real_part == (float)real_part && imag_part == (int)imag_part)
        {
            printf("the roots are: x = %.2f + %.0fi and %.2f - %.0fi \n ", real_part, imag_part, real_part, imag_part);
        }

        else
        {
            printf("the roots are: x = %.2f + %.2fi and %.2f - %.2fi \n ", real_part, imag_part, real_part, imag_part);
        }

        printf("roots are imaginary and unequal\n ");
    }
}

//QUESTIONS

/*
2x2-5x+3=0

x2-45x+324=0

x2+4x+5=0

3x2-4x+10=0

5x2+40x+108=0
*/