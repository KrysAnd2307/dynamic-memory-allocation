#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
FILE * fptr;

void menu() {
    printf("1- Input Values \n");
    printf("2- Delete Value \n");
    printf("3- Display Array \n");
    printf("4- Maximum Value \n");
    printf("5- Minimum Value \n");
    printf("6- Calculate Average \n");
    printf("7- Enter into file \n");
    printf("8- Read file \n");
    printf("9- End Program \n");
}

void  enterValue(int *array){
    printf("Enter values to array: \n");
    for (int i=0; i < SIZE; ++i) {
        printf("array[%d]: \n ", i);
        scanf("%d", &array[i]);
    }
}

void deleteValue(int *array, int value){
    for( int i = 0; i < SIZE -1; ++i){
        if( array[i] == value ){
            for( int j = 0; j < SIZE - 1; ++j){
                array[j] = array[j+1];
            }
            array[SIZE - 1] = 0;
            printf("Deleted %d value. \n", value);
        }
    }
    printf("Value %d not found\n", value);
}

void displayArray(int array[]) {
    for (int i=0; i < SIZE; ++i) {
        printf("array[%d] = %d \n", i, array[i]);
    }
}

int maxValue(int array[]) {
    int max = array[0];
    for (int i = 0; i < SIZE; ++i )
    {
        if(array[i] > max) max = array[i];
    }
    return max;
}

int minValue(int array[]) {
    int min = array[0];
    for (int i = 0; i < SIZE; ++i )
    {
        if(array[i] < min) min = array[i];
    }
    return min;
}

float calcAverage(int array[]){
    int sum = 0;
    for (int i = 0; i < SIZE; ++i ) {
        sum = sum + array[i];
    }
    float avg = (float)sum / SIZE;
    return avg;
}

void displayReslts(int min, int max, float array[]);

int main() {
    int *array = (int*)malloc(SIZE * sizeof(int));
    if( array == NULL ){
        printf("Memory allocation failed!!\n");
    }
    int choice = 0;
    int min = 0;
    int max = 0;
    float average = 0;
    int value = 0;
    while(choice != 9){
        menu();
        printf("Select program: \n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                enterValue(array);
                break;
            case 2:
                printf("Enter the value: \n");
                scanf("%d", &value);
                deleteValue(array, value);
                break;
            case 3:
                displayArray(array);
                break;
            case 4:
                max = maxValue(array);
                printf("Max = %d\n",max);
                break;
            case 5:
                min = minValue(array);
                printf("Min = %d\n",min);
                break;
            case 6:
                average = calcAverage(array);
                printf("Average = %f\n",average);
                break;
            case 7:
                fptr = fopen("letters.txt", "w+");
                if (fptr == NULL)
                {
                    exit(1);
                }
                for (int u = 0; u < SIZE ; ++u)
                {
                    fputc(array[u], fptr);
                }

                fclose(fptr);

                puts("Array Saved");
                break;
            case 8:
                fptr = fopen("letters.txt", "r+");
                if (fptr == NULL){
                    exit(1);
                }
                fseek(fptr, 0, SEEK_SET);
                printf("File content: \n");
                for (int i = 0; i < SIZE; i++)
                {
                    array[i] = fgetc(fptr);
                    fseek(fptr, 0, SEEK_CUR);
                    printf("%d", array[i]);
                }
                printf("\n");
                fclose(fptr);
                break;
        }
    }
    free(array);
    return 0;
}
