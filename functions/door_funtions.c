typedef struct door {
		int type;
		int x, y;
		int key_x, key_y;
		char *message;
		char *password;
		int found;
		int opened;
		char position;
		struct door *link;
} door;

void create_door_normal(char stage[map_y][map_x], door **l_door, int x, int y, char position) {

		door *d = malloc(sizeof(door));

		d->type = 1;
		d->x = x;
		d->y = y;
		d->key_x = 0;
		d->key_y = 0;
		d->message = NULL;
		d->password = NULL;
		d->found = 0;
		d->opened = 0;
		d->position = position;
		stage[y][x] = position;
		d->link = NULL;

		if (*l_door == NULL)
				*l_door = d;
		else {
				door *aux;
				for (aux = *l_door; aux->link != NULL; aux = aux->link);
				aux->link = d;
		}

}

void create_door_password(char stage[map_y][map_x], door **l_door, int x, int y, char position, char *message, char *password) {

		door *d = malloc(sizeof(door));

		d->type = 2;
		d->x = x;
		d->y = y;
		d->key_x = 0;
		d->key_y = 0;
		d->message = message;
		d->password = password;
		d->found = 0;
		d->opened = 0;
		d->position = position;
		stage[y][x] = position;
		d->link = NULL;

		if (*l_door == NULL)
				*l_door = d;
		else {
				door *aux;
				for (aux = *l_door; aux->link != NULL; aux = aux->link);
				aux->link = d;
		}

}

void create_door_key(char stage[map_y][map_x], door **l_door, int x, int y, int key_x, int key_y, char position) {

		door *d = malloc(sizeof(door));

		d->type = 3;
		d->x = x;
		d->y = y;
		d->key_x = key_x;
		d->key_y = key_y;
		d->message = NULL;
		d->password = NULL;
		d->found = 0;
		d->opened = 0;
		d->position = position;
		stage[y][x] = position;
		d->link = NULL;

		if (*l_door == NULL)
				*l_door = d;
		else {
				door *aux;
				for (aux = *l_door; aux->link != NULL; aux = aux->link);
				aux->link = d;
		}

}


void execute_door_normal(char stage[map_y][map_x], door *door, person *p) {

		if(door->opened) {
				if (door->position == door_vertical)
						stage[door->y][door->x] = door_horizontal;
				else
						stage[door->y][door->x] = door_vertical;
				return;
		}

		if ((p->x == door->x) && (p->y == door->y)) {
				stage[door->y][door->x] = ground;
				if (door->position == door_vertical) {
						door->x++;
						stage[door->y][door->x] = door_horizontal;
				} else {
						door->y++;
						stage[door->y + 1][door->x] = door_vertical; 
				}
				door->opened = 1;
		}
}

void execute_door_password(char stage[map_y][map_x], door *d, person *p) {

		if(d->opened) {
				if (d->position == door_vertical)
						stage[d->y][d->x] = door_horizontal;
				else
						stage[d->y][d->x] = door_vertical;
				return;
		}

		if ((p->x == d->x) && (p->y == d->y)) {
				char password[30];
				printf("%s", d->message);
				gets(password);
				if (!strcmp(d->password, password)) {
						stage[d->y][d->x] = ground;
						if (d->position == door_vertical) {
								d->x++;
								stage[d->y][d->x] = door_horizontal;
						} else {
								d->y++;
								stage[d->y][d->x] = door_vertical; 
						}
						d->opened = 1;
				} else {
						stage[p->y][p->x] = d->position;
						p->x = p->previous_x;
						p->y = p->previous_y;
				}
		}
}	

void execute_door_key(char stage[map_y][map_x], door *d, person *p) {

		if(d->found == 0)
				if ((p->x == d->key_x) && (p->y == d->key_y))
						d->found = 1;
				else 
						stage[d->key_y][d->key_x] = key_char;

		if(d->opened) {
				if (d->position == door_vertical)
						stage[d->y][d->x] = door_horizontal;
				else
						stage[d->y][d->x] = door_vertical;
				return;
		}

		if ((p->x == d->x) && (p->y == d->y)) {
				if (d->found) {
						stage[d->y][d->x] = ground;
						if (d->position == door_vertical) {
								d->x++;
								stage[d->y][d->x] = door_horizontal;
						} else {
								d->y++;
								stage[d->y][d->x] = door_vertical; 
						}
						d->opened = 1;
				} else {
						printf("\nVoce nao tem a chave! Tecle enter para volta ao jogo...");
						getchar();
						stage[p->y][p->x] = d->position;
						p->x = p->previous_x;
						p->y = p->previous_y;
				}
		}
}

void execute_door(char stage[map_y][map_x], door *l_door, person *p) {

		door *aux;

		for (aux = l_door; aux != NULL; aux = aux->link)
				if (aux->type == 1)
						execute_door_normal(stage, aux, p);
				else if (aux->type == 2)
						execute_door_password(stage, aux, p);
				else if (aux->type == 3)
						execute_door_key(stage, aux, p);

}
