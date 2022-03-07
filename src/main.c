/*
 * chomp: it chomps bytes from its standard input

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
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"chomp.h"


int main(int argc, char **argv) {
    char in[MAX_BUFFER], out[MAX_BUFFER];
	int ret;

	memset(in, 0, MAX_BUFFER);
	memset(out, 0, MAX_BUFFER);

	fgets(in, MAX_BUFFER, stdin);
	ret = chomp(out, in, 1);
	fprintf(stdout, "%s", out);
	return ret;
}
