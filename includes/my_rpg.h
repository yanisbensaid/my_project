/*
** EPITECH PROJECT, 2023
** Bsminiprintf
** File description:
** Miniprintf
*/

#pragma once
#include <stdarg.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "SFML/Audio.h"
#include "../struct/sprites.h"
#include "../struct/texture.h"
#include "../struct/menu.h"
#include "../struct/player.h"

#define PLAYER_SPEED 0.50f
#define ANIMATION_DURATION 100.0f
#define MAP_WIDTH 8
#define MAP_HEIGHT 8

// typedef struct player_mouve_s {
//     sfRenderWindow *window;
//     sfEvent event;
//     sfTexture *mapTexture;
//     sfSprite *mapSprite;
//     sfTexture *playerTexture;
//     sfSprite *playerSprite;
//     sfClock *clock;
//     float lapsedTime;
//     sfIntRect rect;
//     bool animationActive;
//     sfTime elapsed;
//     float deltaTime;
//     sfVector2f playerPosition;
// } player_mouve_t;

void size_window(struct init_sprites_s *sprite, struct menu_s *menu);
void windows_menu(struct menu_s *menu, struct init_sprites_s *sprite);
void rpg(void);
void create_sprite_menu(struct init_sprites_s *sprite, struct menu_s *menu);
void destroy(struct init_sprites_s *sprite, struct player_s *player);
void display_menu(struct menu_s *menu, struct init_sprites_s *sprite,
    bool isPlayButton, bool isOnPlayButton_exit);
void display_adv(struct menu_s *menu, struct init_sprites_s *sprite);
void create_sprite_adv(struct init_sprites_s *sprite, struct menu_s *menu);
void windows_adv(struct menu_s *menu, struct init_sprites_s *sprite);
void button_menu_follow(struct init_sprites_s *sprite, struct menu_s *menu);
void create_button_menu(struct init_sprites_s *sprite, struct menu_s *menu);
void create_sprite_menu(struct init_sprites_s *sprite, struct menu_s *menu);
void display_menu(struct menu_s *menu_s, struct init_sprites_s *sprite,
    bool isOnPlayButton_play, bool isOnPlayButton_exit);
void windows_map(struct menu_s *menu,
    struct init_sprites_s *sprite, struct player_s *player);
void create_sprite_map(struct init_sprites_s *sprite, struct menu_s *menu);
void overlay(struct menu_s *menu, struct init_sprites_s *sprite);
void create_setting_sprite(struct init_sprites_s *sprite,
    struct menu_s *menu);
void overlay(struct menu_s *menu, struct init_sprites_s *sprite);
void display_overlay(struct menu_s *menu, struct init_sprites_s *sprite);
void click_on_setting(struct menu_s *menu, sfMouseButtonEvent event_menu,
    struct init_sprites_s *sprite);
void cross_sprite(struct init_sprites_s *sprite, struct menu_s *menu);
void click_on_cross(struct menu_s *menu, sfMouseButtonEvent event_menu,
    struct init_sprites_s *sprite);
void display_map(struct menu_s *menu, struct init_sprites_s *sprite,
    struct player_s *player, sfEvent event);
void follow_setting_sprite(struct init_sprites_s *sprite, struct menu_s *menu);
void click_on_cross(struct menu_s *menu, sfMouseButtonEvent event_menu,
    struct init_sprites_s *sprite);
void hover_click_on_menu(struct menu_s *menu, struct init_sprites_s *sprite);
void exit_sprite(struct init_sprites_s *sprite, struct menu_s *menu);
void click_on_exit_menu(struct menu_s *menu, sfMouseButtonEvent event_menu,
    struct init_sprites_s *sprite);
sfMusic* sound(struct init_sprites_s *sprite, struct menu_s *menu);
void click_on_save(struct menu_s *menu, sfEvent event_menu,
    struct init_sprites_s *sprite, struct player_s *player);
void save_sprite(struct init_sprites_s *sprite, struct menu_s *menu);
void sound_sprite_high(struct init_sprites_s *sprite, struct menu_s *menu);
void click_on_high_sound(struct menu_s *menu, sfMouseButtonEvent event_menu,
    struct init_sprites_s *sprite);
void sound_sprite_low(struct init_sprites_s *sprite, struct menu_s *menu);
void click_on_low_sound(struct menu_s *menu, sfMouseButtonEvent event_menu,
    struct init_sprites_s *sprite);
