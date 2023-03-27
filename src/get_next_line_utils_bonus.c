/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:14:21 by llion             #+#    #+#             */
/*   Updated: 2022/12/12 14:45:54 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_new_line(gnl_list *tank)
{
	int		i;
	gnl_list	*current;

	if (tank == NULL)
		return (0);
	current = tank;
	while (current && current->next)
		current = current->next;
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_lst_add_back(gnl_list **lst, int lu, char *buff)
{
	int		i;
	gnl_list	*last;
	gnl_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->next = NULL;
	new->content = malloc(sizeof(char) * (lu + 1));
	if (new->content == NULL)
	{
		free(new);
		return ;
	}
	i = -1;
	while (buff[++i])
		new->content[i] = buff[i];
	new->content[i] = '\0';
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast_gnl(*lst);
	last->next = new;
}

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	free_tank(gnl_list *tank, int index)
{
	gnl_list	*current;
	gnl_list	*next;

	if (index == 1)
	{
		if (tank)
		{
			if (tank->content)
				free(tank->content);
			free(tank);
		}
	}
	else
	{
		current = tank;
		while (current)
		{
			free(current->content);
			next = current->next;
			free(current);
			current = next;
		}
	}
}
