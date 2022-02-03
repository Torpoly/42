/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:53:48 by rpol              #+#    #+#             */
/*   Updated: 2022/02/02 19:47:00 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>

int main(void)
{
  void *mlx;
  void *window;
  
  mlx = mlx_init();
  if (!mlx)
    return (write(1, "ERROR\n", 6), -1);
  window = mlx_new_window(mlx, 1000, 1000, "kayak");
  
  mlx_loop(mlx);
  return (0);
}