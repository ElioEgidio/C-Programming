#include <stdio.h>
#include <string.h>

typedef struct {
    char code[10];
    char word[10];
}dict;

int main() {
    FILE *fin, *f_2in;
    int max_r;
    dict dictionary[30];
    char word[50];

    // START READING OF DICTIONARY
    fin = fopen("../dictionary.txt","r");
    fscanf(fin, "%d", &max_r);

    for (int i = 0; i < max_r; ++i) {
        dict temp;
        fscanf(fin, "%s %s",temp.code,temp.word);
        dictionary[i] = temp;
    }
    // END READING OF DICTIONARY

    // START READING OF TEXT
    f_2in = fopen("../text.txt","r");
    while(fscanf(f_2in, "%s", word) == 1){
        int j = strlen(word);
        char *pointer;
        for (int i = 0; i < max_r; ++i) {
            char *position = strstr(word, dictionary[i].word);
            if (position != NULL) {
                strncpy(position, dictionary[i].code, strlen(dictionary[i].code) +1);
            }
        }
        printf("%s ", word);
    }
    // END READING OF TXT


    return 0;
}
