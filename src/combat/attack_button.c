/*
** EPITECH PROJECT, 2024
** force_a_nous
** File description:
** attack_button
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../includes/my_rpg.h"
#include <string.h>
#include <math.h>

void attack_button(struct init_sprites_s *sprite)
{
    sprite->combat->attack_button_texture = sfTexture_createFromFile(
        "asset/asset_combat/menu_combat/attack.png", NULL);
    sprite->combat->attack_button_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->combat->attack_button_sprite,
        sprite->combat->attack_button_texture, sfTrue);
    sprite->combat->attack_button_pos.x = 10;
    sprite->combat->attack_button_pos.y = 740;
    sfSprite_setPosition(sprite->combat->attack_button_sprite,
        sprite->combat->attack_button_pos);
}

void create_bras_droit_button(struct init_sprites_s *sprite)
{
    sprite->combat->bras_droit_texture = sfTexture_createFromFile(
        "asset/asset_combat/menu_combat/bras_droit.png", NULL);
    sprite->combat->bras_droit_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->combat->bras_droit_sprite,
        sprite->combat->bras_droit_texture, sfTrue);
    sprite->combat->bras_droit_pos.x = 900;
    sprite->combat->bras_droit_pos.y = 750;
    sfSprite_setPosition(sprite->combat->bras_droit_sprite,
        sprite->combat->bras_droit_pos);
}

void create_bras_gauche_button(struct init_sprites_s *sprite)
{
    sprite->combat->bras_gauche_texture = sfTexture_createFromFile(
        "asset/asset_combat/menu_combat/bras_gauche.png", NULL);
    sprite->combat->bras_gauche_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->combat->bras_gauche_sprite,
        sprite->combat->bras_gauche_texture, sfTrue);
    sprite->combat->bras_gauche_pos.x = 375;
    sprite->combat->bras_gauche_pos.y = 750;
    sfSprite_setPosition(sprite->combat->bras_gauche_sprite,
        sprite->combat->bras_gauche_pos);
    sprite->combat->bras_gauche_bounds =
        sfSprite_getGlobalBounds(sprite->combat->bras_gauche_sprite);
}

void create_jambe_droit(struct init_sprites_s *sprite)
{
    sprite->combat->jambes_droit_texture = sfTexture_createFromFile(
        "asset/asset_combat/menu_combat/jambe_droite.png", NULL);
    sprite->combat->jambes_droit_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->combat->jambes_droit_sprite,
        sprite->combat->jambes_droit_texture, sfTrue);
    sprite->combat->jambes_droit_pos.x = 900;
    sprite->combat->jambes_droit_pos.y = 850;
    sfSprite_setPosition(sprite->combat->jambes_droit_sprite,
        sprite->combat->jambes_droit_pos);
    sprite->combat->jambes_droit_bounds =
        sfSprite_getGlobalBounds(sprite->combat->jambes_droit_sprite);
}

void create_jambe_gauche(struct init_sprites_s *sprite)
{
    sprite->combat->jambes_gauche_texture = sfTexture_createFromFile(
        "asset/asset_combat/menu_combat/jambe_gauche.png", NULL);
    sprite->combat->jambes_gauche_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->combat->jambes_gauche_sprite,
        sprite->combat->jambes_gauche_texture, sfTrue);
    sprite->combat->jambes_gauche_pos.x = 375;
    sprite->combat->jambes_gauche_pos.y = 850;
    sfSprite_setPosition(sprite->combat->jambes_gauche_sprite,
        sprite->combat->jambes_gauche_pos);
    sprite->combat->jambes_gauche_bounds =
        sfSprite_getGlobalBounds(sprite->combat->jambes_gauche_sprite);
}
