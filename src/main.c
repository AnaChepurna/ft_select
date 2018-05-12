#include "../ft_select.h"


void	process(char **argv)
{
	t_interface *in;

	in = manage_interface();
	init_interface(in, argv);
	manage_interface();
	start_signal_handling();
	parse_controls(in);
}

int 	main(int argc, char **argv)
{
	(void)argc;
	manage_term(INIT);
	manage_term(SET);
	process(++argv);
	// int n = 0;
	// char b;
	// // ft_putstr(tgetstr("cl", NULL));
	// // while(n++ < 10)
	// // {
	// while (n < 20)
	// {
	// 	read(0, &b, 1);
	// 	n++;
	// }
	// 	ft_putchar(b);
	// 	//ft_putstr(tgoto(tgetstr("cm", NULL), 2, 2));
	// 	//ft_putstr(tgetstr("cm", NULL));
	// }
	char b[5];
	read(0, b, 1);
	ft_putstr(b);
	read(0, b, 1);
	manage_term(RE_SET);
	//ft_putstr(UNDERLINE REVVID "love" RESET " love");
	return 0;
}