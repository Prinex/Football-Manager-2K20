
## Notice:
> This repository contains improvements of [4007CEM/Football-Manager2K20](https://github.com/4007CEM/Football-Manager-2K20).
>
> A based-text game that simulates a match between two football clubs.
> 
> It is a game that has no graphics. 
> 
> It uses only the English language or/and any ASCII character.
>
> Note that this is project is not really meant to be working on UNIX-like systems because of the windows.h usage which is working only on Windows

## You can choose to build the project for MinGW Makefiles or VS 16 2019

- run the shell script files by clicking on them or using a terminal
1. If you choose VS 16 2019, after generating the project's solution, make sure you:
* Build the project's source files by selecting ALL_BUILD project in the solution explorer of VS, right click on it, and select 'build'.
* Select Football-Manager-2K20, right click on it and select 'Set as StartUp project'.
* Now you can run the project in VS.

3. If you choose MinGW Makefiles make sure you:
* Run the project using MinGW Makefiles use 'run.sh' script file.
* Have gcc installed, a recent version.

### Improvements:
* Better dynamic allocation using smart pointers.
* Using more of STL features: iterators, containers, and functions.
* Automated compilation and running using shell scripts.
* Comiplation using cmake for MinGW MakeFiles or VS 2019 as mentioned above.

### Game instructions :

* Use 'esc' key to go back to the main menu
* Use 'backspace' key to go back to a submenu.
* Use 'enter' to select an option.
* Use left and right key arrows to navigate the main menu
* Use up and down key arrows to navigate the submenus

### UML - class diagram interface plan:

* We are using data structures to store players and football clubs as a "database".

![](/media/interface_plan.PNG)

### Some demos:
* Choosing a sqaud according to a country:

![](/media/select_squad.gif) 

* Viewing user's status players' status:

![](/media/status_and_players.gif)

* Short demo gameplay:

![](/media/gameplay.gif)
