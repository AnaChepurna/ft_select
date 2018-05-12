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
	if (in->lines < 2 || !in->columnes)
		return ;
	if (in->lines * in->columnes < in->len)
	{
		while (in->carriage < in->start)
			in->start -= in->lines;
		while (in->carriage > in->lines * in->columnes - in->start)
			in->start += in->lines;
	}
	else
		in->start = 0;
}

t_interface			*manage_interface(void)
{
	static t_interface	*in = NULL;

	if (!in)
	{
		printf("create interface\n");
		in = new_interface();
	}
	ft_putstr(tgetstr("cl", NULL));
	if (in->args)
	{
		make_interface(in);
		display_interface(in);
	}
	else
		ft_putstr("nothing to display\n");
	return (in);
}