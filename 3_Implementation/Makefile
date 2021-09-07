# Name of the project
PROJECT_NAME = TextPad

# Output directory
BUILD = build

# All source code files
SRC = project_main.c\
src/passwordUsernameFormatChecker.c\
src/masterAccountFunctions.c\
src/credentialFunctions.c\
src/sha256.c\

# All test source files
TEST_SRC = src/passwordUsernameFormatChecker.c\
src/masterAccountFunctions.c\
src/credentialFunctions.c\
test/testTextPadFunctions.c\
src/sha256.c\
unity/unity.c\

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME).out

# All include folders with header files
INC	= -Iinc\
-Iunity\

#Library Inlcudes
#if working with CUnit 
#INCLUDE_LIBS = -lcunit
#INCLUDE_LIBS =

# Project Output name
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME)

DEBUG_OUTPUT = $(BUILD)/Debug_$(PROJECT_NAME)

# Document files
DOCUMENTATION_OUTPUT = documentation/html

# Default target built
$(PROJECT_NAME):all

# Run the target even if the matching name exists
.PHONY: run clean test doc all

all: $(SRC) $(BUILD)
	gcc $(SRC) $(INC) $(INCLUDE_LIBS) -o $(PROJECT_OUTPUT).out

windows:
	gcc $(SRC) $(INC) $(INCLUDE_LIBS) -o $(PROJECT_OUTPUT).exe


debug: $(SRC) $(BUILD)
	gcc -g $(SRC) $(INC) $(INCLUDE_LIBS) -o $(DEBUG_OUTPUT).out

# Call `make run` to run the application
run:$(PROJECT_NAME)
	./$(PROJECT_OUTPUT).out

run_windows:$(PROJECT_NAME)
	./$(PROJECT_OUTPUT).exe

# Document the code using Doxygen
#doc:
#	make -C ./documentation

# Build and run the unit tests
test:$(BUILD)
	gcc $(TEST_SRC) $(INC) $(INCLUDE_LIBS) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)
#Coverage
coverageCheck:$(BUILD)
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 $(TEST_SRC) $(INC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)

# Remove all the built files, invoke by `make clean`
clean:
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)

# Create new build folder if not present
$(BUILD):
	mkdir build
