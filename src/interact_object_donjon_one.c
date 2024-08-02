/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** interact_object_donjon_one
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include <string.h>
#include <math.h>

void detect_object_donjon_one(struct player_s *player,
    struct init_sprites_s *sprite)
{
    detect_key(player, sprite);
}

void interact_with_object_donjon_one(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu)
{
    if (sprite->key_detected == true && player->win_first_boss ==
        true && sprite->key_visible == true){
        sfRenderWindow_drawSprite(sprite->window,
            sprite->press_e_key_sprite, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE) && sprite->key_detected == true) {
            sprite->key_visible = false;
        }
    }
}
