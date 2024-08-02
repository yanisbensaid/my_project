/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** parsingpos
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>
#include <sys/types.h>


ssize_t read_next_line(FILE *file, char **line, size_t *len)
{
    return getline(line, len, file);
}

static void extract_x_value(char *line, struct player_s *player)
{
    char *token = strtok(line, ":");

    token = strtok(NULL, ":");
    if (token != NULL) {
        while (*token == ' ') {
            token++;
        }
        if (token[strlen(token) - 1] == '\n')
            token[strlen(token) - 1] = '\0';
        player->x_value = atoi(token);
    }
}

static void find_x_value(char *line, struct player_s *player)
{
    if (strstr(line, "position.x") != NULL) {
        extract_x_value(line, player);
    }
}

static void extract_y_value(char *line, struct player_s *player)
{
    char *token = strtok(line, ":");

    token = strtok(NULL, ":");
    if (token != NULL) {
        while (*token == ' ') {
            token++;
        }
        if (token[strlen(token) - 1] == '\n')
            token[strlen(token) - 1] = '\0';
        player->y_value = atoi(token);
    }
}

void find_position_y(char *line, struct player_s *player)
{
    if (strstr(line, "position.y") != NULL) {
            extract_y_value(line, player);
        }
}

void parsing_follow(FILE *file, struct player_s *player)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    nread = read_next_line(file, &line, &len);
    while (nread != -1) {
        if (nread == 0)
            continue;
        find_x_value(line, player);
        find_life_player(line, player);
        find_xp_player(line, player);
        find_position_y(line, player);
        find_life_barre(line, player);
        find_attack_player(line, player);
        find_state_boss_one(line, player);
        find_state_boss_two(line, player);
        nread = getline(&line, &len, file);
    }
    free(line);
}

int parsing_pos(struct player_s *player)
{
    FILE *file = fopen("src/info.txt", "r");

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }
    parsing_follow(file, player);
    fclose(file);
    return 0;
}
