void end_level(char stage[map_y][map_x], person *p, int *out, int x, int y) {
		stage[y][x] = end_level_char; 
		if ((p->x == x) && (p->y == y)) {
				system("clear");
				printf("Vc acabou a fase teste. Agora eh sofrer mais um pouco pra fazer mais fases. Vai q vai! :D ");
				getchar();
				*out = 1;
		}
}
