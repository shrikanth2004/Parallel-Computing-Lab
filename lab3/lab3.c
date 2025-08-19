#include<stdio.h>
#include<omp.h>

int f(int n){
    int i,j;
    if(n<2){
        return n;
    }
    
    else{
        #pragma omp task shared(i) firstprivate(n)
        i=f(n-1);
        #pragma omp task shared(j) firstprivate(n)
        j=f(n-2);
         #pragma omp taskwait 

        return i+j;
    }
}


int main(){
    int n;
    printf("\n enter the number to calculate fibonacci=");
    scanf("%d",&n);
    omp_set_dynamic(0);
    omp_set_num_threads(4);
    #pragma omp parallel shared(n)
    {
        #pragma omp single
        printf("fib(%d)=%d\n",n,f(n));
    }
    return 0;
}