# My first project in Geant4

--------------------------------------------------

This is my Geant4 template project.
This project is already working. However, it will simulate only a proton beam moving through air.
The detector, the geometry, and the Physics list can be modified by opening the .cc files and adding the desired features to teh project.

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