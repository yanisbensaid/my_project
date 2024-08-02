/*
** EPITECH PROJECT, 2024
** rpg_yanis_push_22
** File description:
** create_sword
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include <string.h>
#include <math.h>

void create_sword(struct init_sprites_s *sprite)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f epee_pos;
    sfVector2f scale = {0.25, 0.25};
    sfVector2f scale_button = {0.5, 0.5};
    sfVector2f pos_button = {325, 2350};

    sprite->epee_texture = sfTexture_createFromFile("asset/epee.png", NULL);
    sprite->epee_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->epee_sprite, sprite->epee_texture, sfTrue);
    epee_pos.x = 400;
    epee_pos.y = 2500;
    sfSprite_setPosition(sprite->epee_sprite, epee_pos);
    sfSprite_setScale(sprite->epee_sprite, scale);
    texture->press_sword_texture =
        sfTexture_createFromFile("asset/press_e.png", NULL);
    sprite->press_sword_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->press_sword_sprite,
        texture->press_sword_texture, sfTrue);
    sfSprite_setPosition(sprite->press_sword_sprite, pos_button);
    sfSprite_setScale(sprite->press_sword_sprite, scale_button);
}

void create_shield_in_inventory(struct init_sprites_s *sprite)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f epee_pos;
    sfVector2f scale = {0.25, 0.25};

    texture->shield_inv_texture =
        sfTexture_createFromFile("asset/bouclier.png", NULL);
    sprite->shield_sprite_inv = sfSprite_create();
    sfSprite_setTexture(sprite->shield_sprite_inv,
        texture->shield_inv_texture, sfTrue);
    epee_pos.x = 1010;
    epee_pos.y = 540;
    sfSprite_setPosition(sprite->shield_sprite_inv, epee_pos);
    sfSprite_setScale(sprite->shield_sprite_inv, scale);
}

void create_sword_in_inventory(struct init_sprites_s *sprite)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f epee_pos;
    sfVector2f scale = {0.4, 0.4};

    texture->sword_inv_texture =
        sfTexture_createFromFile("asset/epee.png", NULL);
    sprite->sword_sprite_inv = sfSprite_create();
    sfSprite_setTexture(sprite->sword_sprite_inv,
        texture->sword_inv_texture, sfTrue);
    epee_pos.x = 1000;
    epee_pos.y = 350;
    sfSprite_setPosition(sprite->sword_sprite_inv, epee_pos);
    sfSprite_setScale(sprite->sword_sprite_inv, scale);
}

void init_damage(struct init_sprites_s *sprite)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f damage_pos = {1500, 820};
    sfVector2f shield_pos = {1500, 770};
    sfVector2f scale = {0.6, 0.6};

    texture->ten_damage_texture =
        sfTexture_createFromFile("asset/10damage.png", NULL);
    sprite->ten_damage_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->ten_damage_sprite,
        texture->ten_damage_texture, sfTrue);
    sfSprite_setPosition(sprite->ten_damage_sprite, damage_pos);
    sfSprite_setScale(sprite->ten_damage_sprite, scale);
    texture->shield_text_texture =
        sfTexture_createFromFile("asset/20boucliers.png", NULL);
    sprite->shield_text_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->shield_text_sprite,
        texture->shield_text_texture, sfTrue);
    sfSprite_setPosition(sprite->shield_text_sprite, shield_pos);
    sfSprite_setScale(sprite->shield_text_sprite, scale);
}

static float distance_sword(sfVector2f pos1, sfVector2f pos2)
{
    return sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
}

void detect_sword(struct player_s *player, struct init_sprites_s *sprite)
{
    sfVector2f sword_pos = sfSprite_getPosition(sprite->epee_sprite);
    float dist = distance_sword(player->playerPosition, sword_pos);

    if (dist <= 300.0f) {
        sprite->sword_detected = true;
    } else {
        sprite->sword_detected = false;
    }
}
