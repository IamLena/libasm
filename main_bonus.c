#include <stdio.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_atoi_base(char *str, char *base);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
int		ft_strcmp(char *str1, char *str2);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

void	print_list(t_list *list)
{
	printf("List: ");
	while (list)
	{
		printf("%s, ", (char *)list->content);
		list = list->next;
	}
	printf("\n");
}

int main(void)
{
	printf("--------------ATOI_BASE---------\n");
	printf("%d\n", ft_atoi_base("101", "01")); // 5
	printf("%d\n", ft_atoi_base("134", "314")); // 9 + 6 + 4 = 19
	printf("%d\n", ft_atoi_base("1a", "0123456789abcdef")); //26
	printf("%d\n", ft_atoi_base("1A", "0123456789ABCDEF")); //26
	printf("%d\n", ft_atoi_base("))", "*.)")); // 8

	//errors result = 0
	printf("%d\n", ft_atoi_base(NULL, "0123"));
	printf("%d\n", ft_atoi_base("123", NULL));
	printf("%d\n", ft_atoi_base("123", "+0123"));
	printf("%d\n", ft_atoi_base("123", "01-23"));
	printf("%d\n", ft_atoi_base("123", "01203"));
	printf("%d\n", ft_atoi_base("1a", "0123456789ABCDEF"));


	printf("--------------LIST_PUSH_FRONT---------\n");
	t_list *begin_list = NULL;
	ft_list_push_front(&begin_list, "1");
	ft_list_push_front(&begin_list, "21");
	ft_list_push_front(&begin_list, "111");
	ft_list_push_front(&begin_list, "567");
	ft_list_push_front(&begin_list, "98");
	ft_list_push_front(&begin_list, "");
	ft_list_push_front(&begin_list, NULL);
	ft_list_push_front(NULL, "8");

	print_list(begin_list); //(null), , 98, 567, 111, 21, 1

	printf("--------------LIST_SIZE---------\n");
	printf("list_size - %d\n", ft_list_size(NULL)); // 0
	printf("list_size - %d\n", ft_list_size(begin_list)); // 7


	printf("--------------LIST_SORT---------\n");
	print_list(begin_list); //(null), , 98, 567, 111, 21, 1
	ft_list_sort(&begin_list, ft_strcmp);
	print_list(begin_list); //(null), , 1, 111, 21, 567, 98


	printf("--------------LIST_REMOVE---------\n");
	print_list(begin_list); // (null), , 1, 111, 21, 567, 98
	ft_list_remove_if(&begin_list, "1", ft_strcmp);
	print_list(begin_list); // (null), , 111, 21, 567, 98
	ft_list_remove_if(&begin_list, "21", ft_strcmp);
	print_list(begin_list); // (null), , 111, 567, 98
	ft_list_remove_if(&begin_list, "98", ft_strcmp);
	print_list(begin_list); // (null), , 111, 567
	ft_list_remove_if(&begin_list, "21", ft_strcmp);
	print_list(begin_list); // (null), , 111, 567

	//??
	ft_list_remove_if(&begin_list, "", ft_strcmp);
	print_list(begin_list); // 111, 567 ??

	//segma
	// ft_list_remove_if(&begin_list, NULL, ft_strcmp);
	// print_list(begin_list); // (null), 111, 567
}
