/*
** EPITECH PROJECT, 2024
** map
** File description:
** foret
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

void animation(struct player_s *player)
{
    player->elapsed_time = sfClock_getElapsedTime(player->clock);
    player->elapsed_seconds = sfTime_asSeconds(player->elapsed_time);
    if (player->elapsed_seconds >= 0.3f) {
        player->rect.left += 77;
        if (player->rect.left >= 231) {
            player->rect.left = 0;
        }
        sfSprite_setTextureRect(player->sprite_player_s, player->rect);
        sfClock_restart(player->clock);
    }
}

void player_animation(struct player_s *player, struct init_sprites_s *sprite)
{
    sfIntRect playerRect = {0, 0, 77, 115};

    player->rect = playerRect;
    sfSprite_setTextureRect(player->sprite_player_s, player->rect);
}

void create_sprite_player(struct player_s *player,
    struct init_sprites_s *sprite)
{
    sfVector2u windowSize = sfRenderWindow_getSize(sprite->window);

    if (parsing_pos(player) != 0) {
        printf("Erreur lors de l'analyse du fichier.\n");
        return;
    }
    player->playerPosition.x = player->x_value;
    player->playerPosition.y = player->y_value;
    player->window_size = windowSize;
    player->clock = sfClock_create();
    player->texture_player_s =
        sfTexture_createFromFile("asset/yinx_map/player_s.png", NULL);
    player->sprite_player_s = sfSprite_create();
    sfSprite_setTexture(player->sprite_player_s,
        player->texture_player_s, sfTrue);
    sfSprite_setPosition(player->sprite_player_s,
        player->playerPosition);
}

void init_pos_after_tp(struct player_s *player, struct menu_s *menu)
{
    if (menu->game == 7 && !menu->position_initialized) {
        player->playerPosition.x = 500;
        player->playerPosition.y = 580;
        player->x_value = player->playerPosition.x;
        player->y_value = player->playerPosition.y;
        menu->position_initialized = true;
    }
    if (menu->game == 6 && !menu->position_initialized) {
        player->playerPosition.x = 1000;
        player->playerPosition.y = 580;
        player->x_value = 1000;
        player->y_value = 580;
        menu->position_initialized = true;
    } else {
        player->playerPosition.x = player->x_value;
        player->playerPosition.y = player->y_value;
    }
}

void move_player(struct player_s *player, struct menu_s *menu,
    struct init_sprites_s *sprite)
{
    float movementSpeed = 0.7f;
    float maxX = 4600;
    float maxY = 4000;

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

/*void move_player_in_donjon_one(struct player_s *player, struct menu_s *menu,
    struct init_sprites_s *sprite)
{
    float movementSpeed = 1.0f;
    float minX = 0;
    float minY = 0;
    float maxX = 4620;
    float maxY = 900;

    move_player_follow(player, menu);
    if (sfKeyboard_isKeyPressed(sfKeyZ) && player->y_value > 0) {
        player->y_value -= movementSpeed;
        if (check_collision(player->x_value, player->y_value))
            player->y_value += movementSpeed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && player->y_value < maxY) {
        player->y_value += movementSpeed;
        if (check_collision(player->x_value, player->y_value))
            player->y_value -= movementSpeed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && player->x_value > 0) {
        player->x_value -= movementSpeed;
        if (check_collision(player->x_value, player->y_value))
            player->x_value += movementSpeed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) && player->x_value < maxX) {
        player->x_value += movementSpeed;
        if (check_collision(player->x_value, player->y_value))
            player->x_value -= movementSpeed;
    }
    detect_object(player, sprite);
    sfSprite_setPosition(player->sprite_player_s, player->playerPosition);
    sfSprite_setPosition(player->sprite_player_q, player->playerPosition);
    sfSprite_setPosition(player->sprite_player_z, player->playerPosition);
    sfSprite_setPosition(player->sprite_player_d, player->playerPosition);
    sfSprite_setPosition(player->sprite_player_no, player->playerPosition);
}
*/
