/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** move_player_in_donjon
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

void move_player_in_donjon_one(struct player_s *player, struct menu_s *menu,
    struct init_sprites_s *sprite)
{
    float movementSpeed = 1.3f;
    float maxX = 4620;
    float maxY = 900;

    init_pos_after_tp(player, menu);
    if (sfKeyboard_isKeyPressed(sfKeyZ) && player->y_value > 0)
        player->y_value -= movementSpeed;
    if (sfKeyboard_isKeyPressed(sfKeyS) && player->y_value < maxY)
        player->y_value += movementSpeed;
    if (sfKeyboard_isKeyPressed(sfKeyQ) && player->x_value > 0)
        player->x_value -= movementSpeed;
    if (sfKeyboard_isKeyPressed(sfKeyD) && player->x_value < maxX)
        player->x_value += movementSpeed;
    detect_object(player, sprite);
    sfSprite_setPosition(player->sprite_player_s, player->playerPosition);
    sfSprite_setPosition(player->sprite_player_q, player->playerPosition);
    sfSprite_setPosition(player->sprite_player_z, player->playerPosition);
    sfSprite_setPosition(player->sprite_player_d, player->playerPosition);
    sfSprite_setPosition(player->sprite_player_no, player->playerPosition);
}

void display_player_donjon_one(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu)
{
    player->is_inMoove = false;
    move_player_in_donjon_one(player, menu, sprite);
    display_player_z(sprite, player);
    display_player_q(sprite, player);
    display_player_s(sprite, player);
    display_player_d(sprite, player);
}
