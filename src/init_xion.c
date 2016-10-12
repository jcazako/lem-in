/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 18:31:05 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/12 19:22:35 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_list	*get_addr_hill(char *n, t_list *h_lst)
{
	char	*name;

	while (h_lst)
	{
		name = ((t_hill*)(h_lst->content))->n;
		if (!ft_strcmp(n, name))
			return (h_lst);
		h_lst = h_lst->next
	}
	return (NULL);
}

static void		add_xion(t_list **h_lst, char *n)
{
	t_list	*tmp;
	t_xion	content;

	content.pipe = get_addr_hill(n, *h_lst);
	if (!(tmp = ft_lstnew(&content, sizeof(content))))
		return ;
	if (!((t_hill*)((*h_lst)->content))->xion)
		ft_lstadd(&((t_hill*)((*h_lst)->content))->xion, tmp);
	else
		ft_lstadd_back(((t_hill*)((*h_lst)->content))->xion, tmp);
}

static t_list	*get_xion(t_list **h_lst, t_list *p_lst)
{
	char	*n;
	char	*n_1;
	char	*n_2;

	n = ((t_hill*)((*h_lst)->content))->n;
	while (p_lst)
	{
		n_1 = ((t_pipe*)(p_lst->content))->n_1;
		n_2 = ((t_pipe*)(p_lst->content))->n_2;
		if (!ft_strcmp(n, n_1) || !ft_strcmp(n, n_2))
		{
			if (!ft_strcmp(n, n_1))

			else if (!ft_strcmp(n, n_2))

		}
		p_lst = p_lst->next;
	}
}
