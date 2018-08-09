struct safe_box {
		int x, y;
		int key_x, key_y;
		int type, opened;
		char *password;
		struct safe_box *link;
};

void create_safe_box_pass(char stage[map_y][map_x], struct safe_box **l_safe_box, int x, int y, char *password) {
		// type = 0 -> nenhum, 1-> normal(nao tem), 2->key, 3->password
		
		struct safe_box *aux = malloc(sizeof(struct safe_box));

		aux->type = 3;
		aux->x = x;
		aux->y = y;
		aux->key_x = 0;
		aux->key_y = 0;
		aux->password = password;
		aux->opened = 0;
		aux->link = NULL;
		stage[y][x] = safe_box_char;

		if (*l_safe_box == NULL) {
				*l_safe_box = aux;
		} else {
				struct safe_box *aux2;

				for (aux2 = *l_safe_box; aux2->link != NULL; aux2 = aux2->link);

				aux2->link = aux;
		}

}

void execute_safe_box_password(char stage [map_y][map_x], person *p, struct safe_box *l_safe_box) {
		struct safe_box *aux;

		for (aux = l_safe_box; aux != NULL; aux = aux->link) {

				if (aux->opened == 1)
						return ;
				else
						stage[aux->y][aux->x] = safe_box_char;

				if (p->x > aux->x - 2 && p->x < aux->x + 2 && p->y > aux->y - 2 && p->y < aux->y + 2) {

						printf("Digite a senha viado: ");
						char password[30];
						gets(password);
						if (!strcmp(aux->password, password)) {
								printf("Aberto!");
								getchar();
								aux->opened = 1;
								//sleep(1);
						} else {
								printf("Senha incorreta!");
								getchar();
								stage[p->y][p->x] = ground;
								p->x = p->previous_x;
								p->y = p->previous_y;
								//sleep(1);
						}
				}
		}
}












