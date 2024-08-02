/*
** EPITECH PROJECT, 2024
** calculate pos
** File description:
** rpg
*/

#include "../includes/my_rpg.h"

sfVector2f calculate_scale(sfSprite *background, sfVector2u windowSize)
{
    sfVector2f scale = {
        (float)windowSize.x / sfTexture_getSize
        (sfSprite_getTexture(background)).x,
        (float)windowSize.y / sfTexture_getSize
        (sfSprite_getTexture(background)).y
    };

    return scale;
}

sfVector2f calculate_exit_position
(sfSprite *exit_sprite, sfVector2u windowSize)
{
    sfVector2f pos_exit = {
        (float)windowSize.x / 2 - sfSprite_getGlobalBounds
        (exit_sprite).width / 2,
        (float)windowSize.y / 2 + sfSprite_getGlobalBounds
        (exit_sprite).height / 2 + 20
    };

    return pos_exit;
}

sfVector2f calculate_play_position
(sfSprite *play_sprite, sfVector2u windowSize)
{
    sfVector2f pos_play = {
        (float)windowSize.x / 2 - sfSprite_getGlobalBounds
        (play_sprite).width / 2,
        (float)windowSize.y / 2 - sfSprite_getGlobalBounds
        (play_sprite).height / 2
    };

    return pos_play;
}
