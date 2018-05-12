#include "../ft_select.h"

static int		parse_arrows(char *buf, t_interface *in)
{
	printf("trying to parse %s\n", buf);
	if (ft_strequ(buf, tgetstr("kd", NULL)))
	{
		printf("ugu\n");
		return (command_carriage(in, DOWN));
	}
	if ((ft_strequ(buf, tgetstr("ku", NULL))))
		return (command_carriage(in, UP));
	if ((ft_strequ(buf, tgetstr("kl", NULL))))
		return (command_carriage(in, LEFT));
	if ((ft_strequ(buf, tgetstr("kr", NULL))))
		return (command_carriage(in, RIGHT));
	printf("nope\n");
	return (0);
}

// static int		

// static int		

// static int		

void			parse_controls(t_interface *in)
{
	char	buf[5];

	while (1)
	{
		printf("hmmm\n");
		ft_memset(buf, '\0', 5);
		printf("reading\n");
		read(0, &buf, 4);
		printf("readed\n");
		parse_arrows(buf, in);
		manage_interface();
	}

}