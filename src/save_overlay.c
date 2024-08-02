/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** three_overlay
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

void save_sprite(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_save = {735, 550};
    sfVector2f scale = {1.0, 1.0};

    texture->save_white_texture =
        sfTexture_createFromFile("asset/button_save_white.png", NULL);
    sprite->save_white_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->save_white_sprite,
        texture->save_white_texture, sfTrue);
    sfSprite_setPosition(sprite->save_white_sprite, pos_save);
    sfSprite_setScale(sprite->save_white_sprite, scale);
    texture->save_grey_texture =
        sfTexture_createFromFile("asset/button_save_grey.png", NULL);
    sprite->save_grey_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->save_grey_sprite,
        texture->save_grey_texture, sfTrue);
    sfSprite_setPosition(sprite->save_grey_sprite, pos_save);
    sfSprite_setScale(sprite->save_grey_sprite, scale);
}

void save_session(struct init_sprites_s *sprite, struct menu_s *menu)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f pos_save = {20, 20};
    sfVector2f scale = {1.0, 1.0};

    texture->save_session_texture =
        sfTexture_createFromFile("asset/session_enregistre.png", NULL);
    sprite->save_session_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->save_session_sprite,
        texture->save_session_texture, sfTrue);
    sfSprite_setPosition(sprite->save_session_sprite, pos_save);
    sfSprite_setScale(sprite->save_session_sprite, scale);
}

void save_player_position(struct player_s *player)
{
    FILE *file = fopen("src/info.txt", "w");

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    fprintf(file, "position.x : %.0f\n", player->x_value);
    fprintf(file, "position.y : %.0f\n", player->y_value);
    fprintf(file, "life_player : %f\n", player->life_player);
    fprintf(file, "xp_player : %f\n", player->xp_player);
    fprintf(file, "value_life_barre : %f\n", player->value_life_barre);
    fprintf(file, "attack_player : %f\n", player->attack_player);
    fprintf(file, "state_first_boss : %f\n", player->state_boss_one);
    fprintf(file, "state_second_boss : %f\n", player->state_boss_two);
    fclose(file);
}

void click_on_save(struct menu_s *menu, sfEvent event_menu,
    struct init_sprites_s *sprite, struct player_s *player)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(sprite->window);
    sfFloatRect spriteBounds =
        sfSprite_getGlobalBounds(sprite->save_white_sprite);

    if (event_menu.type == sfEvtMouseButtonPressed &&
        event_menu.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&spriteBounds, mouse_pos.x, mouse_pos.y)) {
        player->y_value = player->playerPosition.y;
        save_player_position(player);
    }
}
