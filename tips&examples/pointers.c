// QUICK IMPLEMENTATION AS A REMINDER OF HOW POINTERS WORK

// CODE WITHOUT POINTERS

int counter = 0;

int main() {
  while(counter < 21) {
    ++counter;
  }
  return 0;
}

// CODE WITH POINTERS

int counter = 0;

int main() {
  int *p_int; // reading backwards, this is p_int, a variable that can store addresses (definition of pointer) of integer variables, 
  p_int = &counter; // in this case, we can store the ADDRESS of the counter variable in the p_int variable; 
  while(*p_int < 21) { // *p_int now is the value stored in the adress p_int . This is de-referencing the pointer. 
    ++(*p_int);
  }
  return 0;
}
