/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:58:54 by achepurn          #+#    #+#             */
/*   Updated: 2018/05/16 13:52:47 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define INIT		0
# define SET		1
# define RE_SET		2
# define GET_NEW	3
# define GET_OLD	4
# define UP			0
# define DOWN		1
# define FORWARD	2
# define BACK		3
# define FRESH		1
# define INFO		4
# define FREE		2
# define YES		1
# define NO			0
# define ON_YELLOW	"\033[43m"

typedef struct		s_interface
{
	int				columnes;
	int				lines;
	int				width;
	int				start;
	int				carriage;
	t_list			*args;
	int				*choosen;
	int				ch_num;
	int				len;
}					t_interface;

/*
**main.c
*/
void				clear(void);

/*
**terminal.c
*/
struct termios		*manage_term(int mode);

/*
**signal.c
*/
void				start_signal_handling(void);

/*
**interface.c
*/
t_interface			*manage_interface(int mode, char **argv);
void				free_interface(t_interface **in);
void				init_interface(t_interface *in, char **argv);

/*
**utils.c
*/
int					get_maxlen(t_list *lst);
int					is_choosen(t_interface *in, int i);
void				change_greater(t_interface *in, int i);

/*
**display.c
*/
void				display_interface(t_interface *in);

/*
**control.c
*/
void				parse_controls(t_interface *in);

/*
**command.c
*/
int					command_carriage(t_interface *in, int mode);
int					manage_choice(t_interface *in);
int					make_return(t_interface *in);
int					delete_arg(t_interface *in);

/*
**search.c
*/
void				manage_search(int mode, char *key,
	t_interface *in);

#endif
