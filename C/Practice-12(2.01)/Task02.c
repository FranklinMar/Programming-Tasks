/*
----------------
Name: Task02.c
------------------------------------------------------------
Description: Write a program taking into consideration 
  example of code on "Growing Arrays" lecture page (or just 
  use created code from the previous task).
  Function delname() doesn't call function realloc(), to 
  return a memory, that was freed when deleting elements.
  
  Analyze the example and give answer on question: Was this 
  example correct on not using function realloc()? How do 
  you think, is it possible to implement the tasks set in 
  the example by other way? And, which way would be better?
------------------------------------------------------------

Answer: In this example, the better way depends on our goals:
  If we need to change the amount of assigned memory (change 
  the amount of memory), then we need to use realloc() function.
  Yes, the tasks set in the example could be implemented by 
  other way.
*/
