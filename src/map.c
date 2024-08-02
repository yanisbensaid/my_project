/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** map
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>
#include <math.h>

void create_sprite_map(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f scale = {3.0, 3.0};

    sprite->map_pos_x = 0;
    sprite->pos_map = (sfVector2f){sprite->map_pos_x, 0};
    create_setting_sprite(sprite, menu);
    texture->map_texture =
        sfTexture_createFromFile("asset/map_yanis.png", NULL);
    sprite->map_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->map_sprite,
        texture->map_texture, sfTrue);
    sfSprite_setScale(sprite->map_sprite, scale);
    sfSprite_setPosition(sprite->map_sprite, sprite->pos_map);
    free(texture);
}

static void init_view_follow(struct menu_s *menu,
    struct init_sprites_s *sprite, struct player_s *player)
{
    menu->mapWidth = sfSprite_getGlobalBounds(sprite->map_sprite).width;
    menu->mapHeight = sfSprite_getGlobalBounds(sprite->map_sprite).height;
    menu->playerX = player->playerPosition.x;
    menu->playerY = player->playerPosition.y;
    menu->windowWidth = sfRenderWindow_getSize(sprite->window).x;
    menu->windowHeight = sfRenderWindow_getSize(sprite->window).y;
}

static void init_view_follow_two(struct player_s *player, struct menu_s *menu)
{
    player->distanceLeft = menu->playerX;
    player->distanceRight = menu->mapWidth - menu->playerX;
    player->distanceTop = menu->playerY;
    player->distanceBottom = menu->mapHeight - menu->playerY;
    player->viewLeft = fmaxf(menu->playerX - menu->windowWidth / 2, 0);
    player->viewTop = fmaxf(menu->playerY - menu->windowHeight / 2, 0);
    player->viewRight = fmaxf(menu->playerX + menu->windowWidth / 2, 0);
    player->viewBottom = fmaxf(menu->playerY + menu->windowHeight / 2, 0);
    player->viewWidth = fminf(menu->windowWidth,
        menu->mapWidth - player->viewLeft);
    player->viewHeight = fminf(menu->windowHeight,
        menu->mapHeight - player->viewTop);
}

static void init_wiew(struct menu_s *menu,
    struct init_sprites_s *sprite, struct player_s *player)
{
    sfView *view = sfView_createFromRect((sfFloatRect){player->viewLeft,
        player->viewTop, player->viewWidth, player->viewHeight});

    init_view_follow(menu, sprite, player);
    sfRenderWindow_setView(sprite->window, view);
    sfRenderWindow_clear(sprite->window, sfBlack);
    sfRenderWindow_drawSprite(sprite->window, sprite->map_sprite, NULL);
    sfRenderWindow_drawSprite(sprite->window, sprite->pnj_one_sprite, NULL);
    sfRenderWindow_drawSprite(sprite->window, sprite->pnj_two_sprite, NULL);
    sfRenderWindow_drawSprite(sprite->window, sprite->draven_sprite, NULL);
    if (sprite->shield_visible == true && sprite->key_visible == false)
        sfRenderWindow_drawSprite(sprite->window, sprite->shield_sprite, NULL);
    interact_with_object(sprite, player, menu);
    display_player_zqs(sprite, player, menu);
    if (sprite->sword_visible == true && player->attack_player != 20)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->epee_sprite, NULL);
    sfRenderWindow_setView(sprite->window,
    sfRenderWindow_getDefaultView(sprite->window));
}

void create_sprite_enenmi(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_enemi = {menu->positionx, menu->positiony};

    if (menu->game == 6) {
        menu->positionx = 500;
        menu->positiony = 150;
    }
    texture->enemi_texture =
        sfTexture_createFromFile("asset/enemi/enemi.png", NULL);
    sprite->enemi_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->enemi_sprite,
        texture->enemi_texture, sfTrue);
    sfSprite_setPosition(sprite->enemi_sprite, pos_enemi);
    free(texture);
}

