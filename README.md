# IMG2ASCII
![build](https://github.com/EfesX/img2ascii/actions/workflows/build.yml/badge.svg)

The simple converter any image into ASCII art.

The background for working with images is the OpenCV library.

## BUILD

```bash
cmake -S . -B build
```

## INSTALL
```bash
cmake --install build
```

## USAGE
The program accepts the following parameters:

- `help` - to show the help message
- `size` - size (default = 100) of target art
- `inv`  - inverse (true) or not (false, default) source image

### Example usage

```bash
img2show --size=70 img.png
```
