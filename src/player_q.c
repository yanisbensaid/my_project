/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** player_q
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

void animation_q(struct player_s *player)
{
    player->elapsed_time_q = sfClock_getElapsedTime(player->clock_q);
    player->elapsed_seconds_q = sfTime_asSeconds(player->elapsed_time_q);
    if (player->elapsed_seconds_q >= 0.3f) {
        player->rect_q.left += 77;
        if (player->rect_q.left >= 231) {
            player->rect_q.left = 0;
        }
        sfSprite_setTextureRect(player->sprite_player_q, player->rect_q);
        sfClock_restart(player->clock_q);
    }
}

void player_animation_q(struct player_s *player, struct init_sprites_s *sprite)
{
    sfIntRect playerRect = {0, 0, 77, 115};

    player->rect_q = playerRect;
    sfSprite_setTextureRect(player->sprite_player_q, player->rect_q);
}

void create_sprite_player_q(struct player_s *player,
    struct init_sprites_s *sprite)
{
    sfVector2u windowSize = sfRenderWindow_getSize(sprite->window);
    sfVector2u mapSize = {800, 600};

    player->window_size = windowSize;
    player->clock_q = sfClock_create();
    player->texture_player_q =
        sfTexture_createFromFile("asset/yinx_map/player_q.png", NULL);
    player->sprite_player_q = sfSprite_create();
    sfSprite_setTexture(player->sprite_player_q,
        player->texture_player_q, sfTrue);
}
