maxlinks:= 1000
pagelimit:= 10
threads:= 3
# er ror
all_targets:= clear compile run clean

all: ${all_targets}

clear:
	@clear
	@rm -r -f thread_logs > /dev/null 2>&1
	@rm -r -f crawler > /dev/null 2>&1
	@mkdir thread_logs

compile:
	@echo "Compiling file..."
	g++ -std=c++14 main.cpp -o crawler -lssl -lpthread -w

run:
	@echo "Running..."
	./crawler $(maxlinks) $(pagelimit) $(threads)
	python graph.py

clean:
	rm -r -f crawler
	rm -r -f thread_logs
	rm -r -f logs.txt
	rm -r -f th_timings.csv
	
	@echo "All cleaned."