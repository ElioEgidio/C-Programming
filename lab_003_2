//WORK IN PROGRESS

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fin;
    fin = fopen("input.txt", "r"); // I will check validity of files later
    char current_char, previous_char1, previous_char2;

    int counter_brackets = 0;
    int space_between_digits = 0;

    while((current_char = fgetc(fin)) != EOF){

        if(current_char == '('){
            counter_brackets += 1;


        }
        if(current_char == ')'){
            counter_brackets += -1;

        }

        if(isspace(current_char)){
            if(isdigit(previous_char1) || isdigit(previous_char2)){
                space_between_digits = 1;
            }
        }
        if(current_char == '+' || current_char == '-'|| current_char == '*'||current_char ==  '/' ||current_char =='%'){
            space_between_digits += -1;
        }

        if(isdigit(current_char)){
            if(space_between_digits == 1){
                printf("invalid format");
                break;
            }
        }


        previous_char2 = previous_char1;
        previous_char1 = current_char;

    }
    if(counter_brackets == 0){
        printf("brackets ok");
    }
    return 0;
}
