/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** parsing_follow
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

static void extract_state_boss_one(char *line, struct player_s *player)
{
    char *token = strtok(line, ":");

        token = strtok(NULL, ":");
        if (token != NULL) {
            while (*token == ' ') {
                token++;
            }
            player->state_boss_one = atof(token);
        }
}

void find_state_boss_one(char *line, struct player_s *player)
{
    if (strstr(line, "state_first_boss") != NULL) {
        extract_state_boss_one(line, player);
    }
}

static void extract_attack_player(char *line, struct player_s *player)
{
    char *token = strtok(line, ":");

        token = strtok(NULL, ":");
        if (token != NULL) {
            while (*token == ' ') {
                token++;
            }
            player->attack_player = atof(token);
        }
}

void find_attack_player(char *line, struct player_s *player)
{
    if (strstr(line, "attack_player") != NULL) {
        extract_attack_player(line, player);
    }
}

static void extract_xp_player(char *line, struct player_s *player)
{
    char *token = strtok(line, ":");

        token = strtok(NULL, ":");
        if (token != NULL) {
            while (*token == ' ') {
                token++;
            }
            player->xp_player = atof(token);
        }
}

void find_xp_player(char *line, struct player_s *player)
{
    if (strstr(line, "xp_player") != NULL) {
        extract_xp_player(line, player);
    }
}

static void extract_life_player(char *line, struct player_s *player)
{
    char *token = strtok(line, ":");

        token = strtok(NULL, ":");
        if (token != NULL) {
            while (*token == ' ') {
                token++;
            }
            player->life_player = atof(token);
        }
}

void find_life_player(char *line, struct player_s *player)
{
    if (strstr(line, "life_player") != NULL) {
        extract_life_player(line, player);
    }
}

static void extract_life_barre(char *line, struct player_s *player)
{
    char *token = strtok(line, ":");

        token = strtok(NULL, ":");
        if (token != NULL) {
            while (*token == ' ') {
                token++;
            }
            player->value_life_barre = atof(token);
        }
}

void find_life_barre(char *line, struct player_s *player)
{
    if (strstr(line, "value_life_barre") != NULL) {
        extract_life_barre(line, player);
    }
}
