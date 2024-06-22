/*
** EPITECH PROJECT, 2024
** ennemy.h
** File description:
** header for ennemy
*/

#ifndef ENNEMY_H_
    #define ENNEMY_H_
    #include <SFML/Graphics.h>
    #include <SFML/System/Vector2.h>

typedef struct stat_s {
    int hp;
    int atk;
    int def;
} stat_t;

static const int db_offset = 142;
static const stat_t death_bringer = {160, 12, 9};

// setting death_bringer idle animation
static const int max_db_idle = 994;
static const sfIntRect db_idle = {0, 0, 142, 97};
static const sfVector2f db_idle_origin = {72, 48.5};

// setting death_bringer atk animation
static const int max_db_atk = 1278;
static const sfIntRect db_atk = {0, 97, 142, 97};
static const sfVector2f db_atk_origin = {72, 145.5};

// setting death_bringer hurt animation
static const int max_db_hurt = 284;
static const sfIntRect db_hurt = {0, 194, 142, 97};
static const sfVector2f db_hurt_origin = {72, 242.5};

// setting death_bringer die animation
static const int max_db_die = 1278;
static const sfIntRect db_die = {0, 291, 142, 97};
static const sfVector2f db_die_origin = {72, 339.5};

static const int nb_offset = 80;
static const stat_t nightborne = {100, 15, 0};

// setting nightborne idle animation
static const int max_nb_idle = 640;
static const sfIntRect nb_idle = {0, 0, 80, 80};

// setting nightborne attack animation
static const int max_nb_atk = 880;
static const sfIntRect nb_atk = {0, 160, 80, 80};

// setting nightborne hurt animation
static const int max_nb_hurt = 320;
static const sfIntRect nb_hurt = {0, 240, 80, 80};

// setting nightborne dead animation
static const int max_nb_die = 1760;
static const sfIntRect nb_die = {0, 320, 80, 80};

#endif /* ENNEMY_H_ */
