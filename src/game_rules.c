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

void game_rules_random_heal(Game *game)
{
    int random = 0;

    if (!game)
        return;

    /*If the game is in determinist mode, we don't want to use random functions*/
    if (game_get_determinist_status(game) == TRUE)
    {
        return;
    }

    random = rand() % 5;

    /*It has a 20% chance of healing the player*/
    if (random == 0)
    {
        player_set_health(game_get_player(game), player_get_health(game_get_player(game)) + 1);
        printf("You have been healed one hitpoint!\n");
    }
}

void game_rules_random_attack(Game *game)
{
    int i = 0, random = 0;
    Id *characters_in_space = NULL;

    /*If the game is in determinist mode, we don't want to use random functions*/
    if (game_get_determinist_status(game) == TRUE)
    {
        return;
    }

    if (!game)
        return;

    random = rand() % 10;

    /*It has a 10% chance of attacking the player (if there's a hostile character in that space)*/
    if (random == 0)
    {
        characters_in_space = space_get_characters_ids(game_get_space(game, game_get_player_location(game)));
        for (i = 0; i < space_get_ncharacters(game_get_space(game, game_get_player_location(game))); i++)
        {
            if (character_get_friendly(game_get_character(game, characters_in_space[i])) == FALSE)
            {
                player_set_health(game_get_player(game), player_get_health(game_get_player(game)) - 1);
                printf("You have been attacked one hitpoint!\n");
                break;
            }
        }
    }
}

void game_rules_open_door1(Game *game)
{
    char *guard1_name = "Guard1";
    Character *guard1 = NULL;
    char *key1_name = "Key1";
    Object *key1 = NULL;
    Id key1_id = 901;
    Id link1_id = 48;

    if (!game)
        return;

    guard1 = game_get_character_from_name(game, guard1_name);
    if (!guard1)
        return;

    key1 = game_get_object(game, key1_id);
    if (key1) {
        return;
    }

    if (character_get_health(guard1) == 0)
    {
        key1 = object_create(key1_id);
        object_set_name(key1, key1_name);
        object_set_description(key1, "A key to open the door");
        object_set_movable(key1, TRUE);
        object_set_open(key1, link1_id);

        game_add_object(game, key1);
        space_set_new_object(game_get_space(game, game_get_player_location(game)), key1_id);
        game_set_message(game, "The guard has dropped a key!");
    }
}

void game_rules_open_door2(Game *game)
{
    char *guard2_name = "Guard2";
    Character *guard2 = NULL;
    char *key2_name = "Key2";
    Object *key2 = NULL;
    Id key2_id = 902;
    Id link2_id = 49;

    if (!game)
        return;

    guard2 = game_get_character_from_name(game, guard2_name);
    if (!guard2)
        return;

    key2 = game_get_object(game, key2_id);
    if (key2) {
        return;
    }

    if (character_get_health(guard2) == 0)
    {
        key2 = object_create(key2_id);
        object_set_name(key2, key2_name);
        object_set_description(key2, "A key to open the door");
        object_set_movable(key2, TRUE);
        object_set_open(key2, link2_id);

        game_add_object(game, key2);
        space_set_new_object(game_get_space(game, game_get_player_location(game)), key2_id);
        game_set_message(game, "The guard has dropped a key!");
    }
}

void game_rules_open_door3(Game *game)
{
    char *guard3_name = "Guard3";
    Character *guard3 = NULL;
    char *key3_name = "Key3";
    Object *key3 = NULL;
    Id key3_id = 903;
    Id link3_id = 70;

    if (!game)
        return;

    guard3 = game_get_character_from_name(game, guard3_name);
    if (!guard3)
        return;

    key3 = game_get_object(game, key3_id);
    if (key3) {
        return;
    }

    if (character_get_health(guard3) == 0)
    {
        key3 = object_create(key3_id);
        object_set_name(key3, key3_name);
        object_set_description(key3, "A key to open the door");
        object_set_movable(key3, TRUE);
        object_set_open(key3, link3_id);

        game_add_object(game, key3);
        space_set_new_object(game_get_space(game, game_get_player_location(game)), key3_id);
        game_set_message(game, "The guard has dropped a key!");
    }
}

