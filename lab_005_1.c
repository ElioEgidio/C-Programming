#include <stdio.h>

void findLeader(int matrix[19][19], int max_r, int max_c);

int main() {

    FILE *fin;
    int max_r, max_c;
    int matrix[19][19];

    fin = fopen("../text.txt", "r");

    fscanf( fin,"%i %i", &max_r, &max_c );
    for(int i = 0; i < max_r; i++){
        for(int j =0; j < max_c; j++){
            fscanf(fin, "%i", &matrix[i][j]);
            printf("%i  ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    findLeader(matrix, max_r, max_c);

    return 0;
}

void findLeader(int matrix[19][19],  int max_r, int max_c){
    int teams[6] = {0};
    int value;

    for(int column = 0; column < max_c; column++){
        int max = 0;
        for(int row = 0; row < max_r; row++){
            value = matrix[row][column];
            teams[row] = teams[row] + value;
        }
        printf("POINTS DAY %i: \n\n" , column);

        for(int i = 0; i<max_r;i++){
            if(teams[i] >= max){
                max = teams[i];

            }

            printf("TEAM %i: %i \n",i+1, teams[i]);
        }
        for(int index = 0; index < max_r; index++){
            if(teams[index] == max){
                printf(" the leading team is TEAM: %i\n", index+1);
                break;
            }
        }

    }

}
