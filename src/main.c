/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

static void free_destroy(struct init_sprites_s *sprite, struct menu_s *menu,
    struct player_s *player, struct init_texture_s *texture)
{
    destroy(sprite, player);
    free(sprite);
    free(menu);
    free(player);
    free(texture);
}

void size_window(struct init_sprites_s *sprite, struct menu_s *menu)
{
    sprite->mode.width = 1920;
    sprite->mode.height = 1080;
    sprite->mode.bitsPerPixel = 32;
    sprite->window = sfRenderWindow_create(sprite->mode,
        "Darkened Souls", sfDefaultStyle, NULL);
    sound(sprite, menu);
    if (!sprite->window) {
        exit(EXIT_FAILURE);
    }
}

static void destroy_follow(struct init_sprites_s *sprite,
    struct player_s *player)
{
    sfTexture_destroy(player->texture_player_no);
    sfSprite_destroy(sprite->map_sprite);
    sfSprite_destroy(sprite->square_sprite);
    sfSprite_destroy(sprite->setting_black_sprite);
    sfSprite_destroy(sprite->setting_white_sprite);
    sfSprite_destroy(sprite->exit_red_sprite);
    sfSprite_destroy(sprite->exit_white_sprite);
    sfSprite_destroy(sprite->cross_black_sprite);
    sfSprite_destroy(sprite->cross_white_sprite);
    sfSprite_destroy(sprite->redexit_menu_sprite);
    sfSprite_destroy(sprite->whiteexit_menu_sprite);
    sfSprite_destroy(sprite->save_white_sprite);
    sfSprite_destroy(sprite->save_grey_sprite);
}

void destroy(struct init_sprites_s *sprite, struct player_s *player)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));

    sfRenderWindow_destroy(sprite->window);
    sfSprite_destroy(sprite->background);
    sfSprite_destroy(sprite->play_white_sprite);
    sfSprite_destroy(sprite->avertissment_sprite);
    sfSprite_destroy(player->sprite_player_s);
    sfClock_destroy(player->clock);
    sfTexture_destroy(player->texture_player_s);
    sfSprite_destroy(player->sprite_player_q);
    sfTexture_destroy(player->texture_player_q);
    sfSprite_destroy(player->sprite_player_z);
    sfTexture_destroy(player->texture_player_z);
    sfSprite_destroy(player->sprite_player_d);
    sfTexture_destroy(player->texture_player_d);
    sfSprite_destroy(player->sprite_player_no);
    destroy_follow(sprite, player);
}

static void enter_and_exit_donjon(struct menu_s *menu,
    struct init_sprites_s *sprite, struct player_s *player)
{
    sfEvent event;

    if (player->life_player == 120)
        enter_in_donjon_two(player, sprite, menu);
    enter_in_donjon(player, sprite, menu, event);
    exit_donjon_two(player, sprite, menu, event);
    exit_donjon_one(player, sprite, menu, event);
    if (player->state_boss_one == 0)
        update_game_state(menu, player, sprite);
    if (menu->game == 7 && player->state_boss_two == 0)
        update_game_state_two(menu, player, sprite);
}

static void gestion_scene(struct menu_s *menu, struct init_sprites_s *sprite,
    struct player_s *player)
{
    enter_and_exit_donjon(menu, sprite, player);
    if (menu->game == 0)
        windows_menu(menu, sprite);
    if (menu->game == 1)
        windows_adv(menu, sprite);
    if (menu->game == 3)
        windows_map(menu, sprite, player);
    if (menu->game == 4)
        game_over(menu, sprite, player);
    if (menu->game == 5)
        lancer_nouvelle_scene(menu, sprite, player);
    if (menu->game == 6)
        windows_donjon_one(menu, sprite, player);
    if (menu->game == 7)
        windows_donjon_two(menu, sprite, player);
    if (menu->game == 8)
        fight_donjon_two(menu, sprite, player);
    if (menu->game == 9)
        end_game(menu, sprite, player);
}

static void init_bool_main(struct init_sprites_s *sprite,
    struct menu_s *menu, struct player_s *player)
{
    sprite->shield_visible = true;
    sprite->key_visible = true;
    sprite->sword_visible = true;
    player->win_first_boss = false;
    player->win_second_boss = false;
    sprite->monster_one_visible = true;
    sprite->monster_two_visible = true;
    sprite->combat = malloc(sizeof(struct combat_s));
    sprite->combat->set_sprite_enemi = false;
    create_sprite(sprite, menu, player);
    menu->isclick_on_seeting = false;
    sprite->combat->turn = 1;
    sprite->combat->enemi_turn = 0;
    sprite->combat->defense_enemi = 80;
    sprite->combat->defense_enemi_two = 80;
}

void rpg(void)
{
    struct init_sprites_s *sprite = malloc(sizeof(struct init_sprites_s));
    struct menu_s *menu = malloc(sizeof(struct menu_s));
    struct player_s *player = malloc(sizeof(struct player_s));
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    struct combat_s *combat = malloc(sizeof(struct combat_s));

    init_bool_main(sprite, menu, player);
    while (sfRenderWindow_isOpen(sprite->window) && menu->game != 2) {
        gestion_scene(menu, sprite, player);
    }
    free_destroy(sprite, menu, player, texture);
}

int main(int ac, char **av)
{
    rpg();
    return 0;
}

    /*const char *filename = "asset/Amayyas_MAP/map_dungeon_yinx.tmx";
    extract_wall_values(filename);*/
