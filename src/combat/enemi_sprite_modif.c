/*
** EPITECH PROJECT, 2024
** force_a_nous
** File description:
** enemi_sprite_modif
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

void handel_modif_sprite_enemi_third(struct init_sprites_s *sprite)
{
    if (sprite->combat->bras_gauche_is_clicked == true &&
        sprite->combat->jambes_gauche_is_clicked == true){
        sfSprite_setTexture(sprite->combat->enemi_combat_sprite,
            sprite->combat->enemi_sans_cote_gauche, sfTrue);
    }
    if (sprite->combat->bras_droit_is_clicked == true &&
        sprite->combat->jambes_gauche_is_clicked == true){
        sfSprite_setTexture(sprite->combat->enemi_combat_sprite,
        sprite->combat->enemi_sans_bras_droit_jambe_gauche, sfTrue);
    }
    if (sprite->combat->bras_gauche_is_clicked == true &&
        sprite->combat->jambes_droit_is_clicked == true){
        sfSprite_setTexture(sprite->combat->enemi_combat_sprite,
            sprite->combat->enemi_sans_bras_gauche_jambe_droit, sfTrue);
    }
}

void handel_modif_sprite_enemi_second(struct init_sprites_s *sprite)
{
    if (sprite->combat->jambes_droit_is_clicked == true &&
        sprite->combat->jambes_gauche_is_clicked == true){
        sfSprite_setTexture(sprite->combat->enemi_combat_sprite,
        sprite->combat->enemi_sans_jambes, sfTrue);
    }
    if (sprite->combat->bras_droit_is_clicked == true &&
        sprite->combat->bras_gauche_is_clicked == true){
        sfSprite_setTexture(sprite->combat->enemi_combat_sprite,
        sprite->combat->sans_bras, sfTrue);
    }
    if (sprite->combat->bras_droit_is_clicked == true &&
        sprite->combat->jambes_droit_is_clicked == true){
        sfSprite_setTexture(sprite->combat->enemi_combat_sprite,
        sprite->combat->enemi_sans_cote_droit, sfTrue);
    }
    handel_modif_sprite_enemi_third(sprite);
}

void handel_modif_sprite_enemi_fourth(struct init_sprites_s *sprite)
{
    if (sprite->combat->jambes_droit_is_clicked &&
        sprite->combat->jambes_gauche_is_clicked == true &&
        sprite->combat->bras_gauche_is_clicked == true){
        sfSprite_setTexture(sprite->combat->enemi_combat_sprite,
        sprite->combat->enemi_sans_jambe_sans_bras_gaucge, sfTrue);
    }
    if (sprite->combat->jambes_droit_is_clicked &&
        sprite->combat->jambes_gauche_is_clicked == true &&
            sprite->combat->bras_droit_is_clicked == true){
        sfSprite_setTexture(sprite->combat->enemi_combat_sprite,
        sprite->combat->enemi_sans_jambe_sans_bras_droit, sfTrue);
    }
    if (sprite->combat->bras_droit_is_clicked == true &&
        sprite->combat->bras_gauche_is_clicked == true
        && sprite->combat->jambes_droit_is_clicked == true &&
        sprite->combat->jambes_gauche_is_clicked == true){
        sfSprite_setTexture(sprite->combat->enemi_combat_sprite,
        sprite->combat->enemi_tronc, sfTrue);
    }
}

void handel_modif_sprite_enemi_first(struct init_sprites_s *sprite)
{
    handel_modif_sprite_enemi_second(sprite);
    if (sprite->combat->bras_droit_is_clicked == true &&
        sprite->combat->jambes_droit_is_clicked == true
        && sprite->combat->jambes_gauche_is_clicked == true){
        sfSprite_setTexture(sprite->combat->enemi_combat_sprite,
        sprite->combat->enemi_sans_bras_sans_jambe_droite, sfTrue);
    }
    if (sprite->combat->bras_gauche_is_clicked == true &&
        sprite->combat->bras_droit_is_clicked == true
        && sprite->combat->jambes_gauche_is_clicked == true){
        sfSprite_setTexture(sprite->combat->enemi_combat_sprite,
        sprite->combat->enemi_sans_bras_sans_jambe_gauche, sfTrue);
    }
    handel_modif_sprite_enemi_fourth(sprite);
}

static void create_enemi_sans_bras_sprire_second(struct init_sprites_s *sprite)
{
    sprite->combat->enemi_sans_bras_gauche_jambe_droit =
    sfTexture_createFromFile(
    "asset/enemi/enemi_sans_bras_gauche_et_jambe_droit.png", NULL);
    sprite->combat->enemi_sans_bras_sans_jambe_droite =
    sfTexture_createFromFile(
    "asset/enemi/enemi_sans_bras_droit_et_gauche_et_jambe_droit.png", NULL);
    sprite->combat->enemi_sans_bras_sans_jambe_gauche =
    sfTexture_createFromFile(
    "asset/enemi/enemi_sans_bras_droit_et_gauche_et_jambe_gauche.png", NULL);
    sprite->combat->enemi_sans_jambe_sans_bras_gaucge =
    sfTexture_createFromFile(
    "asset/enemi/enemi_sans_bras_gauche_et_jambe_droit_et_gauche.png", NULL);
    sprite->combat->enemi_sans_jambe_sans_bras_droit =
    sfTexture_createFromFile(
    "asset/enemi/enemi_sans_jambe_et_sans_bras_droit.png", NULL);
}

void create_enemi_sans_bras_sprire(struct init_sprites_s *sprite)
{
    sprite->combat->sans_bras =
    sfTexture_createFromFile("asset/enemi/enemi_sans_bras.png", NULL);
    sprite->combat->enemi_tronc =
    sfTexture_createFromFile("asset/enemi/enemi_tronc.png", NULL);
    sprite->combat->enemi_sans_jambes =
    sfTexture_createFromFile("asset/enemi/enemi_sans_jambe.png", NULL);
    sprite->combat->enemi_sans_cote_droit =
    sfTexture_createFromFile(
    "asset/enemi/enemi_sans_bras_droit_et_jambe_droit.png", NULL);
    sprite->combat->enemi_sans_cote_gauche =
    sfTexture_createFromFile(
    "asset/enemi/enemi_sans_bras_gauche_et_jambe_gauche.png", NULL);
    sprite->combat->enemi_sans_bras_droit_jambe_gauche =
    sfTexture_createFromFile(
    "asset/enemi/enemi_sans_bras_droit_et_jambe_gauche.png", NULL);
    create_enemi_sans_bras_sprire_second(sprite);
}
