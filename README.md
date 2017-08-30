# 42-fdf
Interpreting 3D coordinates with rotation on 3 axes to 2D output

The purpose of this project "fils de fer" or "wires" (wireframe) is an exercise in using C to visually represent a figure described in a text file.

By stage:
  <br>• validate file formatting as correct per project specifications
  <br>• interpret a properly-formatted text file to xyz integer-only coordinates
  <br>• build functions in C to translate 3D coordinates at any given perspective into 2D, x-y coordinates that would represent the figure
  <br>• develop an algorithm to connect the 2D coordinates to build a wireframe representation
  <br>• use the MLX graphics library provided to output the wireframe pixel-by-pixel to an image file and then relay the image-size buffer to the screen
  
The binary should at least compile with Mac OS X versions Yosemite and later.

## The Project

An example of a valid text file to be interpreted would look like this:
![map42.fdf](/fdf_screenshots/screenshot_map42.png?raw=true "map42.fdf")


Where the column count from the left represents the x-coordinate, the row count from the top represents the y-coordinate, 
and the value of each integer represents the height, or z-coordinate. The initial output for this image will be rotated slightly on 3 axes to give a better 3D effect: 

![map42](/fdf_screenshots/map42.png?raw=true "map42.fdf")
