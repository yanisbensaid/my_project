/*
** EPITECH PROJECT, 2024
** colision
** File description:
** rpg
*/


#include "../../includes/my_rpg.h"

bool collisionMap[MAP_WIDTH][MAP_HEIGHT] = {

    {true, true, true, true, true, true, true, true},
    {true, false, false, false, false, false, false, true},
    {true, false, false, false, false, false, false, true},
    {true, false, false, false, false, false, false, true},
    {true, false, false, false, false, false, false, true},
    {true, false, false, false, false, false, false, true},
    {true, false, false, false, false, false, false, true},
    {true, true, true, true, true, true, true, true}
};

void initialize_collision_map(void)
{
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            collisionMap[i][j] = false;
        }
    }
}

void set_collision(int x, int y)
{
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        collisionMap[x][y] = true;
    }
}

bool check_collision(int x, int y)
{
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        return collisionMap[x][y];
    }
    return false;
}

int main(void)
{
    bool isCollision = checkCollision(3, 4);

    initializeCollisionMap();
    setCollision(3, 4);
    setCollision(7, 2);
    if (isCollision) {
        printf("Collision détectée à la position (3, 4)\n");
    } else {
        printf("Pas de collision à la position (3, 4)\n");
    }
    return 0;
}
