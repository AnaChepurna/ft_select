#include "../ft_select.h"

static t_interface	*new_interface(void)
{
	t_interface	*in;

	if ((in = (t_interface *)malloc(sizeof(t_interface))))
	{
		in->args = NULL;
		in->choosen = NULL;
		in->carriage = 0;
		in->ch_num = 0;
		in->start = 0;
	}
	return (in);
}

static void			make_interface(t_interface *in)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	in->len = ft_lstlen(in->args);
	in->width = get_maxlen(in->args) + 2;
	in->lines = in->len < w.ws_row ? in->len : w.ws_row;
	in->columnes = w.ws_col / in->width;
	if (in->lines < 2 || !in->columnes)
		return ;
	if (in->lines * in->columnes < in->len)
	{
		while (in->carriage < in->start)
			in->start -= in->lines;
		while (!(in->carriage >= in->start &&
			in->carriage < in->start + in->lines * in->columnes))
			in->start += in->lines;
	}
	else
		in->start = 0;
}

static void			fresh_interface(t_interface *in)
{
	ft_putstr_fd(tgetstr("cl", NULL), 2);
	if (in->args)
	{
		make_interface(in);
		display_interface(in);
	}
	else
	{
		clear();
		exit(0);
	}
}

t_interface			*manage_interface(int mode, char **argv)
{
	static t_interface	*in = NULL;

	if (!in)
		in = new_interface();
	else
	{
		if (mode == INIT && argv)
			in->args = ft_arrtolst(argv);
		else if (mode == FREE)
		{
			if (in->args)
				ft_lstdel(&in->args, &ft_memclr);
			if (in->choosen)
				free(in->choosen);
			free(in);
		}
		else if (mode == FRESH)
			fresh_interface(in);
	}
	return (in);
}
