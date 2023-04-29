#include <stdio.h>

void subSequences(int v[], int n);

int main() {
    int num;
    int i = 0;

    int matrix[30];
    do{
        printf("enter number, -1 to exit: \n");
        scanf("%d", &num);

        if(num != -1){
            matrix[i] = num;
            i++;
        }


    }while(num != -1 && i < 30);


    subSequences(matrix,i);

    return 0;
}

void subSequences(int matrix[], int n){
    int  index, max = -1;

    for(int j = 0; j< n; j++){
        if(matrix[j] != 0){
            if(matrix[j+1] == 0 || (j + 1 == n && matrix[j] != 0)){
                    if(index >= max){
                        max = index;
                    }
                    index = 0;
                }
            else{
                index++;
            }

            }
        }
    printf("%i", max);

    for(int j = 0; j< n; j++){
        if(matrix[j] != 0){
            if(matrix[j+1] == 0 || (j + 1 == n && matrix[j] != 0)){
                if(index == max){
                    for(int k = j-index; k <= j; k++){
                        printf("%i ", matrix[k]);
                    }index = 0;
                }

            }
            else{
                index++;
            }

        }
    }

    }

