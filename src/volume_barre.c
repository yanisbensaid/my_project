/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** volume_barre
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

void three_volume_barre_sprite(struct init_sprites_s *sprite,
    struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_setting = {785, 470};
    sfVector2f scale = {0.65, 1.0};

    texture->volume_mid_texture =
        sfTexture_createFromFile("asset/volume_barre(5).png", NULL);
    sprite->volume_mid_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->volume_mid_sprite,
        texture->volume_mid_texture, sfTrue);
    sfSprite_setPosition(sprite->volume_mid_sprite, pos_setting);
    sfSprite_setScale(sprite->volume_mid_sprite, scale);
}

void follow_volume_barre_sprite(struct init_sprites_s *sprite,
    struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_setting = {785, 470};
    sfVector2f scale = {0.65, 1.0};

    texture->volume_low_texture =
        sfTexture_createFromFile("asset/volume_barre(3).png", NULL);
    sprite->volume_low_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->volume_low_sprite,
        texture->volume_low_texture, sfTrue);
    sfSprite_setPosition(sprite->volume_low_sprite, pos_setting);
    sfSprite_setScale(sprite->volume_low_sprite, scale);
    texture->volume_mute_texture =
        sfTexture_createFromFile("asset/volume_barre(4).png", NULL);
    sprite->volume_mute_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->volume_mute_sprite,
        texture->volume_mute_texture, sfTrue);
    sfSprite_setPosition(sprite->volume_mute_sprite, pos_setting);
    sfSprite_setScale(sprite->volume_mute_sprite, scale);
}

void volume_barre_sprite(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_setting = {785, 470};
    sfVector2f scale = {0.65, 1.0};

    texture->volume_full_texture =
        sfTexture_createFromFile("asset/volume_barre(1).png", NULL);
    sprite->volume_full_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->volume_full_sprite,
        texture->volume_full_texture, sfTrue);
    sfSprite_setPosition(sprite->volume_full_sprite, pos_setting);
    sfSprite_setScale(sprite->volume_full_sprite, scale);
    texture->volume_high_texture =
        sfTexture_createFromFile("asset/volume_barre(2).png", NULL);
    sprite->volume_high_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->volume_high_sprite,
        texture->volume_high_texture, sfTrue);
    sfSprite_setPosition(sprite->volume_high_sprite, pos_setting);
    sfSprite_setScale(sprite->volume_high_sprite, scale);
}
