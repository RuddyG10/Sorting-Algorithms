#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionSort(int ar[],int n);

void insertionSort(int ar[], int size);

void bubbleSort(int ar[], int size);

void randomArray(int array[], int n, int max);

int main(){
    int *array;
    srand(time(NULL));
    //time counters start and end
    clock_t start , end;

    //computer time used
    double timeUsed;

    //array size
    
    int sz = 100000;
    
    array = (int *) malloc(sz * sizeof(int));
    
    randomArray(array,sz,1000);
    printf("ARREGLO DESORDENADO\n\n");
    
    printf("\n");
    printf("pause");
    printf("cls");
    printf("\n");
    //selectionSort(ar,n);
    //insertionSort(ar,n);

    //Test with bubble
    start = clock();
    bubbleSort(array,sz);
    end = clock();
    timeUsed = ((double)(end - start))/ CLOCKS_PER_SEC;
    printf("ARREGLO ORDENADO\n\n");
    printf("Tiempo de bubbleSort con 100mil elementos: %f\n",timeUsed);
    //clear cache
    fflush(stdin);
    //Test with insertion
    
    randomArray(array,sz,1000);
    start = clock();
    insertionSort(array,sz);
    end = clock();
    timeUsed = ((double)(end - start))/ CLOCKS_PER_SEC;
    printf("Tiempo de insertionSort con 100mil elementos: %f\n",timeUsed);
    //clear cache
    fflush(stdin);
    //Test with selection
    randomArray(array,sz,1000);
    start = clock();
    selectionSort(array,sz);
    end = clock();
    timeUsed = ((double)(end - start))/ CLOCKS_PER_SEC;
    printf("Tiempo de SelectionSort con 100mil elementos: %f\n",timeUsed);
    //clear cache
    fflush(stdin);

    return 0;
}

void selectionSort(int *ar,int n){
    int helper = 0;
    //array iteration
    for  (int i = 0; i < n-1; i++)
    {
        //set the min value
        int minIndex = i;
        int minValue = ar[i];

        //check next min
        for (int j = i+1; j < n; j++)
        {
            //checking if the value j is less than min value
            if (ar[j] < minValue)
            {
                //set new min value and min index
                minIndex = j;
                minValue = ar[j];
            }
            
        }
        //exchange elements
        helper = ar[i];
        ar[i] = ar[minIndex];
        ar[minIndex] = helper;

    }
    
}

void insertionSort(int *ar,int size){
    if(ar == NULL || size == 0){
        return;
    }
    int helper = 0;
    // sort the array
    for (int i = 0; i < size; i++)
    {
        //get the curret value
        int val = ar[i];
        //iterate backwards to find position
        int j = i;
        while (j>0)
        {
           if (val < ar[j-1])
           {
            //exchange
            helper = ar[j-1];
            ar[j-1] = ar[j];
            ar[j] = helper;

            //decrement
            j--;
           }
           else{
            //correct the position
            break;
           }
            
        }
        
    }
    
}
void bubbleSort(int *ar,int size){

    if(ar == NULL || size == 0)
    {
        return;
    }
    int helper = 0;
    for (int i = size - 1; i > 0; i--)
    {
        //exchange flag
        int exchange = 0;
        //iterate inner loop
        for (int j = 0; j < i; j++)
        {
            //check contiguos
            if (ar[j]>ar[j+1])
            {
                //exchange
                helper = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = helper;
                exchange = 1;
            }
            
        }
        //chack no exchange
        if (exchange == 0)
        {
            break;
        }
        
        
    }
    
}

//Random array
void randomArray(int *ar,int n, int max ){

    if(ar == NULL || n == 0){
        return;
    }
    for (int i = 0; i < n; i++)
    {
        ar[i] = (rand() % max) + 1;
    }
    

}