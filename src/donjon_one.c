/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** donjon_one
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include <string.h>
#include <math.h>

void init_donjon_one(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f scale = {2.0, 2.0};
    sfVector2f pos = {0, -300};

    texture->donjon_one_texture =
        sfTexture_createFromFile("asset/Amayyas_MAP/map_yinx_dungeon02.png",
            NULL);
    sprite->donjon_one_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->donjon_one_sprite,
        texture->donjon_one_texture, sfTrue);
    sfSprite_setScale(sprite->donjon_one_sprite, scale);
    sfSprite_setPosition(sprite->donjon_one_sprite, pos);
}

void display_donjon_one(struct menu_s *menu, struct init_sprites_s *sprite,
    struct player_s *player, sfEvent event)
{
    sfRenderWindow_clear(sprite->window, sfBlack);
    detect_object_donjon_one(player, sprite);
    sfRenderWindow_drawSprite(sprite->window, sprite->donjon_one_sprite, NULL);
    interact_with_object_donjon_one(sprite, player, menu);
    if (player->win_first_boss == true && sprite->key_visible == true)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->key_sprite, NULL);
    display_player_zqs(sprite, player, menu);
    create_sprite_enenmi(sprite, menu);
    if (player->state_boss_one == 0)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->enemi_sprite, NULL);
    sfRenderWindow_display(sprite->window);
}

void windows_donjon_one(struct menu_s *menu,
    struct init_sprites_s *sprite, struct player_s *player)
{
    sfEvent event_menu;

    while (sfRenderWindow_pollEvent(sprite->window, &event_menu)) {
        if (event_menu.type == sfEvtClosed)
            sfRenderWindow_close(sprite->window);
    }
    display_donjon_one(menu, sprite, player, event_menu);
}

void enter_in_donjon(struct player_s *player,
    struct init_sprites_s *sprite, struct menu_s *menu, sfEvent event)
{
    if (player->playerPosition.x >= 2656 && player->playerPosition.x <= 2754 &&
        player->playerPosition.y >= 940 && player->playerPosition.y <= 1090) {
        menu->game = 6;
        menu->position_initialized = false;
    }
}

void exit_donjon_one(struct player_s *player,
    struct init_sprites_s *sprite, struct menu_s *menu, sfEvent event)
{
    if (menu->game == 6 && player->playerPosition.x >= 950 &&
        player->playerPosition.x <= 1060 &&
        player->playerPosition.y >= 731 && player->playerPosition.y <= 900) {
        menu->game = 3;
        player->playerPosition.x = 2705;
        player->playerPosition.y = 1236;
        player->x_value = player->playerPosition.x;
        player->y_value = player->playerPosition.y;
        menu->position_initialized = false;
    }
}
