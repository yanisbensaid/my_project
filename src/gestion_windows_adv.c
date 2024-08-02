/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** gestion_windows_adv
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include <string.h>
#include <math.h>

void create_sprite_adv(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_play = {0, 0};
    sfVector2f pos_press = {1000, 880};
    sfVector2f scale_press = {1.0, 1.0};

    texture->avertissment_texture =
        sfTexture_createFromFile("asset/avertissement.jpeg", NULL);
    sprite->avertissment_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->avertissment_sprite,
        texture->avertissment_texture, sfTrue);
    sfSprite_setPosition(sprite->avertissment_sprite, pos_play);
    texture->text_press_texture =
        sfTexture_createFromFile("asset/press.png", NULL);
    sprite->text_press_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->text_press_sprite,
        texture->text_press_texture, sfTrue);
    sfSprite_setPosition(sprite->text_press_sprite, pos_press);
    sfSprite_setScale(sprite->text_press_sprite, scale_press);
    free(texture);
}

void display_adv(struct menu_s *menu, struct init_sprites_s *sprite)
{
    sfVector2u windowSize = sfRenderWindow_getSize(sprite->window);
    sfVector2f scale = {
        (float)windowSize.x / sfTexture_getSize(sfSprite_getTexture
        (sprite->avertissment_sprite)).x,
        (float)windowSize.y / sfTexture_getSize(sfSprite_getTexture
        (sprite->avertissment_sprite)).y
    };

    sfSprite_setScale(sprite->avertissment_sprite, scale);
    sfRenderWindow_clear(sprite->window, sfBlack);
    sfRenderWindow_drawSprite
    (sprite->window, sprite->avertissment_sprite, NULL);
    sfRenderWindow_drawSprite(sprite->window, sprite->text_press_sprite, NULL);
    sfRenderWindow_display(sprite->window);
}

void windows_adv(struct menu_s *menu, struct init_sprites_s *sprite)
{
    sfEvent event_menu;

    while (sfRenderWindow_pollEvent(sprite->window, &event_menu)) {
        if (event_menu.type == sfEvtClosed) {
            sfRenderWindow_close(sprite->window);
        }
        if (event_menu.type == sfEvtKeyPressed &&
            event_menu.key.code == sfKeyReturn) {
            menu->game = 3;
        }
    }
    display_adv(menu, sprite);
}
