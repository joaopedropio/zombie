#define screen_x 90   // full, font 9 = 190 /// half, font 9 = 90///  full, font 14 = 118 
#define screen_y 34   // full, font 9 = 40  /// half, font 9 = 40///  full, font 14 = 26
#define map_x 43
#define map_y 23 

#define person_begin_x 15
#define person_begin_y 11

#define door_vertical '|'
#define door_horizontal '_'

#define right 'd'
#define left 'a'
#define up 'w'
#define down 's'
#define fire_key 't'
#define menu_key 'p'

#define zombie_delay 10 
#define zombie_bite 5
#define sleep_time 15000 //15000

#define face_up_char '^'
#define face_down_char 'v'
#define face_right_char '>'
#define face_left_char '<'

#define letter_char 'C'
#define puzzle_box_char 'B'
#define zombie_char 'Z'
#define safe_box_char 'S'
#define ground '.'
#define final_frontier '#'
#define pos_final_frontier_char '&'
#define wall '#'
#define key_char 'K'
#define end_level_char 'E'

#define ground_symbol " "
#define pos_final_frontier_symbol "\u2591"
#define face_up_symbol    "\u25b4"
#define face_right_symbol "\u25b8"
#define face_left_symbol  "\u25c0"
#define face_down_symbol  "\u25bc"
#define letter_symbol "\u2709"
#define zombie_symbol "\u2697"
#define safe_box_symbol "\u2680"
#define key_symbol "\u26b7" 
#define end_level_symbol "\u03a0"
#define puzzle_box_symbol "\u25a9" 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

#include "functions/person_functions.c"
#include "functions/stage_functions.c"
#include "functions/letter_functions.c"
#include "functions/zombie_functions.c"
#include "functions/door_funtions.c"
#include "functions/puzzle_box_functions.c"
#include "functions/safe_box_functions.c"
#include "functions/end_level.c"
#include "keyboard_hit.c"

void key_pressed(char key, person *p, int *out, char stage[map_y][map_x], struct list_letter *l_letter) {

		if (key == fire_key)
				p->fire = 1;
		else if (p->dead == 1){
				*out = 1;
				printf("DEAD!");
		} else if (key == 'q') {
				printf("QUIT!");
				*out = 1;
		} else if (key == 'o')
				menu_letter(p, l_letter);
		else
				person_movement(p, key, stage, &out);
}

int main (void) {
		init_attr();
		int out = 0;
		char stage[map_y][map_x];
		create_stage(stage);
		person p;
		create_person(&p, person_begin_x, person_begin_y);
		#include "create.c"
		system("xset r rate 100 10");
		while (!out) {
				usleep(sleep_time);	
				char key = kbhit();
				system("clear");
				//printf("%c[f", 27);
				//printf("\e[1;1H\e[2J");
				show_stage_relative(stage, p);

				//###################################################################
				// Aqui sao colocadas as funcoes a serem executadas dos objetos do mapa
				// Portas
				execute_door(stage, l_door, &p);

				// Zombis
				execute_zombie(&p, l_zombie, stage);

				// Carta
				execute_letter(stage, l_letter, &p);

				// Caixas de puzzle	
				execute_puzzle_box(stage, l_puzzle_box, &p);

				// Cofres
				execute_safe_box_password(stage, &p, l_safe_box);

				// Fim do jogo
				end_level(stage, &p, &out, 40, 12);		


				key_pressed(key, &p, &out, stage, l_letter);
		}
		system("xset r rate 660 25");
		return 0;
}
