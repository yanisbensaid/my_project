/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** win_the_first_room
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

void init_interact_key(struct init_sprites_s *sprite,
    struct player_s *player)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_save = {600, 300};
    sfVector2f scale = {0.2, 0.2};
    sfVector2f scale_button = {0.5, 0.5};
    sfVector2f pos_button = {600, 250};

    texture->key_texture =
        sfTexture_createFromFile("asset/key.png", NULL);
    sprite->key_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->key_sprite,
        texture->key_texture, sfTrue);
    sfSprite_setPosition(sprite->key_sprite, pos_save);
    sfSprite_setScale(sprite->key_sprite, scale);
    texture->press_e_key =
        sfTexture_createFromFile("asset/press_e.png", NULL);
    sprite->press_e_key_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->press_e_key_sprite,
        texture->press_e_key, sfTrue);
    sfSprite_setPosition(sprite->press_e_key_sprite, pos_button);
    sfSprite_setScale(sprite->press_e_key_sprite, scale_button);
}

static float distance_key(sfVector2f pos1, sfVector2f pos2)
{
    return sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
}

void detect_key(struct player_s *player, struct init_sprites_s *sprite)
{
    sfVector2f sword_pos = sfSprite_getPosition(sprite->key_sprite);
    float dist = distance_key(player->playerPosition, sword_pos);

    if (dist <= 300.0f) {
        sprite->key_detected = true;
    } else {
        sprite->key_detected = false;
    }
}

void init_shield(struct init_sprites_s *sprite,
    struct player_s *player)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_save = {3800, 2900};
    sfVector2f scale = {0.2, 0.2};
    sfVector2f scale_button = {0.5, 0.5};
    sfVector2f pos_button = {3800, 2900};

    texture->shield_texture =
        sfTexture_createFromFile("asset/bouclier.png", NULL);
    sprite->shield_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->shield_sprite,
        texture->shield_texture, sfTrue);
    sfSprite_setPosition(sprite->shield_sprite, pos_save);
    sfSprite_setScale(sprite->shield_sprite, scale);
    texture->press_e_shield =
        sfTexture_createFromFile("asset/press_e.png", NULL);
    sprite->press_e_shield_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->press_e_shield_sprite,
        texture->press_e_shield, sfTrue);
    sfSprite_setPosition(sprite->press_e_shield_sprite, pos_button);
    sfSprite_setScale(sprite->press_e_shield_sprite, scale_button);
}

static float distance_shield(sfVector2f pos1, sfVector2f pos2)
{
    return sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
}

void detect_shield(struct player_s *player, struct init_sprites_s *sprite)
{
    sfVector2f sword_pos = sfSprite_getPosition(sprite->shield_sprite);
    float dist = distance_shield(player->playerPosition, sword_pos);

    if (dist <= 300.0f) {
        sprite->shield_detected = true;
    } else {
        sprite->shield_detected = false;
    }
}
