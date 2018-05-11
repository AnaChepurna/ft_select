#include "../ft_select.h"

// static void		display_obj(char **args, int i, t_interface *in)
// {
// 	int		len;

// 	if (i == in->carriage)
// 		ft_putstr(UNDERLINE);
// 	if (is_choosen(in, i))
// 		ft_putstr(REVVID);
// 	ft_putstr(args[i]);
// 	ft_putstr(RESET);
// 	len = ft_strlen(args[i]);
// 	while (len < in->width)
// 		ft_putstr(" ");
// }

void			display_interface(t_interface *in)
{
	char	**args;
	// int		i;
	// int		x;
	// int		y;

	args = ft_lsttoarr(in->args);
	// y = 0;
	// i = 0;
	// while (i < in->len && y < in->lines)
	// {
	// 	x = 0;
	// 	if (y)
	// 		ft_putstr("\n");
	// 	while (i < in->len && x < in->columnes)
	// 	{
	// 		i = y + x * in->lines;
	// 		display_obj(args, i, in);
	// 		x++;
	// 	}
	// 	y++;
	// }
	//ft_putstr(args[2]);
	while (*args)
	{
		ft_putstr(*args);
		ft_putstr("\n");
		args++;
	}
	//ft_arrfree(&args);
}