void follow_volume_barre_sprite(struct init_sprites_s *sprite,
    struct menu_s *menu);
void volume_barre_sprite(struct init_sprites_s *sprite, struct menu_s *menu);
void three_volume_barre_sprite(struct init_sprites_s *sprite,
    struct menu_s *menu);
void player(struct init_sprites_s *sprite, struct menu_s *menu);
void create_sprite_player(struct player_s *player,
    struct init_sprites_s *sprite);
void player_animation(struct player_s *player, struct init_sprites_s *sprite);
void animation(struct player_s *player);
void move_player(struct player_s *player,
    struct menu_s *menu, struct init_sprites_s *sprite);
void create_sprite_player_q(struct player_s *player,
    struct init_sprites_s *sprite);
void player_animation_q(struct player_s *player,
    struct init_sprites_s *sprite);
void animation_q(struct player_s *player);
void create_sprite_player_z(struct player_s *player,
    struct init_sprites_s *sprite);
void animation_z(struct player_s *player);
void player_animation_z(struct player_s *player,
    struct init_sprites_s *sprite);
void move_player_z(struct player_s *player);
void create_sprite_player_d(struct player_s *player,
    struct init_sprites_s *sprite);
void player_animation_d(struct player_s *player,
    struct init_sprites_s *sprite);
void animation_d(struct player_s *player);
void create_sprite_player_no_moove(struct player_s *player,
    struct init_sprites_s *sprite);
void display_player_zqs(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu);
void get_player_initial_position(player_t *player);
void parse_info_file(player_t *player);
void create_sprite_enenmi(struct init_sprites_s *sprite, struct menu_s *menu);
void lancer_nouvelle_scene(struct menu_s *menu,
    struct init_sprites_s *sprite, struct player_s *player);
