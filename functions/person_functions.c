typedef struct person {
		int x, y;
		int life;
		int previous_x, previous_y;
		char face;
		int dead;
		int fire;
} person;

void person_movement(person *p, char direction, char stage[map_y][map_x], int *out) {

		if (p->life < 1) {
				p->dead = 1;
				return;
		}

		if (p->fire == 1)
				p->fire = 0;
		p->previous_x = p->x;
		p->previous_y = p->y;
		stage[p->y][p->x] = ground;
		switch (direction) {
				case up: 
						if (stage[p->y + 1][p->x] == '#') { 
								p->face = '^';
								break;
						} else {
								p->y++;
								p->face = '^';
								break;
						}
				case down: 
						if (stage[p->y - 1][p->x] == '#') { 
								p->face = 'v';
								break;
						} else {
								p->y--;
								p->face = 'v';
								break;
						}
				case right: 
						if (stage[p->y][p->x + 1] == '#') { 
								p->face = '>';
								break;
						} else {
								p->x++;
								p->face = '>';
								break;
						}
					case left: 
						if (stage[p->y][p->x - 1] == '#') { 
								p->face = '<';
								break;
						} else {
								p->x--;
								p->face = '<';
								break;
						}					
		}
		stage[p->y][p->x] = p->face;
}

void create_person(person *p, int x, int y) {
		p->x = x;
		p->y = y;
		p->fire = 0;
		p->dead = 0;
		p->face = '^';
		p->life = 100;
		return ;
}



