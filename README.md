# Build instructions
## Platform support
Windows and Linux(Debian and RedHat) for now, Mac/iOS/Android for later.

## Start

Ensure you have the necessary libraries. Required dependencies :
- Clang: https://releases.llvm.org/download.html
- Vulkan SDK: https://vulkan.lunarg.com/
    
Recommended text editor :
- VS Code: https://code.visualstudio.com/

Then depending on the OS, run the following commands
### Fedora/RedHat Distributions 

```
sudo dnf install glfw glfw-devel
```

### Ubuntu/Debian Distributions 

```
sudo apt-get install libglfw3 libglfw3-dev
```

### Windows

Follow the instructions on : 

    https://vulkan.lunarg.com/doc/sdk/1.3.236.0/windows/getting_started.html

to install the Vulkan SDK. 

### Build Tiger Engine

Clone the repo.

```
git clone https://github.com/CarlMariaMikage/TigerEngine.git
cd TigerEngine/
```

Open the folder in VS Code then press ```Ctrl+Shift+B``` to build.

The ```.exe```, ```.dll``` and ```.lib``` files will be in the ```/bin``` folder.