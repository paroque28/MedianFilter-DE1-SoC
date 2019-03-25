#include "io.h"

png_props get_png_props(char *filename) {
  FILE *fp = fopen(filename, "rb");
  png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if(!png) abort();
  png_infop info = png_create_info_struct(png);
  if(!info) abort();
  if(setjmp(png_jmpbuf(png))) abort();
  png_init_io(png, fp);
  png_read_info(png, info);
  png_props input_image_props;
  input_image_props.width      = png_get_image_width(png, info);
  input_image_props.height     = png_get_image_height(png, info);
  input_image_props.color_type = png_get_color_type(png, info);
  input_image_props.bit_depth  = png_get_bit_depth(png, info);
  fclose(fp);
  return input_image_props;
}

png_bytep * read_png_file(char *filename) {
  png_bytep *row_pointers;
  FILE *fp = fopen(filename, "rb");

  png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if(!png) abort();

  png_infop info = png_create_info_struct(png);
  if(!info) abort();

  if(setjmp(png_jmpbuf(png))) abort();

  png_init_io(png, fp);

  png_read_info(png, info);

  png_props input_image_props;
  input_image_props.width      = png_get_image_width(png, info);
  input_image_props.height     = png_get_image_height(png, info);
  input_image_props.color_type = png_get_color_type(png, info);
  input_image_props.bit_depth  = png_get_bit_depth(png, info);

  if(input_image_props.bit_depth == 16)
    png_set_strip_16(png);

  if(input_image_props.color_type == PNG_COLOR_TYPE_PALETTE)
    png_set_palette_to_rgb(png);

  // PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth.
  if(input_image_props.color_type == PNG_COLOR_TYPE_GRAY && input_image_props.bit_depth < 8)
    png_set_expand_gray_1_2_4_to_8(png);

  if(png_get_valid(png, info, PNG_INFO_tRNS))
    png_set_tRNS_to_alpha(png);

  // These color_type don't have an alpha channel then fill it with 0xff.
  if(input_image_props.color_type == PNG_COLOR_TYPE_RGB ||
     input_image_props.color_type == PNG_COLOR_TYPE_GRAY ||
     input_image_props.color_type == PNG_COLOR_TYPE_PALETTE)
    png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

  if(input_image_props.color_type == PNG_COLOR_TYPE_GRAY ||
     input_image_props.color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
    png_set_gray_to_rgb(png);
  png_read_update_info(png, info);

  row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * input_image_props.height);
  for(int y = 0; y < input_image_props.height; y++) {
    row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png,info));
  }

  png_read_image(png, row_pointers);

  fclose(fp);
  return row_pointers;
}

void write_png_file(char *filename, PNGImage image ) {
  ImgSize props= image.size;
  png_bytep *row_pointers = image.Rows;
  int y;

  FILE *fp = fopen(filename, "wb");
  if(!fp) abort();

  png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!png) abort();

  png_infop info = png_create_info_struct(png);
  if (!info) abort();

  if (setjmp(png_jmpbuf(png))) abort();

  png_init_io(png, fp);

  // Output is 8bit depth, RGBA format.
  png_set_IHDR(
    png,
    info,
    props.width, props.height,
    8,
    PNG_COLOR_TYPE_RGBA,
    PNG_INTERLACE_NONE,
    PNG_COMPRESSION_TYPE_DEFAULT,
    PNG_FILTER_TYPE_DEFAULT
  );
  png_write_info(png, info);

  // To remove the alpha channel for PNG_COLOR_TYPE_RGB format,
  // Use png_set_filler().
  //png_set_filler(png, 0, PNG_FILLER_AFTER);

  png_write_image(png, row_pointers);
  png_write_end(png, NULL);

  for(int y = 0; y < props.height; y++) {
    free(row_pointers[y]);
  }
  free(row_pointers);

  fclose(fp);
}