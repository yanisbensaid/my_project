/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** pnj_one
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>
#include <math.h>

void init_pnj(struct init_sprites_s *sprite)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_save = {3600, 1800};
    sfVector2f scale = {1.0, 1.0};
    sfVector2f scale_button = {0.5, 0.5};
    sfVector2f pos_button = {3600, 1650};

    texture->pnj_one_texture =
        sfTexture_createFromFile("asset/pnj_onel.png", NULL);
    sprite->pnj_one_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->pnj_one_sprite,
        texture->pnj_one_texture, sfTrue);
    sfSprite_setPosition(sprite->pnj_one_sprite, pos_save);
    sfSprite_setScale(sprite->pnj_one_sprite, scale);
    texture->press_e_texture =
        sfTexture_createFromFile("asset/press_e.png", NULL);
    sprite->press_e_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->press_e_sprite,
        texture->press_e_texture, sfTrue);
    sfSprite_setPosition(sprite->press_e_sprite, pos_button);
    sfSprite_setScale(sprite->press_e_sprite, scale_button);
}

float distance(sfVector2f pos1, sfVector2f pos2)
{
    return sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
}

void detect_player(struct player_s *player, struct init_sprites_s *sprite)
{
    sfVector2f press_e_pos = sfSprite_getPosition(sprite->press_e_sprite);
    float dist = distance(player->playerPosition, press_e_pos);

    if (dist <= 300.0f) {
        sprite->player_detected = true;
    } else {
        sprite->player_detected = false;
    }
}

void init_interact_pnj(struct init_sprites_s *sprite, struct player_s *player)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_save = {3200, 2000};
    sfVector2f scale = {0.5, 0.5};

    texture->interact_pnj_texture =
        sfTexture_createFromFile("asset/interact_pnj.png", NULL);
    sprite->interact_pnj_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->interact_pnj_sprite,
        texture->interact_pnj_texture, sfTrue);
    sfSprite_setPosition(sprite->interact_pnj_sprite, pos_save);
    sfSprite_setScale(sprite->interact_pnj_sprite, scale);
}
