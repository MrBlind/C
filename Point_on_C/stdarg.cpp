#include<stdio.h>
#include<stdarg.h>

float
average(int n_values , ...);

int
main()
{
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;
    scanf("%d", &n1 );
    scanf("%d", &n2 );
    printf("%f", average(4,n1,n2,n3,n4));
    return 0;
}


float
average( int n_values , ... )
{
    va_list var_arg;					//var_arg is the name of the first parameter
    int count;
    float sum=0;
    va_start( var_arg, n_values );		//from the first to the last You can't select the second one without the first one
    for( count = 0; count < n_values; count += 1)
    {

        sum += va_arg( var_arg, int );
    }
    va_end( var_arg );

    return sum / n_values;
}


