# Minishell

This project is about creating **minishell**, a program that execute commands .

### PARSING :

Parsing is the action of turning user raw input string to tokens , expand, validate and translate to list of commands that can be used by teammate to loop over and execute .

#### JOB DONE  :

- [x]  Init repo .
- [x] Create Makefile to manage compiling .
- [x] Create main program entry point .
- [x] Create function that manage env vars CRUD operations .
- [x] Create functions for debuging and testing .
- [x] Display prompt and read user input .
- [x] Lexical tokenization, turn each part of string to meaningful unit .
- [ ] Expanding env variables (*on progress . . .*) .
- [ ] Validation of syntax (*on progress . . .*) .
- [ ] Follow norms .
- [ ] Full test.

### EXECUTION :

> Update this teammate !!!!






#### JOB DONE  :


- [ ] Add your progress here !
- ...


### NOTES

> *Changes made to be aware of .*




### Makefile  :

#### RULES:
<BR>
 
    make

 **make**
:   *build an executable file  .*

    make run

**make run**: *build if necessary and clean object files then run executable .*

    make clean

**make clean**: *remove object files .*
    
    make fclean

**make fclean**: *remove object files and executable .*

    make re

**make re**: *rebuild the project .*

    make debug

**make debug**: *run code in ```debug mode```* display info of stages and unit test lists contents env content .


    make vrun

**make vrun**: *run code with valgrind for memory leak checks !*

    make fvrun

**make fvrun**: *run code with valgrind for full memory leak checks !*


    make norms

**make norms**: *check if files align with norms*

#### REQUIREMENTS

- ```readline```: read input from stdin an return it.
- ```history``` : add user input to history .
- ```valgrind```: check leaks .
- ```norminette```: check norms .
