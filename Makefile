NAMEC = client
NAMES = server
CFLAGS = -Wall -Wextra -Werror

FT_SRCC = \
	src/client.c  src/ft_atoi.c src/ft_atoi_bin.c ft_printf/ft_printf.c ft_printf/ft_putchar.c  ft_printf/ft_putstr.c \
	ft_printf/ft_putnbr.c ft_printf/ft_putnbr_u.c ft_printf/ft_strlen.c  ft_printf/dec_to_hex.c ft_printf/hex_pointer.c
FT_SRCS = \
	src/server.c src/ft_atoi_bin.c ft_printf/ft_printf.c ft_printf/ft_putchar.c  ft_printf/ft_putstr.c \
	ft_printf/ft_putnbr.c ft_printf/ft_putnbr_u.c ft_printf/ft_strlen.c  ft_printf/dec_to_hex.c ft_printf/hex_pointer.c

OBJC = $(FT_SRCC:.c=.o)
OBJS = $(FT_SRCS:.c=.o)





FT_SRCC_bonus = \
	bonus/client_bonus.c  bonus/ft_atoi_bonus.c bonus/ft_atoi_bin_bonus.c ft_printf/ft_printf.c ft_printf/ft_putchar.c  ft_printf/ft_putstr.c \
	ft_printf/ft_putnbr.c ft_printf/ft_putnbr_u.c ft_printf/ft_strlen.c  ft_printf/dec_to_hex.c ft_printf/hex_pointer.c
FT_SRCS_bonus = \
	bonus/server_bonus.c bonus/ft_atoi_bin_bonus.c ft_printf/ft_printf.c ft_printf/ft_putchar.c  ft_printf/ft_putstr.c \
	ft_printf/ft_putnbr.c ft_printf/ft_putnbr_u.c ft_printf/ft_strlen.c  ft_printf/dec_to_hex.c ft_printf/hex_pointer.c

OBJC_bonus = $(FT_SRCC_bonus:.c=.o)
OBJS_bonus = $(FT_SRCS_bonus:.c=.o)






all: $(NAMES) $(NAMEC)

$(NAMES): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o server

$(NAMEC): $(OBJC)
	cc $(CFLAGS) $(OBJC) -o client

bonus: $(OBJS_bonus) $(OBJC_bonus)
	cc $(CFLAGS) $(OBJS_bonus) -o server
	cc $(CFLAGS) $(OBJC_bonus) -o client


clean:
	rm -f $(OBJC) $(OBJS) $(OBJS_bonus) $(OBJC_bonus)

fclean: clean
	rm -f $(NAMEC) $(NAMES)

re: fclean all

