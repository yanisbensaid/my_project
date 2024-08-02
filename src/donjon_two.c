/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** donjon_two
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include <string.h>
#include <math.h>

void init_donjon_two(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f scale = {2.0, 2.0};
    sfVector2f pos = {150, -400};

    texture->donjon_two_texture =
        sfTexture_createFromFile("asset/Amayyas_MAP/map_dungeon_yinx.png",
            NULL);
    sprite->donjon_two_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->donjon_two_sprite,
        texture->donjon_two_texture, sfTrue);
    sfSprite_setScale(sprite->donjon_two_sprite, scale);
    sfSprite_setPosition(sprite->donjon_two_sprite, pos);
}

void display_donjon_two(struct menu_s *menu, struct init_sprites_s *sprite,
    struct player_s *player, sfEvent event)
{
    sfRenderWindow_clear(sprite->window, sfBlack);
    sfRenderWindow_drawSprite(sprite->window, sprite->donjon_two_sprite, NULL);
    display_player_donjon_one(sprite, player, menu);
    create_sprite_enemi_two(sprite, menu);
    if (player->state_boss_two == 0)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->enemi_two_sprite, NULL);
    sfRenderWindow_display(sprite->window);
}

void windows_donjon_two(struct menu_s *menu,
    struct init_sprites_s *sprite, struct player_s *player)
{
    sfEvent event_menu;

    while (sfRenderWindow_pollEvent(sprite->window, &event_menu)) {
        if (event_menu.type == sfEvtClosed)
            sfRenderWindow_close(sprite->window);
    }
    display_donjon_two(menu, sprite, player, event_menu);
}

void enter_in_donjon_two(struct player_s *player,
    struct init_sprites_s *sprite, struct menu_s *menu)
{
    if (player->playerPosition.x >= 4440 && player->playerPosition.x <= 4539 &&
        player->playerPosition.y >= 924 && player->playerPosition.y <= 1090) {
        menu->game = 7;
        sprite->combat->defense_enemi = 80;
        menu->position_initialized = false;
    }
}

void exit_donjon_two(struct player_s *player,
    struct init_sprites_s *sprite, struct menu_s *menu, sfEvent event)
{
    if (menu->game == 7 && player->playerPosition.x >= 364 &&
        player->playerPosition.x <= 475 &&
        player->playerPosition.y >= 693 && player->playerPosition.y <= 833) {
        player->playerPosition.x = 4494;
        player->playerPosition.y = 1265;
        player->x_value = player->playerPosition.x;
        player->y_value = player->playerPosition.y;
        menu->game = 3;
        menu->position_initialized = false;
    }
}
