# \file Makefile
# \author Robert Jakes <jakesrob@fit.cvut.cz>
# \version 1.0

################################################################################

BINARY  :=  game 

DOC_DIR :=  doc
DOC     :=  doxyfile

SRC_DIR :=  src
SRC     :=  $(wildcard $(SRC_DIR)/*.cpp) 

OBJ_DIR :=  build
OBJ     :=  $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o) 

DEP     :=  $(OBJ:.o=.d) 

CPPFLAGS    :=  -MMD -MP 

CXXFLAGS    :=  -Wall -pedantic -std=gnu++0x -Wno-long-long -O0 -ggdb

LDFLAGS     :=  # -L flags

LDLIBS      :=  -lcurses 

.PHONY: all doc run clean

all: $(BINARY) doc

compile: $(BINARY)

$(BINARY): $(OBJ)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

$(OBJ_DIR):
	@mkdir $@

-include $(DEP) 

doc:
	@mkdir -p $(DOC_DIR)
	doxygen $(DOC)

run: $(BINARY)
	./$(BINARY)

clean:
	-rm -rf $(OBJ_DIR) $(BINARY) $(DOC_DIR)
