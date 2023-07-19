#include <stdio.h>
#include <math.h>

void ind();
void dis();
void con();

int n, i ;

int main()
{
    int type;
    printf("SELECT THE SERIES IN WHICH DATA ARE GIVEN:\n");
    printf("1. INDIVIDUAL SERIES\n2. DISCRETE SERIES\n3. CONTINUOUS SERIES\n");
    printf("TYPE 1 FOR INDIVIDUAL, TYPE 2 FOR DISCRETE, TYPE 3 FOR CONTINUOUS SERIES\n");
    scanf("%d", &type);

    switch (type)
    {
    case 1:
        ind();
        break;

    case 2:
        dis();
        break;

    case 3:
        con();
        break;

    default:
        printf(" you typed invalid number. try again\n");
        break;
    }

    return 0;
}

void ind()
{
    float mean;
    float standard_deviation, sum_of_data = 0, sum_of_x_square = 0;

    printf("enter the number of observations\n\n");
    scanf("%d", &n);

    double data[n];

    printf("start entering data\n");

    for (i = 0; i < n; i++)
    {
        scanf("%lf", &data[i]);
        sum_of_data = sum_of_data + data[i];
        sum_of_x_square = sum_of_x_square + pow(data[i], 2);
    }

    mean = sum_of_data / n;
    standard_deviation = sqrt((sum_of_x_square / n) - pow(mean, 2));

    printf("\nData\t\t\tSquare of Data\n");

    for (i = 0; i < n; i++)
    {
        printf("%.2lf\t\t\t%.2lf\n", data[i], pow(data[i], 2));
    }
    printf("sum_of_data=%.2f\tsum_of_x_square=%.2f\n\n", sum_of_data, sum_of_x_square);
    printf("standard_deviation=%.2f\n", standard_deviation);
}

void dis()
{
    float mean;
    float standard_deviation, summation_fx = 0, summation_fx_square = 0;
    printf("enter the number of observations\n");
    scanf("%d", &n);

    float data[n];

    int summation_of_freq = 0, freq[n], N;

    for (i = 0; i < n; i++)
    {
        printf("enter data\n");
        scanf("%f", &data[i]);
        printf("enter the frequency of data\n");
        scanf("%d", &freq[i]);
        summation_of_freq = summation_of_freq + freq[i];
        summation_fx = summation_fx + (freq[i] * data[i]);
        summation_fx_square = summation_fx_square + (freq[i] * data[i] * data[i]);
    }

    N = summation_of_freq;
    mean = summation_fx / N;
    standard_deviation = sqrt((summation_fx_square / N) - pow(mean, 2));

    printf("\nData\t\t   Freqency(f)\t\t\tfx\t\t\tfx^2\n");

    for (i = 0; i < n; i++)
    {
        printf("%.2f\t\t\t%d\t\t\t%.2f\t\t\t%.2f\n", data[i], freq[i], (freq[i] * data[i]), (freq[i] * data[i] * data[i]));
    }
    printf("total\t\tsummation_of_freq=%d\tsummation_fx=%.2f\tsummation_fx_square=%.2f\n\n", summation_of_freq, summation_fx, summation_fx_square);
    printf("standard_deviation=%.2f\n\n", standard_deviation);
}

void con()
{
    char ch;
    float mean;
    float standard_deviation, summation_fx = 0, summation_fx_square = 0;
    printf("enter the number of observations\n");
    scanf("%d", &n);

    float mid_value[n];
    float low[n], upp[n];
    int summation_of_freq = 0, freq[n], N;

    for (i = 0; i < n; i++)
    {
        printf("enter class interval\n");
        scanf("%f%c%f", &low[i], &ch, &upp[i]);
        printf("enter the frequency of class interval\n");
        scanf("%d", &freq[i]);
        mid_value[i] = (low[i] + upp[i]) / 2;
        summation_of_freq = summation_of_freq + freq[i];
        summation_fx = summation_fx + (freq[i] * mid_value[i]);
        summation_fx_square = summation_fx_square + (freq[i] * mid_value[i] * mid_value[i]);
    }

    N = summation_of_freq;
    mean = summation_fx / N;
    standard_deviation = sqrt((summation_fx_square / N) - pow(mean, 2));

    printf("\nClass Interval\t\t   Freqency(f)\t\t   Mid_value(x)\t\t fx\t\t\tfx^2\n");

    for (i = 0; i < n; i++)
    {
        printf("%.2f%c%.2f\t\t\t%d\t\t   %.2f\t\t\t%.2f\t\t\t%.2f\n", low[i], ch, upp[i], freq[i], mid_value[i], (freq[i] * mid_value[i]), (freq[i] * mid_value[i] * mid_value[i]));
    }
    printf("total\t\t\tsummation_of_freq=%d\t\t\t\tsummation_fx=%.2f\tsummation_fx_square=%.2f\n\n", summation_of_freq, summation_fx, summation_fx_square);
    printf("standard_deviation=%.2f\n\n", standard_deviation);
}

// WRITTEN BY: BIGYAN