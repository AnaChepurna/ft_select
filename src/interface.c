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
	}
	return (in);
}

void				free_interface(t_interface **in)
{
	ft_lstdel(&(*in)->args, &ft_memclr);
	free((*in)->choosen);
	free(*in);
	in = NULL;
}

void				init_interface(t_interface *in, char **argv)
{
	in->args = ft_arrtolst(argv);
}

static void			make_interface(t_interface *in)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	in->len = ft_lstlen(in->args);
	in->width = get_maxlen(in->args) + 2;
	in->lines = in->len < w.ws_row ? in->len : w.ws_row;
	in->columnes = w.ws_col / in->width;
	ft_putstr("interface len + width + lines + columnes\n");
	if (!in->lines || !in->columnes)
	{
		ft_putstr("void lines or columnes\n");
		return ;
	}
	if (in->lines * in->columnes < in->len)
	{
		while (in->carriage < in->start)
		{
			ft_putstr("I am in less\n");
			in->start -= in->lines;
		}
		while (in->carriage > in->lines * in->columnes - in->start)
		{
			ft_putstr("I am in more\n");
			in->start += in->lines;
		}
	}
	else
		in->start = 0;
}

t_interface			*manage_interface(void)
{
	static t_interface	*in = NULL;

	ft_putstr("interface:\n");
	if (!in)
	{
		ft_putstr("interface created\n");
		in = new_interface();
	}
	ft_putstr(tgetstr("cl", NULL));
	if (in->args)
	{
		ft_putstr("making interface\n");
		make_interface(in);
		ft_putstr("interface will be displayed\n");
		display_interface(in);
	}
	else
		ft_putstr("nothing to display\n");
	return (in);
}