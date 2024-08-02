/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** interact_with_object
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

void detect_object(struct player_s *player, struct init_sprites_s *sprite)
{
    detect_player(player, sprite);
    detect_sword(player, sprite);
    detect_pnj(player, sprite);
    detect_draven(player, sprite);
    detect_shield(player, sprite);
}

static void interact_with_object_follow(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu)
{
    if (sprite->player_detected == true)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->press_e_sprite, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE) &&
            sprite->player_detected == true){
            sfRenderWindow_drawSprite(sprite->window,
                sprite->interact_pnj_sprite, NULL);
        }
    if (sprite->eloi_detected == true)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->press_e_pnj_two, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE) &&
            sprite->eloi_detected == true){
            sfRenderWindow_drawSprite(sprite->window,
                sprite->interact_eloi_sprite, NULL);
        }
}

static void interact_with_draven(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu)
{
    if (sprite->draven_detected == true)
    sfRenderWindow_drawSprite(sprite->window,
        sprite->press_e_draven_sprite, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyE) &&
        sprite->draven_detected == true && player->state_boss_one == 0){
        sfRenderWindow_drawSprite(sprite->window,
            sprite->interact_draven_sprite, NULL);
    }
    if (sfKeyboard_isKeyPressed(sfKeyE) &&
        sprite->draven_detected == true && player->state_boss_one == 1){
        sfRenderWindow_drawSprite(sprite->window,
            sprite->interact_draven_two_sprite, NULL);
    }
}

static void interact_with_shield(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu)
{
    if (sprite->shield_detected == true && sprite->shield_visible == true &&
        sprite->key_visible == false)
        sfRenderWindow_drawSprite(sprite->window,
            sprite->press_e_shield_sprite, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyE) &&
        sprite->shield_detected == true){
        sprite->shield_visible = false;
    }
}

void interact_with_object(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu)
{
    if (sprite->sword_detected == true && sprite->sword_visible == true
        && player->attack_player != 20){
        sfRenderWindow_drawSprite(sprite->window,
            sprite->press_sword_sprite, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE) &&
            sprite->sword_detected == true) {
            sprite->sword_visible = false;
        }
    }
    interact_with_draven(sprite, player, menu);
    interact_with_object_follow(sprite, player, menu);
    interact_with_shield(sprite, player, menu);
}
