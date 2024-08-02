/*
** EPITECH PROJECT, 2024
** force_a_nous
** File description:
** sprite_menu
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

void fond_menu(struct init_sprites_s *sprite,
    struct menu_s *menu, struct player_s *player)
{
    sprite->combat->show_bras_droit = false;
    sprite->combat->fond_menu_long_texture = sfTexture_createFromFile(
        "asset/asset_combat/menu_combat/square_long.png", NULL);
    sprite->combat->menu_combat_long_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->combat->menu_combat_long_sprite,
        sprite->combat->fond_menu_long_texture, sfTrue);
    sprite->combat->menu_combat_long_pos.x = 100;
    sprite->combat->menu_combat_long_pos.y = 719;
    sprite->combat->size_menu_combat_long.x = 1;
    sprite->combat->size_menu_combat_long.y = 1;
    sfSprite_setPosition(sprite->combat->menu_combat_long_sprite,
        sprite->combat->menu_combat_long_pos);
    sfSprite_setScale(sprite->combat->menu_combat_long_sprite,
        sprite->combat->size_menu_combat_long);
}

void fond_menu_court(struct init_sprites_s *sprite)
{
    sprite->combat->fond_menu_combat_texture = sfTexture_createFromFile(
        "asset/asset_combat/menu_combat/square.png", NULL);
    sprite->combat->menu_combat_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->combat->menu_combat_sprite,
        sprite->combat->fond_menu_combat_texture, sfTrue);
    sprite->combat->menu_combat_pos.x = 0;
    sprite->combat->menu_combat_pos.y = 719;
    sfSprite_setPosition(sprite->combat->menu_combat_sprite,
        sprite->combat->menu_combat_pos);
}
