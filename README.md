
## Notice:
> This repository contains improvements of [4007CEM/Football-Manager2K20](https://github.com/4007CEM/Football-Manager-2K20).
>
> A based-text game that simulates a match between two football clubs.
> 
> It is a game that has no graphics. 
> 
> It uses only the English language or/and any ASCII character.

## You can choose to build the project for MinGW Makefiles or VS 16 2019

- run the shell script files by clicking on them or using a terminal
1. If you choose VS 16 2019, after generating the project's solution, make sure you:
* Build the project's source files by selecting ALL_BUILD project in the solution explorer of VS, right click on it, and select 'build'.
* Select Football-Manager-2K20, right click on it and select 'Set as StartUp project'.
* Now you can run the project in VS.

3. If you choose MinGW Makefiles make sure you:
* Run the project using mingw makfiles use 'run.sh' script file.
* Have gcc installed, a recent version.
* Run the .exe file is ran using the windows terminal, if not, the output will be displayed wrong, e.g., git terminal.

### Improvements:
* Better dynamic allocation using smart pointers.
* Using more of STL features: iterators, containers, and functions.
* Automated compilation and running using shell scripts.
* Comiplation using cmake for MinGW MakeFiles or VS 2019 as mentioned above.

### Game instructions :

* Use 'esc' key to go back to the main menu
* Use 'backspace' key to go back to a submenu.
* Use 'enter' to select an option.

### UML - ERD interface plan:

* We are using data structures to store players and football clubs as a "database".

![](/images/interface_plan.PNG)

### Some demos:
* Choosing a sqaud according to a country:

![](/images/na.PNG) 
![](/images/squads.PNG)

* The main menu:

![](/images/menu.PNG)

* Viewing players:

![](/images/Capture.PNG)
![](/images/pl.PNG)

* Gampeplay:

![](/images/gameplay.PNG)
