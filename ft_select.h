#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <signal.h>
# include <termios.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termcap.h>
# include <sys/param.h>

typedef struct		s_interface
{
	int				columnes;
	int				lines;
	int				width;
	int				start;
	int				carriage;
	t_list			*args;
	int				len;
}					t_interface;

/*
**terminal.c
*/
void	init_term(struct termios *old, struct termios *new);
void	set_term(struct termios new);
void	reset_term(struct termios old);

/*
**signal.c
*/
void	signal_window_handler(int signo);

/*
**interface.c
*/
void	print_interface(t_interface in);

/*
**utils.c
*/
int		get_maxlen(t_list *lst);

/*
**display.c
*/
void	display_interface(t_interface in);

#endif