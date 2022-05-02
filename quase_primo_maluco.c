#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <stdint.h>

#define TRUE 1
#define FALSE 0

int answer_a, answer_b;

typedef struct thread_acp_struct {
    int tid, number;
} thread_acp_args;

int find_divisors(int number){
    //returns true if finds 10 divisors greater than 10
    int mod, divisor_count = 0;
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

void *find_almost_crazy_prime_a(void *args){

    int possibility;
    possibility = (intptr_t)args;
    int FOUND_ACP = FALSE;
    while(FOUND_ACP == FALSE){
        possibility++;
        if(possibility<508079) continue;
        FOUND_ACP = find_divisors(possibility);
    }

    // return possibility;
    answer_a = possibility;
}

void *find_almost_crazy_prime_b(void *args){

    int possibility;
    possibility = (intptr_t)args;
    int FOUND_ACP = FALSE;
    while(FOUND_ACP == FALSE){
        possibility++;
        if(possibility<508079) continue;
        FOUND_ACP = find_divisors(possibility);
    }

    // return possibility;
    answer_b = possibility;
}

int main(){
    pthread_t thread_a_id, thread_b_id;
    
    // printf("Hello world!\n");
    int qty;
    // printf("how many numbers? ");
    scanf("%d", &qty);
    int number_a, number_b, result_a, result_b;

    for(int i=1; i<=qty; i+=2){
        
        // printf("write the number: ");
        scanf("%d", &number_a);
        // cria thread
        pthread_create(&thread_a_id, NULL, &find_almost_crazy_prime_a, (void *)(intptr_t)number_a);
        
        if(i<qty){
            // scanf("%d", &number_b);
            scanf("%d", &number_b);
            // cria thread
            pthread_create(&thread_b_id, NULL, &find_almost_crazy_prime_b, (void *)(intptr_t)number_b);
            pthread_join(thread_b_id, NULL);
        }
        // espera thread
        pthread_join(thread_a_id, NULL);
        
        printf("%d\n", answer_a);
        if(i<qty)
            printf("%d\n", answer_b);
        
        // espera thread   

    }
    return 0;
}