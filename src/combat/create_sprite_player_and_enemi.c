/*
** EPITECH PROJECT, 2024
** force_a_nous
** File description:
** create_sprite_player_and_enemi
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

void sprite_player_combat_modif(struct init_sprites_s *sprite)
{
    sprite->combat->player_sans_jambe_droite = sfTexture_createFromFile(
        "asset/player/player_combat_sans_jambe_droite.png", NULL);
    sprite->combat->player_sans_jambe_gauche = sfTexture_createFromFile(
        "asset/player/player_tronc.png", NULL);
    sprite->combat->player_sans_bras_droit = sfTexture_createFromFile(
        "asset/player/player_sans_cote_droit.png", NULL);
    sprite->combat->player_sans_bras_gauche = sfTexture_createFromFile(
        "asset/player/player_sans_jambe_et sans_bras_droit.png", NULL);
}

int sprite_player_combat(struct init_sprites_s *sprite)
{
    sfVector2f scal = {0.1, 0.1};

    sprite->combat->player_pos;
    sprite->combat->player_pos.x = 600;
    sprite->combat->player_pos.y = 300;
    sprite->combat->player_combat_texture = sfTexture_createFromFile(
        "asset/player/player_combat.png", NULL);
    sprite->combat->player_combat_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->combat->player_combat_sprite,
        sprite->combat->player_combat_texture, sfTrue);
    sfSprite_setPosition(sprite->combat->player_combat_sprite,
        sprite->combat->player_pos);
    sfSprite_setScale(sprite->combat->player_combat_sprite, scal);
}

void create_enemi_combat_sprite(struct init_sprites_s *sprite)
{
    sprite->combat->enemi_combat_texture = sfTexture_createFromFile(
        "asset/enemi/enemi.png", NULL);
    sprite->combat->enemi_combat_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->combat->enemi_combat_sprite,
        sprite->combat->enemi_combat_texture, sfTrue);
    sprite->combat->enemi_combat_pos.x = 780;
    sprite->combat->enemi_combat_pos.y = 100;
    sfSprite_setPosition(sprite->combat->enemi_combat_sprite,
        sprite->combat->enemi_combat_pos);
}
