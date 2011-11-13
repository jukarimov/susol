/*
   	Susol - sudoku solver
    Copyright (C) 2011 Jalil U. Karimov <jukarimov@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
*/
#include "main.h" 
 
int main(int foo, char *bar[]) 
{
	if (foo < 2) {
		puts("Give me a Sudoku file");  
		return -1;
	}

	input(bar[1]);
	getdat();

	if (fill_min() != -1) {
		if (chkdat() != 0)
			fprintf(stderr, "fill_min: Wrong solution\n");
		output(DAT, "output.min");
	} else
		fprintf(stderr, "fill_min: failed\n");

/*
	int anti_shit = 10, c = 0;

	while (1) {

		if (++c > anti_shit) {
    		fprintf(stderr, "Go green :D...\n"); 
			break;
		}

		if (fill_next(bar[1], bar[2]) != -1) {
			if (chkdat() != 0)
				fprintf(stderr, "fill_next: Wrong solution\n");
			printf("# %d\n", c);
			output(DAT, bar[1]);
			logdat(DAT, "log");
		}
		else
			break;
	}

*/

	getdat();  

	if (fill_max() != -1)
		if (chkdat() != 0)
			fprintf(stderr, "fill_max: Wrong solution\n");
		output(DAT, "output.max");
	else 
		fprintf(stderr, "fill_max: failed\n");

    return 0; 
}

