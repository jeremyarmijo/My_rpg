/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** foncitons tpg
*/

#ifndef RPG
    #define RPG
    #include <stddef.h>
    #include <SFML/Audio/Music.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Config.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window/Types.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "my_macro.h"

enum statement {
    HOVER = 0,
    PRESSED,
    NONE
};

typedef struct path_sprites_s {
    char *basic;
    char *is_hover;
    char *is_pressed;
} path_sprites_t;

typedef struct button_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f size;
    sfVector2f position;
    path_sprites_t *paths;
    int is_active;
    int is_released;
    float radius;
    struct button_s *previous_state;
    enum statement button_state;
    struct button_s *next;
} button_t;

typedef struct fight_s {
    int health;
    int stat_attack;
    int stat_defense;
    sfSprite *life_bar;
    sfSprite **pixel_life;
    sfSprite *menu_attack;
    button_t *attack;
} fight_t;

typedef struct map_enemy_s {
    sfSprite *sprite;
    sfTexture *texture;
} map_enemy_t;

typedef struct option_s {
    int shield;
    int apple;
    int speed_potion;
    int skull;
    bool armor;
    bool bag;
    int bread;
    int meat;
    int max_item;
} option_t;

typedef struct player_s {
    int save;
    int level;
    option_t inventory;
    sfSprite *body;
    sfTexture *skin;
    sfIntRect move;
    int hp;
    int mana;
    int atk;
    int def;
    float speed;
    bool is_left;
    bool is_moving;
    fight_t *fight;
} player_t;

typedef struct scene_s {
    sfTexture *texture;
    sfSprite *sprite;
    button_t *button;
    int status;
    button_t *exit_game;
    struct scene_s *next;
} scene_start_t;

typedef struct battle_s {
    int hp;
    int hp_max;
    int mana;
    int atk;
    int def;
    sfIntRect move;
    sfTexture *texture;
    sfSprite *sprite;
    sfRectangleShape *life_bar;
    sfRectangleShape *bord;
    sfRectangleShape *part_of_life;
    sfRectangleShape *energy;
    sfTexture *m_tex;
    sfSprite *menu_attack;
    button_t *attack;
    button_t *attack_sp1;
    button_t *attack_sp2;
} battle_t;

typedef struct blank_stage_s {
    sfTexture *texture;
    sfSprite *sprite;
    battle_t *player;
    battle_t *enemy;
} blank_stage_t;

typedef struct main_menu_s {
    sfSprite *back_menu_sprite;
    sfTexture *back_menu_texture;
    button_t *exit_menu;
    button_t *setting;
    button_t *saving;
    button_t *player_option;
    button_t *loading;
} main_menu_t;

typedef struct fight_event_s {
    int level;
    bool level_1;
    bool level_2;
    bool level_3;
    bool atk_move;
    bool end_fight;
    bool player_turn;
    bool start_fight;
    bool up_slash;
    bool slash;
    bool atk_sp;
    bool ult_sp;
    bool enemy_fight;
    bool dead_step;
} fight_event_t;

typedef struct gamestat_s {
    bool start_menu;
    bool menu;
    bool music;
    bool son;
    bool enable_move;
    bool game_in;
    bool in_fight;
    bool in_move;
    bool run_anim;
    bool depressed;
    bool display;
    bool intro;
    fight_event_t *level;
} gamestat_t;

typedef struct sound_database_s {
    sfMusic *hit;
    sfMusic *in_fight;
} sound_database_t;

typedef struct param_win_s {
    sfRenderWindow *window;
    sfEvent event;
    sfBool click;
    sfTime time;
    sfClock *clock;
    sfVector2u size_window;
    gamestat_t *gamestat;
    player_t *player;
    blank_stage_t *battle_stage;
    main_menu_t *menu;
    map_enemy_t *map_enemy;
    int which_scene;
    sfMusic* main_music;
    sound_database_t sounds;
    bool language;
} param_win_t;