void game_rules_open_door4(Game *game)
{
    char *guard4_name = "Guard4";
    Character *guard4 = NULL;
    char *key4_name = "Key4";
    Object *key4 = NULL;
    Id key4_id = 904;
    Id link4_id = 86;

    if (!game)
        return;

    guard4 = game_get_character_from_name(game, guard4_name);
    if (!guard4)
        return;

    key4 = game_get_object(game, key4_id);
    if (key4) {
        return;
    }

    if (character_get_health(guard4) == 0)
    {
        key4 = object_create(key4_id);
        object_set_name(key4, key4_name);
        object_set_description(key4, "A key to open the door");
        object_set_movable(key4, TRUE);
        object_set_open(key4, link4_id);

        game_add_object(game, key4);
        space_set_new_object(game_get_space(game, game_get_player_location(game)), key4_id);
        game_set_message(game, "The guard has dropped a key!");
    }
}

void game_rules_open_door5(Game *game)
{
    char *guard5_name = "Guard5";
    Character *guard5 = NULL;
    char *key5_name = "Key5";
    Object *key5 = NULL;
    Id key5_id = 905;
    Id link5_id = 88;

    if (!game)
        return;

    guard5 = game_get_character_from_name(game, guard5_name);
    if (!guard5)
        return;

    key5 = game_get_object(game, key5_id);
    if (key5) {
        return;
    }

    if (character_get_health(guard5) == 0)
    {
        key5 = object_create(key5_id);
        object_set_name(key5, key5_name);
        object_set_description(key5, "A key to open the door");
        object_set_movable(key5, TRUE);
        object_set_open(key5, link5_id);

        game_add_object(game, key5);
        space_set_new_object(game_get_space(game, game_get_player_location(game)), key5_id);
        game_set_message(game, "The guard has dropped a key!");
    }
}

void game_rules_open_door6(Game *game)
{
    char *guard6_name = "Guard6";
    Character *guard6 = NULL;
    char *key6_name = "Key6";
    Object *key6 = NULL;
    Id key6_id = 906;
    Id link6_id = 84;

    if (!game)
        return;

    guard6 = game_get_character_from_name(game, guard6_name);
    if (!guard6)
        return;

    key6 = game_get_object(game, key6_id);
    if (key6) {
        return;
    }

    if (character_get_health(guard6) == 0)
    {
        key6 = object_create(key6_id);
        object_set_name(key6, key6_name);
        object_set_description(key6, "A key to open the door");
        object_set_movable(key6, TRUE);
        object_set_open(key6, link6_id);

        game_add_object(game, key6);
        space_set_new_object(game_get_space(game, game_get_player_location(game)), key6_id);
        game_set_message(game, "The guard has dropped a key!");
    }
}

void game_rules_open_door7(Game *game)
{
    char *guard7_name = "Guard7";
    Character *guard7 = NULL;
    char *key7_name = "Key7";
    Object *key7 = NULL;
    Id key7_id = 907;
    Id link7_id = 62;

    if (!game)
        return;

    guard7 = game_get_character_from_name(game, guard7_name);
    if (!guard7)
        return;

    key7 = game_get_object(game, key7_id);
    if (key7) {
        return;
    }

    if (character_get_health(guard7) == 0)
    {
        key7 = object_create(key7_id);
        object_set_name(key7, key7_name);
        object_set_description(key7, "A key to open the door");
        object_set_movable(key7, TRUE);
        object_set_open(key7, link7_id);

        game_add_object(game, key7);
        space_set_new_object(game_get_space(game, game_get_player_location(game)), key7_id);
        game_set_message(game, "The guard has dropped a key!");
    }
}

