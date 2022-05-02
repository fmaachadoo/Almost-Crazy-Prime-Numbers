#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int find_divisors(int number){
    //returns true if finds 10 divisors greater than 10
    int possibilities, mod, divisor_count = 0;
    possibilities = number / 2;
    double n_sqrt = sqrt(number);
    for(int i=1; i<n_sqrt; i++){
        mod = number % i;
        if(mod == 0){
            if(i==1) continue;
            if(i > 10){
                divisor_count++;
                if(divisor_count == 10){
                    return TRUE;
                }
            }else{
                return FALSE;
            }

            
        }
    }
    return FALSE;
}

void find_almost_crazy_prime(int number){
    int possibility = number;
    int FOUND_ACP = FALSE;
    while(FOUND_ACP == FALSE){
        possibility++;
        if(possibility<508079) continue;
        FOUND_ACP = find_divisors(possibility);
    }

    printf("%d\n", possibility);
    
}

int main(){
    printf("Hello world!\n");
    int qty;
    printf("how many numbers? ");
    scanf("%d", &qty);
    for(int i=0; i<qty; i++){
        int number_a, number_b;
        printf("write the number: ");
        scanf("%d", &number_a);
        // cria thread
        find_almost_crazy_prime(number_a);

        // scanf("%d", &number_b);
        //cria thread  
    
        // espera thread
        // espera thread   

    }
    return 0;
}