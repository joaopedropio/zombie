//void init_attr(void) ;
//void close_attr(void) ;
//int kbhit(void) ;

struct termios old_attr, new_attr;

void init_attr(void) {
		    /* Obtém as configurações atuais. */
		    tcgetattr(0,&old_attr);
        new_attr=old_attr;

        /* Desliga modo canônico. */
        new_attr.c_lflag &=~ICANON ;

        /* Desliga ecoamento. */
        new_attr.c_lflag &= ~ECHO;

        new_attr.c_cc[VTIME]=0 ;
        new_attr.c_cc[VMIN]=0 ;
}

/* Retorna configurações antigas. */
void close_attr(void) {
		    tcsetattr(STDIN_FILENO,TCSANOW,&old_attr);
}


int kbhit(void) {
		    //int c ;
		    char c;

        tcsetattr(STDIN_FILENO,TCSANOW,&new_attr);
        c = getchar() ; /* retorna EOF se nada foi pressionado */
        tcsetattr(STDIN_FILENO,TCSANOW,&old_attr);

        return c ;
}
