/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** menu_map
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include <string.h>
#include <math.h>

void create_setting_sprite(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_setting = {20, 10};
    sfVector2f scale = {0.0270, 0.0270};

    texture->setting_black_texture =
        sfTexture_createFromFile("asset/setting_blackkk.png", NULL);
    sprite->setting_black_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->setting_black_sprite,
        texture->setting_black_texture, sfTrue);
    sfSprite_setPosition(sprite->setting_black_sprite, pos_setting);
    sfSprite_setScale(sprite->setting_black_sprite, scale);
    texture->setting_white_texture =
        sfTexture_createFromFile("asset/setting_whiteee.png", NULL);
    sprite->setting_white_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->setting_white_sprite,
        texture->setting_white_texture, sfTrue);
    sfSprite_setPosition(sprite->setting_white_sprite, pos_setting);
    sfSprite_setScale(sprite->setting_white_sprite, scale);
    free(texture);
}

void overlay(struct menu_s *menu, struct init_sprites_s *sprite)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pose_square = {700, 300};
    sfVector2f scale = {2.0, 2.0};

    texture->square_texture =
        sfTexture_createFromFile("asset/square.png", NULL);
    sprite->square_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->square_sprite,
        texture->square_texture, sfTrue);
    sfSprite_setPosition(sprite->square_sprite, pose_square);
    sfSprite_setScale(sprite->square_sprite, scale);
}

static void three_display_overlay(struct menu_s *menu,
    struct init_sprites_s *sprite)
{
    if (sprite->volume == 0)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->volume_mute_sprite, NULL);
    if (sprite->volume == 25)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->volume_low_sprite, NULL);
    if (sprite->volume == 50)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->volume_mid_sprite, NULL);
    if (sprite->volume == 75)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->volume_high_sprite, NULL);
    if (sprite->volume == 100)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->volume_full_sprite, NULL);
}

static void follow_display_overlay(struct menu_s *menu,
    struct init_sprites_s *sprite)
{
    if (menu->isOnPlayButton_save == true)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->save_grey_sprite, NULL);
    else
        sfRenderWindow_drawSprite(sprite->window,
            sprite->save_white_sprite, NULL);
    if (menu->isOnPlayButton_sound_high == true)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->high_sound_grey_sprite, NULL);
    else
        sfRenderWindow_drawSprite(sprite->window,
            sprite->high_sound_white_sprite, NULL);
    if (menu->isOnPlayButton_sound_low == true)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->low_sound_grey_sprite, NULL);
    else
        sfRenderWindow_drawSprite(sprite->window,
            sprite->low_sound_white_sprite, NULL);
}

void display_overlay(struct menu_s *menu, struct init_sprites_s *sprite)
{
    sfRenderWindow_drawSprite(sprite->window,
        sprite->square_sprite, NULL);
    if (menu->isOnPlayButton_cross == true)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->cross_black_sprite, NULL);
    else
        sfRenderWindow_drawSprite(sprite->window,
            sprite->cross_white_sprite, NULL);
    if (menu->isOnPlayButton_exit == true)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->whiteexit_menu_sprite, NULL);
    else
        sfRenderWindow_drawSprite(sprite->window,
            sprite->redexit_menu_sprite, NULL);
    follow_display_overlay(menu, sprite);
    three_display_overlay(menu, sprite);
}

void click_on_setting(struct menu_s *menu, sfMouseButtonEvent event_menu,
    struct init_sprites_s *sprite)
{
    sfVector2i mousePosition;
    sfFloatRect spriteBounds;
    sfBool mouseOverSprite;

    menu->window_menu = sprite->window;
    mousePosition = sfMouse_getPositionRenderWindow(menu->window_menu);
    spriteBounds = sfSprite_getGlobalBounds(sprite->setting_white_sprite);
    mouseOverSprite = sfFloatRect_contains(&spriteBounds,
        mousePosition.x, mousePosition.y);
    if (event_menu.x >= spriteBounds.left && event_menu.x <= (spriteBounds.left
        + spriteBounds.width) && event_menu.y >= spriteBounds.top
        && event_menu.y <= (spriteBounds.top + spriteBounds.height)) {
        menu->isclick_on_seeting = true;
    }
}
