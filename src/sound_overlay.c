/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** sound
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

void sound_sprite_low(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_save = {740, 480};
    sfVector2f scale = {1.0, 1.0};

    texture->low_sound_grey_texture =
        sfTexture_createFromFile("asset/button_low_grey.png", NULL);
    sprite->low_sound_grey_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->low_sound_grey_sprite,
        texture->low_sound_grey_texture, sfTrue);
    sfSprite_setPosition(sprite->low_sound_grey_sprite, pos_save);
    sfSprite_setScale(sprite->low_sound_grey_sprite, scale);
    texture->low_sound_white_texture =
        sfTexture_createFromFile("asset/button_low_white.png", NULL);
    sprite->low_sound_white_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->low_sound_white_sprite,
        texture->low_sound_white_texture, sfTrue);
    sfSprite_setPosition(sprite->low_sound_white_sprite, pos_save);
    sfSprite_setScale(sprite->low_sound_white_sprite, scale);
}

void click_on_low_sound(struct menu_s *menu, sfMouseButtonEvent event_menu,
    struct init_sprites_s *sprite)
{
    sfVector2i mousePosition;
    sfFloatRect spriteBounds;
    sfBool mouseOverSprite;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(sprite->window);

    menu->window_menu = sprite->window;
    mousePosition = sfMouse_getPositionRenderWindow(menu->window_menu);
    spriteBounds = sfSprite_getGlobalBounds(sprite->low_sound_white_sprite);
    if (sfFloatRect_contains(&spriteBounds, mouse_pos.x, mouse_pos.y)) {
        sprite->volume -= 25;
        if (sprite->volume < 0)
            sprite->volume = 0;
        sfMusic_setVolume(sprite->music, sprite->volume);
    }
}

void sound_sprite_high(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_save = {1110, 480};
    sfVector2f scale = {1.0, 1.0};

    texture->high_sound_grey_texture =
        sfTexture_createFromFile("asset/button_high_grey.png", NULL);
    sprite->high_sound_grey_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->high_sound_grey_sprite,
        texture->high_sound_grey_texture, sfTrue);
    sfSprite_setPosition(sprite->high_sound_grey_sprite, pos_save);
    sfSprite_setScale(sprite->high_sound_grey_sprite, scale);
    texture->high_sound_white_texture =
        sfTexture_createFromFile("asset/button_high_white.png", NULL);
    sprite->high_sound_white_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->high_sound_white_sprite,
        texture->high_sound_white_texture, sfTrue);
    sfSprite_setPosition(sprite->high_sound_white_sprite, pos_save);
    sfSprite_setScale(sprite->high_sound_white_sprite, scale);
}

void click_on_high_sound(struct menu_s *menu, sfMouseButtonEvent event_menu,
    struct init_sprites_s *sprite)
{
    sfVector2i mousePosition;
    sfFloatRect spriteBounds;
    sfBool mouseOverSprite;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(sprite->window);

    menu->window_menu = sprite->window;
    mousePosition = sfMouse_getPositionRenderWindow(menu->window_menu);
    spriteBounds = sfSprite_getGlobalBounds(sprite->high_sound_white_sprite);
    if (sfFloatRect_contains(&spriteBounds, mouse_pos.x, mouse_pos.y)) {
        sprite->volume += 25;
        if (sprite->volume > 100)
            sprite->volume = 100;
        sfMusic_setVolume(sprite->music, sprite->volume);
    }
}
