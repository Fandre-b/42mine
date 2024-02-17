#include "push_swap.h"

t_stack	*ft_lstnew(int nbr)
{
	t_stack *current;

	current = (t_stack *) malloc (sizeof(t_stack));
	if (!current)
		return (NULL);
	current->value = nbr;
	current->next = NULL;
	current->prev = NULL;
	return (current);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack *last;

	if (*lst)
	{
		last = (*lst)->prev;
		if (last) //check se existe mais que 1 elemento
		{
			last->next = new;
			new->prev = last;
			(*lst)->prev = new;
		}
		else //se apenas 1 elemento 
		{
			(*lst)->next = new;
			new->prev = *lst;
			(*lst)->prev = new;
		}
	}
	else
		(*lst) = new;
	return;
}

void	ft_lstdel(t_stack *lst)
{
	t_stack	*temp;

	while(lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
	return ;
}

void free_tree(t_stack *node)
{
	if (!node) // Base case: if the node is null, return
		return;
	free_tree(node->prev); // Recursively delete left subtree
	free_tree(node->next); // Recursively delete right subtree
	free(node); // Delete this node
	node = NULL; // Set the pointer to NULL to avoid dangling pointers
	return ;
}

long	ft_atoi(char *str, int *error)
{
	int		sign;
	long	nbr;

	*error = 0;
	nbr = 0;
	sign = 1;
	if(*str == '-')
	{
		sign = -1;
		str++;
	}
	if (!*str)
		*error = 1;
	while(*str && *str >= '0' && *str <= '9')
		nbr = nbr * 10 + sign * (*str++ - '0');
	if(*str && (*str < '0' || *str > '9' || nbr > INT_MAX || nbr < INT_MIN))
		*error = 1;
	return(nbr);
}

void	ft_checkrepeated(t_stack **binary_tree, t_stack *node, int *error)
{
	t_stack *temp;

	temp = *binary_tree;
	if(!temp)
		*binary_tree = node;
	while(temp && node->value != temp->value && temp != node)
	{//sai do loop se os valores forem iguais ou os nos c/ igual addr
		if(node->value > temp->value)
		{//se nao econtrar prox pointer entao adiciona node, e passa auto para esse ptr
			if(!temp->next)
				temp->next = node;
			temp = temp->next;
		}
		else if(node->value < temp->value)
		{
			if(!temp->prev)
				temp->prev = node;
			temp = temp->prev;
		}
	}
	if (temp && node->value == temp->value && temp != node)
		*error = 1;
	if (temp && (node->value == temp->value && temp != node))
		free(node); //node nao foi add
	return;
}

t_stack *ft_extract_stack(int argc, char **argv, int *error)
{
	int i;
	int	nbr;

	t_stack *node;
	t_stack *node_tree;
	t_stack *stack_a;
	t_stack *binary_tree;

	i = 1;
	stack_a = NULL;
	binary_tree = NULL;
	while(i < argc && !*error)
	{
		nbr = ft_atoi(argv[i++], error);
		node = ft_lstnew(nbr);
		node_tree = ft_lstnew(nbr);
		ft_checkrepeated(&binary_tree, node_tree, error);
		ft_lstadd_back(&stack_a, node);
//		ft_push(&stack_a, node);
	}
	free_tree(binary_tree);
	return (stack_a);
}

void	ft_putnbr(int nbr)
{
	char	c;
	int		sign;

	sign = 1;
	if(nbr < 0)
	{
		sign = -1;
		write(1, "-", 1);
	}
	if(nbr / 10)
		ft_putnbr(sign * (nbr / 10));
	c = '0' + sign * (nbr % 10);
	write(1, &c, 1);
	return;
}

void	ft_lstprint(t_stack *lst)
{
	if (!lst)
		return;
	while(lst)
	{
		ft_putnbr(lst->value);
		write (1, " ", 1);
		lst = lst->next;
	}
	write (1, "\n", 1);
	return;
}

int	main(int argc, char **argv)
{
	int error;
	t_stack	*stack_a;

	stack_a = ft_extract_stack(argc, argv, &error);
	//adicionar possibilidade de fazer com string ou com argumentos.
	if (error)
	{
		ft_lstdel(stack_a);
		write (1, "ERROR\n", 6);
		return(1);
	}
//	ft_sorter(stack_a, algoritm name)
	ft_lstprint(stack_a);
	ft_lstdel(stack_a);
	return(0);
}

//mechanical turk

//quicksort, heapsort, or merge sort