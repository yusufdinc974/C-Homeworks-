all: clean compile run

compile: hmw1.c util.c
#	@echo "-----------------------------------------"
#	@echo "Compiling..."
	gcc -o test hmw1.c util.c
	
run:
#	@echo "-----------------------------------------"
#	@echo "Running the tests..."
#	@echo "========================================="
	./test
#	@echo "========================================="
#	@echo "Completed tests..."

clean:
#	@echo "-----------------------------------------"
#	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
