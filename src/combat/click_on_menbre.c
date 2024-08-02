/*
** EPITECH PROJECT, 2024
** force_a_nous
** File description:
** click_on_menbre
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

static void chance_droit(struct init_sprites_s *sprite, int chance)
{
    if (chance == 0)
        sprite->combat->bras_droit_is_clicked = true;
}

static void miss_attack(struct init_sprites_s *sprite, sfTexture *new_texture,
    struct player_s *player, struct menu_s *menu)
{
    int chance = rand() % 2;

    if (menu->mouse_over_bras_droit &&
        sprite->combat->bras_droit_is_clicked == false) {
        if (player->attack_player > sprite->combat->attack_enemi) {
            sprite->combat->bras_droit_is_clicked = true;
        } else {
            chance_droit(sprite, chance);
        }
        if (sprite->combat->bras_droit_is_clicked) {
            inflige_damage_monter(sprite, player, menu);
            new_texture = sfTexture_createFromFile
            ("asset/enemi/enemi_bras_droit.png", NULL);
            sfSprite_setTexture
            (sprite->combat->enemi_combat_sprite, new_texture, sfTrue);
        }
        turn_fight(sprite, player);
    }
}

static void click_bras_droit(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu)
{
    sfTexture *new_texture;

    sprite->combat->bras_droit_bounds =
        sfSprite_getGlobalBounds(sprite->combat->bras_droit_sprite);
    menu->mouse_over_bras_droit =
        sfFloatRect_contains(&sprite->combat->bras_droit_bounds,
        sprite->combat->mousePosition.x, sprite->combat->mousePosition.y);
    miss_attack(sprite, new_texture, player, menu);
}

static void chance_gauche(struct init_sprites_s *sprite, int chance)
{
    if (chance == 0)
        sprite->combat->bras_gauche_is_clicked = true;
}

void miss_attack_gauche(struct init_sprites_s *sprite, sfTexture *new_texture,
    struct player_s *player, struct menu_s *menu)
{
    int chance = rand() % 2;

    if (menu->mouse_over_bras_gauche
        && sprite->combat->bras_gauche_is_clicked == false) {
        if (player->attack_player > sprite->combat->attack_enemi) {
            sprite->combat->bras_gauche_is_clicked = true;
        } else {
            chance_gauche(sprite, chance);
        }
        if (sprite->combat->bras_gauche_is_clicked) {
            inflige_damage_monter(sprite, player, menu);
            new_texture = sfTexture_createFromFile
            ("asset/enemi/enemi_bras_gauche.png", NULL);
            sfSprite_setTexture
            (sprite->combat->enemi_combat_sprite, new_texture, sfTrue);
        }
        turn_fight(sprite, player);
    }
}

void click_bras_gauche(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu)
{
    sfTexture *new_texture;

    sprite->combat->bras_gauche_bounds =
        sfSprite_getGlobalBounds(sprite->combat->bras_gauche_sprite);
    menu->mouse_over_bras_gauche =
        sfFloatRect_contains(&sprite->combat->bras_gauche_bounds,
        sprite->combat->mousePosition.x, sprite->combat->mousePosition.y);
    miss_attack_gauche(sprite, new_texture, player, menu);
}

void click_jambe_droit(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu)
{
    sfBool mouse_over_jambe_droit;
    sfTexture *new_texture;

    sprite->combat->jambes_droit_bounds =
        sfSprite_getGlobalBounds(sprite->combat->jambes_droit_sprite);
    mouse_over_jambe_droit =
        sfFloatRect_contains(&sprite->combat->jambes_droit_bounds,
        sprite->combat->mousePosition.x, sprite->combat->mousePosition.y);
    if (mouse_over_jambe_droit
        && sprite->combat->jambes_droit_is_clicked == false) {
        sprite->combat->jambes_droit_is_clicked = true;
        inflige_damage_monter(sprite, player, menu);
        new_texture =
        sfTexture_createFromFile("asset/enemi/enemi_jambe_droite.png", NULL);
        sfSprite_setTexture(sprite->combat->enemi_combat_sprite,
            new_texture, sfTrue);
        turn_fight(sprite, player);
    }
}

void click_jambe_gauche(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu)
{
    sfBool mouse_over_jambe_gauche;
    sfTexture *new_texture;

    sprite->combat->jambes_gauche_bounds =
        sfSprite_getGlobalBounds(sprite->combat->jambes_gauche_sprite);
    mouse_over_jambe_gauche =
        sfFloatRect_contains(&sprite->combat->jambes_gauche_bounds,
        sprite->combat->mousePosition.x, sprite->combat->mousePosition.y);
    if (mouse_over_jambe_gauche
        && sprite->combat->jambes_gauche_is_clicked == false) {
        sprite->combat->jambes_gauche_is_clicked = true;
        inflige_damage_monter(sprite, player, menu);
        new_texture =
        sfTexture_createFromFile("asset/enemi/enemi_jambe_gauche.png", NULL);
        sfSprite_setTexture(sprite->combat->enemi_combat_sprite,
            new_texture, sfTrue);
        turn_fight(sprite, player);
    }
}

void check_combat_part_click(struct init_sprites_s *sprite,
    bool showSprites, struct player_s *player, struct menu_s *menu)
{
    if (showSprites) {
        click_bras_droit(sprite, player, menu);
        click_bras_gauche(sprite, player, menu);
        click_jambe_droit(sprite, player, menu);
        click_jambe_gauche(sprite, player, menu);
    }
}
