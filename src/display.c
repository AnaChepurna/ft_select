#include "../ft_select.h"

void		display_color(char *str)
{
	struct stat	st;
	char	*color;

	color = NULL;
	if (!lstat(str, &st))
	{
		if (S_ISDIR(st.st_mode))
			color = BLUE;
		else if (S_ISLNK(st.st_mode))
			color = CYAN;
		else if (S_ISFIFO(st.st_mode) || S_ISBLK(st.st_mode)
			|| S_ISCHR(st.st_mode))
			color = YELLOW;
		else if (S_ISSOCK(st.st_mode))
			color = MAGENTA;
		else if ((st.st_mode & S_IXUSR) || (st.st_mode & S_IXGRP)
			|| (st.st_mode & S_IXOTH))
			color = GREEN;
		else
			color = RED;
	}
	ft_putstr_fd(color, 2);
}

static void		display_obj(char **args, int i, t_interface *in)
{
	int		len;

	if (i == in->carriage)
		ft_putstr_fd(UNDERLINE, 2);
	if (is_choosen(in, i))
		ft_putstr_fd(REVVID, 2);
	display_color(args[i]);
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

	//ft_putstr_fd(">>trying to display_interface", 2);
	if (!in->columnes || (in->lines < 2 && in->len > 1))
		ft_putstr_fd("too small window\n", 2);
	else
	{
		args = ft_lsttoarr(in->args);
		y = -1;
		while (++y < in->lines)
		{
			x = -1;
			if (y != in->start)
				ft_putstr_fd("\n", 2);
			while (++x < in->columnes)
			{
				i = in->start + y + x * in->lines;
				if (i < in->len)
					display_obj(args, i, in);
			}
		}
		ft_arrfree(&args);
	}
}