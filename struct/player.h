/*
** EPITECH PROJECT, 2024
** pull
** File description:
** player
*/

#pragma once
#include "../includes/my_rpg.h"

typedef struct player_s {
    float player_x;
    float player_y;
    sfClock *clock;
    sfTime elapsed_time;
    float elapsed_seconds;
    sfVector2f playerPosition;
    sfTexture *texture_player_s;
    sfSprite *sprite_player_s;
    sfIntRect rect;
    sfVector2u window_size;
    sfTexture *texture_player_q;
    sfSprite *sprite_player_q;
    sfClock *clock_q;
    sfTime elapsed_time_q;
    float elapsed_seconds_q;
    sfIntRect rect_q;
    sfTexture *texture_player_z;
    sfSprite *sprite_player_z;
    sfClock *clock_z;
    sfTime elapsed_time_z;
    float elapsed_seconds_z;
    sfIntRect rect_z;
    sfTexture *texture_player_d;
    sfSprite *sprite_player_d;
    sfClock *clock_d;
    sfTime elapsed_time_d;
    float elapsed_seconds_d;
    sfIntRect rect_d;
    sfTexture *texture_player_no;
    sfSprite *sprite_player_no;
    bool is_inMoove;
    float mapWidth;
    float mapHeight;
    float playerX;
    float playerY;
    float windowWidth;
    float windowHeight;
    int player_hp;
    int player_max_hp;
    int xp;
    int xp_max;
    int player_lvl;
    int player_atk;
    int player_def;
    float life_player;
    float barre;
    float x_value;
    float y_value;
    float xp_player;
    float value_life_barre;
    bool pos_initialized;
    float distanceLeft;
    float distanceRight;
    float distanceTop;
    float distanceBottom;
    float viewLeft;
    float viewTop;
    float viewRight;
    float viewBottom;
    float viewWidth;
    float viewHeight;
    float attack_player;
    bool win_first_boss;
    bool win_second_boss;
    float state_boss_one;
    float state_boss_two;
} player_t;
