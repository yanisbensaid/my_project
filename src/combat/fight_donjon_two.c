/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** fight_donjon_two
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

static void win_second_monster(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu)
{
    if (player->win_second_boss == true) {
    menu->game = 7;
    menu->position_initialized = false;
    }
}

void init_fight_donjon_two(struct menu_s *menu,
    struct init_sprites_s *sprite, struct player_s *player)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));

    sprite->combat->bras_droit_is_clicked = false;
    sprite->combat->bras_gauche_is_clicked = false;
    sprite->combat->jambes_droit_is_clicked = false;
    sprite->combat->jambes_gauche_is_clicked = false;
    if (sprite->combat->set_sprite_enemi == false) {
    sfSprite_setTexture(sprite->combat->enemi_combat_sprite,
        sprite->combat->enemi_combat_texture, sfTrue);
    sfSprite_setTexture(sprite->combat->player_combat_sprite,
        sprite->combat->player_combat_texture, sfTrue);
    sprite->combat->set_sprite_enemi = true;
    }
    sprite->combat->attack_enemi = 20;
    sprite->combat->mouseOverSprite = false;
}

void fight_donjon_two(struct menu_s *menu,
    struct init_sprites_s *sprite, struct player_s *player)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(sprite->window);
    sfEvent combat_event;

    init_fight_donjon_two(menu, sprite, player);
    if (sprite->combat->turn % 2 == 1) {
        process_combat_click(sprite, combat_event, player, menu);
    }
    check_combat_miss(sprite, menu, player);
    change_barre_life(sprite, menu, player);
    win_second_monster(sprite, player, menu);
    sfRenderWindow_display(sprite->window);
    free(texture);
}
