/*
** EPITECH PROJECT, 2024
** structure
** File description:
** sprites.h
*/

#pragma once

#include "../includes/my_rpg.h"

typedef struct combat_s {
    sfTexture *player_combat_texture;
    sfSprite *player_combat_sprite;
    sfVector2f player_pos;
    sfTexture *fond_menu_combat_texture;
    sfSprite *menu_combat_sprite;
    sfVector2f menu_combat_pos;
    sfVector2i mousePosition;

    sfTexture *fond_menu_long_texture;
    sfSprite *menu_combat_long_sprite;
    sfVector2f menu_combat_long_pos;
    sfVector2f size_menu_combat_long;

    sfTexture *attack_button_texture;
    sfSprite *attack_button_sprite;
    sfVector2f attack_button_pos;
    sfFloatRect attack_button_bounds;

    sfTexture *skill_button_texture;
    sfSprite *skill_button_sprite;
    sfVector2f skill_button_pos;
    sfFloatRect skill_button_bounds;

    sfTexture *guard_button_texture;
    sfSprite *guard_button_sprite;
    sfVector2f guard_button_pos;
    sfFloatRect guard_button_bounds;

    sfTexture *item_button_texture;
    sfSprite *item_button_sprite;
    sfVector2f item_button_pos;
    sfFloatRect item_button_bounds;

    sfTexture *bras_droit_texture;
    sfSprite *bras_droit_sprite;
    sfVector2f bras_droit_pos;
    sfFloatRect bras_droit_bounds;

    sfTexture *bras_gauche_texture;
    sfSprite *bras_gauche_sprite;
    sfVector2f bras_gauche_pos;
    sfFloatRect bras_gauche_bounds;

    sfTexture *tete_texture;
    sfSprite *tete_sprite;
    sfVector2f tete_pos;
    sfFloatRect tete_bounds;

    sfTexture *jambes_droit_texture;
    sfSprite *jambes_droit_sprite;
    sfVector2f jambes_droit_pos;
    sfFloatRect jambes_droit_bounds;

    sfTexture *jambes_gauche_texture;
    sfSprite *jambes_gauche_sprite;
    sfVector2f jambes_gauche_pos;
    sfFloatRect jambes_gauche_bounds;

    bool is_bras_droit_displayed; // Add this field
    bool is_attacking;  // Indicateur d'état d'attaque
    bool show_bras_droit; // Add this variable
    bool show_bras_gauche; // Add this variable
    bool show_jambe_gauche; // Add this variable
    bool show_jambe_droit;
    sfTexture *enemi_combat_texture;
    sfSprite *enemi_combat_sprite;
    sfVector2f enemi_combat_pos;
    sfFloatRect enemi_bounds;

    sfTexture *steal_skill_texture;
    sfSprite *steal_skill_sprite;
    sfVector2f steal_skill_pos;
    sfFloatRect steal_skill_bounds;

    sfTexture *esquielle_skill_texture;
    sfSprite *esquielle_skill_sprite;
    sfVector2f esquielle_skill_pos;
    sfFloatRect esquielle_skill_bounds;

    bool test;
    bool bras_droit_is_clicked;
    bool bras_gauche_is_clicked;
    bool tete_is_clicked;
    bool jambes_droit_is_clicked;
    bool jambes_gauche_is_clicked;
    bool set_sprite_enemi;
    sfTexture *sans_bras;
    sfTexture *enemi_tronc;
    sfTexture *enemi_sans_jambes;
    sfTexture *enemi_sans_cote_droit;
    sfTexture *enemi_sans_cote_gauche;
    sfTexture *enemi_sans_bras_droit_jambe_gauche;
    sfTexture *enemi_sans_bras_gauche_jambe_droit;
    sfTexture *enemi_sans_bras_sans_jambe_droite;
    sfTexture *enemi_sans_bras_sans_jambe_gauche;
    sfTexture *enemi_sans_jambe_sans_bras_gaucge;
    sfTexture *enemi_sans_jambe_sans_bras_droit;
    int vitesse_player;
    int vitesse_enemi;
    int attack_enemi;
    int turn;
    int enemi_turn;
    int defense_player;
    int defense_enemi;
    int defense_enemi_two;
    sfTexture *player_sans_jambe_droite;
    sfTexture *player_sans_jambe_gauche;
    sfTexture *player_sans_bras_droit;
    sfTexture *player_sans_bras_gauche;
    sfBool mouseOverSprite;
    sfEvent event_attack;
    sfTexture *game_over_texture;
    sfSprite *game_over_sprite;
    sfVector2f game_over_pos;
    sfVector2f size_game_over;
} combat_t;


