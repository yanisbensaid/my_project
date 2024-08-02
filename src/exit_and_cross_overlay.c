/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** follow_overlay
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include <string.h>
#include <math.h>

void exit_sprite(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_setting = {800, 700};
    sfVector2f scale = {1.0, 1.0};

    texture->whiteexit_menu_texture =
        sfTexture_createFromFile("asset/button_exit_grey.png", NULL);
    sprite->whiteexit_menu_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->whiteexit_menu_sprite,
        texture->whiteexit_menu_texture, sfTrue);
    sfSprite_setPosition(sprite->whiteexit_menu_sprite, pos_setting);
    sfSprite_setScale(sprite->whiteexit_menu_sprite, scale);
    texture->redexit_menu_texture =
        sfTexture_createFromFile("asset/button_exit_white.png", NULL);
    sprite->redexit_menu_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->redexit_menu_sprite,
        texture->redexit_menu_texture, sfTrue);
    sfSprite_setPosition(sprite->redexit_menu_sprite, pos_setting);
    sfSprite_setScale(sprite->redexit_menu_sprite, scale);
}

void cross_sprite(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_setting = {1120, 320};
    sfVector2f scale = {1.0, 1.0};

    texture->cross_black_texture =
        sfTexture_createFromFile("asset/croix_black.png", NULL);
    sprite->cross_black_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->cross_black_sprite,
        texture->cross_black_texture, sfTrue);
    sfSprite_setPosition(sprite->cross_black_sprite, pos_setting);
    sfSprite_setScale(sprite->cross_black_sprite, scale);
    texture->cross_white_texture =
        sfTexture_createFromFile("asset/croix_white.png", NULL);
    sprite->cross_white_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->cross_white_sprite,
        texture->cross_white_texture, sfTrue);
    sfSprite_setPosition(sprite->cross_white_sprite, pos_setting);
    sfSprite_setScale(sprite->cross_white_sprite, scale);
}

void click_on_cross(struct menu_s *menu, sfMouseButtonEvent event_menu,
    struct init_sprites_s *sprite)
{
    sfVector2i mousePosition;
    sfFloatRect spriteBounds;
    sfBool mouseOverSprite;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(sprite->window);

    menu->window_menu = sprite->window;
    mousePosition = sfMouse_getPositionRenderWindow(menu->window_menu);
    spriteBounds = sfSprite_getGlobalBounds(sprite->cross_black_sprite);
    if (sfFloatRect_contains(&spriteBounds, mouse_pos.x, mouse_pos.y)) {
        menu->isclick_on_seeting = false;
    }
}

void click_on_exit_menu(struct menu_s *menu, sfMouseButtonEvent event_menu,
    struct init_sprites_s *sprite)
{
    sfVector2i mousePosition;
    sfFloatRect spriteBounds;
    sfBool mouseOverSprite;

    menu->window_menu = sprite->window;
    mousePosition = sfMouse_getPositionRenderWindow(menu->window_menu);
    spriteBounds = sfSprite_getGlobalBounds(sprite->redexit_menu_sprite);
    mouseOverSprite = sfFloatRect_contains(&spriteBounds,
        mousePosition.x, mousePosition.y);
    if (event_menu.x >= spriteBounds.left && event_menu.x <= (spriteBounds.left
        + spriteBounds.width) && event_menu.y >= spriteBounds.top
        && event_menu.y <= (spriteBounds.top + spriteBounds.height)) {
        menu->game = 2;
    }
}
