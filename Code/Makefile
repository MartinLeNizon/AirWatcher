# /*************************************************************************
#                           		 Makefile
#                              -------------------
#     début                : 9 mai 2023
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
EXEC = $(EXECDIR)airwatcher
SRCDIR = src/
SRC = $(wildcard $(SRCDIR)*.cpp)
OBJDIR = obj/
OBJ = $(SRC:$(SRCDIR)%.cpp=$(OBJDIR)%.o)


all: $(EXEC) $(TEST)

ifeq ($(DEBUG),yes)
	@echo "Mode debug"
else
	@echo "Mode release"
endif


# TEST
TESTDIR = Tests/classes/
TESTSRC = $(wildcard $(TESTDIR)*.cpp)
TESTOBJ = $(TESTSRC:%.cpp=%.o)
TEST = $(TESTSRC:%.cpp=%)

$(TESTDIR)StatisticsServicesTests: $(TESTDIR)StatisticsServicesTests.o $(filter-out $(OBJDIR)main.o, $(OBJ))
	@$(CXX) -o $@ $^ $(LDFLAGS)

$(TESTDIR)SystemTests: $(TESTDIR)SystemTests.o $(filter-out $(OBJDIR)main.o, $(OBJ))
	@$(CXX) -o $@ $^ $(LDFLAGS)

$(TESTDIR)%.o: $(TESTDIR)%.cpp
	@$(CXX) -o $@ -c $< $(CXXFLAGS)


$(EXEC): $(OBJ)
	@$(CXX) -o $@ $^ $(LDFLAGS)


$(OBJDIR)Device.o: $(SRCDIR)Device.h $(SRCDIR)Coordinates.h

$(OBJDIR)Cleaner.o: $(SRCDIR)Cleaner.h $(SRCDIR)Device.h $(SRCDIR)Coordinates.h

$(OBJDIR)Sensor.o: $(SRCDIR)Sensor.h $(SRCDIR)Device.h $(SRCDIR)Coordinates.h

$(OBJDIR)Measurement.o: $(SRCDIR)Measurement.h $(SRCDIR)Values.h

$(OBJDIR)User.o: $(SRCDIR)User.h

$(OBJDIR)AgencyEmployee.o: $(SRCDIR)AgencyEmployee.h $(SRCDIR)User.h

$(OBJDIR)PrivateUser.o: $(SRCDIR)PrivateUser.h  $(SRCDIR)User.h

$(OBJDIR)ProviderEmployee.o: $(SRCDIR)ProviderEmployee.h $(SRCDIR)User.h

$(OBJDIR)System.o: $(SRCDIR)System.h $(SRCDIR)User.h $(SRCDIR)Device.h $(SRCDIR)Sensor.h $(SRCDIR)Cleaner.h $(SRCDIR)Provider.h

$(OBJDIR)StatisticsServices.o: $(SRCDIR)StatisticsServices.h $(SRCDIR)Coordinates.h $(SRCDIR)Measurement.h $(SRCDIR)Values.h $(SRCDIR)Device.h $(SRCDIR)Zone.h

$(OBJDIR)main.o: $(SRCDIR)System.h $(SRCDIR)Device.h $(SRCDIR)StatisticsServices.h $(SRCDIR)Conversions.h

$(TESTDIR)StatisticsServicesTests.o: $(SRCDIR)System.h $(SRCDIR)Device.h $(SRCDIR)StatisticsServices.h $(SRCDIR)Measurement.h $(SRCDIR)Values.h $(SRCDIR)Conversions.h

$(TESTDIR)SystemTests.o: $(SRCDIR)System.h $(SRCDIR)Device.h $(SRCDIR)Sensor.h $(SRCDIR)Cleaner.h $(SRCDIR)StatisticsServices.h $(SRCDIR)Measurement.h $(SRCDIR)Values.h $(SRCDIR)Conversions.h $(SRCDIR)Coordinates.h $(SRCDIR)Zone.h $(SRCDIR)PrivateUser.h

$(OBJDIR)%.o: $(SRCDIR)%.cpp Makefile
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

# CLEAN
.PHONY:clean mrproper

clean:
	@rm -rf $(OBJ) $(TESTDIR)StatisticsServicesTests.o
	@echo "Fichiers objets supprimés"

mrproper: clean
	@rm -rf $(EXEC) $(TESTDIR)StatisticsServicesTests.o $(TESTDIR)StatisticsServicesTests
	@echo "Fichiers objets et exécutable(s) supprimés"