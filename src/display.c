#include "../ft_select.h"

static void		display_obj(char **args, int i, t_interface *in)
{
	int		len;

	if (i == in->carriage)
		ft_putstr_fd(UNDERLINE, 2);
	if (is_choosen(in, i))
		ft_putstr_fd(REVVID, 2);
	ft_putstr_fd(args[i], 2);
	ft_putstr_fd(RESET, 2);
	len = ft_strlen(args[i]);
	while (len < in->width)
	{
		ft_putstr_fd(" ", 2);
		len++;
	}
}

void			display_interface(t_interface *in)
{
	char	**args;
	int		i;
	int		x;
	int		y;

	args = ft_lsttoarr(in->args);
	y = 0;
	while (y < in->lines)
	{
		x = 0;
		if (y != in->start)
			ft_putstr_fd("\n", 2);
		while (x < in->columnes)
		{
			i = in->start + y + x * in->lines;
			if (i < in->len)
				display_obj(args, i, in);
			x++;
		}
		y++;
	}
	ft_arrfree(&args);
}