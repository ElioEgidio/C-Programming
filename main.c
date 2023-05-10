#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char route_code[30];
    char departure[30];
    char destination[30];
    char date[50];
    char time_departure[50];
    char time_arrival[50];
    int delay;

}trips;

void menu(trips totTrips[], int num_lines);
void printing();
void rides_time_interval(char in_date[50], char en_date[50], trips totTrips[], int num_lines);
void same_departure(trips totTrips[], int num_lines, char departure[]);
void same_destination(trips totTrips[], int num_lines, char destination[]);
void rides_late_within_date(trips totTrips[], int num_lines, char in_date[50], char en_date[50]);
void delay_by_route(trips totTrips[], int num_lines, char route_code[]);

void rides_time_interval(char in_date[50], char en_date[50], trips totTrips[], int num_lines){
    for(int i = 0; i < num_lines; i++){
        int a = strcmp(totTrips[i].time_departure, in_date);
        int b = strcmp(totTrips[i].time_arrival, en_date);
        if(strcmp(totTrips[i].date, in_date) > 0 &&  strcmp(totTrips[i].date, en_date) < 0){
            printf("-> %s %s %s\n", totTrips[i].route_code, totTrips[i].departure, totTrips[i].destination);
        }
    }

}

void same_departure(trips totTrips[], int num_lines, char departure[]){
    for(int i = 0; i < num_lines; i++){
        if(strcmp(totTrips[i].departure, departure) == 0){
            printf("-> %s %s %s\n", totTrips[i].route_code, totTrips[i].departure, totTrips[i].destination);
        }
    }
}

void same_destination(trips totTrips[], int num_lines, char destination[]){
    for(int i = 0; i < num_lines; i++){
        if(strcmp(totTrips[i].destination, destination) == 0){
            printf("-> %s %s %s\n", totTrips[i].route_code, totTrips[i].departure, totTrips[i].destination);
        }
    }
}

void rides_late_within_date( trips totTrips[], int num_lines, char in_date[50], char en_date[50]){
    for(int i = 0; i < num_lines; i++){
        if(strcmp(totTrips[i].date, in_date) > 0 &&  strcmp(totTrips[i].date, en_date) < 0){
            if(totTrips[i].delay != 0){
                printf("-> %s %s %s\n", totTrips[i].route_code, totTrips[i].departure, totTrips[i].destination);
            }

        }
    }

}

void delay_by_route(trips totTrips[], int num_lines, char route_code[]){
    int tot_delay;
    for(int i = 0; i < num_lines; i++){
        if(strcmp(totTrips[i].route_code, route_code)==0){
            tot_delay += totTrips[i].delay;
        }
    }printf("-> %d: delay by route code: %s\n", tot_delay, route_code);
}


void printing(){
    printf("enter choiche:\n"
           "   1) list all rides departed within a certain interval of dates\n"
           "   2) list all the trips starting from a given departure\n"
           "   3) list all the trips with a given destination\n"
           "   4) list all trips that reached their destination late, within a given interval of dates\n"
           "   5) list the overall delay accumulated by the trips that are identified by a given route code\n"
           "   6) terminate the program\n");
}

void menu(trips totTrips[], int numLines){
    int choice = 0;
    printing();
    scanf("%d", &choice);
    while(choice != 6){
        if(choice == 1){
            char in_date[50];
            char en_date[50];

            printf("insert date interval: ");
            scanf("%s", in_date);
            scanf("%s", en_date);
            rides_time_interval(in_date, en_date, totTrips, numLines);
        }
        if(choice == 2){
            char departure[50];

            printf("insert departure: ");
            scanf("%s", departure);
            same_departure( totTrips, numLines, departure);
        }
        if(choice == 3){
            char destination[50];

            printf("insert destination: ");
            scanf("%s", destination);
            same_destination( totTrips, numLines, destination);
        }if(choice == 4){
            char in_date[50];
            char en_date[50];

            printf("insert date interval: ");
            scanf("%s", in_date);
            scanf("%s", en_date);
            rides_late_within_date( totTrips, numLines, in_date, en_date);
        }
        if(choice == 5){
            char route_code[50];

            printf("insert route code: ");
            scanf("%s", &route_code);
            delay_by_route( totTrips, numLines, route_code);
        }

        printing();
        scanf("%d", &choice);
    }
}



int main() {
    FILE *fin;
    int num_lines;
    trips tot_trips[1000];
    fin = fopen("../log.txt", "r");
    fscanf(fin, "%d", &num_lines);
    for(int i = 0; i < num_lines; i++){
        trips temp;
        fscanf(fin, "%s %s %s", temp.route_code, temp.departure,temp.destination);
        fscanf(fin, "%s", temp.date);
        fscanf(fin, "%s", temp.time_departure);
        fscanf(fin, "%s", temp.time_arrival);
        fscanf(fin, "%d", &temp.delay);

        tot_trips[i] = temp;
    }
    menu(tot_trips, num_lines);
    fclose(fin);
    return 0;
}
