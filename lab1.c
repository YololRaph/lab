#include <stdio.h>


double series_sum(long long int n);
int main(){
    long long int n;
    double sum = 0;
    printf("Enter the upper limit of the summation: ");
    if (scanf("%lld", &n) != 1) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }
    sum = series_sum(n);
    printf("%10.10f\n", sum);
    return 0;
}
double series_sum(long long int n){
    double sum = 0;
    for (long long int i=1; i <= n; i++){
        double i_dbl = (double)i; 
        double i2 = i_dbl * i_dbl;
        double i4 = i2 * i2;
        
        sum += i2 / (i4 + 1.0);
    }
    if (n%2!=0){
        sum=-sum;
    }
    return sum;
}


/*The largest N for which the sum can be computed in under a second, can be determined through testing a single parameter and then solving for N=Ntest/time, since the time complexity is O(N)
--source Discrete Mathematics and Its Applications 8th Edition,Rosen 
The sum doesnt converge since the value of (-1^N) alternates`, so the series diverges by oscillation 
Since our variable type is long long int ,the largest N the program can handle is LLONG_MAX which is 9223372036854775807 */