void main_scene(param_win_t *win);
void free_all(param_win_t *win, scene_start_t *start_scene);
int my_grep(char *haystack, char *needle);
void set_language(param_win_t *win, button_t *french, button_t *english);
void hit_sound(param_win_t *win);
void reset_sound(param_win_t *win);
void sound_in_fight(param_win_t *win);
void set_default_music(param_win_t *win);
void skull_management(param_win_t *win, sfVector2f pos);
void display_stat(param_win_t *win, sfVector2f pos);
void speed_potion(param_win_t *win, sfVector2f pos);
void armor_management(param_win_t *win, sfVector2f pos);
void draw_text_dynamic(param_win_t *win, sfVector2f pos, char *ref, int nb);
void bread_management(param_win_t *win, sfVector2f pos);
void bag_management(param_win_t *win, sfVector2f pos);
void meat_management(param_win_t *win, sfVector2f pos);
void shield_management(param_win_t *win, sfVector2f pos);
void apple_management(param_win_t *win, sfVector2f pos);
void draw_text(char *str, sfVector2f pos, param_win_t *win,
    unsigned int police_size);
void display_command_list(param_win_t *win);
void display_size_win(param_win_t *win, sfVector2f pos);
void manage_volume(button_t *button, param_win_t *win, sfVector2f pos
    , bool which);
void display_volume(param_win_t *win, sfVector2f pos);
bool active_button(button_t *button, param_win_t *win);
void resize_win(param_win_t *win, button_t *button,
    sfVector2u size, sfVector2f pos);
void free_button(button_t *button);
bool save_game(void);
char *verif_save(unsigned int nb, param_win_t *win, int save);
void manage_action_player_option(button_t *button, param_win_t *win);
void manage_action_setting(button_t *button, param_win_t *win);
void manage_action_loading(button_t *button, param_win_t *win);
void manage_action_save(button_t *button, param_win_t *win);
void level1(param_win_t *win);
void level2(param_win_t *win);
void level3(param_win_t *win);
void reset_level(const char *path_map, param_win_t **win,
    sfVector2f size, sfVector2f pos);
bool attribute_back_action(button_t *button_to_active,
    button_t *button_to_exit, param_win_t *win);
void return_back_state(param_win_t *win);
void reset_action(param_win_t *win);
void button_management(button_t *button, param_win_t *win);
void display_menu(param_win_t *win);
void set_previous_state(main_menu_t *menu);
void configure_setting(button_t *setting, main_menu_t *menu);
void set_position_sprites(button_t *exit_menu, button_t *saving,
    button_t *loading, button_t *player_option);
main_menu_t *init_menu(void);
player_t *init_player(char *path_picture);
void set_position_size(button_t **button, sfVector2f
    position, sfVector2f scale);
void set_position_size(button_t **button, sfVector2f position,
    sfVector2f scale);
char *duplicate_string(char const *src);
void check_event_type(param_win_t *win);
scene_start_t *init_start_scene(void);
bool set_sprite_and_texture(button_t **button,
    char *path_none, char *path_is_hover, char *path_is_pressed);
void set_sprite_button_state(button_t *start_scene, param_win_t *win);
void set_state_button(button_t *button, enum statement button_state);
int my_rpg(void);
sfBool is_hover_button(button_t *button, param_win_t *config);
void close_win(param_win_t **win, scene_start_t *start_scene);
void load_start_scene(scene_start_t *start_scene, param_win_t *win);
button_t *init_button(char *basic, char *over, float x, float y);
scene_start_t *init_fight_scene(void);
void set_player_caractere_sprite(param_win_t **win);
bool set_scene(scene_start_t **scene, const char *path_picture,
    float x, float y);
void set_scale(scene_start_t **scene, sfVector2f scale);
scene_start_t *init_start_scene(void);
param_win_t *init_game_status(void);
button_t *init_exit_button(char *normal, char *over);

// player in map animation | player_move.c
void set_gamestatus(param_win_t *win);
void player_moves(param_win_t *win);
void idle_animation(param_win_t *win);

// player fight animation | start_fight.c
void start_fight(param_win_t *win);
void time_mov(float level);
void print_menu_attack(param_win_t *win, int mana);
void set_player_ult_attack(param_win_t **win);

// player fighting animation | fight_player_animation.c
void player_battle_animation(param_win_t *win);
void handle_battle_animation(param_win_t *win);

void death_bringer_fight_move(param_win_t *win);
void draw_intro(param_win_t *win);
bool choice_bot_100(battle_t **player, battle_t **enemy);
void choice_bot_attack(battle_t **player, battle_t **enemy);

#endif /* RPG_H_ */
