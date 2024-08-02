/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** pnj_villageois
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

void init_pnj_two(struct init_sprites_s *sprite)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_save = {3000, 3000};
    sfVector2f scale = {1.0, 1.0};
    sfVector2f scale_button = {0.5, 0.5};
    sfVector2f pos_button = {3000, 2850};

    texture->pnj_two_texture =
        sfTexture_createFromFile("asset/pnj_villageoiss.png", NULL);
    sprite->pnj_two_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->pnj_two_sprite,
        texture->pnj_two_texture, sfTrue);
    sfSprite_setPosition(sprite->pnj_two_sprite, pos_save);
    sfSprite_setScale(sprite->pnj_two_sprite, scale);
    texture->press_e_pnj_two =
        sfTexture_createFromFile("asset/press_e.png", NULL);
    sprite->press_e_pnj_two = sfSprite_create();
    sfSprite_setTexture(sprite->press_e_pnj_two,
        texture->press_e_pnj_two, sfTrue);
    sfSprite_setPosition(sprite->press_e_pnj_two, pos_button);
    sfSprite_setScale(sprite->press_e_pnj_two, scale_button);
}

float distance_eloi(sfVector2f pos1, sfVector2f pos2)
{
    return sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
}

void detect_pnj(struct player_s *player, struct init_sprites_s *sprite)
{
    sfVector2f press_e_pos = sfSprite_getPosition(sprite->press_e_pnj_two);
    float dist = distance_eloi(player->playerPosition, press_e_pos);

    if (dist <= 300.0f) {
        sprite->eloi_detected = true;
    } else {
        sprite->eloi_detected = false;
    }
}

void init_interact_pnj_two(struct init_sprites_s *sprite,
    struct player_s *player)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_save = {2800, 3200};
    sfVector2f scale = {0.5, 0.5};

    texture->interact_eloi_texture =
        sfTexture_createFromFile("asset/interact_eloi.png", NULL);
    sprite->interact_eloi_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->interact_eloi_sprite,
        texture->interact_eloi_texture, sfTrue);
    sfSprite_setPosition(sprite->interact_eloi_sprite, pos_save);
    sfSprite_setScale(sprite->interact_eloi_sprite, scale);
}
