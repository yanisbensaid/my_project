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

// int player_mouve(struct player_mouve_s *player, sfVector2f *playerPosition)
// {
//     if (sfKeyboard_isKeyPressed(sfKeyZ))
//         player_mouve_z(player, playerPosition);
//     if (sfKeyboard_isKeyPressed(sfKeyS))
//         player_mouve_s(player, playerPosition);
//     if (sfKeyboard_isKeyPressed(sfKeyQ))
//         player_mouve_q(player, playerPosition);
//     if (sfKeyboard_isKeyPressed(sfKeyD)) {
//         player_mouve_d(player, playerPosition);
//     } else {
//         player->animationActive = false;
//     }
// }

// void player_mouve_z(struct player_mouve_s *player, sfVector2f *movement)
// {
//         player->animationActive = true;
//         player->playerTexture = sfTexture_createFromFile
//             ("asset/yinx_map/player_dont_mouve.png", NULL);
//         player->rect = (sfIntRect){0, 0, 16, 32};
//         sfSprite_setTexture(player->playerSprite, player->playerTexture,
//             sfTrue);
//         sfSprite_setTextureRect(player->playerSprite, player->rect);
//         (*movement).y -= PLAYER_SPEED;
// }

// void player_mouve_s(struct player_mouve_s *player, sfVector2f *movement)
// {
//         player->animationActive = true;
//         player->playerTexture = sfTexture_createFromFile
//             ("asset/yinx_map/sprite_pokemon_s.png", NULL);
//         player->rect = (sfIntRect){0, 0, 16, 32};
//         sfSprite_setTexture(player->playerSprite,
//             player->playerTexture, sfTrue);
//         sfSprite_setTextureRect(player->playerSprite, player->rect);
//         movement->y += PLAYER_SPEED;
// }

// void player_mouve_q(struct player_mouve_s *player, sfVector2f *movement)
// {
//         player->animationActive = true;
//         player->playerTexture = sfTexture_createFromFile
//             ("asset/yinx_map/pokemon.png", NULL);
//         player->rect = (sfIntRect){0, 0, 16, 32};
//         sfSprite_setTexture(player->playerSprite,
//             player->playerTexture, sfTrue);
//         sfSprite_setTextureRect(player->playerSprite, player->rect);
//         movement->x -= PLAYER_SPEED;
// }

// void player_mouve_d(struct player_mouve_s *player, sfVector2f *movement)
// {
//         player->animationActive = true;
//         player->playerTexture = sfTexture_createFromFile
//             ("asset/yinx_map/player.jpg", NULL);
//         player->rect = (sfIntRect){0, 0, 16, 32};
//         sfSprite_setTexture(player->playerSprite,
//             player->playerTexture, sfTrue);
//         sfSprite_setTextureRect(player->playerSprite, player->rect);
//         movement->x += PLAYER_SPEED;
// }
