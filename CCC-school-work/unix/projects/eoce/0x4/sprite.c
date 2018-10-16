/*
 * sprite.c   - code to use the GD graphics library to create
 *              an image
 *
 * To compile:  gcc -o sprite sprite.c -lgd
 * To execute:  ./sprite /valid/path/to/image_to_create.png
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gd.h>

#define WIDTH		800
#define HEIGHT		600

// color values
//
#define BLACK       0
#define GRAY        1
#define VIOLET      2
#define INDIGO      3
#define BLUE        4
#define GREEN       5
#define YELLOW      6
#define ORANGE      7
#define RED         8
#define WHITE       9
#define DARKGREEN   10

int main(int argc, char **argv)
{
    char				*outfile;		// name out of the output file
    FILE				*in, *out;		// file pointers
    gdImagePtr			img;			// GD Image Construct
    unsigned int		color[11];		// color array
	unsigned int		sprite[16][16]; // sprite array
    unsigned short int	wide, high;		// image attributes
	int                 i, j, k;		// loop variables
	int                 x, y;			// coordinates
	float radian;						// radians

	// image dimensions (adjust and recompile as needed)
	//
    wide = WIDTH;
    high = HEIGHT;

	if (argc == 2)
	{
		outfile = *(argv+1);
		fprintf(stdout, "Using '%s' as output filename\n", outfile);
	}
	else
	{
		fprintf(stderr, "Error! Must specify output filename!\n");
		exit(1);
	}

	// Create new image of specified wide-ness and high-ness
	//
    img = gdImageCreateTrueColor(wide, high);

    // My GD color definitions
    //
    color[BLACK]     = gdImageColorAllocate(img, 0x00, 0x00, 0x00);  
    color[BLUE]      = gdImageColorAllocate(img, 0x00, 0x00, 0xFF);  
    color[GREEN]     = gdImageColorAllocate(img, 0x00, 0xFF, 0x00);  
    color[DARKGREEN] = gdImageColorAllocate(img, 0x33, 0x6B, 0x00);  
    color[RED]       = gdImageColorAllocate(img, 0xFF, 0x00, 0x00);  
    color[GRAY]      = gdImageColorAllocate(img, 0xCC, 0xCC, 0xCC);  
    color[WHITE]     = gdImageColorAllocate(img, 0xFF, 0xFF, 0xFF);

	if ((in = fopen("sprite.dat", "r")) == NULL)
	{
		fprintf(stderr, "Error opening 'sprite.dat'\n");
		exit(1);
	}

	// Paint the background black
	//
	gdImageFilledRectangle(img, 0, 0, wide, high, color[BLACK]);

	for(x=0; x<16; x++)
	{
		for(y=0; y<16; y++)
		{
			sprite[y][x] = fgetc(in) - 48;
		}
		fgetc(in);
	}

	for(y=0; y<16; y++)
	{
		for(x=0; x<16; x++)
		{
			i = (x * (wide / 16));
			j = (y * (high / 16));
			gdImageFilledRectangle(img, i, j, (i+(wide/16)-2), (j+(high/16)-2), color[(sprite[x][y])]);
		}
	}

    // Output the data
    //
    if((out = fopen(outfile, "wb")) == NULL)
	{
		fprintf(stderr, "Error opening '%s'\n", outfile);
		exit(1);
	}

	// Send image to file
	//
    gdImagePngEx(img, out, -1);

    // Close things up
    //
    fclose(out);
    gdImageDestroy(img);

    return(0);
}
