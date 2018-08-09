struct list_letter *l_letter = NULL;
/* l_letter = malloc(sizeof(struct list_letter)); */
/* l_letter->number = 0; */
/* l_letter->found = 0; */
/* l_letter->link = NULL; */

//create_menu_letter(l_letter);
//
// Crie suas cartas aqui

char message1[200] = "Existem algumas portas diferentes no jogo. Essa do seu quarto abre sem chave ou senha";
char title1[200] = "Carta sobre porta";
create_letter(stage, &l_letter, 15, 9, title1, message1, '1');

char message2[200] = "Essa porta precisa de senha... Tente 1234";
char title2[200] = "Mais portas... Ultima vez. Prometo!";
create_letter(stage, &l_letter, 16, 3, title2, message2, '2');

char message3[200] = "Pegue a chave logo abaixo e, quando chegar na porta, ela abrira...";
char title3[50] = "Mais cartas sobre portas...";
create_letter(stage, &l_letter, 9, 7, title3, message3, '3');
