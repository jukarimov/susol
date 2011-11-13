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

int fill_min(void) 
{ 
	int i, j, start; 
	i = 0; 
	j = 0; 
	start = 1; 
	while (1) { 
	    //printf("Cell: [%d,%d]\n", i, j); 
	    //output(); 
		if (RAW[i][j] == '.') { 
			int res; 
			if ((res = search(i, j, start)) != -1) { 
				//printf("OK: [%d,%d]: %d\n", i, j, res); 
				DAT[i][j] = res; 
			} 
			else if (res == -1) { 
				//puts("Not possible"); 
				DAT[i][j] = 0; 
				dec(&i, &j); 
				if (i == -1) 
					break; 
				//printf("Moving Back to %d, %d\n", i, j); 
				while (DAT[i][j] == 9 || RAW[i][j] != '.') { 
				//printf("Skipped: %d, %d\n", i, j); 
					if (RAW[i][j] == '.') 
						DAT[i][j] = 0; 
						dec(&i, &j); 
						if (i == -1) 
							break; 
				}
				start = DAT[i][j] + 1; 
				continue; 
			} 
		} 
		if (i == 8 && j == 8) { 
			fprintf(stderr, "fill_min: Last cell reached.\n"); 
			return 0; 
		} 
		inc(&i, &j); 
		if (i == -1) 
			break; 
		start = 1; 
        //printf("Moving Forwad to %d, %d\n", i, j); 
	} 
 
	fprintf(stderr, "fill_min: Could not solve, or something...\n"); 
	return -1; 
} 

int fill_next(char *fromsu, char *raw) 
{
	
	int i, j, start; 

	input(fromsu);
	getdat();

	int TMP[MAX][MAX];
	datcpy(TMP);

	input(raw);
	getdat();

	//output(TMP, "tmp");

	i = 0;
	j = 0;
	start = TMP[i][j] + 1; 

	if (start == 10) { 
		inc(&i, &j); 
    		if (i == -1)
			break; 
		start = 1;
		fprintf(stderr, "start reseted\n"); 
	}

	int anti_shit = 10000000;
	while (1) {

		if (!--anti_shit) {
    		fprintf(stderr, "fill_next: Go green :D...\n"); 
			break;
		}

		//printf("@Cell: [%d,%d]: ", i, j); 

		if (RAW[i][j] == '.') {

			int res; 
			if ((res = search(i, j, start)) != -1) { 
				//printf("OK: %d\n", res); 
				DAT[i][j] = res; 
			}
			else if (res == -1) { 
				//printf("NONE\n"); 
				DAT[i][j] = 0; 
				dec(&i, & j); 
				if (i == -1) 
					break; 
				//printf("Moving Back to %d, %d\n", i, j); 
				start = TMP[i][j];
				continue;
			}
		}
		if (i == 8 && j == 8) { 
			fprintf(stderr, "fill_next: Last cell reached.\n"); 
			return 0; 
		}
		inc(&i, &j); 
		if (i == -1) 
			break; 
		start = TMP[i][j] + 1; 
		if (start == 10) { 
			fprintf(stderr, "start reseted\n"); 
			start = 1;
		}
	}
 
	fprintf(stderr, "fill_next: Could not solve, or something...\n"); 
	return -1; 
} 
	
int fill_max(void) 
{ 
    //freopen("log.txt", "w", stdout);  

	int i, j, start; 
	i = 0; 
	j = 0; 
	start = 9; 
	while (1) { 
	    //printf("Cell: [%d,%d]: ", i, j); 
		if (RAW[i][j] == '.') { 
			int res; 
			if ((res = searchbak(i, j, start)) != -1) { 
				//printf("OK: %d\n", res); 
				DAT[i][j] = res; 
			} 
			else if (res == -1) { 
				//puts("Not possible"); 
				DAT[i][j] = 0; 
				dec(&i, &j); 
				if (i == -1) 
					break; 
				//printf("Moving Back to %d, %d\n", i, j); 
				while (DAT[i][j] == 1 || RAW[i][j] != '.') { 
					//printf("Skipped: %d, %d\n", i, j); 
					if (RAW[i][j] == '.') 
						DAT[i][j] = 0; 
					dec(&i, &j); 
					if (i == -1) 
						break; 
				} 
				start = DAT[i][j] - 1; 
				continue; 
			} 
		} 
		if (i == 8 && j == 8) { 
			fprintf(stderr, "fill_max: Last cell reached.\n"); 
			return 0; 
		} 
		inc(&i, &j); 
		if (i == -1) 
			break; 
		start = 9; 
		//printf("Moving Forwad to %d, %d\n", i, j); 
	}

	fprintf(stderr, "fill_max: Could not solve, or something...\n"); 
	return -1; 
} 
