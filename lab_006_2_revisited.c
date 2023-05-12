#include <stdio.h>
#include <ctype.h>
#include <string.h>

void reset_matrix(char matrix[26]);

int main() {
    FILE *f_text, *f_seq;
    char sequence[6];
    char word[26] = "\0";
    char c;
    int size;
    int c_ind;

    f_seq = fopen("../sequences.txt", "r");
    f_text = fopen("../text.txt", "r");


    fscanf(f_seq, "%d", &size);
    for(int i = 0; i < size; i++){
        int index=1, index_found=0;
        fscanf(f_seq, "%s", sequence);
        while(fscanf(f_text, "%c", &c) == 1 && index_found < 20){
            if(isspace(c) || ispunct(c)){
                for (int j = 0; word[j]; j++) {
                    word[j] = tolower(word[j]);
                }
                if (strstr(word, sequence) != NULL) {
                    printf("%s %d\n", word, index);
                    index_found++;
                }
                reset_matrix(word);
                c_ind = 0;
                index++;
            }
            else{
                word[c_ind] = c;
                c_ind++;
            }

        }rewind(f_text);
    }
    return 0;
}
void reset_matrix(char word[]){
    for (int j = 0; word[j]; j++) {
        strcpy(&word[j], "\0");
    }
}
