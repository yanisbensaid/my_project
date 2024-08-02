/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** gestion_windows
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include <string.h>
#include <math.h>

void click_on_play
(struct menu_s *menu, sfMouseButtonEvent event_menu,
    struct init_sprites_s *sprite)
{
    sfVector2i mousePosition;
    sfFloatRect spriteBounds;
    sfBool mouseOverSprite;

    menu->window_menu = sprite->window;
    menu->game = 0;
    mousePosition = sfMouse_getPositionRenderWindow(menu->window_menu);
    spriteBounds = sfSprite_getGlobalBounds(sprite->play_white_sprite);
    mouseOverSprite = sfFloatRect_contains(&spriteBounds,
        mousePosition.x, mousePosition.y);
    if (event_menu.x >= spriteBounds.left && event_menu.x <= (spriteBounds.left
        + spriteBounds.width) && event_menu.y >= spriteBounds.top
        && event_menu.y <= (spriteBounds.top + spriteBounds.height)) {
        menu->game++;
    }
}

void click_on_exit
(struct menu_s *menu, sfMouseButtonEvent event_menu,
    struct init_sprites_s *sprite)
{
    sfVector2i mousePosition;
    sfFloatRect spriteBounds;
    sfBool mouseOverSprite;

    menu->window_menu = sprite->window;
    mousePosition = sfMouse_getPositionRenderWindow(menu->window_menu);
    spriteBounds = sfSprite_getGlobalBounds(sprite->exit_red_sprite);
    mouseOverSprite = sfFloatRect_contains(&spriteBounds,
        mousePosition.x, mousePosition.y);
    if (event_menu.x >= spriteBounds.left && event_menu.x <= (spriteBounds.left
        + spriteBounds.width) && event_menu.y >= spriteBounds.top
        && event_menu.y <= (spriteBounds.top + spriteBounds.height)) {
        menu->game = 2;
    }
}

void follow_windows_menu(struct menu_s *menu, struct init_sprites_s *sprite)
{
    sfEvent event_menu;

    while (sfRenderWindow_pollEvent(sprite->window, &event_menu)) {
    if (event_menu.type == sfEvtClosed)
        sfRenderWindow_close(sprite->window);
    if (event_menu.type == sfEvtMouseButtonPressed)
        click_on_play(menu, event_menu.mouseButton, sprite);
    if (event_menu.type == sfEvtMouseButtonPressed)
        click_on_exit(menu, event_menu.mouseButton, sprite);
    if (event_menu.type == sfEvtResized) {
        sfRenderWindow_setView(sprite->window,
            sfView_createFromRect((sfFloatRect){0, 0,
                event_menu.size.width, event_menu.size.height}));
    }
    }
}

void windows_menu(struct menu_s *menu, struct init_sprites_s *sprite)
{
    sfEvent event_menu;
    bool isOnPlayButton_play = false;
    bool isOnPlayButton_exit = false;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(sprite->window);
    sfFloatRect spriteBounds_play =
        sfSprite_getGlobalBounds(sprite->play_white_sprite);
    sfFloatRect spriteBounds_exit =
        sfSprite_getGlobalBounds(sprite->exit_red_sprite);

    follow_windows_menu(menu, sprite);
    if (sfFloatRect_contains(&spriteBounds_play, mouse_pos.x, mouse_pos.y))
        isOnPlayButton_play = true;
    if (sfFloatRect_contains(&spriteBounds_exit, mouse_pos.x, mouse_pos.y))
        isOnPlayButton_exit = true;
    display_menu(menu, sprite, isOnPlayButton_play, isOnPlayButton_exit);
}
