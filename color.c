/*
 * Copyright (C) 2014 haru <uobikiemukot at gmail dot com>
 * Copyright (C) 2014 Hayaki Saito <user@zuse.jp>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>
#include <string.h>
#include "color.h"

/*
    The default color list

    byte order: (MSB) RR GG BB (LSB)
*/
uint32_t color_list[256] = {
    /* system color: 16 */
    0x262626, 0xd70000, 0x5f8700, 0xaf8700, 0x0087ff, 0xaf005f, 0x0087ff, 0xe4e4e4,
    0x1c1c1c, 0xd75f00, 0x585858, 0x626262, 0x808080, 0x5f5faf, 0x8a8a8a, 0xffffd7,
    /* color cube: 216 */
    0x000000, 0x00005F, 0x000087, 0x0000AF, 0x0000D7, 0x0000FF, 0x005F00, 0x005F5F,
    0x005F87, 0x005FAF, 0x005FD7, 0x005FFF, 0x008700, 0x00875F, 0x008787, 0x0087AF,
    0x0087D7, 0x0087FF, 0x00AF00, 0x00AF5F, 0x00AF87, 0x00AFAF, 0x00AFD7, 0x00AFFF,
    0x00D700, 0x00D75F, 0x00D787, 0x00D7AF, 0x00D7D7, 0x00D7FF, 0x00FF00, 0x00FF5F,
    0x00FF87, 0x00FFAF, 0x00FFD7, 0x00FFFF, 0x5F0000, 0x5F005F, 0x5F0087, 0x5F00AF,
    0x5F00D7, 0x5F00FF, 0x5F5F00, 0x5F5F5F, 0x5F5F87, 0x5F5FAF, 0x5F5FD7, 0x5F5FFF,
    0x5F8700, 0x5F875F, 0x5F8787, 0x5F87AF, 0x5F87D7, 0x5F87FF, 0x5FAF00, 0x5FAF5F,
    0x5FAF87, 0x5FAFAF, 0x5FAFD7, 0x5FAFFF, 0x5FD700, 0x5FD75F, 0x5FD787, 0x5FD7AF,
    0x5FD7D7, 0x5FD7FF, 0x5FFF00, 0x5FFF5F, 0x5FFF87, 0x5FFFAF, 0x5FFFD7, 0x5FFFFF,
    0x870000, 0x87005F, 0x870087, 0x8700AF, 0x8700D7, 0x8700FF, 0x875F00, 0x875F5F,
    0x875F87, 0x875FAF, 0x875FD7, 0x875FFF, 0x878700, 0x87875F, 0x878787, 0x8787AF,
    0x8787D7, 0x8787FF, 0x87AF00, 0x87AF5F, 0x87AF87, 0x87AFAF, 0x87AFD7, 0x87AFFF,
    0x87D700, 0x87D75F, 0x87D787, 0x87D7AF, 0x87D7D7, 0x87D7FF, 0x87FF00, 0x87FF5F,
    0x87FF87, 0x87FFAF, 0x87FFD7, 0x87FFFF, 0xAF0000, 0xAF005F, 0xAF0087, 0xAF00AF,
    0xAF00D7, 0xAF00FF, 0xAF5F00, 0xAF5F5F, 0xAF5F87, 0xAF5FAF, 0xAF5FD7, 0xAF5FFF,
    0xAF8700, 0xAF875F, 0xAF8787, 0xAF87AF, 0xAF87D7, 0xAF87FF, 0xAFAF00, 0xAFAF5F,
    0xAFAF87, 0xAFAFAF, 0xAFAFD7, 0xAFAFFF, 0xAFD700, 0xAFD75F, 0xAFD787, 0xAFD7AF,
    0xAFD7D7, 0xAFD7FF, 0xAFFF00, 0xAFFF5F, 0xAFFF87, 0xAFFFAF, 0xAFFFD7, 0xAFFFFF,
    0xD70000, 0xD7005F, 0xD70087, 0xD700AF, 0xD700D7, 0xD700FF, 0xD75F00, 0xD75F5F,
    0xD75F87, 0xD75FAF, 0xD75FD7, 0xD75FFF, 0xD78700, 0xD7875F, 0xD78787, 0xD787AF,
    0xD787D7, 0xD787FF, 0xD7AF00, 0xD7AF5F, 0xD7AF87, 0xD7AFAF, 0xD7AFD7, 0xD7AFFF,
    0xD7D700, 0xD7D75F, 0xD7D787, 0xD7D7AF, 0xD7D7D7, 0xD7D7FF, 0xD7FF00, 0xD7FF5F,
    0xD7FF87, 0xD7FFAF, 0xD7FFD7, 0xD7FFFF, 0xFF0000, 0xFF005F, 0xFF0087, 0xFF00AF,
    0xFF00D7, 0xFF00FF, 0xFF5F00, 0xFF5F5F, 0xFF5F87, 0xFF5FAF, 0xFF5FD7, 0xFF5FFF,
    0xFF8700, 0xFF875F, 0xFF8787, 0xFF87AF, 0xFF87D7, 0xFF87FF, 0xFFAF00, 0xFFAF5F,
    0xFFAF87, 0xFFAFAF, 0xFFAFD7, 0xFFAFFF, 0xFFD700, 0xFFD75F, 0xFFD787, 0xFFD7AF,
    0xFFD7D7, 0xFFD7FF, 0xFFFF00, 0xFFFF5F, 0xFFFF87, 0xFFFFAF, 0xFFFFD7, 0xFFFFFF,
    /* gray scale: 24 */
    0x080808, 0x121212, 0x1C1C1C, 0x262626, 0x303030, 0x3A3A3A, 0x444444, 0x4E4E4E,
    0x585858, 0x626262, 0x6C6C6C, 0x767676, 0x808080, 0x8A8A8A, 0x949494, 0x9E9E9E,
    0xA8A8A8, 0xB2B2B2, 0xBCBCBC, 0xC6C6C6, 0xD0D0D0, 0xDADADA, 0xE4E4E4, 0xEEEEEE,
};

