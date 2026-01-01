#include<stdio.h>
#include<string.h>

double num_from_string(char* str){
    int i = 0;
    double num = 0;
    while(str[i] != '\0' && str[i] != '.'){
        num *= 10;
        num += str[i] - '0';
        i++;
    }
    double divisor = 10.0;
    while(str[i] != 0){
        if(str[++i]!= 0){
            num += (str[i] - '0') / divisor;
            divisor *= 10;
        } else {
            break;
        }
    }
    return num;
}


int main(){
    // double num;
    char *str = "12";
    printf("%f", num_from_string(str));

}


