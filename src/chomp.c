/*
 * Chomp: chomps bytes from standard input
 * Copyright (C) 2022 Paolo Perego <paolo@codiceinsicuro.i>
 *
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include<stdio.h>
#include<stddef.h>
#include<string.h>
#include"chomp.h"

int chomp(char *dst, const char *src, int bytes_to_chomp) {
    if (src == NULL)
        return -1;
    if (strcmp(src, "") == 0)
        return -1;
    if ((bytes_to_chomp > strlen(src)) || (bytes_to_chomp < 0))
        return -1;
    strncpy(dst, src, strlen(src) - bytes_to_chomp);
    return 0;
}
