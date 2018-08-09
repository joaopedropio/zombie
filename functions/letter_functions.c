typedef struct list_letter {
		int x, y;
		char *title;
		char number;
		char *message;
		int found;
		struct list_letter *link;
} list_letter;

void create_letter(char stage[map_y][map_x], struct list_letter **l_letter, int x, int y, char *title, char *message, int number) {

		/* struct list_letter *aux; */

		/* for (aux = l_letter; aux->link != NULL; aux = aux->link); */

		/* aux->link = malloc(sizeof(list_letter)); */
		/* aux = aux->link; */
		/* aux->x = x; */
		/* aux->y = y; */
		/* stage[x][y] = letter_char; */
		/* aux->number = number; */
		/* aux->message = message; */
		/* aux->title = title; */
		/* aux->found = 0; */
		/* aux->link = NULL; */

struct list_letter *aux;

		if (*l_letter == NULL) {
				*l_letter = malloc(sizeof(struct list_letter));
				(**l_letter).x = x;
				(**l_letter).y = y;
				(**l_letter).number = number;
				(**l_letter).message = message;
				(**l_letter).title = title;
				(**l_letter).found = 0;
				(**l_letter).link = NULL;
				stage[y][x] = letter_char;
				

		} else {
				for (aux = *l_letter; aux->link != NULL; aux = aux->link);

				aux->link = malloc(sizeof(list_letter));
				aux = aux->link;
				aux->x = x;
				aux->y = y;
				stage[y][x] = letter_char;
				aux->number = number;
				aux->message = message;
				aux->title = title;
				aux->found = 0;
				aux->link = NULL;
		}
}

/* void create_menu_letter(struct list_letter *list_letter) { */

/* 		list_letter = malloc(sizeof(struct list_letter)); */

/* 		list_letter->found = 0; */
/* 		list_letter->number = 0; */
/* 		list_letter->link = NULL; */

/* } */

void menu_letter(person *p, struct list_letter *l_letter) {

		int out = 0;

		while (!out) {

				int i, j = 0;
				int tam = 10;

				system("clear");
		
				// Printa borda superior
				for (i = 0; i < screen_x + 4; i++)
						printf(grey border " " reset);	
				printf("\n" grey border "  " reset);

				// Varre a lista por cartas encontradas
				struct list_letter *aux = l_letter;
				for (i = 0; i < screen_y; i++) {
						if (aux != NULL)
								while (aux != NULL){ 
										if (aux->found == 1) 
												break;
										aux = aux->link;
								}

						if (aux != NULL) {
								printf("%d. %s", aux->number - 48, aux->title);
								for (j = strlen(aux->title) + 3; j < screen_x; j++)
										printf(" ");
								printf(grey border "  \n  " reset);

						} else {
								if (i == 0) {
										char *no_letter = "Voce nao tem cartas!";
										printf("%s", no_letter);
										for (j = strlen(no_letter); j < screen_x; j++)
												printf(" ");
										printf(grey border "  \n  " reset);
								} else {
										for (j = 0; j < screen_x; j++)
												printf(" ");
										printf(grey border "  \n  " reset);
								}
						}
						if (aux != NULL)
								aux = aux->link;	
				}

				for (i = 0; i < screen_x + 2; i++)
						printf(grey border " " reset);	

				// Acessar carta ou voltar ao jogo
				int key = kbhit();
				if (key != 0) { 
						for (aux = l_letter; aux != NULL; aux = aux->link)
								if (aux->number == key && aux->found == 1){
										int out2 = 0;
										while (!out2) {
												system("clear");
												printf("%s\n\nDigite 'q' para voltar ao jogo\nDigite 'o' para voltar ao menu de cartas\n", aux->message);
												key = kbhit();
												if (key == 'o')
														out2 = 1;
												if (key == 'q') {
														out2 = 1;
														out = 1;
														break;
												}
										}
								}
				}
				if (key == 'q')
						out = 1;
				usleep(200000);
		} //while
		system("clear");

}

void execute_letter(char stage[map_y][map_x], struct list_letter *list_letter, person *p) {
		
		struct list_letter *aux;

		for (aux = list_letter; aux != NULL; aux = aux->link)

				if (aux->found == 0)
						if ((aux->x == p->x) && (p->y == aux->y)) {
								int out = 0;
								while(!out) {
										printf("\r%s", aux->message);
										char key = kbhit();	
										if (key == 10)
												out = 1;
								}
								system("clear");
								aux->found = 1;	
								stage[aux->y][aux->x] = ground;
						}

}
