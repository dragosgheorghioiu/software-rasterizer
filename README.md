# Software Rasterizer Demo
## Description
Simple software rasterizer developed in C using Raylib
It is based on the triangle rasterizer found [here](https://github.com/gustavopezzi/triangle-rasterizer-float.git).

It implements:
- top left rasterization rule
- barycentric coordinates for interpolating colors
- edge function per-pixel optimization
- subpixel coordinates

## Build and run
Install raylib and run:
```bash
# build
make
# run
./rasterizer <scale>
```
## Controls
```
SPACE   - toggle rotation
1, 2, 3 - toggle the triangles
```

