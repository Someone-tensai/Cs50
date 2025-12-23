#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average[i][j] = (round) (image[i][j].rgbtRed / 3.0 + image[i][j].rgbtBlue / 3.0 + image[i][j].rgbtGreen / 3.0);
            image[i][j].rgbtRed = average[i][j];
            image[i][j].rgbtGreen = average[i][j];
            image[i][j].rgbtBlue = average[i][j];
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed[height][width], sepiaGreen[height][width], sepiaBlue[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed[i][j] =
                (round) ((.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue));
            sepiaGreen[i][j] =
                (round) ((.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue));
            sepiaBlue[i][j] =
                (round) ((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue));
            if (sepiaRed[i][j] > 255)
            {
                sepiaRed[i][j] = 255;
            }
            if (sepiaBlue[i][j] > 255)
            {
                sepiaBlue[i][j] = 255;
            }
            if (sepiaGreen[i][j] > 255)
            {
                sepiaGreen[i][j] = 255;
            }
            image[i][j].rgbtRed = sepiaRed[i][j];
            image[i][j].rgbtGreen = sepiaGreen[i][j];
            image[i][j].rgbtBlue = sepiaBlue[i][j];
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE t, copy[height][width];
    int end;
    for (int i = 0; i < height; i++)
    {
        int half = (round) (width / 2);
        for (int j = 0; j < half; j++)
        {
            t = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = t;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

     RGBTRIPLE copy[height][width];
    float avgR, avgG, avgB, counter;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            avgR = 0;
            avgG = 0;
            avgB = 0;
            counter = 0; // for checking how many are valid
            // Find valid pixels in a 3x3 grid around the current copy[i][j]
            // current_pix = copy[row][col]
            // Different cases for different areas

            // sub matrix 3x3
            for (int a = -1; a < 2; a++)
                {
                    for (int b = -1; b < 2; b++)
                    {
                        // Any corner top left || top right || botton left || bottom right
                        if ((row + a < 0 && col + b < 0) || (row + a < 0 && col + b > width) || (row + a > height && col + b < 0) || (row + a > height && col + b > width))
                        {
                            avgR += copy[row][col].rgbtRed;
                            avgG += copy[row][col].rgbtGreen;
                            avgB += copy[row][col].rgbtBlue;
                            counter ++;
                        }
                        // Not corner vertical edge ==> col + b < 0 (left) or col + b > width ()
                        else if (col + b < 0 || col + b > width){
                            avgR += copy[row + a][col].rgbtRed;
                            avgG += copy[row + a][col].rgbtGreen;
                            avgB += copy[row + a][col].rgbtBlue;
                            counter ++;
                        }
                        // Not corner horizontal edge ==> row + a < 0 (top) or row + a > height ()
                        else if (col + b < 0 || col + b > width){
                            avgR += copy[row][col+b].rgbtRed;
                            avgG += copy[row][col+b].rgbtGreen;
                            avgB += copy[row][col+b].rgbtBlue;
                            counter ++;
                        }
                        // Not corner or edge
                        else
                        {
                            avgR += copy[row + a][col + b].rgbtRed;
                            avgG += copy[row + a][col + b].rgbtGreen;
                            avgB += copy[row + a][col + b].rgbtBlue;
                            counter ++;
                        }
                    }
                }
            image[row][col].rgbtRed = round(avgR / counter);
            image[row][col].rgbtBlue = round(avgB / counter);
            image[row][col].rgbtGreen = round(avgG / counter);
        }

    }

    return;

}
