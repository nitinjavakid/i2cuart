#include <usart.h>
#include <twi.h>
#define F_CPU 16E6

int main()
{
    n_io_handle_t usart_handle, twi_handle;
    n_usart_enable(N_USART_8BIT, N_USART_PARITY_NONE, N_USART_STOPBIT1, 115200);
    twi_handle = n_twi_new_slave_io(0x04, 100);
    usart_handle = n_usart_new_io(100);

    while(1)
    {
        char *line = n_io_readline(twi_handle, NULL, 0);
        n_io_printf(usart_handle, "%s", line);
        free(line);
    }

    return 0;
}
