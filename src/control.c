#include "../ft_select.h"

static int		parse_arrows(char *key, t_interface *in)
{
	if (ft_strequ(key, "[B"))
		return (command_carriage(in, DOWN));
	if ((ft_strequ(key, "[A")))
		return (command_carriage(in, UP));
	if ((ft_strequ(key, "[C")))
		return (command_carriage(in, FORWARD));
	if ((ft_strequ(key, "[D")))
		return (command_carriage(in, BACK));
	return (0);
}

static int		parse_exit(char *key)
{
	if (ft_strequ(key, ""))
	{
		manage_term(RE_SET);
		exit(0);
	}
	return (0);
}	

static int		parse_commands(char *key, t_interface *in)
{
	if (ft_strequ(key, " "))
		return (manage_choice(in));
	if (ft_strequ(key, "\n"))
		return (make_return(in));
	return (0);
}		

// static int		

void			parse_controls(t_interface *in)
{
	char key[5];

	while (1)
	{
		ft_memset(key, '\0', 5);
		read(0, &key, 4);
		parse_arrows(key, in);
		parse_exit(key);
		parse_commands(key, in);
		manage_interface();
	}

}