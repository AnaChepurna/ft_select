#include "ft_select.h"

int main(int argc, char const **argv)
{
	struct termios old, new;

	(void)argc;
	(void)argv;
	init_term(&old, &new);
	set_term(new);
	int n = 0;
	char b;
	ft_putstr(tgetstr("cl", NULL));
	while(n++ < 10)
	{
		read(0, &b, 1);
		ft_putchar(b);
		//ft_putstr(tgoto(tgetstr("cm", NULL), 2, 2));
		//ft_putstr(tgetstr("cm", NULL));
	}
	reset_term(old);
	return 0;
}