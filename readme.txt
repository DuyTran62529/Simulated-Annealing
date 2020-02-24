How to use:

_compile using the command in gcc_command.txt
_cmd command: program.exe netlist_name output_name
*Note: netlist must be in .net form. Don't include .type suffix in netlist_name and output_name argument.

Change Note:

1/
_Changed net matrix to net adjacency list.
_Cost function: only calculate the cost of 2 cells that are swapped
_Move function: moved random generator out to main()

2/
_Changed k from 1 to 2.72
_Output Cost.text, Accepted move.txt, Iteration.txt for ploting charts
