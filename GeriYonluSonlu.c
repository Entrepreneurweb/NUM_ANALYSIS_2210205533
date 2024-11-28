#include <stdio.h>
#include <stdlib.h>

 
double Y_Delta_Geri(int degre, int index, double** YDelta_array, double* X, double* Y, int n) {
     
    if (index - degre < 0) {
        return 0;
    }

   
    if (YDelta_array[degre][index] != 0) {
        return YDelta_array[degre][index];
    }

 
    if (degre == 0) {
        YDelta_array[degre][index] = Y[index];  
    } else {
        YDelta_array[degre][index] = (Y_Delta_Geri(degre - 1, index - 1, YDelta_array, X, Y, n) -
                                      Y_Delta_Geri(degre - 1, index, YDelta_array, X, Y, n)) /
                                     (X[index] - X[index - degre]);
    }

    return YDelta_array[degre][index];
}

 
double X_multiplication_Geri(int degre, double x, double* X, int n) {
    double result = 1;
    for (int i = n - 1; i >= n - degre; i--) {
        result *= (x - X[i]);
    }
    return result;
}

 
double P_polinum_Geri(double x, double** YDelta_array, double* X, double* Y, int n) {
    double Result = 0;

    for (int degre = 0; degre < n; degre++) {
     
        double delta = Y_Delta_Geri(degre, n - 1, YDelta_array, X, Y, n);

        
        Result += delta * X_multiplication_Geri(degre, x, X, n);
    }

    return Result;
}

int main() {
    int n = 4;  
    double X[] = {1, 2, 3, 4};  
    double Y[] = {1, 4, 9, 16};  

     
    double** YDelta_array = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        YDelta_array[i] = (double*)calloc(n, sizeof(double));  
    }

    
    double x = 2.5;
    double result = P_polinum_Geri(x, YDelta_array, X, Y, n);

    printf("Pn(%.2f) = %.4f\n", x, result);

     
    for (int i = 0; i < n; i++) {
        free(YDelta_array[i]);
    }
    free(YDelta_array);

    return 0;
}
