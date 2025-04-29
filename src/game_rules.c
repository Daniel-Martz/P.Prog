/**
 * @brief It implements the game rules functions
 *
 * @file game_rules.h
 * @author Jorge Martín
 * @version 0
 * @date 22-04-2025
 * @copyright Copyright (c) 2025
 */

#include "game_rules.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void game_rules_random_heal(Game *game) {
    int random = 0;

    if (!game) return;

    /*If the game is in determinist mode, we don't want to use random functions*/
    if (game_get_determinist_status(game) == TRUE) {
        return;
    }

    random = rand() % 5;

    /*It has a 20% chance of healing the player*/
    if (random == 0) {
        player_set_health(game_get_player(game), player_get_health(game_get_player(game)) + 1);
        printf("You have been healed one hitpoint!\n");
    }
}

void game_rules_random_attack(Game *game) {
    int i = 0, random = 0;
    Id *characters_in_space = NULL;
    
    /*If the game is in determinist mode, we don't want to use random functions*/
    if (game_get_determinist_status(game) == TRUE) {
        return;
    }

    if (!game) return;

    random = rand() % 10;

    /*It has a 10% chance of attacking the player (if there's a hostile character in that space)*/
    if (random == 0) {
        characters_in_space = space_get_characters_ids(game_get_space(game, game_get_player_location(game)));
        for (i=0; i<space_get_ncharacters(game_get_space(game, game_get_player_location(game))); i++){
            if (character_get_friendly(game_get_character(game, characters_in_space[i])) == FALSE) {
                player_set_health(game_get_player(game), player_get_health(game_get_player(game)) - 1);
                printf("You have been attacked one hitpoint!\n");
                break;
            }
        }
    }
}

void game_rules_open_final_door(Game *game){

}

void game_rules_check_boss_defeat(Game *game) {
    char *boss_name = "Boss";
    Character *boss = NULL;

    if (!game) return;

    boss = game_get_character_from_name(game, boss_name);
    if (!boss) return;
    /* Check if the boss is dead */
    if (character_get_health(boss) <= 0) {
        game_set_finished(game, TRUE);
        printf("Congratulations, you have defeated the boss!\n");
    }
}

void game_rules_change_turn(Game *game) {
    if (!game) return;

    if (game_get_nplayers(game) <= 0) return;

    if (game_get_nplayers(game) == 1) {
        return;
    }

    if (game_get_finished(game) == FALSE) {
        game_set_turn(game, (game_get_turn(game) + 1) % game_get_nplayers(game));
    }
}

void game_rules_run_all(Game *game) {
    if (!game) return;

    game_rules_random_heal(game);
    game_rules_random_attack(game);
    game_rules_open_final_door(game);
    game_rules_check_boss_defeat(game);
    game_rules_change_turn(game);
}


