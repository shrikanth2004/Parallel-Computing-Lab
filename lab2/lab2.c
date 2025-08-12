#include<stdio.h>
#include<omp.h>
int main(){
    int num;
    printf("\nenter iteration=");
    scanf("%d",&num);
    #pragma omp parallel
    {
        #pragma omp for schedule(static,2)
        for(int i=0;i<num;i++){
            printf("thread  %d: iteration %d \n",omp_get_thread_num(),i);

        }
    }
    return 0;
    }