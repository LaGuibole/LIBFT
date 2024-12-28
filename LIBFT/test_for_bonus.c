/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:27:38 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/28 16:19:59 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void    print_list(t_list *lst)
{
    while (lst)
    {
        printf("Contenu : %s\n", (char *)lst->content);
        lst = lst->next;
    }
}

void	delete_content(void *content)
{
	free(content);
}

void	print_content(void *content)
{
	printf("Contenu : %s\n", (char *)content);
}

void	to_uppercase(void *content)
{
	char *str = (char *)content;
	while (*str >= 'a' && *str <= 'z')
	{
		*str -= 32;
		str++;
	}
}

void	*duplicate_with_prefix(void *content)
{
	char	*str = (char *)content;
	char 	*prefix = "-> New ";
	size_t	total_len = ft_strlen(prefix) + ft_strlen(str) + 1;
	char	*new_str = malloc(total_len);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, prefix, total_len);
	ft_strlcat(new_str, str, total_len);
	return (new_str);
}

int	main(void)
{
	char	*str = "Hello World";
	t_list *node;

	node = ft_lstnew((void *)str);

	printf("----------------------------------------------------\n");
	printf(BOLD_YELLOW "LST_NEW : \n" RESET);


	if (node){
		printf("Contenu : %s\n", (char *)node->content);
		printf("Next : %p\n", (void *)node->next);
	}

	free(node);

	printf("----------------------------------------------------\n");
	printf(BOLD_YELLOW "LST_ADD_FRONT : \n" RESET);

    t_list *head = NULL;
    t_list *node1;
    t_list *node2;
    t_list *node3;

    node1 = ft_lstnew("Premier");
    node2 = ft_lstnew("Deuxieme");
    node3 = ft_lstnew("Troisieme");

    head = node1;
    ft_lstadd_front(&head, node2);
    ft_lstadd_front(&head, node3);

    printf("Liste apres ajout des noeuds en tete:\n");
    print_list(head);

	printf("----------------------------------------------------\n");
	printf(BOLD_YELLOW "LST_ADD_BACK : \n" RESET);

    node1 = ft_lstnew("Premier");
    node2 = ft_lstnew("Deuxieme");
    node3 = ft_lstnew("Troisieme");

    head = node1;
    ft_lstadd_back(&head, node2);
    ft_lstadd_back(&head, node3);

    printf("Liste apres ajout des noeuds a la fin:\n");
    print_list(head);
	printf("----------------------------------------------------\n");

	printf(BOLD_YELLOW "LST_SIZE : \n" RESET);

    head = node1;
	node1->next = node2;
	node2->next = node3;

    printf("Liste complete :\n");
    print_list(head);

	int size = ft_lstsize(head);
	printf(BOLD_MAGENTA "Taille de la liste : %d\n" RESET, size);
	printf("----------------------------------------------------\n");

	printf(BOLD_YELLOW "LST_LAST : \n" RESET);

	node1 = ft_lstnew("Premier");
	node2 = ft_lstnew("Deuxieme");
	node3 = ft_lstnew("Troisieme");

	head = node1;
	node1->next = node2;
	node2->next = node3;

	printf("Liste complete :\n");
	print_list(head);

	t_list *last = ft_lstlast(head);
	if (last)
		printf(BOLD_MAGENTA "Dernier element de la liste : %s\n" RESET, (char *)last->content);
	else
	printf(BOLD_MAGENTA "La liste est vide\n" RESET);
	printf("----------------------------------------------------\n");

	printf(BOLD_YELLOW "LST_DELONE : \n" RESET);

	char	*content1 = ft_strdup("Premier");
	char	*content2 = ft_strdup("Deuxieme");
	char	*content3 = ft_strdup("Troisieme");

	node1 = ft_lstnew(content1);
	node2 = ft_lstnew(content2);
	node3 = ft_lstnew(content3);

	node1->next = node2;
	node2->next = node3;

	printf(BOLD_MAGENTA "Liste avant la suppression :\n" RESET);
	print_list(node1);

	printf(BOLD_RED "\nSuppression du deuxieme noeud...\n" RESET);
	ft_lstdelone(node2, free);
	node1->next = node3;

	printf(BOLD_MAGENTA "\nListe apres suppression :\n" RESET);
	print_list(node1);

	ft_lstdelone(node1, free);
	ft_lstdelone(node3, free);

	printf("----------------------------------------------------\n");
	printf(BOLD_YELLOW "LST_ITER : \n" RESET);

	t_list	*tete = ft_lstnew(ft_strdup("premier"));
	t_list	*noeud1 = ft_lstnew(ft_strdup("deuxieme"));
	t_list	*noeud2 = ft_lstnew(ft_strdup("troisieme"));

	tete->next = noeud1;
	noeud1->next = noeud2;

	printf(BOLD_MAGENTA "Liste avant transformation : (fonction to_upper)\n" RESET);
	ft_lstiter(tete, print_content);

	ft_lstiter(tete, to_uppercase);

	printf(BOLD_MAGENTA "\nListe apres uppercase :\n" RESET);
	ft_lstiter(tete, print_content);

	ft_lstclear(&tete, free);

	printf("----------------------------------------------------\n");
	printf(BOLD_YELLOW "LST_MAP : \n" RESET);

	t_list *tete2 = ft_lstnew(ft_strdup("Premier"));
	t_list *noeud11 = ft_lstnew(ft_strdup("Deuxieme"));
	t_list *noeud22 = ft_lstnew(ft_strdup("Troisieme"));
	tete2->next = noeud11;
	noeud11->next = noeud22;

	printf(BOLD_MAGENTA "Liste d'origine :\n" RESET);
	ft_lstiter(tete2, print_content);

	t_list *new_list = ft_lstmap(tete2, duplicate_with_prefix, delete_content);

	printf(BOLD_MAGENTA "Nouvelle liste :\n" RESET);
	ft_lstiter(new_list, print_content);

	ft_lstclear(&tete2, delete_content);
	ft_lstclear(&new_list, delete_content);
    return (0);
}

