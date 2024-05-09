#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
FILE * fptr;

void menu() {
    printf("1- Input Values \n");
    printf("2- Display Array \n");
    printf("3- Maximum Value \n");
    printf("4- Minimum Value \n");
    printf("5- Calculate Average \n");
    printf("6- Enter into file \n");
    printf("7- Read file \n");
    printf("8- Stop Program \n");
}

void  enterValue(int *array){
    printf("Enter values to array: \n");
    for (int i=0; i < SIZE; ++i) {
        printf("array[%d]: \n ", i);
        scanf("%d", &array[i]);
    }
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
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7 ,8, 9, 10};
    int choice = 0;
    int min = 0;
    int max = 0;
    float average = 0;
    while(choice != 8){
        menu();
        printf("Select program: \n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                enterValue(array);
                break;
            case 2:
                displayArray(array);
                break;
            case 3:
                max = maxValue(array);
                printf("Max = %d\n",max);
                break;
            case 4:
                min = minValue(array);
                printf("Min = %d\n",min);
                break;
            case 5:
                average = calcAverage(array);
                printf("Average = %f\n",average);
                break;
            case 6:
                fptr = fopen("letters.txt", "w+");
                if (fptr == 0)
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
            case 7:
                fptr = fopen("letters.txt", "r+");
                fseek(fptr, 0, SEEK_SET);
                printf("Oto zawartosc pliku:\n");
                for (int i = 0; i < SIZE; i++)
                {
                    array [i] = fgetc(fptr);
                    fseek(fptr, 0, SEEK_CUR);
                    printf("%d", array [i]);
                }
                printf("\n");
                fclose(fptr);
                break;
        }
    }
    return 0;
}