/*
  ANSI colors

  Original seq2gif colors
  - palette16_solarized256

  Taken from http://en.wikipedia.org/wiki/ANSI_escape_code
  - palette16_standard_vga Standard VGA colors
  - palette16_winxp_cmd    Windows XP CMD
  - palette16_power_shell  PowerShell
  - palette16_terminal_app Terminal.app
  - palette16_putty        PuTTY
  - palette16_mirc         mIRC
  - palette16_xterm        xterm
  - palette16_css          CSS/HTML (incomplete)
  - palette16_x11          X (incomplete)
  - palette16_ubuntu       Ubuntu

  Taken from https://blogs.msdn.microsoft.com/commandline/2017/08/02/updating-the-windows-console-colors/
  - palette16_win_console  Windows Console (new colors)

  rosaterm default
  - palette16_rosaterm
*/

static const uint32_t palette16_solarized256[16] = {
    0x262626, 0xd70000, 0x5f8700, 0xaf8700, 0x0087ff, 0xaf005f, 0x0087ff, 0xe4e4e4,
    0x1c1c1c, 0xd75f00, 0x585858, 0x626262, 0x808080, 0x5f5faf, 0x8a8a8a, 0xffffd7,
};

static const uint32_t palette16_standard_vga[16] = {
    0x000000, 0xAA0000, 0x00AA00, 0xAA5500, 0x0000AA, 0xAA00AA, 0x00AAAA, 0xAAAAAA,
    0x555555, 0xFF5555, 0x55FF55, 0xFFFF55, 0x5555FF, 0xFF55FF, 0x55FFFF, 0xFFFFFF,
    /*
    0x000000, 0xAA0000, 0x00AA00, 0xAA5500, 0x0000AA, 0xAA00AA, 0x00AAAA, 0xAAAAAA,
    0x555555, 0xFF5555, 0x55FF55, 0xFFFF55, 0x5555FF, 0xFF55FF, 0x55FFFF, 0xDFDFDF,
    */
};

static const uint32_t palette16_winxp_cmd[16] = {
    0x000000, 0x800000, 0x008000, 0x808000, 0x000080, 0x800080, 0x008080, 0xC0C0C0,
    0x808080, 0xFF0000, 0x00FF00, 0xFFFF00, 0x0000FF, 0xFF00FF, 0x00FFFF, 0xFFFFFF,
};

static const uint32_t palette16_power_shell[16] = {
    0x000000, 0x800000, 0x008000, 0xEEEDF0, 0x000080, 0x012456, 0x008080, 0xC0C0C0,
    0x808080, 0xFF0000, 0x00FF00, 0xFFFF00, 0x0000FF, 0xFF00FF, 0x00FFFF, 0xFFFFFF,
};

