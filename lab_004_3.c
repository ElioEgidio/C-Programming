#include <stdio.h>
// Sum not implemented yet as it is an easier task to accomplish, this code 
// is meant to show how to iterate in complex manner through matrices.
// For a better understanding also refer to ---> https://github.com/Aghavali9/PT-Polito/blob/main/Lab04/3/Lab04_3.c
int main() {

    int max_rows, max_col;
    int current_num;
    int sub_dim;

    FILE *fin;
    fin = fopen("input.txt", "r");

    if(fin == NULL){
        printf("file doesn't exist");
        return 1;
    }

    fscanf(fin,"%d %d", &max_rows, &max_col);
    int matrix[max_rows][max_col];



    for(int i = 1; i <= max_rows; i++){
        for(int j = 1; j <= max_col; j++){
            fscanf(fin, " %d", &current_num);
            matrix[i][j] = current_num;
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    do {
        printf("enter wanted sub matrix dimension: ");
        fscanf(stdin, " %i", &sub_dim);

        for(int mother_row = 1; mother_row <= max_rows - sub_dim + 1; mother_row++){
            for(int mother_col = 1; mother_col <= max_col - sub_dim + 1; mother_col++){
                for(int sub_row = mother_row; sub_row < sub_dim + mother_row ; sub_row++){
                    for(int sub_col = mother_col; sub_col < sub_dim + mother_col; sub_col++){
                        printf("%i", matrix[sub_row][sub_col]);
                    }printf("\n");
                }
                printf("\n");
            }
        }



    } while (sub_dim < max_rows && sub_dim < max_col);


    return 0;
}
