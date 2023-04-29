#include <stdio.h>
#define maxN 30

void rotate(int v[maxN], int n, int p, int dir);

int main() {
    int size, matrix[maxN], num, i = 0, p, dir;
    printf("enter array size: ");
    scanf("%i", &size);

    do{
        printf("enter array value, -1 to terminate: ");
        scanf("%i", &num);
        if(num != 0){
          matrix[i]  = num;
          i++;
        }

    }while(num != -1 && i < size);

    do{
        printf("enter shift value and direction (1 R, -1 L): ");
        scanf("%i %i", &p, &dir);
        if(p != 0){
            rotate(matrix, size, p, dir);
        }
    }while(p!=0);
    return 0;
}
void rotate(int matrix[], int size, int p, int dir){
    int m_matrix[size];
    if(dir == 1){
            for(int i = 0; i < size; i++){
                if(i + p >= size){
                    int num = i + p -size;
                    m_matrix[num] = matrix[i];
                }else{
                    m_matrix[i + p] = matrix[i];
                }

            }
    }else{
        for(int i = 0; i < size; i++){
            if(i - p < 0){
                int num = i - p + size;
                m_matrix[num] = matrix[i];
            }else{
                m_matrix[i - p] = matrix[i];
            }

        }
    }

    for(int val = 0; val < size; val++){
        printf("%i ", m_matrix[val]);
    }
}
