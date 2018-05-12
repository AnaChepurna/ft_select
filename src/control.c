#include "../ft_select.h"

static int		parse_arrows(char *key, t_interface *in)
{
	char *str;
	int i;

	i = 0;
	if (ft_strequ(key, (str = tgetstr("do", NULL))))
	{
		printf("\n");
		i = 0;
		while (i++ < 4)
			ft_putnbr(*str++);
		printf("down\n");
		return (command_carriage(in, DOWN));
	}
	else
	{
		i = 0;
		printf("not down -> \n");
		while (i++ < 4)
			ft_putnbr(*str++);
	}
	if ((ft_strequ(key, (str =tgetstr("up", NULL)))))
	{
		printf("\n");
		i = 0;
		while (i++ < 4)
			ft_putnbr(*str++);
		printf("up\n");
		return (command_carriage(in, UP));
	}
	else
	{
		i = 0;
		printf("not up -> \n");
		while (i++ < 4)
			ft_putnbr(*str++);
	}
	if ((ft_strequ(key, (str =tgetstr("nd", NULL)))))
	{
		printf("\n");
		i = 0;
		while (i++ < 4)
			ft_putnbr(*str++);
		printf("forward\n");
		return (command_carriage(in, FORWARD));
	}
	else
	{
		i = 0;
		printf("not forward -> \n");
		while (i++ < 4)
			ft_putnbr(*str++);
	}
	if ((ft_strequ(key, (str =tgetstr("le", NULL)))))
	{
		printf("\n");
		i = 0;
		while (i++ < 4)
			ft_putnbr(*str++);
		printf("back\n");
		return (command_carriage(in, BACK));
	}
	else
	{
		i = 0;
		printf("not back -> \n");
		while (i++ < 4)
			ft_putnbr(*str++);
	}
	i = 0;
	printf("this is -> \n");
		while (i++ < 4)
			ft_putnbr(*key++);
	printf("nope\n");
	return (0);
}

// static int		

// static int		

// static int		

void			parse_controls(t_interface *in)
{
	char key[5];

	while (1)
	{
		ft_memset(key, '\0', 5);
		read(0, &key, 4);
		parse_arrows(key, in);
		//manage_interface();
	}

}