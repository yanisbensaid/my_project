/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** init_parameter_fight
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

void init_parameter_fight(struct init_sprites_s *sprite,
    struct player_s *player)
{
    if (sprite->sword_visible == false) {
        player->attack_player = 20;
    }
    if (sprite->shield_visible == false) {
        player->life_player = 120;
        player->value_life_barre = 0;
    }
}

void win_first_monster(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu)
{
    if (player->win_first_boss == true) {
    menu->game = 6;
    menu->position_initialized = false;
    sprite->monster_one_visible = false;
    }
}

void turn_fight(struct init_sprites_s *sprite, struct player_s *player)
{
    int chance = rand() % 2;

    if (chance == 1) {
        sprite->combat->turn += 1;
        sprite->combat->enemi_turn += 1;
        player->life_player -= 20;
        player->value_life_barre += 120;
    }
}

static void inflige_damage_monster_one(struct init_sprites_s *sprite,
    struct player_s *player)
{
    sprite->combat->defense_enemi -= player->attack_player;
    if (sprite->combat->defense_enemi <= 0)
        player->win_first_boss = true;
        player->state_boss_one = 1;
}

static void inflige_damage_monster_two(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu)
{
    sprite->combat->defense_enemi_two -= player->attack_player;
    if (sprite->combat->defense_enemi_two <= 0) {
        player->win_second_boss = true;
        player->state_boss_two = 1;
        menu->game = 9;
    }
}

void inflige_damage_monter(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu)
{
    if (menu->game == 5)
        inflige_damage_monster_one(sprite, player);
    if (menu->game == 8)
        inflige_damage_monster_two(sprite, player, menu);
}
