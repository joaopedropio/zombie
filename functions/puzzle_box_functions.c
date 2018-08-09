typedef struct puzzle_box	{
		int x, y;
		struct puzzle_box *link;
} puzzle_box;


void create_puzzle_box(char stage[map_y][map_x], struct puzzle_box **l_puzzle_box, int x, int y) {
		puzzle_box *aux = malloc(sizeof(struct puzzle_box));

		aux->x = x;
		aux->y = y;
		stage[y][x] = puzzle_box_char;
		aux->link = NULL;

		if (*l_puzzle_box == NULL)
				*l_puzzle_box = aux;
		else {
				struct puzzle_box *aux2;

				for (aux2 = *l_puzzle_box; aux2->link != NULL; aux2 = aux2->link);

				aux2->link = aux;
		}
}

void execute_puzzle_box(char stage[map_y][map_x], struct puzzle_box *pb, person *p) {

		struct puzzle_box *aux;

		for (aux = pb; aux != NULL; aux = aux->link)
				
				if (p->x == aux->x && p->y == aux->y) {

						switch (p->face) {
								case face_up_char:
										if (stage[aux->y + 1][aux->x] != wall && stage[aux->y + 1][aux->x] != puzzle_box_char)
												aux->y++;
										else {
												p->x = p->previous_x;
												p->y = p->previous_y;
										}
										break;
								case face_down_char:
										if (stage[aux->y - 1][aux->x] != wall && stage[aux->y - 1][aux->x] != puzzle_box_char)
												aux->y--;
										else {
												p->x = p->previous_x;
												p->y = p->previous_y;
										}
										break;
								case face_right_char:
										if (stage[aux->y][aux->x + 1] != wall && stage[aux->y][aux->x + 1] != puzzle_box_char )
												aux->x++;
										else {
												p->x = p->previous_x;
												p->y = p->previous_y;
										}
										break;
								case face_left_char:
										if (stage[aux->y][aux->x - 1] != wall && stage[aux->y][aux->x - 1] != puzzle_box_char )
												aux->x--;
										else {
												p->x = p->previous_x;
												p->y = p->previous_y;
										}
										break;
						}
						stage[aux->y][aux->x] = puzzle_box_char;
				}
}















