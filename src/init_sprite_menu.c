/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** init_sprite_menu
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include <string.h>

void button_menu_follow(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_exit = {800, 650};

    texture->exit_white_texture =
        sfTexture_createFromFile("asset/button_exit_grey.png", NULL);
    sprite->exit_white_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->exit_white_sprite,
        texture->exit_white_texture, sfTrue);
    sfSprite_setPosition(sprite->exit_white_sprite, pos_exit);
    texture->exit_red_texture =
        sfTexture_createFromFile("asset/button_exit_white.png", NULL);
    sprite->exit_red_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->exit_red_sprite,
        texture->exit_red_texture, sfTrue);
    sfSprite_setPosition(sprite->exit_red_sprite, pos_exit);
}

void create_button_menu(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_play_black = {800, 500};
    sfVector2f pos_play = {800, 500};

    menu->game = 0;
    texture->play_grey_texture =
        sfTexture_createFromFile("asset/play_button_grey.png", NULL);
    sprite->play_grey_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->play_grey_sprite,
        texture->play_grey_texture, sfTrue);
    sfSprite_setPosition(sprite->play_grey_sprite,
        pos_play_black);
    texture->play_white_texture =
        sfTexture_createFromFile("asset/play_button_white.png", NULL);
    sprite->play_white_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->play_white_sprite,
        texture->play_white_texture, sfTrue);
    sfSprite_setPosition(sprite->play_white_sprite, pos_play);
    button_menu_follow(sprite, menu);
}

void create_sprite_menu(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f scale = {1.0, 1.0};

    create_button_menu(sprite, menu);
    texture->background = sfTexture_createFromFile
    ("asset/background.jpeg", NULL);
    sprite->background = sfSprite_create();
    sfSprite_setTexture(sprite->background, texture->background, sfTrue);
    sfSprite_setScale(sprite->background, scale);
    free(texture);
}

void display_menu(struct menu_s *menu_s, struct init_sprites_s *sprite,
    bool isOnPlayButton_play, bool isOnPlayButton_exit)
{
    sfVector2u windowSize = sfRenderWindow_getSize(sprite->window);
    sfVector2f scale = calculate_scale(sprite->background, windowSize);
    sfVector2f pos_exit = calculate_exit_position
    (sprite->exit_red_sprite, windowSize);
    sfVector2f pos_play = calculate_play_position
    (sprite->play_white_sprite, windowSize);

    sfSprite_setScale(sprite->background, scale);
    sfRenderWindow_clear(sprite->window, sfBlack);
    sfRenderWindow_drawSprite(sprite->window, sprite->background, NULL);
    set_sprite_positions(sprite, pos_play, pos_exit);
    draw_play_button(sprite, isOnPlayButton_play);
    draw_exit_button(sprite, isOnPlayButton_exit);
    sfRenderWindow_display(sprite->window);
}

void set_sprite_positions(struct init_sprites_s *sprite,
    sfVector2f pos_play, sfVector2f pos_exit)
{
    sfSprite_setPosition(sprite->play_white_sprite, pos_play);
    sfSprite_setPosition(sprite->play_grey_sprite, pos_play);
    sfSprite_setPosition(sprite->exit_red_sprite, pos_exit);
    sfSprite_setPosition(sprite->exit_white_sprite, pos_exit);
}
