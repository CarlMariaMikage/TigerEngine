---
page_type: sample
languages:
- cpp
products:
- windows
- windows-uwp
name: Leviathan
urlFragment: leviathan
description: This sample demonstrates the use of asynchronous compute shaders (multi-engine) to simulate an n-body gravity system.
extendedZipContent:
- path: LICENSE
  target: LICENSE
---

# Leviathan

![Sample](src/D3D12nBodyGravity.png)

A 3D game engine in C++ that utilises the DirectX 12 Graphics API.

## Build instructions

### Platform support

Windows only.

### Dependencies

Ensure you have the Visual Studio IDE with Windows SDK installed. 
- Visual Studio: <https://visualstudio.microsoft.com/>

### Build Leviathan

Clone the repo.

```bash
git clone https://github.com/Mistral1729/Leviathan.git
cd Leviathan/
```
Open the Visual Studio solution then build.

The ```.exe```, ```.dll``` and ```.lib``` files will be in the ```/bin``` folder.
