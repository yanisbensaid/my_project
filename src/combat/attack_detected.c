/*
** EPITECH PROJECT, 2024
** force_a_nous
** File description:
** attack_detected
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

static void create_background_fight(struct init_sprites_s *sprite)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f background_scale = {2.0, 2.0};
    sfVector2f background_pos = {200, 0};

    texture->background_fight_texture = sfTexture_createFromFile(
        "asset/School1.png", NULL);
    sprite->background_fight_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->background_fight_sprite,
        texture->background_fight_texture, sfTrue);
    sfSprite_setScale(sprite->background_fight_sprite, background_scale);
    sfSprite_setPosition(sprite->background_fight_sprite, background_pos);
}

void create_tete_button(struct init_sprites_s *sprite)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f tete_pos = {275, 1050};
    sfVector2f background_scale = {2.0, 2.0};
    sfVector2f background_pos = {200, 0};

    sprite->combat->tete_texture = sfTexture_createFromFile(
        "asset/asset_combat/menu_combat/tete.png", NULL);
    sprite->combat->tete_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->combat->tete_sprite,
        sprite->combat->tete_texture, sfTrue);
    sfSprite_setPosition(sprite->combat->tete_sprite,
        sprite->combat->tete_pos);
    sprite->combat->tete_bounds =
        sfSprite_getGlobalBounds(sprite->combat->tete_sprite);
    create_background_fight(sprite);
}

void draw_sprite_combat(struct init_sprites_s *sprite)
{
    sfRenderWindow_drawSprite(sprite->window,
        sprite->background_fight_sprite, NULL);
    sfRenderWindow_drawSprite(sprite->window,
        sprite->combat->player_combat_sprite, NULL);
    sfRenderWindow_drawSprite(sprite->window,
        sprite->combat->menu_combat_long_sprite, NULL);
    sfRenderWindow_drawSprite(sprite->window,
        sprite->combat->menu_combat_sprite, NULL);
    sfRenderWindow_drawSprite(sprite->window,
        sprite->combat->attack_button_sprite, NULL);
}

void attack_on(sfEvent event, struct init_sprites_s *sprite)
{
    sfRenderWindow_drawSprite(sprite->window,
        sprite->combat->bras_droit_sprite, NULL);
    sfRenderWindow_drawSprite(sprite->window,
        sprite->combat->bras_gauche_sprite, NULL);
    sfRenderWindow_drawSprite(sprite->window,
        sprite->combat->jambes_droit_sprite, NULL);
    sfRenderWindow_drawSprite(sprite->window,
        sprite->combat->jambes_gauche_sprite, NULL);
}
