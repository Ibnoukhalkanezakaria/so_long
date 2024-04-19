/*  */

#include "so_long.h"
#include <mlx.h>

// void f()
// {
//     void    *mlx_ptr;
//     // void    *mlx_p;

//     mlx_ptr = mlx_init();
    
//     mlx_new_window(mlx_ptr, 400, 800, "tofaha");
//     mlx_loop(mlx_ptr);
// }

// int main()
// {
//     f();
//     return 0;
// }

#include <mlx.h>

void f()
{
    void *mlx_ptr;
    
    mlx_ptr = mlx_init();
    
    mlx_new_window(mlx_ptr, 400, 800, "tofaha");
    mlx_loop(mlx_ptr);
}

int main()
{
    f();
    return 0;
}