bool isCollision(sfSprite *sprite1, sfSprite *sprite2);
void create_sprite_combat(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void init_life(struct init_sprites_s *sprite,
    struct menu_s *menu, struct player_s *player);
int parsing_pos(struct player_s *player);
void change_barre_life(struct init_sprites_s *sprite,
    struct menu_s *menu, struct player_s *player);
void find_xp_player(char *line, struct player_s *player);
void find_life_player(char *line, struct player_s *player);
void find_life_barre(char *line, struct player_s *player);
void save_session(struct init_sprites_s *sprite,
    struct menu_s *menu);
void game_over(struct menu_s *menu, struct init_sprites_s *sprite,
    struct player_s *player);
void init_game_over(struct init_sprites_s *sprite, struct menu_s *menu);
void create_inventory_sprite(struct init_sprites_s *sprite,
    struct menu_s *menu);
void click_on_inventory(struct menu_s *menu, sfMouseButtonEvent event_menu,
    struct init_sprites_s *sprite);
void inventory_square_overlay(struct menu_s *menu,
    struct init_sprites_s *sprite);
void display_inventory_overlay(struct menu_s *menu,
    struct init_sprites_s *sprite);
void update_game_state(struct menu_s *menu, struct player_s *player,
    struct init_sprites_s *sprite);
bool is_colision(sfSprite *sprite1, sfSprite *sprite2);
void enemi_asset(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void player_combat_asset(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void combat_overlay_gris(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void menu_asset_combat(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void atack_asset(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void menu_asset_combat2(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void skill_asset(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void guards_asset(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void menu_asset_combat3(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void item_asset_combat(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void init_combat_asset(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void init_scale(struct init_sprites_s *sprite);
void create_sprite_combat(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void init_drawsprite(struct init_sprites_s *sprite);
void init_menu_combat(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void init_combat_tet_texture(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void init_combat_menu_asset_second(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void inti_combat_menu_asset(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void init_comnbat_menu_asset_four(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void inti_combat_menu_asset_third(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void init_text_jambe_droite_combat(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void init_text_jambe_gauche_combat(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void init_text_bras_gauche_combat(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void init_text_bras_droit(struct init_sprites_s *sprite,
    struct init_texture_s *texture);
void init_colision_tete(struct init_sprites_s *sprite,
    sfVector2i mouse_pos);
void init_colision_bras_gauche(struct init_sprites_s *sprite,
    struct init_texture_s *texture, sfVector2i mouse_pos);
void init_colision_bras_droit(struct init_sprites_s *sprite,
    struct init_texture_s *texture, sfVector2i mouse_pos);
void init_colision_jambe_gauche(struct init_sprites_s *sprite,
    struct init_texture_s *texture, sfVector2i mouse_pos);
void init_colision_jambe_droite(struct init_sprites_s *sprite,
    struct init_texture_s *texture, sfVector2i mouse_pos);
void init_combat_menu_asset_enemi(struct init_sprites_s *sprite,
    struct init_texture_s *texture, bool enemi_completed);
void init_colision_attack(struct init_sprites_s *sprite);
void init_collision_skill(struct init_sprites_s *sprite, sfEvent combat_event,
    sfFloatRect spriteBounds_skill);
void init_colision_guard(struct init_sprites_s *sprite,
    sfEvent combat_event, sfFloatRect spriteBounds_guards);
void init_colision_item(struct init_sprites_s *sprite,
    sfEvent combat_event, sfFloatRect spriteBounds_item);
void colision_menu_combat(struct init_sprites_s *sprite,
    sfEvent combat_event, struct menu_s *menu);
void draw_attack_sprite(struct init_sprites_s *sprite);
void attack_is_clicked_deteced(struct init_sprites_s *sprite);
void init_combat(struct menu_s *menu,
    struct init_sprites_s *sprite, struct init_texture_s *texture);
void init_colision_texte_combat(struct menu_s *menu,
    struct init_sprites_s *sprite, sfVector2i mouse_pos,
    struct init_texture_s *texture);
void move_player_arrow(struct player_s *player);
void display_player_arrow_up_down(struct init_sprites_s *sprite,
    struct player_s *player);
void display_player_arrow_right_left(struct init_sprites_s *sprite,
    struct player_s *player);
int sprite_player_combat(struct init_sprites_s *sprite);
void fond_menu(struct init_sprites_s *sprite,
    struct menu_s *menu, struct player_s *player);
void fond_menu_court(struct init_sprites_s *sprite);
void attack_button(struct init_sprites_s *sprite);
void create_bras_droit_button(struct init_sprites_s *sprite);
void create_bras_gauche_button(struct init_sprites_s *sprite);
void create_jambe_droit(struct init_sprites_s *sprite);
void create_jambe_gauche(struct init_sprites_s *sprite);
void create_enemi_combat_sprite(struct init_sprites_s *sprite);
void create_enemi_sans_bras_sprire(struct init_sprites_s *sprite);
void create_enemi_combat_sprite(struct init_sprites_s *sprite);
void draw_sprite_combat(struct init_sprites_s *sprite);
void attack_on(sfEvent event, struct init_sprites_s *sprite);
void check_combat_part_click(struct init_sprites_s *sprite,
    bool showSprites, struct player_s *player, struct menu_s *menu);
void create_enemi_sans_bras_sprire(struct init_sprites_s *sprite);
void handel_modif_sprite_enemi_first(struct init_sprites_s *sprite);
void enter_in_donjon(struct player_s *player, struct init_sprites_s *sprite,
    struct menu_s *menu, sfEvent event);
void windows_donjon_one(struct menu_s *menu,
    struct init_sprites_s *sprite, struct player_s *player);
void display_donjon_one(struct menu_s *menu, struct init_sprites_s *sprite,
    struct player_s *player, sfEvent event);
void init_donjon_one(struct init_sprites_s *sprite, struct menu_s *menu);
void init_pnj(struct init_sprites_s *sprite);
void detect_player(struct player_s *player, struct init_sprites_s *sprite);
void write_text_progressively(sfRenderWindow *window, sfText *text,
    const char *fullText, float delay);
void sprite_player_combat_modif(struct init_sprites_s *sprite);
void create_sword(struct init_sprites_s *sprite);
void init_donjon_two(struct init_sprites_s *sprite, struct menu_s *menu);
void enter_in_donjon_two(struct player_s *player,
    struct init_sprites_s *sprite, struct menu_s *menu);
void windows_donjon_two(struct menu_s *menu,
    struct init_sprites_s *sprite, struct player_s *player);
void display_donjon_two(struct menu_s *menu, struct init_sprites_s *sprite,
    struct player_s *player, sfEvent event);
void init_donjon_two(struct init_sprites_s *sprite, struct menu_s *menu);
void create_sprite(struct init_sprites_s *sprite,
    struct menu_s *menu, struct player_s *player);
void exit_donjon_two(struct player_s *player,
    struct init_sprites_s *sprite, struct menu_s *menu, sfEvent event);
void set_sprite_positions(struct init_sprites_s *sprite,
    sfVector2f pos_play, sfVector2f pos_exit);
void draw_play_button(struct init_sprites_s *sprite, bool isOnPlayButton_play);
void draw_exit_button(struct init_sprites_s *sprite, bool isOnPlayButton_exit);
void exit_donjon_one(struct player_s *player,
    struct init_sprites_s *sprite, struct menu_s *menu, sfEvent event);
void init_interact_pnj(struct init_sprites_s *sprite, struct player_s *player);
void detect_sword(struct player_s *player, struct init_sprites_s *sprite);
void interact_with_object(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu);
void init_damage(struct init_sprites_s *sprite);
sfVector2f calculate_scale(sfSprite *background, sfVector2u windowSize);
sfVector2f calculate_exit_position
(sfSprite *exit_sprite, sfVector2u windowSize);
sfVector2f calculate_play_position
(sfSprite *play_sprite, sfVector2u windowSize);
void click_on_cross_inventory(struct menu_s *menu,
    sfMouseButtonEvent event_menu, struct init_sprites_s *sprite);
void cross_sprite_inventory(struct init_sprites_s *sprite,
    struct menu_s *menu);
void display_cross_inventory(struct menu_s *menu,
    struct init_sprites_s *sprite);
void display_inventory(struct menu_s *menu, struct init_sprites_s *sprite,
    struct player_s *player);
void create_sword_in_inventory(struct init_sprites_s *sprite);
void init_pnj_two(struct init_sprites_s *sprite);
void detect_pnj(struct player_s *player, struct init_sprites_s *sprite);
void init_interact_pnj_two(struct init_sprites_s *sprite,
    struct player_s *player);
void detect_object(struct player_s *player,
    struct init_sprites_s *sprite);
void move_player_in_donjon_one(struct player_s *player, struct menu_s *menu,
    struct init_sprites_s *sprite);
void display_player_donjon_one(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu);
void test_collision(struct player_s *player, struct map_s *map);
void parse_map(const char *filename, struct map_s *map);
void extract_wall_values(const char *filename);
int check_collision(float x, float y);
void move_player_follow(struct player_s *player, struct menu_s *menu);
void display_player_donjon_one(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu);
void display_player_s(struct init_sprites_s *sprite, struct player_s *player);
void display_player_z(struct init_sprites_s *sprite, struct player_s *player);
void display_player_q(struct init_sprites_s *sprite, struct player_s *player);
void display_player_d(struct init_sprites_s *sprite, struct player_s *player);
void init_pos_after_tp(struct player_s *player, struct menu_s *menu);
void create_tete_button(struct init_sprites_s *sprite);
void find_attack_player(char *line, struct player_s *player);
void init_parameter_fight(struct init_sprites_s *sprite,
    struct player_s *player);
void win_first_monster(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu);
void detect_draven(struct player_s *player, struct init_sprites_s *sprite);
void init_interact_draven(struct init_sprites_s *sprite,
    struct player_s *player);
void init_draven(struct init_sprites_s *sprite);
void init_interact_key(struct init_sprites_s *sprite,
    struct player_s *player);
void detect_key(struct player_s *player, struct init_sprites_s *sprite);
void interact_with_object_donjon_one(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu);
void detect_object_donjon_one(struct player_s *player,
    struct init_sprites_s *sprite);
void init_shield(struct init_sprites_s *sprite,
    struct player_s *player);
void detect_shield(struct player_s *player, struct init_sprites_s *sprite);
void create_shield_in_inventory(struct init_sprites_s *sprite);
void find_state_boss_one(char *line, struct player_s *player);
void create_sprite_enemi_two(struct init_sprites_s *sprite,
    struct menu_s *menu);
void update_game_state_two(struct menu_s *menu,
    struct player_s *player, struct init_sprites_s *sprite);
void fight_donjon_two(struct menu_s *menu,
    struct init_sprites_s *sprite, struct player_s *player);
void find_state_boss_two(char *line, struct player_s *player);
void inflige_damage_monter(struct init_sprites_s *sprite,
    struct player_s *player, struct menu_s *menu);
void process_combat_click(struct init_sprites_s *sprite,
    sfEvent combat_event, struct player_s *player, struct menu_s *menu);
void check_combat_miss(struct init_sprites_s *sprite,
    struct menu_s *menu, struct player_s *player);
void turn_fight(struct init_sprites_s *sprite, struct player_s *player);
void init_end_game(struct init_sprites_s *sprite, struct menu_s *menu);
void end_game(struct menu_s *menu, struct init_sprites_s *sprite,
    struct player_s *player);