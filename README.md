# My first project in Geant4

![Geant4 logo](https://geant4.web.cern.ch/sites/default/files/g4logo-web.png)

This project folder is inspired from the YouTube video series you can find at the following link [Physics Matters](https://www.youtube.com/playlist?list=PLLybgCU6QCGWgzNYOV0SKen9vqg4KXeVL).

- For the official page of **Geant4 toolkit** visit [https://geant4.web.cern.ch/](https://geant4.web.cern.ch/)

------------------------------------

## Brief description of the directory structure
The project is aimed to be a template project with the definitions of the required classes. In this simulation, a Cherenkov detector has been implemented. The main elements of the detector are the following:
- Aerogel and Fused Silica radiatior
- World made with air
- proton beam
- Silicon PM detectors
This directory is not aimed to give a quantitative simulation of a particular instrument but only to have a template reusable for future projects. 
The detector, the geometry, and the Physics list can be modified by opening the .cc files and adding the desired features to teh project.


The main folder contains all the sources files. 

This is a **CMake** project. Therefore, a CMake file is required. In this case, the file is named **CMakeLists.txt**. The subdirectory **build/** is needed to compile the project.

---------------------------------------


## Build the project
To build the project go to the /build directory and run the command

```
cmake ..
```

Then, you can run the command

```
make
```

Then, an executable file will be created in the /build directory. To run the executable file, simply run the command
```
./Name_of_the_executable_file
```
The name of the executable file, in this case, is simply "simulation", which is exactly the name of the project.

--------------------------------------------

## Useful resources 
- Physics Matters Geant4 tutorial : [Link](https://www.youtube.com/playlist?list=PLLybgCU6QCGWgzNYOV0SKen9vqg4KXeVL)
- Geant4 page : [Link](https://geant4.web.cern.ch/)
- Geant4 User guide : [Link](https://geant4.web.cern.ch/support/user_documentation)
- ROOT Cern C++ : [Link](https://root.cern/)