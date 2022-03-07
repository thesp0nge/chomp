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

#ifndef CHOMP_H
#define CHOMP_H

#define MAX_BUFFER	2048

int chomp(char *dst, const char *src, int bytes_to_chomp);
#endif /* CHOMP_H */
