/*
** EPITECH PROJECT, 2024
** player_mouve
** File description:
** player_mouve
*/

// #include <SFML/Graphics.h>
// #include <SFML/Window.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "../../includes/my_rpg.h"

// void animation_player(struct player_mouve_s *player)
// {
//     player->lapsedTime += player->deltaTime;
//     if (player->lapsedTime > ANIMATION_DURATION) {
//         player->lapsedTime = 0;
//         player->rect.left += 16;
//         if (player->rect.left >= 70) {
//             player->rect.left = 0;
//         }
//         sfSprite_setTextureRect(player->playerSprite,
//             player->rect);
//         sfClock_restart(player->clock);
//     }
// }

// void player_deplacement(sfVector2f playerPosition,
//     sfVideoMode mode, struct player_mouve_s *player)
// {
//     sfSprite_setPosition(player->playerSprite, playerPosition);
//     if (playerPosition.x < 0)
//         playerPosition.x = 0;
//     if (playerPosition.y < 0)
//         playerPosition.y = 0;
//     if (playerPosition.x > mode.width)
//         playerPosition.x = mode.width;
//     if (playerPosition.y > mode.height)
//         playerPosition.y = mode.height;
// }
