/*
** EPITECH PROJECT, 2024
** disp player
** File description:
** rpg
*/

#include "../includes/my_rpg.h"

void display_player_d(struct init_sprites_s *sprite,
    struct player_s *player)
{
    if ((sfKeyboard_isKeyPressed(sfKeyD) ||
    sfKeyboard_isKeyPressed(sfKeyRight)) && player->is_inMoove == false) {
        sfRenderWindow_drawSprite(sprite->window,
        player->sprite_player_d, NULL);
        player->is_inMoove = true;
    }
    if (player->is_inMoove == false){
        sfRenderWindow_drawSprite(sprite->window,
            player->sprite_player_no, NULL);
    }
}

void display_player_z(struct init_sprites_s *sprite, struct player_s *player)
{
    if ((sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyUp))
    && player->is_inMoove == false) {
        sfRenderWindow_drawSprite(sprite->window,
        player->sprite_player_z, NULL);
        player->is_inMoove = true;
    }
}

void display_player_q(struct init_sprites_s *sprite, struct player_s *player)
{
    if ((sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyLeft))
    && player->is_inMoove == false) {
        sfRenderWindow_drawSprite(sprite->window,
        player->sprite_player_q, NULL);
        player->is_inMoove = true;
    }
}

void display_player_s(struct init_sprites_s *sprite, struct player_s *player)
{
    if ((sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyDown))
    && player->is_inMoove == false) {
        sfRenderWindow_drawSprite(sprite->window,
        player->sprite_player_s, NULL);
        player->is_inMoove = true;
    }
}

void display_player_zqs(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu)
{
    player->is_inMoove = false;
    move_player(player, menu, sprite);
    display_player_z(sprite, player);
    display_player_q(sprite, player);
    display_player_s(sprite, player);
    display_player_d(sprite, player);
}
