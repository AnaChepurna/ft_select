#include "../ft_select.h"

void	signal_window_handler(int signo)
{
	if (signo == SIGWINCH)
	{
		manage_interface();
		signal(SIGWINCH, signal_window_handler);
	}
}

void	signal_stop_handler(int signo)
{
	if (signo == SIGTSTP)
	{
		manage_term(RE_SET);
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
	}
}

void	signal_continue_handler(int signo)
{
	if (signo == SIGCONT)
	{
		manage_term(SET);
		manage_interface();
		start_signal_handling();
	}
}

void	start_signal_handling(void)
{
	signal(SIGWINCH, signal_window_handler);
	signal(SIGCONT, signal_continue_handler);
	signal(SIGTSTP, signal_stop_handler);
}
