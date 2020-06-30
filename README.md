# 42-fdf
#### Interpreting 3D coordinates with rotation on 3 axes to 2D output

## Installation

Clone the [repository](https://github.com/indy728/42-fdf.git) to your local filesystem. Navigate to the repository and build the executable:

```
make
```

Or without object files:

```
make && make clean
```

## Usage

```
./fdf [path_to_file]
```

## Motivation

The purpose of this project "fils de fer" or "wires" (wireframe) is an exercise in using C to visually represent a figure described in a text file.

By stage:
  - validate file formatting as correct per project specifications
  - interpret a properly-formatted text file to xyz integer-only coordinates
  - build functions in C to translate 3D coordinates at any given perspective into 2D, x-y coordinates that would represent the figure
  - develop an algorithm to connect the 2D coordinates to build a wireframe representation
  - use the MLX graphics library provided to output the wireframe pixel-by-pixel to an image file and then relay the image-size buffer to the screen
  
The binary should at least compile with Mac OS X versions Yosemite and later.

## The Project

An example of a valid text file to be interpreted would look like this:

![map42.fdf](/fdf_screenshots/screenshot_map42.png?raw=true "map42.fdf")

Where the column count from the left represents the x-coordinate, the row count from the top represents the y-coordinate, 
and the value of each integer represents the height, or z-coordinate. The initial output for this image will be rotated slightly on 3 axes to give a better 3D effect: 

![map42](/fdf_screenshots/map_42.png?raw=true "map 42")

To draw the lines, I adapted Bresenham's line-drawing algorithm for integers. My rotation algorithm uses two functions which implement rotation matrices for isometric projection, for which there are numerous resources online. All the information needed to complete this project can be found on the following wiki pages:
<br> • https://en.wikipedia.org/wiki/Rotation_matrix
<br> • https://en.wikipedia.org/wiki/Isometric_projection

## Project Bonuses
The meat of the project is fairly simple: a single perspective's projection to a window. However, once the rotation for a single perspective is achieved, it is a simple task to assign keys to adjust the rotation angles and reprint to screen. The goal I set for myself on this project was to be able to set any two colors to the highest- and lowest-most z-values and any point in between those two points would be assigned a color based on height proportional to the gradient between the two given colors. The algorithm I came up with takes the z-values at two points, determines their base RGB hex color based on proportion of total height, and steps each of the R, G, and B components in correlation with the steps of my adapted Bresenham algorithm. The final touch was to be able to maually adjust the peak and valley RGB values individually using the num-pad, so that any color pair can be achieved.

## Visualization:
### Screenshots:

![map420](/fdf_screenshots/map_42_rot0.png?raw=true "map 42_rot0")

![map421](/fdf_screenshots/map_42_rot1.png?raw=true "map 42_rot1")

![julia0](/fdf_screenshots/julia_rot0.png?raw=true "julia rot0")

![julia0z](/fdf_screenshots/julia_rot0_zoom1.png?raw=true "julia rot0 zoom")

![mandel](/fdf_screenshots/mandelbrot_full.png?raw=true "mandelbrot")

![mandelclose](/fdf_screenshots/mandelbrot_closeup.png?raw=true "mandel closeup")

### In Action:

#### Scale & Translate
<img src="/fdf_gifs/scale-translate.gif" alt="Scale & Translate" width="600">

#### Rotate XYZ
<img src="/fdf_gifs/rotate-xyz.gif" alt="Rotate XYZ" width="600">

#### Elevation Change
<img src="/fdf_gifs/elevation-change.gif" alt="Elevation Change" width="600">

#### Elevation Color
<img src="/fdf_gifs/elevation-color.gif" alt="Elevation Color" width="600">

#### Theme Color
<img src="/fdf_gifs/theme-color.gif" alt="Theme Color" width="600">

#### Julia Zoom
<img src="/fdf_gifs/julia-zoom.gif" alt="Julia Zoom" width="600">


## Project Improvements
The obvious improvements to implement for me would be to use hooks to catch keys being held down and released, mouse clicks, mouse location and mouse scroll wheel for ease and fluidity of user input. For smoothness, multithreading to separate processes and allow for the program to move at full video speed, even with files of hundreds of thousands of coordinates or more. Also, accepting multiple files as arguments to be opened concurrently in different windows, and user input to dictate window size and starting colors.
