/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** click_on_cross_inv
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include <string.h>

void click_on_cross_inventory(struct menu_s *menu,
    sfMouseButtonEvent event_menu, struct init_sprites_s *sprite)
{
    sfVector2i mousePosition;
    sfFloatRect spriteBounds;
    sfBool mouseOverSprite;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(sprite->window);

    menu->window_menu = sprite->window;
    mousePosition = sfMouse_getPositionRenderWindow(menu->window_menu);
    spriteBounds = sfSprite_getGlobalBounds(sprite->cross_black__inv_sprite);
    if (sfFloatRect_contains(&spriteBounds, mouse_pos.x, mouse_pos.y)) {
        menu->isclick_on_inventory = false;
    }
}

void display_cross_inventory(struct menu_s *menu,
    struct init_sprites_s *sprite)
{
    if (menu->isOnPlayButton_cross_inv == true)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->cross_black__inv_sprite, NULL);
    else
        sfRenderWindow_drawSprite(sprite->window,
            sprite->cross_white_inv_sprite, NULL);
}

void cross_sprite_inventory(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_setting = {1155, 290};
    sfVector2f scale = {1.0, 1.0};

    texture->cross_black__inv_texture =
        sfTexture_createFromFile("asset/croix_black.png", NULL);
    sprite->cross_black__inv_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->cross_black__inv_sprite,
        texture->cross_black__inv_texture, sfTrue);
    sfSprite_setPosition(sprite->cross_black__inv_sprite, pos_setting);
    sfSprite_setScale(sprite->cross_black__inv_sprite, scale);
    texture->cross_white_inv_texture =
        sfTexture_createFromFile("asset/croix_white.png", NULL);
    sprite->cross_white_inv_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->cross_white_inv_sprite,
        texture->cross_white_inv_texture, sfTrue);
    sfSprite_setPosition(sprite->cross_white_inv_sprite, pos_setting);
    sfSprite_setScale(sprite->cross_white_inv_sprite, scale);
}
