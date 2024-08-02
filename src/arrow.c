/*
** EPITECH PROJECT, 2024
** arrow movment
** File description:
** RPG
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include <string.h>
#include <math.h>


void display_player_arrow_up_down(struct init_sprites_s *sprite,
    struct player_s *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) && player->is_inMoove == false) {
        sfRenderWindow_drawSprite(sprite->window,
        player->sprite_player_z, NULL);
        player->is_inMoove = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && player->is_inMoove == false) {
        sfRenderWindow_drawSprite(sprite->window,
        player->sprite_player_s, NULL);
        player->is_inMoove = true;
    }
}

void display_player_arrow_right_left(struct init_sprites_s *sprite,
    struct player_s *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && player->is_inMoove == false) {
        sfRenderWindow_drawSprite(sprite->window,
        player->sprite_player_q, NULL);
        player->is_inMoove = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && player->is_inMoove == false) {
        sfRenderWindow_drawSprite(sprite->window,
        player->sprite_player_d, NULL);
        player->is_inMoove = true;
    }
}
