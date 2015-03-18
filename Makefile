
NAME = ft_retro

SRCSFILES = \
			main.cpp\
			AObject.class.cpp\
			Background.class.cpp\
			Game.class.cpp\
			Shape.class.cpp\
  ./enemies/Pig.class.cpp\
     ./move/IMovIA.class.cpp\
     ./move/AMovPatternDefault.class.cpp\
    ./shoot/IShootIA.class.cpp\
    ./shoot/AShootPatternDefault.class.cpp

SRCPATH = .
OBJPATH = obj
CC = g++
INCLUDES = -I . -I ./enemies/ -I ./move/ -I ./shoot/
LIBS = -lncurses
CFLAGS = -Werror -Wall -Wextra -O2
RM = rm -rf

SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.cpp=$(OBJPATH)/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(OBJECTS) $(LIBS)
	
$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

clean:
	$(RM) $(OBJPATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all
