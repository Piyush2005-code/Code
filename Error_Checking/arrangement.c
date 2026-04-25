#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int abs(int a);

int abs(int a){
    if(a >= 0)
    return a;
    else
    return -a;
    
}



int main() {

    int t;
    scanf("%d", &t);
    int* output = (int*)calloc(t, sizeof(int));
    char* str;
    char* tstr;
    int n, swaps;
    
    for(int iter = 0; iter < t; iter++){
        scanf("%d", &n);
        int i = 0, j = 0;
        int count1_str = 0, count1_tstr = 0;
        swaps = 0;

        str = (char*)malloc((n+1)*sizeof(char));
        tstr = (char*)malloc((n+1)*sizeof(char));
        fgets(str, 100, stdin);
        fgets(tstr, 100, stdin);
        
        for(int l = 0; l < n; l++)
            if(str[l] == '1') count1_str++;
        
        for(int l = 0; l < n; l++)
            if(tstr[l] == '1') count1_tstr++;

        if(count1_str == count1_tstr){
            while(i < n && j < n){
                if(str[i] == tstr[j] && str[i] == '1'){
                    i++; j++; swaps += abs(i-j);
                }
                else if(str[i] != tstr[j]){
                    if(str[i] == '1') j++;
                    else i++;   
                }
                
            }
            output[iter] = swaps;
            
        }
        else output[iter] = -1;
        
        
        free(str);free(tstr);
    }
    
    
    for(int iter = 0; iter < t; iter++)
        printf("%d\n", output[iter]);
    
    free(output);
}
