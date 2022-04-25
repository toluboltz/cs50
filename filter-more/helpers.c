#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute the average of the RGB values for each pixel
            int rgb_average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = rgb_average;
            image[i][j].rgbtGreen = rgb_average;
            image[i][j].rgbtBlue = rgb_average;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, k = width - 1; j < width && k > 0; j++, k--)
        {
            // Starting from opposite ends, swap the RGB values
            if (k > j)
            {
                RGBTRIPLE temp = image[i][j];
                image[i][j] = image[i][k];
                image[i][k] = temp;
            }
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        int sum_red = 0;
        int sum_green = 0;
        int sum_blue = 0;

        int pixel_count = 0;

        for (int j = 0; j < width; j++)
        {
            // Initialize the indices of all pixels
            // within one row and column of the original pixel
            int top_left[] = {i - 1, j - 1};
            int top_middle[] = {i - 1, j};
            int top_right[] = {i - 1, j + 1};
            int middle_left[]= {i, j - 1};
            int middle_right[] = {i, j + 1};
            int bottom_left[] = {i + 1, j -1};
            int bottom_middle[] = {i + 1, j};
            int bottom_right[] = {i + 1, j + 1};

            if (top_left[0] >= 0 && top_left[1] >= 0)
            {
                sum_red += image[top_left[0]][top_left[1]].rgbtRed;
                sum_green += image[top_left[0]][top_left[1]].rgbtGreen;
                sum_blue += image[top_left[0]][top_left[1]].rgbtBlue;
                pixel_count += 1;

            }
            if (top_middle[0] >= 0)
            {
                sum_red += image[top_middle[0]][top_middle[1]].rgbtRed;
                sum_green += image[top_middle[0]][top_middle[1]].rgbtGreen;
                sum_blue += image[top_middle[0]][top_middle[1]].rgbtBlue;
                pixel_count += 1;
            }
            if (top_right[0] >= 0 && top_right[1] < width)
            {
                sum_red += image[top_right[0]][top_right[1]].rgbtRed;
                sum_green += image[top_right[0]][top_right[1]].rgbtGreen;
                sum_blue += image[top_right[0]][top_right[1]].rgbtBlue;
                pixel_count += 1;
            }
            if (middle_left[1] >= 0)
            {
                sum_red += image[middle_left[0]][middle_left[1]].rgbtRed;
                sum_green += image[middle_left[0]][middle_left[1]].rgbtGreen;
                sum_blue += image[middle_left[0]][middle_left[1]].rgbtBlue;
                pixel_count += 1;
            }
            if (middle_right[1] < width)
            {
                sum_red += image[middle_right[0]][middle_right[1]].rgbtRed;
                sum_green += image[middle_right[0]][middle_right[1]].rgbtGreen;
                sum_blue += image[middle_right[0]][middle_right[1]].rgbtBlue;
                pixel_count += 1;
            }
            if (bottom_left[0] < height && bottom_left[1] >= 0)
            {
                sum_red += image[bottom_left[0]][bottom_left[1]].rgbtRed;
                sum_green += image[bottom_left[0]][bottom_left[1]].rgbtGreen;
                sum_blue += image[bottom_left[0]][bottom_left[1]].rgbtBlue;
                pixel_count += 1;
            }
            if (bottom_middle[0] < height)
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
