/*
** EPITECH PROJECT, 2024
** create potion
** File description:
** rpg
*/

#include "../includes/my_rpg.h"

void create_potion(struct init_sprites_s *sprite)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f potion_pos;
    sfVector2f scale = {0.25, 0.25};
    sfVector2f scale_button = {0.5, 0.5};
    sfVector2f pos_button = {325, 2350};

    sprite->potion_texture = sfTexture_createFromFile("asset/epee.png", NULL);
    sprite->potion_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->potion_sprite, sprite->potion_texture, sfTrue);
    potion_pos.x = 400;
    potion_pos.y = 2500;
    sfSprite_setPosition(sprite->potion_sprite, potion_pos);
    sfSprite_setScale(sprite->potion_sprite, scale);
    texture->press_potion_texture =
        sfTexture_createFromFile("asset/press_e.png", NULL);
    sprite->press_potion_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->press_potion_sprite,
        texture->press_potion_texture, sfTrue);
    sfSprite_setPosition(sprite->press_potion_sprite, pos_button);
    sfSprite_setScale(sprite->press_potion_sprite, scale_button);
}

void create_potion_in_inventory(struct init_sprites_s *sprite)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f potion_pos;
    sfVector2f scale = {0.4, 0.4};

    texture->potion_inv_texture =
        sfTexture_createFromFile("asset/epee.png", NULL);
    sprite->potion_sprite_inv = sfSprite_create();
    sfSprite_setTexture(sprite->potion_sprite_inv,
        texture->potion_inv_texture, sfTrue);
    potion_pos.x = 1000;
    potion_pos.y = 350;
    sfSprite_setPosition(sprite->potion_sprite_inv, potion_pos);
    sfSprite_setScale(sprite->potion_sprite_inv, scale);
}

void init_heal(struct init_sprites_s *sprite)
{
    struct init_texture_s *texture = malloc(sizeof(struct init_texture_s));
    sfVector2f heal_pos;
    sfVector2f scale = {0.9, 0.9};

    texture->five_heal_texture =
        sfTexture_createFromFile("asset/10damage.png", NULL);
    sprite->five_heal_sprite = sfSprite_create();
    sfSprite_setTexture(sprite->five_heal_sprite,
        texture->five_heal_texture, sfTrue);
    heal_pos.x = 1450;
    heal_pos.y = 800;
    sfSprite_setPosition(sprite->five_heal_sprite, heal_pos);
    sfSprite_setScale(sprite->five_heal_sprite, scale);
}

static float distance_potion(sfVector2f pos1, sfVector2f pos2)
{
    return sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
}

void detect_potion(struct player_s *player, struct init_sprites_s *sprite)
{
    sfVector2f potion_pos = sfSprite_getPosition(sprite->potion_sprite);
    float dist = distance_potion(player->playerPosition, potion_pos);

    if (dist <= 300.0f) {
        sprite->potion_detected = true;
    } else {
        sprite->potion_detected = false;
    }
}
