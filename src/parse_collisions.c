/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** parse_collisions
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

/*int wall_data[800][800];

void extract_wall_values(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    char line[4096];
    int inside_wall_data = 0;
    int row = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "<layer") && strstr(line, "name=\"wall\"")) {
            inside_wall_data = 1;
            continue;
        }
        if (inside_wall_data) {
            if (strstr(line, "<data encoding=\"csv\">")) {
                continue;
            }
            if (strstr(line, "</data>")) {
                inside_wall_data = 0;
                break;
            }
            char *token = strtok(line, ",");
            int col = 0;
            while (token != NULL) {
                wall_data[row][col] = atoi(token);
                token = strtok(NULL, ",");
                col++;
            }
            row++;
        }
    }

    fclose(file);
}

int check_collision(float x, float y) {
    int col = (int)(x / 50);
    int row = (int)(y / 50);
    if (wall_data[row][col] != 0) {
        printf("COLLISIONS\n");
        return 1;
    }
    return 0;
}*/
