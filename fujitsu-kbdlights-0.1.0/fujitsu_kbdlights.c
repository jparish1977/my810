/*
 *  Copyright (c) 2009, 2010 zmiq2
 *
 *  Actuvate keyboard lights for Fujitsu U810, U820
 *
 *  2010.07.23 zmiq2: created
 *                   
 */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */
#define VERSION "0.1.0"
#define MODULE	"fujitsu_kbdlights"

#define LEDS_SYSPATH	"/sys/devices/platform/fujitsu-laptop/leds/fujitsu::kblamps/brightness"
#define LEDS_ON		255
#define LEDS_OFF	0

#include <stdio.h>
#include <stdlib.h>

void show_help(void) {
	printf("fujitsu keyboard lights utility - version %s\n", VERSION);
	printf("usage: %s {on|off|toggle}\n", MODULE);
}

int get_leds()
{
	int leds;

	FILE *fd;
	fd=fopen(LEDS_SYSPATH,"r");
        if(fd) {
		fscanf(fd,"%d",&leds);
		fclose(fd);
		return(leds);
        }
        else {
        	printf("%s::error::parameter not available [%s]\n",MODULE,LEDS_SYSPATH);
        }

	return(-1);
}

void set_leds(int ival)
{
	FILE *fd;
	fd=fopen(LEDS_SYSPATH,"w");
        if(fd) {
		fprintf(fd,"%d",ival);
		fclose(fd);
        }
        else {
        	printf("%s::error::parameter not available [%s]\n",MODULE,LEDS_SYSPATH);
        }
}

main(int argc, char** argv)
{
	FILE *fd;
	int pval;

	if(argc!=2) {
		show_help();
		exit(1);
	}

	if(strncmp(argv[1],"on",2)==0) {
		set_leds(LEDS_ON);
		exit(0);
	}
	if(strncmp(argv[1],"off",3)==0) {
		set_leds(LEDS_OFF);
		exit(0);
	}
	if(strncmp(argv[1],"toggle",6)==0) {
		pval=get_leds();
		if(pval==LEDS_ON) {
			set_leds(LEDS_OFF);
			exit(0);
		}
		if(pval==LEDS_OFF) {
			set_leds(LEDS_ON);
			exit(0);
		}
	}

	show_help();
	exit(1);
}
