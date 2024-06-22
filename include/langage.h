/*
** EPITECH PROJECT, 2024
** macro
** File description:
** for rpg
*/

#ifndef LANGAGE_H_
    #define LANGAGE_H_

    #define STRING_NOT_ACTIVE win->language ? " = Not active "
    #define STRING_F : "  = Non actif"
    #define STRING_ACTIVE win->language ? " = Active " : "  = Actif"

    #define SUCCESS_LOAD win->language ?
    #define SUCCESS_LOAD_E "Your game is successfully\n\t\t\t\tsaved !"
    #define SUCCESS_LOAD_F : " T'as partie est chargé"

    #define SUCCESS_SAVE win->language ?
    #define SUCCESS_SAVE_E "Your game is successfully\n\t\t\t\tloaded !"
    #define SUCCESS_SAVE_F : " T'as partie est sauvegardé"

    #define ERROR_LOAD_F : "\tTu n'as pas de sauvegarde"
    #define ERROR_LOAD_E win->language ? " You have nothing to save"

    #define ERROR_SAVE_E win->language ? "\tYou don't have a save"
    #define ERROR_SAVE_F : "\tTu n'as rien a sauvegarder"

#endif /* LANGUAGE_H_ */
