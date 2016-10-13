/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:18:42 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/13 20:54:13 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_hill(t_list *hill)
{
	char	*str;
	t_list	**tmp;

	while (hill)
	{
		str = ((t_hill*)(hill->content))->n;
		tmp = ((t_hill*)(hill->content))->pipe;
		ft_printf("hill :%s\taddr :%p\n", str, hill);
		print_tab_addr(tmp);
		hill = hill->next;
	}
}
