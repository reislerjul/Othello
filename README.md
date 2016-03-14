
Caltech CS2 Assignment 9: Othello

See [assignment9_part1.html](http://htmlpreview.github.io/?https://github.com/caltechcs2/othello/blob/master/assignment9_part1.html) and [assignment9_part2.html](http://htmlpreview.github.io/?https://github.com/caltechcs2/othello/blob/master/assignment9_part2.html)

# Othello

To make my Al tournament worthy, I changed the values for the heuristic function. 
First, I added conditions so that a move on an edge (that's not next to a corner) is 
weighted positively and a move next to the edge (that's not also next to a corner)
is weighted negatively. I also tested different values for each weight against the 
ConstantTimePlayer to determine the best Al to use. Here are the results: 

Corners: 10 
Edges: 2 
Next to edges: -2
next to corners: -5 
Wins as Black: 1/5 
Wins as White: 0/5 

Corners: 3
Edges: 1
Next to edges: 1
next to corners: -3
Wins as Black: 0/5
Wins as White: 2/5

Corners: 4
Edges: 2
Next to edges: -2
next to corners: -4
Wins as Black: 0/5
Wins as White: 1/5 

Corners: 5
Edges: 2
Next to edges: -2
next to corners: -5
Wins as Black: 2/5 
Wins as White: 0/5

Corners: 10
Edges: 5
Next to edges: 1
next to corners: -5
Wins as Black: 0/5
Wins as White: 0/5 


Corners: 5
Edges: 2
Next to edges: 1
next to corners: 0
Wins as Black: 1/5
Wins as White: 1/5 


Corners: 5
Edges: 2
Next to edges: -1
next to corners: -3
Wins as Black: 0/5
Wins as White: 0/5 

Out of the these, the best Als had a total of 2/10 wins against ConstantTimePlayer. 
Thus, I changed the values in my Al to weight the corners as 5, next to corners as 
-5, edges as 2, and next to edges as -2. 
