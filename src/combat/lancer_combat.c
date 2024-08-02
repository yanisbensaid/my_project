/*
** EPITECH PROJECT, 2024
** lancer_combat
** File description:
** lancer_combat
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

static void draw_sprite_attack(struct init_sprites_s *sprite)
{
    sfRenderWindow_clear(sprite->window, sfBlack);
    draw_sprite_combat(sprite);
    handel_modif_sprite_enemi_first(sprite);
    sfRenderWindow_drawSprite(sprite->window,
        sprite->combat->enemi_combat_sprite, NULL);
}

static void close_window(struct init_sprites_s *sprite)
{
    if (sprite->combat->event_attack.type == sfEvtClosed)
        sfRenderWindow_close(sprite->window);
}

static void set_variable(struct init_sprites_s *sprite)
{
    sprite->combat->mousePosition =
    sfMouse_getPositionRenderWindow(sprite->window);
    sprite->combat->attack_button_bounds =
    sfSprite_getGlobalBounds(sprite->combat->attack_button_sprite);
}

void process_combat_click(struct init_sprites_s *sprite,
    sfEvent combat_event, struct player_s *player, struct menu_s *menu)
{
    static bool showSprites = false;

    while (sfRenderWindow_pollEvent(sprite->window,
        &sprite->combat->event_attack)) {
        close_window(sprite);
        if (sprite->combat->event_attack.type == sfEvtMouseButtonReleased &&
            sprite->combat->event_attack.mouseButton.button == sfMouseLeft) {
            set_variable(sprite);
            sprite->combat->mouseOverSprite =
            sfFloatRect_contains(&sprite->combat->attack_button_bounds,
            sprite->combat->mousePosition.x, sprite->combat->mousePosition.y);
            check_combat_part_click(sprite, showSprites, player, menu);
        }
    }
    draw_sprite_attack(sprite);
    if (sprite->combat->mouseOverSprite)
        showSprites = !showSprites;
    if (showSprites)
        attack_on(combat_event, sprite);
}

void check_combat_miss(struct init_sprites_s *sprite,
    struct menu_s *menu, struct player_s *player)
{
    if (sprite->combat->turn % 2 == 0) {
        sprite->combat->turn += 1;
        if (sprite->combat->enemi_turn == 1)
            sfSprite_setTexture(sprite->combat->player_combat_sprite,
                sprite->combat->player_sans_jambe_droite, sfTrue);
        if (sprite->combat->enemi_turn == 2)
            sfSprite_setTexture(sprite->combat->player_combat_sprite,
                sprite->combat->player_sans_bras_droit, sfTrue);
        if (sprite->combat->enemi_turn == 3)
            sfSprite_setTexture(sprite->combat->player_combat_sprite,
                sprite->combat->player_sans_bras_gauche, sfTrue);
        if (player->value_life_barre >= 600 && player->life_player <= 0){
            sfSprite_setTexture(sprite->combat->player_combat_sprite,
                sprite->combat->player_sans_jambe_gauche, sfTrue);
            printf("Game Over\n");
            menu->game = 4;
        }
    }
}

void lancer_nouvelle_scene(struct menu_s *menu,
    struct init_sprites_s *sprite, struct player_s *player)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(sprite->window);
    sfEvent combat_event;

    sprite->combat->defense_player = 10;
    sprite->combat->attack_enemi = 20;
    sprite->combat->mouseOverSprite = false;
    if (sprite->combat->turn % 2 == 1) {
        process_combat_click(sprite, combat_event, player, menu);
    }
    check_combat_miss(sprite, menu, player);
    change_barre_life(sprite, menu, player);
    win_first_monster(sprite, player, menu);
    sfRenderWindow_display(sprite->window);
    free(texture);
}

void update_game_state(struct menu_s *menu,
    struct player_s *player, struct init_sprites_s *sprite)
{
    if (is_colision(player->sprite_player_s, sprite->enemi_sprite)) {
        menu->game = 5;
    }
}

void update_game_state_two(struct menu_s *menu,
    struct player_s *player, struct init_sprites_s *sprite)
{
    if (is_colision(player->sprite_player_s, sprite->enemi_two_sprite)) {
        menu->game = 8;
    }
}
