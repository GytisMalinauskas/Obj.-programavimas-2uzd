# Kompiliatoriaus nustatymai
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iheaders

# Šaltinio failai
SRC = $(wildcard source/*.cpp)

# Objektų failai
OBJ = $(SRC:.cpp=.o)

# Vykdomasis failas
TARGET = run
TEST_TARGET = run_tests

# Optimization levels
OPT_LEVELS = O1 O2 O3
OPT_FLAGS_O1 = -O1
OPT_FLAGS_O2 = -O2
OPT_FLAGS_O3 = -O3

# Pagrindinė taisyklė
all: $(OPT_LEVELS)

# Targets for each optimization level
O1: CXXFLAGS += $(OPT_FLAGS_O1)
O1: $(TARGET)_O1

O2: CXXFLAGS += $(OPT_FLAGS_O2)
O2: $(TARGET)_O2

O3: CXXFLAGS += $(OPT_FLAGS_O3)
O3: $(TARGET)_O3

# Vykdomojo failo taisyklės su optimizavimo lygiais
$(TARGET)_O1: $(OBJ)
	@echo "Building target with -O1: $@"
	$(CXX) $(CXXFLAGS) $(OPT_FLAGS_O1) -o $@ $^

$(TARGET)_O2: $(OBJ)
	@echo "Building target with -O2: $@"
	$(CXX) $(CXXFLAGS) $(OPT_FLAGS_O2) -o $@ $^

$(TARGET)_O3: $(OBJ)
	@echo "Building target with -O3: $@"
	$(CXX) $(CXXFLAGS) $(OPT_FLAGS_O3) -o $@ $^

# Kompiliavimo taisyklė kiekvienam šaltinio failui
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Tikslas testams
tests: $(TEST_TARGET)

$(TEST_TARGET): $(OBJ)
	@echo "Building test target: $@"
	$(CXX) $(CXXFLAGS) -o $@ $^

# Švaros taisyklė
clean:
	rm -f $(OBJ) $(TARGET)_O1 $(TARGET)_O2 $(TARGET)_O3 $(TEST_TARGET)
