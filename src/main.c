#include "../ft_select.h"

void	clear(void)
{
	manage_term(RE_SET);
	manage_interface(FREE, NULL);
}

void	process(char **argv)
{
	t_interface *in;

	in = manage_interface(42, NULL);
	manage_interface(INIT, argv);
	manage_interface(FRESH, NULL);
	start_signal_handling();
	parse_controls(in);
}

int 	main(int argc, char **argv)
{
	(void)argc;
	manage_term(INIT);
	manage_term(SET);
	process(++argv);
	return 0;
}