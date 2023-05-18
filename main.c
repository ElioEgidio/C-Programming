#include <stdio.h>


typedef struct {
    int row, col, width, area;
    int max_height;
}max_height;

typedef struct {
    int row, col, height, area;
    int max_width;
}max_width;

typedef struct {
    int row, col, width, height, area;
    int max_area;
}max_area;


int main() {
    FILE *fin;
    int nr, nc, max_h = 0, max_w = 0, max_a = 0;
    int matrix[50][50] = {0};
    max_height square;
    max_width square1;
    max_area square2;

    fin = fopen("../matrix.txt", "r");
    fscanf(fin, "%d %d", &nr, &nc);

    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nc; ++j) {
            fscanf(fin, " %d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nc; ++j) {

            if(matrix[i][j] == 1){
                int width  = 0, height = 0;
                int k = i;
                int m = j;
                while(matrix[k][j] != 0){
                    height++;
                    k++;
                }
                while(matrix[i][m] != 0){
                    width++;
                    m++;
                }
                for (int l = i; l < i + height; ++l) {
                    for (int n = j; n < j + width; ++n) {
                        matrix[l][n]=0;
                    }
                }

                if(height > max_h){
                    max_h = height;
                    square.max_height = max_h;
                    square.col =i;
                    square.row =j;
                    square.width = width;
                    square.area = max_h * width;
                }
                if(width > max_w){
                    max_w = width;
                    square1.max_width = max_w;
                    square1.col =i;
                    square1.row =j;
                    square1.height = height;
                    square1.area = height * max_w;
                }
                if(height * width > max_a){
                    max_a = height * width;
                    square2.max_area = max_a;
                    square2.col =i;
                    square2.row =j;
                    square2.width = width;
                    square2.height = height;
                    square2.area = max_h * width;
                }




            }
        }
    }
    printf("MAX HEIGHT region: upper left corner = (%d, %d), height = %d, width = %d, area = %d \n",square.col ,square.row , square.max_height, square.width, ( square.max_height) *  (square.width));
    printf("MAX WIDTH region: upper left corner = (%d, %d), width = %d, height  = %d, area = %d \n",square1.col ,square1.row , square1.max_width, square1.height, ( square1.max_width) *  (square1.height));
    printf("MAX AREA region: upper left corner = (%d, %d), height = %d, width = %d, area = %d \n",square2.col ,square2.row , square2.height, square2.width,square2.max_area);

    return 0;
}
