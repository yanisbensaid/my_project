/*
** EPITECH PROJECT, 2023
** structure
** File description:
** menu.h
*/

#pragma once
#include "../includes/my_rpg.h"

typedef struct menu_s {
    int game;
    sfVideoMode mode_menu;
    sfRenderWindow *window_menu;
    sfBool isclick_on_seeting;
    sfBool isclick_on_inventory;
    bool isOnPlayButton_setting;
    bool isOnPlayButton_inventory;
    bool inventory_open;
    bool isOnPlayButton_cross;
    bool isOnPlayButton_exit;
    bool isOnPlayButton_save;
    bool isOnPlayButton_sound_high;
    bool isOnPlayButton_sound_low;
    bool isOnPlayButton_cross_inv;
    float mapWidth;
    float mapHeight;
    float playerX;
    float playerY;
    float windowWidth;
    float windowHeight;
    int num_items;
    char name[50];
    char description[100];
    int quantity;
    bool position_initialized;
    sfTime elapsed;
    float seconds;
    sfClock* clock;
    sfIntRect rect;
    float positionx;
    float positiony;
    sfVector2f pos_enemi;
    sfBool mouse_over_bras_gauche;
    sfBool mouse_over_bras_droit;
} menu_t;


struct tile_s {
    int gid;
};

struct layer_s {
    char *name;
    struct tile_s *tiles;
    int width;
    int height;
};

struct map_s {
    struct layer_s *layers;
    int layer_count;
    int width;
    int height;
    int tile_width;
    int tile_height;
};
