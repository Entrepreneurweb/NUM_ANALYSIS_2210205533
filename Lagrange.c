#include <stdio.h>
#include <math.h>

double F_function(double x){
    return  pow(x , 2)+ 2*x+1;
}


double L_lagrange(int *X_array, int array_Size, double x, int k) {
    double Lagrange = 1.0;

    for (int i = 0; i < array_Size; i++) {
        if (i != k) {
            Lagrange *= (x - X_array[i]) / (X_array[k] - X_array[i]);
        }
    }

    return Lagrange;
}

double P_polinom(double x, int *X_array, int array_Size) {
    double Result = 0.0;

    for (int i = 0; i < array_Size; i++) {
        Result += L_lagrange(X_array, array_Size, x, i) * F_function(X_array[i]);
    }

    return Result;
}


int main(){
    int Array[4] = {1, 2, 3, 4};
    
     
   double PolinomResult = P_polinom(2.5, Array, 4);
    printf("Lagrange polynomial = %lf\n", PolinomResult);
    return 1 ;
}