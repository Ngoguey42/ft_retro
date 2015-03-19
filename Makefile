
NAME = ft_retro

SRCSFILES = \
			main.cpp\
			AObject.class.cpp\
			Background.class.cpp\
			Game.class.cpp\
			Scheduler.class.cpp\
			Shape.class.cpp\
  ./enemies/Pig.class.cpp\
  ./enemies/Sheep.class.cpp\
  ./enemies/Snake.class.cpp\
  ./enemies/Centipede.class.cpp\
  ./enemies/Lombric.class.cpp\
  ./enemies/Fizzy.class.cpp\
     ./move/IMovIA.class.cpp\
     ./move/AMovPatternDefault.class.cpp\
     ./move/AMovPatternSheep.class.cpp\
    ./shoot/IShootIA.class.cpp\
    ./shoot/AShootPatternDefault.class.cpp

SRCPATH = .
OBJPATH = obj
CC = g++
# CC = clang++
INCLUDES = -I . -I ./enemies/ -I ./move/ -I ./shoot/
LIBS = -lncurses
CFLAGS = -Werror -Wall -Wextra -O2
RM = rm -rf

SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.cpp=$(OBJPATH)/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "Compiling all"
	$(CC) -o $@ $(CFLAGS) $(OBJECTS) $(LIBS)

$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

clean:
	$(RM) $(OBJPATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all
