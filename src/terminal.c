#include "../ft_select.h"

static void	init_term(struct termios *old, struct termios *new)
{
	tcgetattr(2, old);
	*new = *old;
	(*new).c_lflag &= ~ICANON;
	(*new).c_lflag &= ~ECHO;
	(*new).c_cc[VMIN] = 1;
	(*new).c_cc[VTIME] = 0;
}

static void	set_term(struct termios new)
{
	tgetent(NULL, getenv("TERM"));
	ft_putstr_fd(tgetstr("ti", NULL), 2);
	ft_putstr_fd(tgetstr("vi", NULL), 2);
	tcsetattr(2, TCSANOW, &new);
}

static void	reset_term(struct termios old)
{
	ft_putstr_fd(tgetstr("ve", NULL), 2);
	ft_putstr_fd(tgetstr("te", NULL), 2);
	tcsetattr(2, TCSANOW, &old);
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
