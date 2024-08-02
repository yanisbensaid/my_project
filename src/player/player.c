/*
** EPITECH PROJECT, 2024
** player
** File description:
** player
*/

// #include <SFML/Graphics.h>
// #include <SFML/Window.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "../../includes/my_rpg.h"

// void draw_player(sfRenderWindow *window, sfSprite *playerSprite)
// {
//     sfRenderWindow_drawSprite(window, playerSprite, NULL);
// }

// void set_player(struct player_mouve_s *player, sfVector2f playerPosition)
// {
//     player->playerTexture = sfTexture_createFromFile
//         ("asset/yinx_map/player_dont_mouve.png", NULL);
//     player->mapTexture = sfTexture_createFromFile
//         ("asset/yinx_map/Yinx.JPG", NULL);
//     player->mapSprite = sfSprite_create();
//     sfSprite_setTexture(player->mapSprite,
//         player->mapTexture, sfTrue);
//     player->playerSprite = sfSprite_create();
//     sfSprite_setTexture(player->playerSprite,
//         player->playerTexture, sfTrue);
//     sfSprite_setPosition(player->playerSprite, playerPosition);
//     sfSprite_setTextureRect(player->playerSprite, player->rect);
// }

// void destroy_player(struct player_mouve_s *player)
// {
//     sfSprite_destroy(player->mapSprite);
//     sfSprite_destroy(player->playerSprite);
//     sfTexture_destroy(player->mapTexture);
//     sfTexture_destroy(player->playerTexture);
//     sfRenderWindow_destroy(player->window);
//     free(player);
// }

// static void cond_close(struct player_mouve_s *player)
// {
//     if (player->event.type == sfEvtClosed)
//         sfRenderWindow_close(player->window);
// }

// void player_cond(struct player_mouve_s *player,
//     sfVector2f *playerPosition, sfVideoMode mode)
// {
//     player->elapsed = sfClock_getElapsedTime(player->clock);
//     player->deltaTime = sfTime_asSeconds(player->elapsed);
//     while (sfRenderWindow_pollEvent(player->window, &player->event)) {
//         cond_close(player);
//     }
//     player_mouve(player, playerPosition);
//     player_deplacement(*playerPosition, mode, player);
//     animation_player(player);
//     sfRenderWindow_clear(player->window, sfBlack);
//     sfRenderWindow_drawSprite(player->window, player->mapSprite, NULL);
//     draw_player(player->window, player->playerSprite);
//     sfRenderWindow_display(player->window);
// }

// int main(int ac, char **av)
// {
//     sfVideoMode mode = {1920, 1080, 32};
//     sfVector2f playerPosition = {100.0f, 100.0f};
//     sfVector2f movement = {0.0f, 0.0f};
//     struct player_mouve_s *player = malloc(sizeof(struct player_mouve_s));

//     player->clock = sfClock_create();
//     player->lapsedTime = 0.0f;
//     player->rect = (sfIntRect){0, 0, 16, 32};
//     player->animationActive = false;
//     player->window = sfRenderWindow_create(mode,
//         "My RPG", sfDefaultStyle, NULL);
//     set_player(player, playerPosition);
//     while (sfRenderWindow_isOpen(player->window)) {
//         player_cond(player, &playerPosition, mode);
//     }
//     return 0;
// }
