# IMG2ASCII

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