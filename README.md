# 42-fdf
fdf is a 42-school project to make a tool that visualises a 3D wireframe model from a given heightmap.

# Features
fdf is a very straightforward tool that takes a file as an input and displays the model in a window. It also features a collection of test_maps to try out.
- Parse and read a file containing a grid of points with their given height values.
- Render a 3D wireframe model based on the input data.
- Translation, rotation and zoom controls for the model.

# How to use
## Build
To run fdf you need to build the executable.\
Building is done by simply running make in the root directory:
```bash
git clone https://github.com/lyaneii/42-fdf.git fdf
cd fdf
make
```
## Run
To start the tool you simply run the program with a map as the second argument:
```bash
./fdf test_maps/10-2.fdf
```

# File format
The input file should only contain integers separated by spaces. \
Each line in the file represents a row of points and each integer represents the height at that point.

Example:
```
0 0 0 0 0
0 1 1 1 0
0 1 2 1 0
0 1 1 1 0
0 0 0 0 0
```

# Controls
**Translating the model:**\
`W` - Move model up\
`A` - Move model left\
`S` - Move model down\
`D` - Move model right

**Rotating the model:**\
`↑` - Rotate model up\
`←` - Rotate model left\
`↓` - Rotate model down\
`→` - Rotate model right

**Zooming in and out:**\
`🖱️↑` - Zoom in\
`🖱️↓` - Zoom out

**Perspective controls:**\
`1` - Isometric View\
`2` - Perspective View\
`3` - Top-down View

**Other Controls:**\
`Esc` - Close window\
`R` - Reset transformations
