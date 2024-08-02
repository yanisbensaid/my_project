/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** end_game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include <string.h>
#include <math.h>

void init_end_game(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_save = {600, 300};
    sfVector2f scale = {1.0, 1.0};

    texture->end_game_texture =
        sfTexture_createFromFile("asset/end_game.jpg", NULL);
    sprite->end_game_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->end_game_sprite,
        texture->end_game_texture, sfTrue);
    sfSprite_setPosition(sprite->end_game_sprite, pos_save);
    sfSprite_setScale(sprite->end_game_sprite, scale);
}

void display_end_game(struct menu_s *menu, struct init_sprites_s *sprite)
{
    sfRenderWindow_clear(sprite->window, sfBlack);
    sfRenderWindow_drawSprite(sprite->window,
        sprite->game_over_sprite, NULL);
    sfRenderWindow_display(sprite->window);
}

void end_game(struct menu_s *menu, struct init_sprites_s *sprite,
    struct player_s *player)
{
    sfEvent event_menu;

    while (sfRenderWindow_pollEvent(sprite->window, &event_menu)) {
        if (event_menu.type == sfEvtClosed) {
            sfRenderWindow_close(sprite->window);
        }
        if (event_menu.type == sfEvtKeyPressed &&
            event_menu.key.code == sfKeyReturn) {
            menu->game = 0;
            player->life_player = 100;
            player->playerPosition.x = 3329;
            player->playerPosition.y = 2998;
            player->x_value = player->playerPosition.x;
            player->y_value = player->playerPosition.y;
            menu->position_initialized = false;
        }
    }
    display_end_game(menu, sprite);
}
