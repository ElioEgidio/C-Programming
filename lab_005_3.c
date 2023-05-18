// main idea is correct, works only for left or right but code is modular and a couple morefors would also do up and down, in particular
// my code would treat up as left and down as right, I just change the printing method. Doing all of this would require time and i just wnated to understand the main idea:


#include <stdio.h>
#include <string.h>

void def(int matrix[30][30], int nr, int nc, char selector[], int index, char direction[], int location, int mat[]);

int main() {
    FILE *fn;
    int matrix[30][30] = {0}, nr, nc;
    int  mat[30] = {0};

    int index, location,end;
    char selector[50], direction[50];

    fn = fopen("../text.txt", "r");
    fscanf(fn, "%d %d",&nr,&nc );

    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nc; ++j) {
            fscanf(fn, "%d", &matrix[i][j]);
        }
    }

    do{
        printf("input row/col, index, direction, location, 1 continue -1 for exit: \n");
        scanf( "%s %d %s %d %d", selector, &index, direction, &location, &end );

        if(strcmp(selector, "row") == 0){
            for (int i = 0; i < nc; ++i) {
                mat[i] = matrix[index-1][i];
            }
        }
        def(matrix, nr, nc, selector, index, direction, location, mat);
    }while(end != -1);


    return 0;
}

void def(int matrix[30][30],int nr, int nc, char selector[], int index, char direction[], int location, int mat[]){
    int m_matrix[nc];
    if(strcmp(direction, "right") == 0){
        for(int i = 0; i < nc; i++){
            if(i + location >= nc){
                int num = i + location - nc;
                m_matrix[num] = mat[i];
            }else{
                m_matrix[i + location] = mat[i];
            }


        }
    }else{
        for(int i = 0; i < nc; i++){
            if(i - location < 0){
                int num = i - location + nc;
                m_matrix[num] = mat[i];
            }else{
                m_matrix[i - location] = mat[i];
            }

        }

    }
    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nc; ++j) {
            if(i == index-1){
                printf("%d ", m_matrix[j]);}
            else{
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }

}
