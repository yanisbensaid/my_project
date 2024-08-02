/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-sofia.ben-khaled
** File description:
** create_sprite
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include <string.h>
#include "../struct/player.h"

static void create_sprite_three(struct init_sprites_s *sprite,
    struct menu_s *menu, struct player_s *player)
{
    create_bras_droit_button(sprite);
    create_bras_gauche_button(sprite);
    create_jambe_droit(sprite);
    create_jambe_gauche(sprite);
    create_tete_button(sprite);
    create_enemi_combat_sprite(sprite);
    create_enemi_sans_bras_sprire(sprite);
    create_sword(sprite);
}

static void create_sprite_four(struct init_sprites_s *sprite,
    struct menu_s *menu, struct player_s *player)
{
    init_damage(sprite);
    cross_sprite_inventory(sprite, menu);
    create_sword_in_inventory(sprite);
    init_pnj_two(sprite);
    init_interact_pnj_two(sprite, player);
    init_interact_draven(sprite, player);
    init_draven(sprite);
    init_interact_key(sprite, player);
    init_shield(sprite, player);
    create_shield_in_inventory(sprite);
    create_sprite_enemi_two(sprite, menu);
    init_end_game(sprite, menu);
}

static void create_sprite_follow(struct init_sprites_s *sprite,
    struct menu_s *menu, struct player_s *player)
{
    create_sprite_player(player, sprite);
    player_animation(player, sprite);
    create_sprite_player_q(player, sprite);
    player_animation_q(player, sprite);
    create_sprite_player_z(player, sprite);
    player_animation_z(player, sprite);
    create_sprite_player_d(player, sprite);
    player_animation_d(player, sprite);
    create_sprite_player_no_moove(player, sprite);
    save_session(sprite, menu);
    init_game_over(sprite, menu);
    create_inventory_sprite(sprite, menu);
    inventory_square_overlay(menu, sprite);
    create_sprite_enenmi(sprite, menu);
    init_donjon_one(sprite, menu);
    init_pnj(sprite);
    init_donjon_two(sprite, menu);
    init_interact_pnj(sprite, player);
    create_sprite_four(sprite, menu, player);
    sprite_player_combat_modif(sprite);
}

void create_sprite(struct init_sprites_s *sprite,
    struct menu_s *menu, struct player_s *player)
{
    overlay(menu, sprite);
    size_window(sprite, menu);
    create_sprite_menu(sprite, menu);
    create_sprite_adv(sprite, menu);
    create_sprite_map(sprite, menu);
    cross_sprite(sprite, menu);
    exit_sprite(sprite, menu);
    save_sprite(sprite, menu);
    sound_sprite_high(sprite, menu);
    sound_sprite_low(sprite, menu);
    follow_volume_barre_sprite(sprite, menu);
    volume_barre_sprite(sprite, menu);
    three_volume_barre_sprite(sprite, menu);
    create_sprite_follow(sprite, menu, player);
    init_life(sprite, menu, player);
    sprite_player_combat(sprite);
    fond_menu(sprite, menu, player);
    fond_menu_court(sprite);
    attack_button(sprite);
    create_sprite_three(sprite, menu, player);
}