static const uint32_t palette16_win_console[16] = {
    0x0c0c0c, 0xc50f1f, 0x13a10e, 0xc19c00, 0x0037da, 0x881798, 0x3a96dd, 0xcccccc,
    0x767676, 0xe74856, 0x16c60c, 0xf9f1a5, 0x3b78ff, 0xb4009e, 0x61d6d6, 0xf2f2f2,
};

static const uint32_t palette16_terminal_app[16] = {
    0x000000, 0xC23621, 0x25BC24, 0xADAD27, 0x492EE1, 0xD338D3, 0x33BBC8, 0xCBCCCD,
    0x818383, 0xFC391F, 0x31E722, 0xEAEC23, 0x5833FF, 0xF935F8, 0x14F0F0, 0xE9EBEB,
};

static const uint32_t palette16_putty[16] = {
    0x000000, 0xBB0000, 0x00BB00, 0xBBBB00, 0x0000BB, 0xBB00BB, 0x00BBBB, 0xBBBBBB,
    0x555555, 0xFF5555, 0x55FF55, 0xFFFF55, 0x5555FF, 0xFF55FF, 0x55FFFF, 0xFFFFFF,
};

static const uint32_t palette16_xterm[16] = {
    0x000000, 0xCD0000, 0x00CD00, 0xCDCD00, 0x0000EE, 0xCD00CD, 0x00CDCD, 0xE5E5E5,
    0x7F7F7F, 0xFF0000, 0x00FF00, 0xFFFF00, 0x5C5CFF, 0xFF00FF, 0x00FFFF, 0xFFFFFF,
};

static const uint32_t palette16_mirc[16] = {
    0x000000, 0x7F0000, 0x009300, 0xFC7F00, 0x00007F, 0x9C009C, 0x009393, 0xD2D2D2,
    0x7F7F7F, 0xFF0000, 0x00FC00, 0xFFFF00, 0x0000FC, 0xFF00FF, 0x00FFFF, 0xFFFFFF,
};

/* non terminal colors (without full specification of bright colors)
static const uint32_t palette16_x11[16] = {
    0x000000, 0xFF0000, 0x008000, 0xFFFF00, 0x0000FF, 0xFF00FF, 0x00FFFF, 0xFFFFFF,
    unknown,  unknown,  0x90EE90, 0xE1FFE0, 0xADD8E6, unknown,  0xE0FFFF, unknown,
};

static const uint32_t palette16_css[16] = {
    0x000000, 0xFF0000, 0x00FF00, 0xFFFF00, 0x0000FF, 0xFF00FF, 0x00FFFF, 0xFFFFFF,
    unknown,  unknown,  0x90EE90, 0xFFFFE0, 0xADD8E6, unknown,  0xE0FFFF, unknown,
}; */

static const uint32_t palette16_ubuntu[16] = {
    0x010101, 0xDE382B, 0x39B54A, 0xFFC706, 0x006FB8, 0x762671, 0x2CB5E9, 0xCCCCCC,
    0x808080, 0xFF0000, 0x00FF00, 0xFFFF00, 0x0000FF, 0xFF00FF, 0x00FFFF, 0xFFFFFF,
};

const uint32_t* color_parse_palette16(const char* name) {
  if (strcmp(name, "vga") == 0)
    return palette16_standard_vga;
  else if (strcmp(name, "cmd") == 0)
    return palette16_winxp_cmd;
  else if (strcmp(name, "win") == 0)
    return palette16_win_console;
  else if (strcmp(name, "powershell") == 0)
    return palette16_power_shell;
  else if (strcmp(name, "app") == 0)
    return palette16_terminal_app;
  else if (strcmp(name, "putty") == 0)
    return palette16_putty;
  else if (strcmp(name, "mirc") == 0)
    return palette16_mirc;
  else if (strcmp(name, "xterm") == 0)
    return palette16_xterm;
  else if (strcmp(name, "solarized256") == 0)
    return palette16_solarized256;
  else if (strcmp(name, "ubuntu") == 0)
    return palette16_ubuntu;
  else
    return NULL;
}

/* emacs Local Variables:      */
/* emacs mode: c               */
/* emacs tab-width: 4          */
/* emacs indent-tabs-mode: nil */
/* emacs c-basic-offset: 4     */
/* emacs End:                  */
/* vim: set expandtab ts=4 : */
/* EOF */
