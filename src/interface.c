#include "../ft_select.h"

void			init_interface(t_interface in, char **argc)
{

}

static void		make_interface(t_interface in)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	in.len = ft_lstlen(in.args);
	in.width = get_maxlen(in.args) + 2;
	in.lines = in.len < w.ws_row ? in.len : w.ws_row;
	in.columnes = w.ws_col / in.width;
	if (!in.lines || !in.columnes)
		return ;
	if (in.lines * in.columnes < in.len)
	{
		while (in.carriage < in.start)
			in.start -= in.lines;
		while (in.carriage > in.lines * in.columnes - in.start)
			in.start += in.lines;
	}
	else
		in.start = 0;
}

void			print_interface(t_interface in)
{
	ft_putstr(tgetstr("cl", NULL));
	if (in.args)
	{
		make_interface(in);
		display_interface(in);
	}
	else
		ft_putstr("too small window\n");
}