void game_rules_open_door8(Game *game)
{
    char *guard8_name = "Guard8";
    Character *guard8 = NULL;
    char *key8_name = "Key8";
    Object *key8 = NULL;
    Id key8_id = 908;
    Id link8_id = 65;

    if (!game)
        return;

    guard8 = game_get_character_from_name(game, guard8_name);
    if (!guard8)
        return;

    key8 = game_get_object(game, key8_id);
    if (key8) {
        return;
    }

    if (character_get_health(guard8) == 0)
    {
        key8 = object_create(key8_id);
        object_set_name(key8, key8_name);
        object_set_description(key8, "A key to open the door");
        object_set_movable(key8, TRUE);
        object_set_open(key8, link8_id);

        game_add_object(game, key8);
        space_set_new_object(game_get_space(game, game_get_player_location(game)), key8_id);
        game_set_message(game, "The guard has dropped a key!");
    }
}

void game_rules_open_door9(Game *game)
{
    char *guard9_name = "Guard9";
    Character *guard9 = NULL;
    char *key9_name = "Key9";
    Object *key9 = NULL;
    Id key9_id = 909;
    Id link9_id = 68;

    if (!game)
        return;

    guard9 = game_get_character_from_name(game, guard9_name);
    if (!guard9)
        return;

    key9 = game_get_object(game, key9_id);
    if (key9) {
        return;
    }

    if (character_get_health(guard9) == 0)
    {
        key9 = object_create(key9_id);
        object_set_name(key9, key9_name);
        object_set_description(key9, "A key to open the door");
        object_set_movable(key9, TRUE);
        object_set_open(key9, link9_id);

        game_add_object(game, key9);
        space_set_new_object(game_get_space(game, game_get_player_location(game)), key9_id);
        game_set_message(game, "The guard has dropped a key!");
    }
}

void game_rules_open_door10(Game *game)
{
    char *guard10_name = "Guard10";
    Character *guard10 = NULL;
    char *key10_name = "Key10";
    Object *key10 = NULL;
    Id key10_id = 910;
    Id link10_id = 77;

    if (!game)
        return;

    guard10 = game_get_character_from_name(game, guard10_name);
    if (!guard10)
        return;

    key10 = game_get_object(game, key10_id);
    if (key10) {
        return;
    }

    if (character_get_health(guard10) == 0)
    {
        key10 = object_create(key10_id);
        object_set_name(key10, key10_name);
        object_set_description(key10, "A key to open the door");
        object_set_movable(key10, TRUE);
        object_set_open(key10, link10_id);

        game_add_object(game, key10);
        space_set_new_object(game_get_space(game, game_get_player_location(game)), key10_id);
        game_set_message(game, "The guard has dropped a key!");
    }
}


void game_rules_check_boss_defeat(Game *game)
{
    char *boss_name = "Boss";
    Character *boss = NULL;

    if (!game)
        return;

    boss = game_get_character_from_name(game, boss_name);
    if (!boss)
        return;
    /* Check if the boss is dead */
    if (character_get_health(boss) <= 0)
    {
        game_set_finished(game, TRUE);
        printf("Congratulations, you have defeated the boss!\n");
    }
}

void game_rules_change_turn(Game *game)
{
    if (!game)
        return;

    if (game_get_nplayers(game) <= 0)
        return;

    if (game_get_nplayers(game) == 1)
    {
        return;
    }

    if ((game_get_finished(game) == FALSE) && (command_get_code(game_get_last_command(game)) == GUESS) && (command_get_last_cmd_status(game_get_last_command(game)) == OK))
    {
        game_set_turn(game, (game_get_turn(game) + 1) % game_get_nplayers(game));
    }
}

void game_rules_run_all(Game *game)
{
    if (!game)
        return;

    game_rules_random_heal(game);
    game_rules_random_attack(game);
    game_rules_open_door1(game);
    game_rules_open_door2(game);
    game_rules_open_door3(game);
    game_rules_open_door4(game);
    game_rules_open_door5(game);
    game_rules_open_door6(game);
    game_rules_open_door7(game);
    game_rules_open_door8(game);
    game_rules_open_door9(game);
    game_rules_open_door10(game);
    game_rules_check_boss_defeat(game);
    game_rules_change_turn(game);
}
