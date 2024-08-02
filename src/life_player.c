/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** life_player
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

void init_life(struct init_sprites_s *sprite,
    struct menu_s *menu, struct player_s *player)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_save = {1450, 850};
    sfVector2f scale = {1.0, 1.0};

    texture->life_barre_texture =
        sfTexture_createFromFile("asset/player/barre_life.png", NULL);
    sprite->life_barre_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->life_barre_sprite,
        texture->life_barre_texture, sfTrue);
    sfSprite_setPosition(sprite->life_barre_sprite, pos_save);
    sfSprite_setScale(sprite->life_barre_sprite, scale);
}

void update_barre_life(struct init_sprites_s *sprite,
    struct menu_s *menu, struct player_s *player)
{
    sfIntRect rect = {0, player->value_life_barre, 355, 110};

    sfSprite_setTextureRect(sprite->life_barre_sprite, rect);
    sfRenderWindow_drawSprite(sprite->window, sprite->life_barre_sprite, NULL);
}

void update_game_over_scene(struct menu_s *menu, struct player_s *player)
{
    if (player->value_life_barre >= 600 && player->life_player <= 0)
    menu->game = 4;
}

void change_barre_life(struct init_sprites_s *sprite,
    struct menu_s *menu, struct player_s *player)
{
    static sfClock* clock = NULL;
    sfTime elapsed;

    update_barre_life(sprite, menu, player);
    if (!clock)
        clock = sfClock_create();
    if (clock) {
        elapsed = sfClock_getElapsedTime(clock);
        menu->seconds = sfTime_asSeconds(elapsed);
    } else
        menu->seconds = 0.0f;
    if (menu->seconds >= 300) {
        while (player->value_life_barre < 600 && player->life_player > 0){
            player->life_player -= 20;
            player->value_life_barre += 120;
            break;
        }
        sfClock_restart(clock);
    }
    update_game_over_scene(menu, player);
}
