/*
** EPITECH PROJECT, 2024
** player_data.h
** File description:
** contain data for player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_
    #include <SFML/Graphics.h>
    #include <SFML/System/Vector2.h>

// value of offset by default in 366 x 164 pixel sprite sheet
static const int offset = 52;

// Setting for idle animation of the hero
static const sfIntRect idle_anim = {0, 0, 52, 41};
static const int max_idle = 156;
static const sfVector2f idle_origin = {26, 20.5};

// Setting for run animation of the hero
static const sfIntRect run_anim = {0, 41, 52, 41};
static const int max_run = 260;
static const sfVector2f run_origin = {26, 61.5};

// Setting for jump animation of the hero
static const sfIntRect jump_anim = {0, 82, 52, 41};
static const int max_jump = 260;
static const sfVector2f jump_origin = {26, 102.5};

// Setting for die animation of the hero
static const sfIntRect die_anim = {0, 123, 52, 41};
static const int max_die = 312;
static const sfVector2f die_origin = {26, 143.5};


// fight feature for player

// draw sword
static const sfIntRect draw_sw = {0, 0, 52, 41};
static const int max_draw = 156;
static const sfVector2f draw_origin = {26, 20.5};

// sheathe the sword
static const sfIntRect sheathe_sword = {0, 41, 52, 41};
static const int max_sheathe = 156;
static const sfVector2f sheathe_origin = {26, 61.5};

// battle idle animation
static const sfIntRect idle_battle = {0, 82, 52, 41};
static const int max_battle = 156;
static const sfVector2f battle_origin = {26, 102.5};

// normal attack
static const sfIntRect up_slash = {0, 123, 52, 41};
static const int max_up_slash = 208;
static const sfVector2f up_slash_origin = {26, 143.5};

// normal attack 2
static const sfIntRect slash = {0, 164, 52, 41};
static const int max_slash = 260;
static const sfVector2f slash_origin = {26, 184.5};

// back slash
static const sfIntRect back_slash = {0, 205, 52, 41};
static const int max_back_slash = 260;
static const sfVector2f back_slash_origin = {26, 225.5};

// final attack
static const sfIntRect final_slash = {0, 246, 52, 41};
static const int max_final_slash = 624;
static const sfVector2f final_slash_origin = {26, 266.5};

// get hurt animation
static const sfIntRect hurt_anim = {0, 287, 52, 41};
static const int max_hurt = 104;
static const sfVector2f hurt_origin = {26, 307.5};

// diying animation
static const sfIntRect dying_anim = {0, 328, 52, 41};
static const int max_dying = 301;
static const sfVector2f dying_origin = {26, 348.5};

#endif /* PLAYER_H_ */
