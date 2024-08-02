/*
** EPITECH PROJECT, 2024
** button drawer
** File description:
** rpg
*/

#include "../includes/my_rpg.h"

void draw_play_button(struct init_sprites_s *sprite, bool isOnPlayButton_play)
{
    if (isOnPlayButton_play == true) {
        sfRenderWindow_drawSprite(sprite->window,
            sprite->play_grey_sprite, NULL);
    } else {
        sfRenderWindow_drawSprite(sprite->window,
            sprite->play_white_sprite, NULL);
    }
}

void draw_exit_button(struct init_sprites_s *sprite, bool isOnPlayButton_exit)
{
    if (isOnPlayButton_exit == true) {
        sfRenderWindow_drawSprite(sprite->window,
            sprite->exit_white_sprite, NULL);
    } else {
        sfRenderWindow_drawSprite(sprite->window,
            sprite->exit_red_sprite, NULL);
    }
}
