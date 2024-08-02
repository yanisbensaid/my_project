/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** player_d
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>
void animation_d(struct player_s *player)
{
    player->elapsed_time_d = sfClock_getElapsedTime(player->clock_d);
    player->elapsed_seconds_d = sfTime_asSeconds(player->elapsed_time_d);
    if (player->elapsed_seconds_d >= 0.3f) {
        player->rect_d.left += 77;
        if (player->rect_d.left >= 231) {
            player->rect_d.left = 0;
        }
        sfSprite_setTextureRect(player->sprite_player_d, player->rect_d);
        sfClock_restart(player->clock_d);
    }
}

void player_animation_d(struct player_s *player, struct init_sprites_s *sprite)
{
    sfIntRect playerRect = {0, 0, 77, 115};

    player->rect_d = playerRect;
    sfSprite_setTextureRect(player->sprite_player_d, player->rect_d);
}

void create_sprite_player_d(struct player_s *player,
    struct init_sprites_s *sprite)
{
    sfVector2u windowSize = sfRenderWindow_getSize(sprite->window);
    sfVector2u mapSize = {800, 600};

    player->window_size = windowSize;
    player->clock_d = sfClock_create();
    player->texture_player_d =
        sfTexture_createFromFile("asset/yinx_map/player_d.png", NULL);
    player->sprite_player_d = sfSprite_create();
    sfSprite_setTexture(player->sprite_player_d,
        player->texture_player_d, sfTrue);
}

void create_sprite_player_no_moove(struct player_s *player,
    struct init_sprites_s *sprite)
{
    player->texture_player_no =
        sfTexture_createFromFile("asset/yinx_map/player_no_moove.png", NULL);
    player->sprite_player_no = sfSprite_create();
    sfSprite_setTexture(player->sprite_player_no,
        player->texture_player_no, sfTrue);
}
