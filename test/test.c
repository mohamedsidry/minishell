/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:07:45 by msidry            #+#    #+#             */
/*   Updated: 2025/06/05 17:32:05 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void test(t_list **env, t_list **commands, char **line)
{
    (void)commands,
    (void)line;
    modenotifier(); //NOTE: display message of debuging mode .
	run_unit_tests(); //NOTE: test functionality of pace of codes .
    update_node(env, "THIS_IS_KEY", "THIS_IS_VALUE"); //NOTE : Addes node with key value to env list or update if the key exist . 
	display_env(*env); //NOTE: display current env key:value .
}