void create_sprite_enemi_two(struct init_sprites_s *sprite,
    struct menu_s *menu)
{
        struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_enemi = {menu->positionx, menu->positiony};

    if (menu->game == 7) {
        menu->positionx = 1050;
        menu->positiony = 100;
    }
    texture->enemi_two_texture =
        sfTexture_createFromFile("asset/enemi/enemi.png", NULL);
    sprite->enemi_two_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->enemi_two_sprite,
        texture->enemi_two_texture, sfTrue);
    sfSprite_setPosition(sprite->enemi_two_sprite, pos_enemi);
    free(texture);
}

void display_map(struct menu_s *menu, struct init_sprites_s *sprite,
    struct player_s *player, sfEvent event)
{
    init_view_follow_two(player, menu);
    init_wiew(menu, sprite, player);
    change_barre_life(sprite, menu, player);
    click_on_save(menu, event, sprite, player);
    display_inventory(menu, sprite, player);
    if (menu->isOnPlayButton_setting) {
        sfRenderWindow_drawSprite(sprite->window,
            sprite->setting_white_sprite, NULL);
    } else
        sfRenderWindow_drawSprite(sprite->window,
            sprite->setting_black_sprite, NULL);
    if (menu->isclick_on_seeting)
        display_overlay(menu, sprite);
    sfRenderWindow_display(sprite->window);
}

static void follow_hover_on_menu(struct menu_s *menu,
    struct init_sprites_s *sprite)
{
    sfEvent event_menu;
    sfFloatRect spriteBounds_save =
        sfSprite_getGlobalBounds(sprite->save_white_sprite);
    sfFloatRect spriteBounds_sound_h =
        sfSprite_getGlobalBounds(sprite->high_sound_white_sprite);
    sfFloatRect spriteBounds_sound_l =
        sfSprite_getGlobalBounds(sprite->low_sound_white_sprite);
    sfFloatRect spriteBounds_inv =
        sfSprite_getGlobalBounds(sprite->cross_black__inv_sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(sprite->window);

    if (sfFloatRect_contains(&spriteBounds_inv, mouse_pos.x, mouse_pos.y))
        menu->isOnPlayButton_cross_inv = true;
    if (sfFloatRect_contains(&spriteBounds_save, mouse_pos.x, mouse_pos.y))
        menu->isOnPlayButton_save = true;
    if (sfFloatRect_contains(&spriteBounds_sound_h, mouse_pos.x, mouse_pos.y))
        menu->isOnPlayButton_sound_high = true;
    if (sfFloatRect_contains(&spriteBounds_sound_l, mouse_pos.x, mouse_pos.y))
        menu->isOnPlayButton_sound_low = true;
}

void hover_click_on_menu(struct menu_s *menu, struct init_sprites_s *sprite)
{
    sfEvent event_menu;
    sfFloatRect spriteBounds_setting =
        sfSprite_getGlobalBounds(sprite->setting_white_sprite);
    sfFloatRect spriteBounds_cross =
        sfSprite_getGlobalBounds(sprite->cross_black_sprite);
    sfFloatRect spriteBounds_exit =
        sfSprite_getGlobalBounds(sprite->whiteexit_menu_sprite);
    sfFloatRect spriteBounds_inventor =
        sfSprite_getGlobalBounds(sprite->inventory_black_sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(sprite->window);

    if (sfFloatRect_contains(&spriteBounds_inventor, mouse_pos.x, mouse_pos.y))
        menu->isOnPlayButton_inventory = true;
    if (sfFloatRect_contains(&spriteBounds_setting, mouse_pos.x, mouse_pos.y))
        menu->isOnPlayButton_setting = true;
    if (sfFloatRect_contains(&spriteBounds_cross, mouse_pos.x, mouse_pos.y))
        menu->isOnPlayButton_cross = true;
    if (sfFloatRect_contains(&spriteBounds_exit, mouse_pos.x, mouse_pos.y))
        menu->isOnPlayButton_exit = true;
    follow_hover_on_menu(menu, sprite);
}
