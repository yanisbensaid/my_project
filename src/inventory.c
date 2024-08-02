/*
** EPITECH PROJECT, 2024
** inventory
** File description:
** myrpg
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/my_rpg.h"
#include "../struct/player.h"
#include <string.h>

/*void add_inventory_item(struct menu_s *menu, InventoryItem item)
{
    if (menu->inventory->num_items < 50) {
        menu->inventory->items[menu->inventory->num_items++] = item;
    } else {
        my_printf("L'inventaire est plein.\n");
    }
}
{
    if (inventory->num_items < 50) {
        inventory->items[inventory->num_items++] = item;
    } else {
        my_printf("L'inventaire est plein.\n");
    }
}

void disp_inventory(Inventory *inventory)
{
    my_printf("Inventaire :\n");
    for (int i = 0; i < inventory->num_items; i++) {
        my_printf("%d. %s - %s (x%d)\n", i+1, inventory->items[i].name,
               inventory->items[i].description, inventory->items[i].quantity);
    }
}

int inventory_main(void)
{

    Inventory inventory;
    inventory.num_items = 0;


    InventoryItem potion = {"Potion de guérison",
        "Restaure 50 points de vie", 3};
    InventoryItem sword = {"Épée de Fer", "Une arme de base en fer", 1};

    add_inventory_item(&inventory, potion);
    add_inventory_item(&inventory, sword);

    disp_inventory(&inventory);

    return 0;
}*/
