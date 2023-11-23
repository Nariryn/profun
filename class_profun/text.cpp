#include <stdio.h>

int main() {
    FILE *fptr;
    struct player {
    char name[50];
    int level, score;
    };
    struct player players[5];
    fptr = fopen("StRecordGame.txt", "w");
    for (int i = 0; i < 5; i++) {
        printf("Enter details for player %d:\n", i + 1);
        
        printf("Name: "); scanf("%s", players[i].name);
        printf("Level: "); scanf("%d", &players[i].level);
        printf("Score: "); scanf("%d", &players[i].score);

        fprintf(fptr, "Player Name: %s\n", players[i].name);
        fprintf(fptr, "Player Level: %d\n", players[i].level);
        fprintf(fptr, "Player Score: %d\n", players[i].score);
        fprintf(fptr, "---------------------------------\n");
    }
    fclose(fptr);
    return 0;
}
