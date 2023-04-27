#include "./libft/libft.h"
#include "push_swap.h"

int	ft_the_needed(int min, int max, int size)
{
	int	i;

	if (min > (size / 2))
		min = min - size;
	if (max > (size / 2))
		max = max - size;
	i = ft_min_nbr(max, min);
	return (i);
}

int	ft_the_needed_b(int max, int size)
{
	if (max > (size / 2))
		max = max - size;
	return (max);
}

int	ft_the_needed_a(t_list *stack_a, int cont, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stack_a;
	i = ft_max_or_min(stack_a, cont, size);
	if (i != size + 1)
		return (ft_the_needed_b(i, size));
	while (tmp->nxt != NULL)
		tmp = tmp->nxt;
	if (cont < stack_a->arg && cont > tmp->arg)
		return (0);
	i = 1;
	while (!(cont > stack_a->arg && cont < (stack_a->nxt)->arg))
	{
		stack_a = stack_a->nxt;
		i++;
	}
	return (ft_the_needed_b(i, size));
}

int	*ft_copy_cont(t_list *stack_a, int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *) ft_calloc ((size + 1), sizeof(int));
	if (!arr)
		ft_display_exit();
	while (stack_a != NULL)
	{
		arr[i++] = (stack_a)->arg;
		stack_a = (stack_a)->nxt;
	}
	return (arr);
}

int	*ft_intcpy(int	*arr, int size)
{
	int	i;
	int	*cpy;

	i = 0;
	cpy = (int *) ft_calloc (size, sizeof(int));
	if (!arr || !cpy)
		ft_display_exit();
	while (i < size)
	{
		cpy[i] = arr[i];
		i++;
	}
	return (cpy);
}
