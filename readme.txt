How to use:

_compile using the command in gcc_command.txt
_cmd command: program.exe netlist_name output_name
*Note: netlist must be in .net form. Don't include .net and .txt suffix in netlist_name and output_name argument.


Tuning:

_Maximum temperature: The maximum temperature should be sufficiently larger than delta cost so that at the start the program is more likely to accept bad moves. Generally, about 50% of the moves should be accepted during the initial steps. Assume the netlist with n nets. The average bad move delta cost will be (n-1)/2 = del_cost_ave. The program use random numbers that are the discrete uniform distributed type, meaning all numbers between a range have equal probability to be generated. Therefore, to have 50% of being accepted initially, Boltz number should be around 0.5.
	2.72^[-del_cost_ave/(2*T0)] = 0.5
Knowing the number of nets we can calculate for T0
_ Run the program from T0 to 0.1 * T0 with cool rate of 0.01 and m moves each step. This way the program will run through 1 temperature loop. Check the execution time T

_ T/m = T_ave is average time to execute 1 loop

_ Solve for x in T0 * x^[(Desired  time / T_ave) / m] = 0.1


Change Note:

1/
_Changed net matrix to net adjacency list.
_Cost function: only calculate the cost of 2 cells that are swapped
_Move function: moved random generator out to main()

2/
_Changed k from 1 to 2.72
_Output Cost.text, Accepted move.txt, Iteration.txt for ploting charts

3/
_Add dfilter.cpp to reduce data points of the txt files to plot chart in excel. Take a data point every 112 points for B4 to B6; 252 points for B7 to B10.