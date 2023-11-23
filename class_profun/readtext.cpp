#include <stdio.h>
int main() {
    FILE *fptr;
    struct player 
    {
    char name[50];
    int level, score;
    };
    struct player players[5]; 
    fptr = fopen("RecordGameBi.txt", "r");
    for (int i = 0; i < 5; i++) {
        if (fread(&players[i], sizeof(struct player), 1, fptr) != 1) {
        break;
    }
        printf("Details for player %d:\n", i + 1);
        printf("Name: %s\n", players[i].name);
        printf("Level: %d\n", players[i].level);
        printf("Score: %d\n", players[i].score);
        printf("---------------------------------\n");
    }
    fclose(fptr);
    return 0;
}
