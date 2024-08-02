/*
** EPITECH PROJECT, 2024
** inventory_clickon
** File description:
** rpg
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include <string.h>

void create_inventory_sprite(struct init_sprites_s *sprite,
    struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_setting = {20, 100};
    sfVector2f scale = {0.15, 0.15};

    texture->inventory_black_texture =
        sfTexture_createFromFile("asset/inventory_black.png", NULL);
    sprite->inventory_black_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->inventory_black_sprite,
        texture->inventory_black_texture, sfTrue);
    sfSprite_setPosition(sprite->inventory_black_sprite, pos_setting);
    sfSprite_setScale(sprite->inventory_black_sprite, scale);
    texture->inventory_white_texture =
        sfTexture_createFromFile("asset/inventory_white.png", NULL);
    sprite->inventory_white_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->inventory_white_sprite,
        texture->inventory_white_texture, sfTrue);
    sfSprite_setPosition(sprite->inventory_white_sprite, pos_setting);
    sfSprite_setScale(sprite->inventory_white_sprite, scale);
    free(texture);
}

void inventory_square_overlay(struct menu_s *menu,
    struct init_sprites_s *sprite)
{
    struct init_texture_s *texture =
        malloc(sizeof(struct init_texture_s));
    sfVector2f pose_square = {550, 200};
    sfVector2f scale = {0.8, 0.8};

    texture->square_texture_inventory =
        sfTexture_createFromFile("asset/inventory.png", NULL);
    sprite->square_sprite_inventory = sfSprite_create();
    sfSprite_setTexture(sprite->square_sprite_inventory,
        texture->square_texture_inventory, sfTrue);
    sfSprite_setPosition(sprite->square_sprite_inventory, pose_square);
    sfSprite_setScale(sprite->square_sprite_inventory, scale);
}

void click_on_inventory(struct menu_s *menu, sfMouseButtonEvent event_menu,
    struct init_sprites_s *sprite)
{
    sfVector2i mousePosition;
    sfFloatRect spriteBounds;
    sfBool mouseOverSprite;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(sprite->window);

    menu->window_menu = sprite->window;
    mousePosition = sfMouse_getPositionRenderWindow(menu->window_menu);
    spriteBounds = sfSprite_getGlobalBounds(sprite->inventory_white_sprite);
    if (sfFloatRect_contains(&spriteBounds, mouse_pos.x, mouse_pos.y)) {
        menu->isclick_on_inventory = true;
    }
}

void display_inventory_follow(struct menu_s *menu,
    struct init_sprites_s *sprite, struct player_s *player)
{
    if (player->life_player == 120 && menu->isclick_on_inventory == true)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->shield_sprite_inv, NULL);
    if (player->life_player == 120)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->shield_text_sprite, NULL);
}

void display_inventory(struct menu_s *menu, struct init_sprites_s *sprite,
    struct player_s *player)
{
    display_inventory_follow(menu, sprite, player);
    if (player->attack_player == 20)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->ten_damage_sprite, NULL);
    if (player->attack_player == 20 && menu->isclick_on_inventory == true)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->sword_sprite_inv, NULL);
    if (menu->isclick_on_inventory == true)
        display_cross_inventory(menu, sprite);
    if (menu->isclick_on_inventory == true){
        sfRenderWindow_drawSprite(sprite->window,
            sprite->square_sprite_inventory, NULL);
    }
    if (menu->isOnPlayButton_inventory) {
        sfRenderWindow_drawSprite(sprite->window,
            sprite->inventory_white_sprite, NULL);
    } else
        sfRenderWindow_drawSprite(sprite->window,
            sprite->inventory_black_sprite, NULL);
}
