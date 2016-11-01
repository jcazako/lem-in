#include "lem_in.h"

static t_list	*get_end(t_list *h_lst)
{
	while (h_lst)
	{
		if (((t_hill*)(h_lst->content))->cmd == END)
			return (h_lst);
		h_lst = h_lst->next;
	}
	return (NULL);
}

static int	check_loop(t_list *s_lst, t_list *end)
{
	while (s_lst)
	{
		if (((t_ant*)(s_lst->content))->hill != end)
			return (1);
		s_lst = s_lst->next;
	}
	return (0);
}

static void	help_solver(t_solver *s, t_list **path, t_list **a_lst)
{
	s->t_1 = ((t_xion*)((*path)->content))->pipe;
	s->t_2 = ((t_xion*)(s->t_1->content))->pipe;
	while (s->t_1 && s->t_2 != ((t_ant*)((*a_lst)->content))->hill)
	{
		s->t_1 = s->t_1->next;
		if (s->t_1)
			s->t_2 = ((t_xion*)(s->t_1->content))->pipe;
	}
	if (s->t_1)
	{
		s->t_1 = s->t_1->next;
		if (s->t_1)
			s->t_2 = ((t_xion*)(s->t_1->content))->pipe;
	}
	if (s->t_2 == s->end || !((t_hill*)(s->t_2->content))->a_lst)
	{
		((t_ant*)((*a_lst)->content))->hill = s->t_2;
		((t_hill*)(s->t_2->content))->a_lst = *a_lst;
		if (s->t_3)
			((t_hill*)(s->t_3->content))->a_lst = NULL;
		}
		s->t_3 = s->t_2;
		ft_lstrotate(a_lst);
		ft_lstrotate(path);
		s->i++;
}

int		solver(t_list **a_lst, t_list **h_lst, t_list **path)
{
	t_solver	s;

	s.nb_ant = ft_lstcount(*a_lst);
	s.end = get_end(*h_lst);
	s.t_3 = NULL;
	s.i = 0;
	s.j = 0;
	//print_ant(*a_lst);
	//ft_printf("\n");
	while (check_loop(*a_lst, s.end))
	{	
		while (s.i < s.nb_ant)
			help_solver(&s, path, a_lst);
		while (s.i)
		{
			ft_lstrev_rotate(path);
			s.i--;
		}
		//print_ant(*a_lst);
		//ft_printf("\n");
		s.j++;
	}
	return (s.j);
}