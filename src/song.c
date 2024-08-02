/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** song
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

sfMusic* sound(struct init_sprites_s *sprite, struct menu_s *menu)
{
    sprite->volume = 25;
    sprite->music = sfMusic_createFromFile("song/sound.ogg");
    sfMusic_setLoop(sprite->music, sfTrue);
    sfMusic_play(sprite->music);
    sfMusic_setVolume(sprite->music, sprite->volume);
    return (sprite->music);
}
