# Build instructions

## Linux 

1. Ensure you have the necessary libraries:

### Fedora/RedHat Distributions 

```
sudo dnf install glfw glfw-devel
```

### Ubuntu/Debian Distributions 

```
sudo apt-get install libglfw3 libglfw3-dev
```

2. Change to `build` directory:
```
cd build
```

3. Run `cmake ..` and if everything went well then run `make`:
```
cmake ..
make
```
4. To get rid of CMake cache, Makefiles and other misc. stuff in the `build` directory, simply run:
```
git clean -d -f -x 
```

5. You should now have just the `engine` executable.

## Windows 
Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.

## Mac 
Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.