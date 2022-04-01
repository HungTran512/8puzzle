/******************************************************************************
 *  Name: Tran Nguyen Hung
 *
 *  Operating system: mac OS
 *  Compiler: g++
 *  Text editor / IDE: atom
 *  Hours to complete assignment (optional): 5
 ******************************************************************************/


/******************************************************************************
 *  Explain briefly how you implemented the board data type.
 *****************************************************************************/

 I used a 2d vector to implement the board data type. I also create a solveboard
 which is the goal board to compare. them I use nested loop for counting the hamming
 and manhattan distance.

/******************************************************************************
 *  Explain briefly how you represented a search node
 *  (board + number of moves + previous search node).
 *****************************************************************************/
I made a struct that contains the board content, the number of moves to reach that board,
 and a pointer its the parent.






/******************************************************************************
 *  Explain briefly how you detected unsolvable puzzles. What is the
 *  order of growth of the runtime of your isSolvable() method?
 *****************************************************************************/
If the Inversion is even and the puzzle size is odd then the puzzle is solvable,
If the puzzle size is even, and the sum of inversions and plus the row of the
blank square is odd, the puzzle is solvable

order of growth: N^4.


/******************************************************************************
 *  For each of the following instances, give the minimal number of
 *  moves to reach the goal state. Also give the amount of time
 *  it takes the A* heuristic with the Hamming and Manhattan
 *  priority functions to find the solution. If it can't find the
 *  solution in a reasonable amount of time (say, 5 minutes) or memory,
 *  indicate that instead. Note that you may be able to solve
 *  puzzlexx.txt even if you can't solve puzzleyy.txt even if xx > yy.
 *****************************************************************************/


                  number of          seconds
     instance       moves      Hamming     Manhattan
   ------------  ----------   ----------   ----------
   puzzle28.txt
   puzzle30.txt
   puzzle32.txt
   puzzle34.txt
   puzzle36.txt
   puzzle38.txt
   puzzle40.txt
   puzzle42.txt



/******************************************************************************
 *  If you wanted to solve random 4-by-4 or 5-by-5 puzzles, which
 *  would you prefer:  a faster computer (say, 2x as fast), more memory
 *  (say 2x as much), a better priority queue (say, 2x as fast),
 *  or a better priority function (say, one on the order of improvement
 *  from Hamming to Manhattan)? Why?
 *****************************************************************************/

I would prefer a better priority function and and priority queue because it's
would be more practical and better than faster computer or memory.


 /******************************************************************************
  *  Known bugs / limitations.
  *****************************************************************************/




 /******************************************************************************
  *  Describe whatever help (if any) that you received.
  *  Don't include readings, lectures, and exercises, but do
  *  include any help from people (including classmates and friends) and
  *  attribute them by name.
  *****************************************************************************/


 /******************************************************************************
  *  Describe any serious problems you encountered.
  *****************************************************************************/
  There is something wrong with my neighbor function where is change Tiles value
  to 0.



 /******************************************************************************
  *  List any other comments here. Feel free to provide any feedback
  *  on how much you learned from doing the assignment, and whether
  *  you enjoyed doing it.
  *****************************************************************************/
