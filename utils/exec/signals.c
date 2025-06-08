#include "../../include/header.h"

void	setup_signals(void)
{
	signal(SIGINT, signal_handler); // ctrl+C
	signal(SIGQUIT, signal_handler); // ctrl+\\"
}

void	signal_handler(int sig)
{
	g_signal_received = sig;
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line(); // readline: go to new line
		rl_redisplay(); // readline: redraw prompt
	}
}

void	signal_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	signal_parent(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}