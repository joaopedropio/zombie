typedef struct zombie {
		int x, y;
		int previous_x, previous_y;
		int delay_movement;
		int dead;
		int trigger_x, trigger_y;
		int trigger;
		struct zombie *link;
} zombie;

void create_zombie(zombie **l_zombie, int x, int y, int trigger_x, int trigger_y) {

		zombie *aux = malloc(sizeof(zombie));

		aux->x = x;
		aux->y = y;
		aux->dead = 0;
		aux->trigger = 0;
		aux->trigger_x = trigger_x;
		aux->trigger_y = trigger_y;
		aux->link = NULL;

		if (*l_zombie == NULL)
				*l_zombie = aux;
		else {
				zombie *aux2;
				for (aux2 = *l_zombie; aux2->link != NULL; aux2 = aux2->link);
				aux2->link = aux;
		}

		return ;
}

int z_position(int p_pos, int z_pos) {

		if (p_pos - z_pos == 0) 
				return 0;
		else if (p_pos - z_pos > 0)
				return 1;
		else if (p_pos - z_pos < 0)
				return -1;
}

int zombie_killed(person *p, zombie *z) {

		if (p->fire == 1) {
				if (p->face == '^' && z->y > p->y && z->x == p->x)
						return 1;
				else if (p->face == 'v' && z->y < p->y && z->x == p->x)
						return 1;
				else if (p->face == '>' && z->x > p->x && z->y == p->y)
						return 1;
				else if (p->face == '<' && z->x < p->x && z->y == p->y)
						return 1;
		}
		return 0;
}

void execute_zombie(person *p, zombie *z, char stage[map_y][map_x]) {
		
		zombie *aux;

		for (aux = z; aux != NULL; aux = aux->link) {

				if (aux->dead == 1)
						return ;

				if(aux->trigger == 0)
						if ((aux->trigger_x == p->x) && (aux->trigger_y == p->y))
								aux->trigger = 1;
						else
								return ;

				if (zombie_killed(p, z)) {
						p->fire = 0;
						stage[aux->y][aux->x] = ground;
						aux->dead = 1;
						return ;	
				}

				if (aux->delay_movement < zombie_delay) {
						aux->delay_movement++;
						return ;
				} else
						aux->delay_movement = 0;
				
				if (aux->x == p->x && aux->y == p->y) {
						p->life = p->life - zombie_bite;
						aux->x = aux->previous_x;
						aux->y = aux->previous_y;
						aux->delay_movement = 0;
				}

				int x = z_position(p->x, aux->x);
				int y = z_position(p->y, aux->y);

				if (stage[aux->y + y][aux->x + x] == '#')	
						return ;
		
				aux->previous_x = aux->x;
				aux->previous_y = aux->y;
				stage[aux->y][aux->x] = ground;
				aux->x += z_position(p->x, aux->x);
				aux->y += z_position(p->y, aux->y);

				stage[aux->y][aux->x] = 'Z';
				return ;
		}
}