typedef struct init_sprites_s {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfSprite *background;;
    sfSprite *avertissment_sprite;
    sfSprite *play_white_sprite;
    sfSprite *play_grey_sprite;
    sfSprite *exit_red_sprite;
    sfSprite *exit_white_sprite;
    sfSprite *map_sprite;
    sfSprite *text_press_sprite;
    sfSprite *setting_black_sprite;
    sfSprite *setting_white_sprite;
    sfSprite *inventory_black_sprite;
    sfSprite *inventory_white_sprite;
    sfSprite *square_sprite;
    sfSprite *square_sprite_inventory;
    sfSprite *cross_black_sprite;
    sfSprite *cross_white_sprite;
    sfSprite *redexit_menu_sprite;
    sfSprite *whiteexit_menu_sprite;
    sfSprite *save_white_sprite;
    sfSprite *save_grey_sprite;
    sfSprite *high_sound_grey_sprite;
    sfSprite *high_sound_white_sprite;
    sfSprite *low_sound_grey_sprite;
    sfSprite *low_sound_white_sprite;
    sfSprite *volume_full_sprite;
    sfSprite *volume_high_sprite;
    sfSprite *volume_low_sprite;
    sfSprite *volume_mute_sprite;
    sfSprite *volume_mid_sprite;
    sfSprite *press_sword_sprite;
    sfSprite *draven_sprite;
    sfMusic *music;
    int puissance;
    float volume;
    sfSprite *sprite_player;
    float map_pos_x;
    sfVector2f pos_map;
    sfSprite *enemi_sprite;
    sfSprite *player_combat_sprite;
    sfSprite *combat_overlay_sprite;
    sfSprite *combat_overlay_gris_sprite;
    sfSprite *Attack_sprite;
    sfSprite *buton_skill_sprite;
    sfSprite *skill_sprite;
    sfSprite *button_guards_sprite;
    sfSprite *guard_sprite;
    sfSprite *button_item_sprite;
    sfSprite *item_sprite;
    sfSprite *menu_combat_sprite;
    sfSprite *menu_tete_sprite;
    sfSprite *menu_bras_gauche_sprite;
    sfSprite *menu_bras_droit_sprite;
    sfSprite *menu_jambe_gauche_sprite;
    sfSprite *menu_jambe_droite_sprite;
    sfSprite *text_menu_tete_sprite;
    sfSprite *tete_sprite;
    sfSprite *bras_gauche_sprite;
    sfSprite *bras_droit_sprite;
    sfSprite *jambe_gauche_sprite;
    sfSprite *jambe_droite_sprite;
    sfSprite *life_barre_sprite;
    sfSprite *save_session_sprite;
    sfSprite *game_over_sprite;
    sfSprite *donjon_one_sprite;
    sfSprite *text_menu_bras_gauche_sprite;
    sfSprite *text_menu_bras_droit_sprite;
    sfSprite *text_menu_jambe_gauche_sprite;
    sfSprite *text_menu_jambe_droite_sprite;
    sfSprite *pnj_one_sprite;
    sfSprite *press_e_sprite;
    sfSprite *donjon_two_sprite;
    sfSprite *interact_pnj_sprite;
    sfSprite *ten_damage_sprite;
    sfSprite *cross_black__inv_sprite;
    sfSprite *cross_white_inv_sprite;
    sfSprite *sword_sprite_inv;
    sfSprite *pnj_two_sprite;
    sfSprite *press_e_pnj_two;
    sfSprite *interact_eloi_sprite;
    sfSprite *background_fight_sprite;
    sfSprite *interact_draven_sprite;
    sfSprite *press_e_draven_sprite;
    sfSprite *key_sprite;
    sfSprite *press_e_key_sprite;
    sfSprite *interact_draven_two_sprite;
    sfSprite *shield_sprite;
    sfSprite *press_e_shield_sprite;
    sfSprite *shield_sprite_inv;
    sfSprite *shield_text_sprite;
    sfSprite *enemi_two_sprite;
    sfSprite *end_game_sprite;
    sfFloatRect spriteBounds_text_bras_droit;
    sfFloatRect spriteBounds_text_tete;
    sfFloatRect spriteBounds_text_jambe_droite;
    sfFloatRect spriteBounds_text_jambe_gauche;
    sfFloatRect spriteBounds_text_bras_gauche;
    bool enemi_bras_gauche;
    bool enemi_bras_droit;
    bool enemi_jambe_gauche;
    bool enemi_jambe_droite;
    bool isMouseClicked;
    bool player_detected;
    bool sword_detected;
    bool sword_visible;
    bool eloi_detected;
    bool draven_detected;
    bool monster_one_visible;
    bool monster_two_visible;
    bool key_detected;
    bool key_visible;
    bool shield_detected;
    bool shield_visible;
    sfClock *damage_clock;
    bool show_damage;
    sfVector2i mousePosition;
    sfFloatRect spriteBounds;
    int attack_is_clicked;
    bool attack_menu_is_clicked;
    struct combat_s *combat;
    sfTexture *epee_texture;
    sfSprite *epee_sprite;
    sfTexture *potion_texture;
    sfSprite *potion_sprite;
    bool potion_detected;
    sfSprite *five_heal_sprite;
    sfSprite *potion_sprite_inv;
    sfSprite *press_potion_sprite;
} sprites_t;
