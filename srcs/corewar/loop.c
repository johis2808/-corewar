/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:20:59 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/03 02:30:15 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "process.h"
#include "output.h"
#include "arena.h"
#include "ftio.h"
#include "op.h"
#include "vm.h"

static t_proc	*vm_kill(t_vm *vm, t_proc *proc)
{
	if (vm->verbosity & V_DEATHS)
	{
		corewar_write(1, "Process ", 8);
		corewar_putlnbr(1, proc->pid);
		corewar_write(1, " hasn't lived for ", 18);
		corewar_putnbr(1, vm->cycles - proc->last_live);
		corewar_write(1, " cycles (CTD ", 13);
		corewar_putnbr(1, (int)vm->cycle_to_die);
		corewar_write(1, ")\n", 2);
	}
	return (kill_process(proc));
}

static void		vm_check(t_vm *vm)
{
	t_proc		*proc;

	proc = g_procs.head;
	while (proc)
	{
		if ((vm->cycles - proc->last_live) >= vm->cycle_to_die)
			proc = vm_kill(vm, proc);
		else
			proc = proc->next;
	}
	++vm->last_dec;
	if (vm->total_live >= NBR_LIVE || vm->last_dec >= MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		if (vm->verbosity & V_CYCLES)
			out_ctd(vm->cycle_to_die);
		vm->last_dec = 0;
	}
	vm->total_live = 0;
}

static void		vm_exec(t_vm *vm, t_proc *proc)
{
	t_byte		cur;

	if (!proc->op)
	{
		cur = g_map[proc->pc % MEM_SIZE];
		if (cur <= 0 || cur > 16)
		{
			proc->pc = ((proc->pc + 1) % MEM_SIZE);
			return ;
		}
		proc->op = cur;
		proc->time_to_wait = g_op_tab[cur].cost;
	}
	if (proc->op && !--proc->time_to_wait)
	{
		proc->carry = g_op_tab[proc->op].fnc(vm, proc);
		proc->op = 0;
	}
}

void			cycle(t_vm *vm)
{
	t_proc		*proc;

	if (vm->cycles++ >= vm->dump && vm->dmp_bol)
		vm_dump(DUMP_LEN * vm->dmp_bol);
	if (vm->verbosity & V_CYCLES)
		out_cycles(vm->cycles);
	proc = g_procs.head;
	while (proc)
	{
		vm_exec(vm, proc);
		proc = proc->next;
	}
	if (--vm->last_check <= 0)
	{
		vm_check(vm);
		vm->last_check = vm->cycle_to_die;
	}
}

char			vm_loop(t_vm *vm)
{
	vm->cycles = 0;
	vm->last_check = CYCLE_TO_DIE;
	vm->cycle_to_die = CYCLE_TO_DIE;
	while (g_procs.size && vm->cycle_to_die > -64)
		cycle(vm);
	flush_buffer(1);
	return (0);
}
