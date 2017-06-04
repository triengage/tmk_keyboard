/*
 * SpaceFN layout
 * http://geekhack.org/index.php?topic=51069.0
 */
#include "keymap_common.h"
#include "led.h"



const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: default
     * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.     ,-----------.
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|     |Pwr|Slp|Wak|
     * `---'   `---------------' `---------------' `---------------' `-----------'     `-----------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backspa| |Ins|Hom|PgU| |NmL|  /|  *|  -|
     * |-----------------------------------------------------------| |-----------| |---------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \| |Del|End|PgD| |  7|  8|  9|   |
     * |-----------------------------------------------------------| `-----------' |-----------|  +|
     * |CapsLo|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |               |  4|  5|  6|   |
     * |-----------------------------------------------------------|     ,---.     |---------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     |Up |     |  1|  2|  3|   |
     * |-----------------------------------------------------------| ,-----------. |-----------|Ent|
     * |Ctrl |Gui |Alt |         Space         |Alt |Gui |Menu|Ctrl| |Lef|Dow|Rig| |      0|  .|   |
     * `-----------------------------------------------------------' `-----------' `---------------'
     */
    KEYMAP(
    ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           PSCR,FN3,BRK,
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     LGUI, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     DEL, END, PGDN,    P7,  P8,  P9,
    FN0,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,                         P4,  P5,  P6,  PPLS,
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT,          UP,           P1,  P2,  P3,
    LCTL,LGUI,LALT,          SPACE,                     RALT,RGUI,APP, FN2,     LEFT,DOWN,RGHT,    P0,       PDOT,PENT
    ),

    /* 1: SpaceFN
     * ,-----------------------------------------------------------.
     * |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Delete |
     * |-----------------------------------------------------------|
     * |     |   |   |Esc|   |   |   |Hom|Up |End|Psc|Slk|Pau|Ins  |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |PgU|Lef|Dow|Rig|   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |Spc|PgD|`  |~  |   |Men|          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     */
    KEYMAP(
    ESC, PWR, SLEP, WAKE, F4, F5, MPRV, MPLY, MNXT, MUTE, VOLU, VOLD, F12,     PSCR,FN3,BRK,
    GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,      INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,
    TRNS,TRNS,TRNS,ESC, TRNS,TRNS,TRNS,HOME,UP,  END, PSCR,SLCK,PAUS,INS,      DEL, END, PGDN,    P7,  P8,  P9,
    FN0,FN5,TRNS,TRNS,TRNS,TRNS,PGUP,LEFT,DOWN,RGHT,TRNS,TRNS,     TRNS,                        P4,  P5,  P6,  PPLS,
    TRNS,FN4,FN6,FN7,FN8,SPC, PGDN,GRV, FN1, TRNS,APP,           TRNS,          UP,           P1,  P2,  P3,
    TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS,     LEFT,DOWN,RGHT,    P0,       PDOT,PENT
    ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case 0:
            return (record->event.pressed ?
                    MACRO( T(C), T(O), T(N), T(S), T(O), T(L), T(E), T(DOT), T(L), T(O), T(G), D(LSHIFT), T(9), T(0), U(LSHIFT), T(SCOLON),  END ) :
                    MACRO_NONE );
        case 1:
            return (record->event.pressed ?
                    MACRO( D(LGUI), T(L), U(LGUI), END ) :
                    MACRO_NONE );
        case 2:
            return (record->event.pressed ? 
                    MACRO( D(LCTL), T(Z), U(LCTL), END) :
                    MACRO_NONE );
        case 3:
            return (record->event.pressed ?
                    MACRO( D(LCTL), T(A), U(LCTL), END ) :
                    MACRO_NONE );
        case 4:
            return (record->event.pressed ?
                    MACRO( D(LCTL), T(X), U(LCTL), END ) :
                    MACRO_NONE );
        case 5:
            return (record->event.pressed ?
                    MACRO( D(LCTL), T(C), U(LCTL), END ) :
                    MACRO_NONE );
        case 6:
            return (record->event.pressed ?
                    MACRO( D(LCTL), T(V), U(LCTL), END ) :
                    MACRO_NONE );
    }
    return MACRO_NONE;
}

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TOGGLE(1),
    [1] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),    // tilde
    [2] = ACTION_MACRO(0), // will print 'hello' for example
    [3] = ACTION_MACRO(1), // lock the computer
    [4] = ACTION_MACRO(2), // undo
    [5] = ACTION_MACRO(3), // select all
    [6] = ACTION_MACRO(4), // cut
    [7] = ACTION_MACRO(5), // copy
    [8] = ACTION_MACRO(6), // paste
};

