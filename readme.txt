The tree structure and most of its functions are the same as 
sir's code except the disp_r() function.

In the disp_r() function I have added variables too keep track of level
and count of switch cases while recursion. I visit the parent first and 
then go through all its child nodes. If any of the child nodes are 
parent nodes, then I call the disp_r() on that node. This way, 
I can traverse all the nodes so that I print the Switch statements in 
a single pass. 

In the code that is being generated, i use while/switch functions to
traverse the menu. To exit out of the submenus, without exiting from the whole
program, I use different variables at different levels of sub-menus.
For eg, the topmost menu has a[0] as the variable for while loop and
the sub-menus for "case 1" of that menu will have a[1] as the variable 
and so on. These variables are initialized to 1 before entering the while loop
the switch case, upon receving 0 as the input, will set the corresponding 
variable to 0, which terminates the while loop.

The major takeaway from this assignment was the knowledge of General Purpose Trees
and program generation.
I initially had some problem printing the GPT to switch cases, but as I looked into
it after taking a break, I understoood the logic behind it.
