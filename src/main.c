#include "../ft_select.h"


void	process(char **argv)
{
	t_interface *in;

	in = manage_interface();
	init_interface(in, argv);
	manage_interface();
}

int 	main(int argc, char **argv)
{
	//struct termios old, new;

	(void)argc;
	(void)argv;
	//init_term(&old, &new);
	//set_term(new);
	process(argv);
	int n = 0;
	char b;
	// ft_putstr(tgetstr("cl", NULL));
	// while(n++ < 10)
	// {
	while (n < 20)
	{
		read(0, &b, 1);
		n++;
	}
	// 	ft_putchar(b);
	// 	//ft_putstr(tgoto(tgetstr("cm", NULL), 2, 2));
	// 	//ft_putstr(tgetstr("cm", NULL));
	// }
	//reset_term(old);
	//ft_putstr(UNDERLINE REVVID "love" RESET " love");
	return 0;
}