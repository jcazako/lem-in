/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 21:26:35 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/15 17:12:18 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_printf.h"

# define START 01
# define END 02
# define NONE 00

typedef struct		s_line
{
	char			*line;
}					t_line;

typedef struct		s_room
{
	char			*n;
	int				cmd;
	int				x;
	int				y;
}					t_room;

typedef struct		s_pipe
{
	char			*n_1;
	char			*n_2;
}					t_pipe;

typedef struct		s_mk_lstr
{
	char			*str;
	int				i;
	t_list			*r_lst;
	t_list			*tmp;
	int				conf;
	int			len;
}					t_mk_lstr;

typedef struct		s_ant
{
	int				nu;
	t_list			*hill;
}					t_ant;

typedef struct		s_hill
{
	char			*n;
	int				cmd;
	t_list			*a_lst;
	t_list			*xion;
}					t_hill;

typedef struct		s_xion
{
	t_list			*pipe;
}					t_xion;

void				print_line(t_list *line_lst);
t_list				*get_anthill(void);
int					check_nbant(t_list *lst);
int					strlen_space(char *str);
t_list				*get_room(char *line, int cmd);
int					ch_room_format(char *line);
void				del_room(t_room *room, size_t size);
void				del_line(t_line *room, size_t size);
t_list				*mk_lstroom(t_list **line_lst);
void				print_r_lst(t_list *r_lst);
int					ch_pipe_format(char *line, t_list *r_lst);
int					diff_room(t_list *r_new, t_list *r_lst);
int					diff_pipe(t_list *p_new, t_list *p_lst);
t_list				*get_pipe(char *line, t_list *r_lst);
t_list				*mk_lstpipe(t_list **line_lst, t_list *r_lst);
void				del_pipe(t_pipe *pipe, size_t content);
void				print_p_lst(t_list *p_lst);
void				print_hill(t_list *hill);
t_list				*mk_anthill(t_list **r_lst);
t_list				*get_antlst(int nb_ant, t_list *h_lst);
void				del_ant(t_ant *ant, size_t ct);
void				del_hill(t_hill *hill, size_t ct);
void				print_ant(t_list *a_lst);
void				init_ant(t_list *a_lst, t_list *h_lst);
void				init_xion(t_list **h_lst, t_list *p_lst);
void				print_xion(t_list *xion);
void				path_finder(t_list *h_lst, t_list **w_lst, t_list **ph_lst);
void				del_xion(t_xion *xion, size_t size);
void				print_path(t_list *path);
t_list				*xion_cpy(t_list *xion);
#endif
