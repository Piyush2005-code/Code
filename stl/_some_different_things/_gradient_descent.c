#include<stdio.h>
// Although not optimal, but good implementation...


int a, b;

double absolute(double a);

double func(double x);

double slope(double x);

double grad_desc(double start, double alpha);

double absolute(double a){
    return (a >= 0)? a : -a;
}

double func(double x){
    return (x-a)*(x-a) + b;
}

double slope(double x){
    return (func(x + 0.001) - func(x))/ 0.001;
}

double grad_desc(double start_x, double alpha){

    double updated_x = start_x;
    double previous_x = start_x + 5;

    while(1){
        if(absolute(updated_x - previous_x) < 0.00001)
        return updated_x;
        
        //updation of the values of updated_x and the previous_x:
        previous_x = updated_x;
        updated_x = previous_x - alpha * slope(previous_x);

        if(absolute(updated_x - previous_x) > 10)
        return -1;

    }

}


int main(){

    double start_value;
    double learning_rate;

    printf("Enter the constants 'a' and 'b' in the equation : y = (x - a)^2 + b : \n\n");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("The function is y = (x-%d)^2 + %d\n\n", a, b);

    printf("Enter the starting value of x : ");
    scanf("%lf", &start_value);
    printf("Enter the learning rate value for the gradient descent algorithm : ");
    scanf("%lf", &learning_rate);


    double min_x = grad_desc(start_value, learning_rate);
    if(min_x == -1)
    printf("Overshoot error");
    else
    printf("\n\nThe value of x and the minimized cost function value for the local minimum will be : %lf , %lf", min_x, func(min_x));



}




