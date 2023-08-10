

### Background:
> This repository contains improvements of [4007CEM/Football-Manager2K20](https://github.com/4007CEM/Football-Manager-2K20).
>
> A based-text game that simulates a match between two football clubs.
> 
> It is a game that has no graphics. 
> 
> It uses only the English language or/and any ASCII character.
>
> Note that, this is project will not work on UNIX-like systems because of the windows.h usage, which is working only on Windows.

### Building and running the project:

> You can choose to build the project for MinGW Makefiles or an installed version of VS Visual Studio.
>
> Shell script files have been prodived to build and run the project for you.
>
> You can simply run the run.sh script file, which will also run the buildPrj.sh script file for building and running the project.

#### 1. If you choose your installed version of Visual Studio, and want to modify, run, and build the project using VS IDE, make sure you:
* Generate the project using the buildPrj.sh script file.
* Build and link the project's files by selecting ALL_BUILD project in the solution explorer of VS, right click on it, and select 'build'.
* Select Football-Manager-2K20, right click on it and select 'Set as StartUp project'.

#### 2. If you choose your installed version of Visual Studio, and want just to build and run the project, run the run.sh script file.

#### 3. If you want to build and run the project with a different version of Visual Studio, make sure you:
* Change the version number and year version from the build.sh script file, e.g. from `cmake .. -G "Visual Studio 16 2019"` to `cmake .. -G "Visual Studio 17 2022"`.

#### 4. If you choose MinGW Makefiles make sure you:
* Have gcc installed, a recent version.
* Run the run.sh script file, which will also run the buildPrj.sh script file for building and running the project using MinGW Makefiles.


### Improvements:
* Better dynamic allocation using smart pointers.
* Using more of STL features: iterators, containers, and functions.
* Automated compilation and running using shell scripts.
* Comiplation using cmake for MinGW MakeFiles or VS 2019 as mentioned above.

### Game instructions :

* Use 'esc' key to go back to the main menu.
* Use 'backspace' key to go back to a submenu.
* Use 'enter' to select an option.
* Use left and right key arrows to navigate the main menu.
* Use up and down key arrows to navigate the submenus.

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
