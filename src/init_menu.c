/*
** EPITECH PROJECT, 2024
** init
** File description:
** menu
*/
#include "my_rpg.h"

main_menu_t *attribute_button(button_t *player_option, button_t *exit_menu,
    button_t *saving, button_t *loading)
{
    main_menu_t *menu = malloc(sizeof(main_menu_t));

    menu->player_option = player_option;
    menu->exit_menu = exit_menu;
    menu->saving = saving;
    menu->loading = loading;
    return menu;
}

main_menu_t *init_menu(void)
{
    button_t *setting = init_button(P_SET_B, P_SET_BR, 0.25, 0.25);
    button_t *exit_menu = init_button(P_QUIT_BUTTON,
        P_QUIT_BUTTON_R, 0.25, 0.25);
    button_t *saving = init_button(P_SAVE_BUTTON,
        "scenes/start/button_square/Return Square Button_r.png", 0.30, 0.30);
    button_t *loading = init_button(P_LOAD_BUTTON,
        "scenes/start/button_large/Load Button_r.png", 0.30, 0.30);
    button_t *player_option = init_button(P_OPTION_BUTTON,
        "scenes/start/button_large/Options Button_r.png", 0.30, 0.30);
    main_menu_t *menu = attribute_button(
        player_option, exit_menu, saving, loading);

    configure_setting(setting, menu);
    set_position_sprites(exit_menu, saving, loading, player_option);
    set_previous_state(menu);
    return menu;
}
