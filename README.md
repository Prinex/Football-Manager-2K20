## Notice:
> This repository contains improvements of [4007CEM/Football-Manager2K20](https://github.com/4007CEM/Football-Manager-2K20).

## You can choose to build the project for MinGW Makefiles or VS 16 2019

- run the shell script files by clicking on them or using a terminal
1. If you choose VS 16 2019 make sure to:
* build the project's source files by selecting ALL_BUILD project in the solution explorer, right click on it 
  and select 'build'
* select Football-Manager-2K20, right click on it and select 'Set as StartUp project'
* now you can run the project in VS

2. If you choose MinGW Makefiles make sure you:
* To run the project using mingw makfiles use 'run.sh' script file
* have gcc installed, a recent version
* if the output is positonated wrong when running from terminal, navigate to the directory where the .exe file is and execute it 

### Improvements:
* better dynamic allocation with smart pointers
* using more of STL
* automated compilation and running using a shell scripts
* comiplation using cmake for MinGW MakeFiles or VS 2019 as mentioned above

### Game instructions :

* use esc to go back to the main menu
* backspace to go back to a submenu
* enter to select an option

### Some demos:
* choosing a sqaud according to a country

![](/images/na.PNG) 
![](/images/squads.PNG)

* main menu

![](/images/menu.PNG)

* viewing players

![](/images/Capture.PNG)
![](/images/pl.PNG)

* gampeplay

![](/images/gameplay.PNG)
