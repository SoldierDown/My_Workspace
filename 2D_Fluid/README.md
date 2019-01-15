## Git submodule
```
git clone --recursive XXXXX.git 
```

OR do this after an original git clone

```
git submodule update --init --recursive
```

## RUN
```
mkdir build
cd build
ccmake ..
make -j8

ln -s ../7.3.camera.vs ./
ln -s ../7.3.camera.fs ./
```

## Current Process
* A HelloWorld ImGui on Haozhe's cut hole result

## Things need to be done
Try to see Repo->Boards (menu on hte left hand side of the repo). Since I did not test it yet, I'm not sure can you guys see those cards

* Split up Data & Drawing into different files
* Make Gui interactive (Input data from Gui rather than command line)
* Modify the Orbit control and Mouse Control module (refer to Nova)
* Fix the CMakeLists's imgui bug (see below)

## Bugs need to be fixed
1. I make a folder called 'externals' to reference git submodules for imgui. But the CMakeLists.txt not working as I expected.
[Refer](https://github.com/mit-gfx/opengl_viewer)
Currently I commented `#add_subdirectory(externals)` in the `./CMakeLists.txt` and use 

```
### imgui
include_directories(./externals/imgui)
include_directories(./externals/imgui/examples)

add_library(imgui ./externals/imgui/imgui.cpp ./externals/imgui/imgui_demo.cpp ./externals/imgui/imgui_draw.cpp ./externals/imgui/imgui_widgets.cpp ./externals/imgui/examples/imgui_impl_glfw.cpp ./externals/imgui/examples/imgui_impl_opengl3.cpp)
```

for external imgui library instead.

In fact the `./externals/CMakeLists.txt` should do this things but it not works.


---

## Basic Git Branch Usage

[3.2 Git Branching - Basic Branching and Merging](https://git-scm.com/book/en/v2/Git-Branching-Basic-Branching-and-Merging)

* Create new branch
```
git checkout -b [new_branch_name]
```

and then you can do normal `add` and `commit`

* Push files to a specific branch
```
git push origin [branch_name]
```

**Most of the operations can be done via website**