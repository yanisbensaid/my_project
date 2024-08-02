/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** parsing_three
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

static void extract_state_boss_two(char *line, struct player_s *player)
{
    char *token = strtok(line, ":");

        token = strtok(NULL, ":");
        if (token != NULL) {
            while (*token == ' ') {
                token++;
            }
            player->state_boss_two = atof(token);
        }
}

void find_state_boss_two(char *line, struct player_s *player)
{
    if (strstr(line, "state_second_boss") != NULL) {
        extract_state_boss_two(line, player);
    }
}
