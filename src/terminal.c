#include "../ft_select.h"

static void	init_term(struct termios *old, struct termios *new)
{
	tcgetattr(1, old);
	*new = *old;
	(*new).c_lflag &= ~ICANON;
	(*new).c_lflag &= ~ECHO;
}

static void	set_term(struct termios new)
{
	tgetent(NULL, getenv("TERM"));
	ft_putstr(tgetstr("ti", NULL));
	ft_putstr(tgetstr("vi", NULL));
	tcsetattr(1, TCSANOW, &new);
}

static void	reset_term(struct termios old)
{
	ft_putstr(tgetstr("ve", NULL));
	ft_putstr(tgetstr("te", NULL));
	tcsetattr(1, TCSANOW, &old);
}

struct termios	*manage_term(int mode)
{
	static struct termios	old;
	static struct termios	new;

	if (mode == INIT)
		init_term(&old, &new);
	else if (mode == SET)
		set_term(new);
	else if (mode == RE_SET)
		reset_term(old);
	else if (mode == GET_NEW)
		return (&new);
	else if (mode == GET_OLD)
		return (&old);
	return (NULL);
}

/*int main(int argc, char const **argv)
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
} */
//-D_XOPEN_SOURCE=500