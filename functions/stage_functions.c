// Not used anymore 
//void show_stage(char stage[map_x][map_y]) {
//
//		int i, j;
//		for (i = screen_y - 1; i > -1; i--) {
//				for (j = 0; j < screen_x; j++)
//						printf("%c", stage[j][i]);
//				printf("\n");
//		}
//}


		/* // parece errado, mas funciona '-' */
		/* for (y = half_column + p.y; y  > p.y - half_column; y--) { */
		/* 		for (x = p.x - half_line; x < half_line + p.x; x++) { */ 
		/* 				if (y > map_y - 1 || x > map_x - 1 || x < 0 || y < 0) */
		/* 						printf(purple pos_final_frontier reset); */
		/* 				else if (stage[x][y] == ground) */
		/* 						printf(green "%c" reset, stage[x][y]); */
		/* 				else if (stage[x][y] == final_frontier) */
		/* 						printf(red "%c" reset, stage[x][y]); */
		/* 				else */
		/* 						printf("%c", stage[x][y]); */
		/* 		} */		

		/* 		printf(grey border " \n " reset); */
		/* } */


void create_stage(char stage[map_y][map_x]) {

		int x, y;
		// Cria apenas o mapa, moldura ao qual o personagem nao pode ultrapassar
		/* for (y = 0; y < map_y; y++) */
		/* 		stage[0][y] = final_frontier; */

		/* for (y = 0; y < map_y; y++) */
		/* 		stage[map_x - 1][y] = final_frontier; */

		/* for (x = 0; x < map_x; x++) */
		/* 		stage[x][0] = final_frontier; */

		/* for (x = 0; x < map_x; x++) */
		/* 		stage[x][map_y - 1] = final_frontier; */

		/* for (y = 1; y < map_y - 1; y++) */
		/* 		for (x = 1; x < map_x - 1; x++) */
		/* 				stage[x][y] = ground; */

		// Monte seu mapa aqui

		//for (y = 1; y < 9; y++)
		//		stage[y][6] = warl;

		//memset(stage, '\0', sizeof(stage));




	}

#define reset       "\x1B[0m"
#define red         "\x1B[31m"
#define green       "\x1B[32m"
#define yellow      "\x1B[32m"
#define blue        "\x1B[34m"
#define purple      "\x1B[35m"
#define light_green "\x1B[36m"
#define grey        "\x1B[37m"
#define border      "\x1B[7m"

void show_stage_relative(char stage[map_y][map_x], person p) {

		int x, y, i;

		for (i = 0; i < screen_x + 4; i++)
				printf(grey border " " reset);

		// Imprime borda superior
		printf("\n" grey border "  " reset);

		// Imprime mapa

		for (y = p.y + (screen_y / 2) - 1 ; y > p.y - (screen_y / 2) - 1; y--) {
				for (x = p.x - (screen_x / 2) - 1; x < p.x + (screen_x / 2) - 1; x++) {
						if (y > map_y -1 || x > map_x - 1 || x < 0  || y < 0 || stage[y][x] == pos_final_frontier_char )
								printf(grey border pos_final_frontier_symbol reset);
						else switch(stage[y][x]) {
								case ground: printf(ground_symbol reset, stage[y][x]); break;
								case wall  : printf(border red " " reset); break;
								case face_up_char: printf(face_up_symbol); break;
								case face_right_char: printf(face_right_symbol); break;
								case face_left_char: printf(face_left_symbol); break;
								case face_down_char: printf(face_down_symbol); break;
								case letter_char: printf(letter_symbol); break;
								case zombie_char: printf(zombie_symbol); break;
								case safe_box_char: printf(safe_box_symbol); break;
								case key_char: printf(key_symbol); break;
								case end_level_char: printf(end_level_symbol); break;
								case puzzle_box_char: printf(puzzle_box_symbol); break;
								default: printf("%c", stage[y][x]); break;
						}
				}
		//Imprime bordas adjacentes 
				printf(grey border "  \n  " reset);
		}

		// Imprime borda inferior
		for (i = 0; i < screen_x + 2; i++)
				printf(grey border " " reset);

		//printf("\np.x = %d   p.y = %d \n \n", p.x, p.y);
		printf("\n");





}

