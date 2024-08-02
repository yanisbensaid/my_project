/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** player_z
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

void animation_z(struct player_s *player)
{
    player->elapsed_time_z = sfClock_getElapsedTime(player->clock_z);
    player->elapsed_seconds_z = sfTime_asSeconds(player->elapsed_time_z);
    if (player->elapsed_seconds_z >= 0.3f) {
        player->rect_z.left += 77;
        if (player->rect_z.left >= 231) {
            player->rect_z.left = 0;
        }
        sfSprite_setTextureRect(player->sprite_player_z, player->rect_z);
        sfClock_restart(player->clock_z);
    }
}

void player_animation_z(struct player_s *player, struct init_sprites_s *sprite)
{
    sfIntRect playerRect = {0, 0, 77, 115};

    player->rect_z = playerRect;
    sfSprite_setTextureRect(player->sprite_player_z, player->rect_z);
}

void create_sprite_player_z(struct player_s *player,
    struct init_sprites_s *sprite)
{
    sfVector2u windowSize = sfRenderWindow_getSize(sprite->window);

    player->window_size = windowSize;
    player->clock_z = sfClock_create();
    player->texture_player_z =
        sfTexture_createFromFile("asset/yinx_map/player_z.png", NULL);
    player->sprite_player_z = sfSprite_create();
    sfSprite_setTexture(player->sprite_player_z,
        player->texture_player_z, sfTrue);
}
