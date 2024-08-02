/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** map_follow
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

static void click_on(struct menu_s *menu, sfMouseButtonEvent event,
    struct init_sprites_s *sprite, struct player_s *player)
{
    click_on_setting(menu, event, sprite);
    click_on_exit_menu(menu, event, sprite);
    click_on_cross(menu, event, sprite);
    click_on_high_sound(menu, event, sprite);
    click_on_low_sound(menu, event, sprite);
    click_on_inventory(menu, event, sprite);
    click_on_cross_inventory(menu, event, sprite);
}

static void init_bool(struct menu_s *menu, struct init_sprites_s *sprite)
{
    menu->isOnPlayButton_setting = false;
    menu->isOnPlayButton_cross = false;
    menu->isOnPlayButton_exit = false;
    menu->isOnPlayButton_save = false;
    menu->isOnPlayButton_sound_high = false;
    menu->isOnPlayButton_sound_low = false;
    menu->isOnPlayButton_inventory = false;
    menu->isOnPlayButton_cross_inv = false;
    menu->inventory_open = false;
    sprite->combat->test = false;
    sprite->combat->bras_droit_is_clicked = false;
    sprite->combat->bras_gauche_is_clicked = false;
    sprite->combat->tete_is_clicked = false;
    sprite->combat->jambes_droit_is_clicked = false;
    sprite->combat->jambes_gauche_is_clicked = false;
}

void windows_map(struct menu_s *menu,
    struct init_sprites_s *sprite, struct player_s *player)
{
    sfEvent event_menu;

    animation(player);
    animation_q(player);
    animation_z(player);
    animation_d(player);
    init_bool(menu, sprite);
    while (sfRenderWindow_pollEvent(sprite->window, &event_menu)) {
        if (event_menu.type == sfEvtClosed)
            sfRenderWindow_close(sprite->window);
        if (event_menu.type == sfEvtMouseButtonPressed)
            click_on(menu, event_menu.mouseButton, sprite, player);
    }
    hover_click_on_menu(menu, sprite);
    display_map(menu, sprite, player, event_menu);
    init_parameter_fight(sprite, player);
}
