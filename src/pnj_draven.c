/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** pnj_draven
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

void init_draven(struct init_sprites_s *sprite)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_save = {4450, 1250};
    sfVector2f scale = {1.0, 1.0};
    sfVector2f scale_button = {0.5, 0.5};
    sfVector2f pos_button = {4430, 1100};

    texture->draven_texture =
        sfTexture_createFromFile("asset/Dravenn.png", NULL);
    sprite->draven_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->draven_sprite,
        texture->draven_texture, sfTrue);
    sfSprite_setPosition(sprite->draven_sprite, pos_save);
    sfSprite_setScale(sprite->draven_sprite, scale);
    texture->press_e_draven =
        sfTexture_createFromFile("asset/press_e.png", NULL);
    sprite->press_e_draven_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->press_e_draven_sprite,
        texture->press_e_draven, sfTrue);
    sfSprite_setPosition(sprite->press_e_draven_sprite, pos_button);
    sfSprite_setScale(sprite->press_e_draven_sprite, scale_button);
}

float distance_drav(sfVector2f pos1, sfVector2f pos2)
{
    return sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
}

void detect_draven(struct player_s *player, struct init_sprites_s *sprite)
{
    sfVector2f press_e_pos =
        sfSprite_getPosition(sprite->press_e_draven_sprite);
    float dist = distance_drav(player->playerPosition, press_e_pos);

    if (dist <= 300.0f) {
        sprite->draven_detected = true;
    } else {
        sprite->draven_detected = false;
    }
}

void init_interact_draven(struct init_sprites_s *sprite,
    struct player_s *player)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_save = {4370, 1350};
    sfVector2f scale = {0.4, 0.4};

    texture->interact_draven_text =
        sfTexture_createFromFile("asset/interact_draven.jpg", NULL);
    sprite->interact_draven_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->interact_draven_sprite,
        texture->interact_draven_text, sfTrue);
    sfSprite_setPosition(sprite->interact_draven_sprite, pos_save);
    sfSprite_setScale(sprite->interact_draven_sprite, scale);
    texture->interact_draven_two_text =
        sfTexture_createFromFile("asset/interact_draven_two.jpg", NULL);
    sprite->interact_draven_two_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->interact_draven_two_sprite,
        texture->interact_draven_two_text, sfTrue);
    sfSprite_setPosition(sprite->interact_draven_two_sprite, pos_save);
    sfSprite_setScale(sprite->interact_draven_two_sprite, scale);
}
