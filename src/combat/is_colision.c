/*
** EPITECH PROJECT, 2024
** force_a_nous
** File description:
** is_colision
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

bool is_colision(sfSprite *sprite1, sfSprite *sprite2)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(sprite1);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(sprite2);

    return sfFloatRect_intersects(&rect1, &rect2, NULL);
}
