/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:32:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/02 12:28:10 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_DISABLE_WARNINGS

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "endianes.h"
#include "process.h"
#include "output.h"
#include "parser.h"
#include "arena.h"
#include "ftlib.h"
#include "ftio.h"
#include "vm.h"

/*
**	./corewar [-dump nb_cycles] [[-n num] champ1.cor] ...
**	-dump suivi d'un nombre, n'importe ou dans la commande excepte
**	entre un -n et son num ou entre un -n et son champion.
**	-n suivi d'un nombre puis d'un champion, partout excepte entre -dump et
**	son nombre
**
**	les nombres sont des unsigned int de 32 bit de long (uint32_t)
*/

static void	gen_champ(t_champ *champ, t_header *head)
{
	ft_bzero(champ->live_msg, PROG_NAME_LENGTH + 55);
	ft_strcpy(champ->comm, head->comment);
	ft_strcpy(champ->name, head->prog_name);
	ft_bzero(champ->live_msg, 128);
	ft_memcpy(champ->live_msg, SPLAYER, sizeof(SPLAYER) - 1);
	ft_nbrcat(champ->live_msg + sizeof(SPLAYER) - 1, champ->pid);
	ft_strcat(champ->live_msg, LIVEBRAC);
	ft_strcat(champ->live_msg, champ->name);
	ft_strcat(champ->live_msg, SALIVE);
	champ->live_msg_size = ft_strlen(champ->live_msg);
}

static void	load_file(t_vm *vm, t_champ *chmp, const char *path)
{
	int			fd;
	ssize_t		rd;
	t_header	head;

	chmp->pc = g_map + (MEM_SIZE / vm->psize * chmp->id);
	if ((fd = open(path, O_RDONLY)) < 0)
		exit(ft_print_error("Can't open '%s': %m.\n", path));
	if ((rd = read(fd, &head, sizeof(head))) < 0 && (close(fd) | 1))
		exit(ft_print_error("can't read '%s': %m.\n", path));
	if ((size_t)rd < sizeof(head) && (close(fd) | 1))
		exit(ft_print_error("'%s': Invalid or corrupted file.\n", path));
	bin_to_system(&head.magic, sizeof(head.magic));
	bin_to_system(&head.prog_size, sizeof(head.prog_size));
	if (head.magic != COREWAR_EXEC_MAGIC && (close(fd) | 1))
		exit(ft_print_error("'%s': Invalid or corrupted file.\n", path));
	if ((chmp->size = head.prog_size) > CHAMP_MAX_SIZE && (close(fd) | 1))
		exit(ft_print_error("'%s': File too big.\n", path));
	if ((rd = read(fd, chmp->pc, head.prog_size)) < 0)
		exit(ft_print_error("can't read '%s': %m.\n", path));
	if (close(fd) < 0)
		exit(ft_print_error("can't close fd '%d': %m.\n", fd));
	if (rd < head.prog_size)
		exit(ft_print_error("'%s': Invalid or corrupted file.\n", path));
	gen_champ(chmp, &head);
}

static void	sort_players(t_vm *vm)
{
	size_t	i;
	char	lp;
	t_champ	tmp;

	lp = 1;
	while (lp)
	{
		i = 0;
		lp = 0;
		while (++i < vm->psize)
		{
			if (vm->players[i - 1].pid > vm->players[i].pid)
			{
				tmp = vm->players[i];
				vm->players[i] = vm->players[i - 1];
				vm->players[i - 1] = tmp;
				lp = 1;
			}
		}
	}
}

void		parse_args(t_vm *vm, char **av)
{
	int32_t		i;
	t_proc		*proc;

	ft_bzero(vm, sizeof(t_vm));
	vm->players[0].pid = 1;
	while ((i = 0) || (av && *av))
	{
		while (g_parser[i].opt && !ft_strequ(*av, g_parser[i].opt))
			++i;
		av = g_parser[i].callback(vm, av + !!g_parser[i].opt);
	}
	if (!vm->psize)
		exit(ft_print_error("No player.\n"));
	i = -1;
	while (++i < (int32_t)vm->psize)
		load_file(vm, vm->players + i, (char *)vm->players[i].pc);
	sort_players(vm + (i = 0));
	while (i < (int32_t)vm->psize)
	{
		proc = add_process(vm->players[i].pc - g_map, NULL);
		if (!vm->winer || vm->winer->pid < vm->players[i].pid)
			vm->winer = vm->players + i;
		proc->last = vm->players[i].id;
		proc->regs[0] = -vm->players[i++].pid;
	}
}
