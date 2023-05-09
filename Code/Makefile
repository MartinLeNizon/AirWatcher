# /*************************************************************************
#                           		 Makefile
#                              -------------------
#     début                : 20 janvier 2023
#     copyright            : (C) 2023 par Mathis Nguyen, Hugo Saysana, Thibaut Chantrel & Martin Nizon-Deladoeuille
#     e-mails              : mathis.nguyen@insa-lyon.fr ; hugo.saysana@insa-lyon.fr ; thibaut.chantrel@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
# *************************************************************************/

# option debug : yes/no
# permet utilisation gdb et affichage méthodes appelées
DEBUG = no

CXX = g++
ifeq ($(DEBUG),yes)
	CXXFLAGS = -ansi -pedantic -Wall -std=c++11 -g -DMAP
	LDFLAGS = -DMAP
else
	CXXFLAGS = -ansi -pedantic -Wall -std=c++11
	LDFLAGS =
endif

EXECDIR = bin/
EXEC = $(EXECDIR)main
SRCDIR = src/
SRC = $(wildcard $(SRCDIR)*.cpp)
OBJDIR = obj/
OBJ = $(SRC:$(SRCDIR)%.cpp=$(OBJDIR)%.o)

all: $(EXEC)
ifeq ($(DEBUG),yes)
	@echo "Mode debug"
else
	@echo "Mode release"
endif

$(EXEC): $(OBJ)
	@$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/Sensor.o: $(SRCDIR)Sensor.h

$(OBJDIR)/main.o: $(SRCDIR)Sensor.h

$(OBJDIR)%.o: $(SRCDIR)%.cpp Makefile
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

.PHONY:clean mrproper

clean:
	@rm -rf $(OBJDIR)*.o

mrproper: clean
	@rm -rf $(EXEC)/airwatcher
