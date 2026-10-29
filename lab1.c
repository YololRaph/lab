#include <stdio.h>


double series_sum(long long int n);
int main(){
    long long int n;
    double sum = 0;
    printf("Enter the upper limit of the summation: ");
    if (scanf("%lld", &n) != 1 || n < 1){
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }
    sum = series_sum(n);
    printf("%10.10f\n", sum);
    return 0;
}
double series_sum(long long int n){
    double sum = 0;
    for (long long int i=n; i >= 1; i--){
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
so for example if we test for Ntest=500000000 and it takes 1.509 seconds, then we can compute N=500000000/1.509=331345261 as the largest N that can be computed in under a second
however time depends on the CPU of each computer, so results may vary.
--source Discrete Mathematics and Its Applications 8th Edition,Rosen,Chapter 3.2-3.3 
The sum doesnt converge since the value of (-1^N) alternates`, so the series diverges by oscillation 
Since our variable type is long long int ,the largest N the program can handle is LLONG_MAX which is 9223372036854775807 */
/*Το μεγαλύτερο N για το οποίο το sum μπορεί να υπολογισθεί σε κάτω από ένα δευτερόλεπτο μπορεί να βρεθεί από το να ελέγχουμε μια παράμετρο
και μετά να λύσουμε προς N=Ntest/time καθώς το time complexity είναι O(N)
οπότε για παράδειγμα αν ελέγξουμε για Ntest=500000000 και πάρει 1,509 δευτερόλεπτα, τότε μπορούμε να υπολογίσουμε N=500000000/1,509=331345261 ως το μεγαλύτερο N που μπορεί να υπολογισθεί σε κάτω από ένα δευτερόλεπτο
ωστόσο ο χρόνος εξαρτάται από το CPU του κάθε υπολογιστή, οπότε τα αποτελέσματα μπορεί να διαφέρουν. 
--source Discrete Mathematics and Its Applications 8th Edition,Rosen,Chapter 3.2-3.3
Το sum δεν συγκλίνει καθώς η τιμή του (-1^N) εναλλάσσεται, οπότε η σειρά αποκλίνει λόγω ταλάντωσης 
Καθώς ο τύπος μεταβλητής μας είναι long long int , το μεγαλύτερο N που μπορεί να χειριστεί το πρόγραμμα είναι LLONG_MAX που είναι 9223372036854775807 */