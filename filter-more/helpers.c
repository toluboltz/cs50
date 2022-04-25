#include "helpers.h"
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
    // Make a copy of the image
    RGBTRIPLE image_copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_copy[i][j] = image[i][j];
        }
    }
    // Blur the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize the indices of all pixels
            // within one row and column of the original pixel
            int top_left[] = {i - 1, j - 1};
            int top_middle[] = {i - 1, j};
            int top_right[] = {i - 1, j + 1};
            int middle_left[]= {i, j - 1};
            int middle_right[] = {i, j + 1};
            int bottom_left[] = {i + 1, j - 1};
            int bottom_middle[] = {i + 1, j};
            int bottom_right[] = {i + 1, j + 1};

            // Initialize sum for each color and pixel count
            // middle-pixel
            int sum_red = image_copy[i][j].rgbtRed;
            int sum_green = image_copy[i][j].rgbtGreen;
            int sum_blue = image_copy[i][j].rgbtBlue;
            int pixel_count = 1;
            // top-left
            if (top_left[0] >= 0 && top_left[1] >= 0)
            {
                sum_red += image_copy[top_left[0]][top_left[1]].rgbtRed;
                sum_green += image_copy[top_left[0]][top_left[1]].rgbtGreen;
                sum_blue += image_copy[top_left[0]][top_left[1]].rgbtBlue;
                pixel_count += 1;

            }
            // top-middle
            if (top_middle[0] >= 0)
            {
                sum_red += image_copy[top_middle[0]][top_middle[1]].rgbtRed;
                sum_green += image_copy[top_middle[0]][top_middle[1]].rgbtGreen;
                sum_blue += image_copy[top_middle[0]][top_middle[1]].rgbtBlue;
                pixel_count += 1;
            }
            // top-right
            if (top_right[0] >= 0 && top_right[1] < width)
            {
                sum_red += image_copy[top_right[0]][top_right[1]].rgbtRed;
                sum_green += image_copy[top_right[0]][top_right[1]].rgbtGreen;
                sum_blue += image_copy[top_right[0]][top_right[1]].rgbtBlue;
                pixel_count += 1;
            }
            // middle-left
            if (middle_left[1] >= 0)
            {
                sum_red += image_copy[middle_left[0]][middle_left[1]].rgbtRed;
                sum_green += image_copy[middle_left[0]][middle_left[1]].rgbtGreen;
                sum_blue += image_copy[middle_left[0]][middle_left[1]].rgbtBlue;
                pixel_count += 1;
            }
            // middle-right
            if (middle_right[1] < width)
            {
                sum_red += image_copy[middle_right[0]][middle_right[1]].rgbtRed;
                sum_green += image_copy[middle_right[0]][middle_right[1]].rgbtGreen;
                sum_blue += image_copy[middle_right[0]][middle_right[1]].rgbtBlue;
                pixel_count += 1;
            }
            // bottom-left
            if (bottom_left[0] < height && bottom_left[1] >= 0)
            {
                sum_red += image_copy[bottom_left[0]][bottom_left[1]].rgbtRed;
                sum_green += image_copy[bottom_left[0]][bottom_left[1]].rgbtGreen;
                sum_blue += image_copy[bottom_left[0]][bottom_left[1]].rgbtBlue;
                pixel_count += 1;
            }
            // bottom-middle
            if (bottom_middle[0] < height)
            {
                sum_red += image_copy[bottom_middle[0]][bottom_middle[1]].rgbtRed;
                sum_green += image_copy[bottom_middle[0]][bottom_middle[1]].rgbtGreen;
                sum_blue += image_copy[bottom_middle[0]][bottom_middle[1]].rgbtBlue;
                pixel_count += 1;
            }
            // bottom-right
            if (bottom_right[0] < height && bottom_right[1] < width)
            {
                sum_red += image_copy[bottom_right[0]][bottom_right[1]].rgbtRed;
                sum_green += image_copy[bottom_right[0]][bottom_right[1]].rgbtGreen;
                sum_blue += image_copy[bottom_right[0]][bottom_right[1]].rgbtBlue;
                pixel_count += 1;
            }
            // compute average for each color
            image[i][j].rgbtRed = round(sum_red * 1.0 / pixel_count);
            image[i][j].rgbtGreen = round(sum_green * 1.0 / pixel_count);
            image[i][j].rgbtBlue = round(sum_blue * 1.0 / pixel_count);
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Make a copy of the image
    RGBTRIPLE image_copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_copy[i][j] = image[i][j];
        }
    }
    // Edge detection
    for (int i = 0; i < height; i++)
    {
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

            // Compute Gx and Gy for RGB channels
            // middle-pixel
            double gx_red = 0.0;
            double gx_green = 0.0;
            double gx_blue = 0.0;

            double gy_red = 0.0;
            double gy_green = 0.0;
            double gy_blue = 0.0;
            // top-left
            if (top_left[0] >= 0 && top_left[1] >= 0)
            {
                gx_red += -1.0 * image_copy[top_left[0]][top_left[1]].rgbtRed;
                gx_green += -1.0 * image_copy[top_left[0]][top_left[1]].rgbtGreen;
                gx_blue += -1.0 * image_copy[top_left[0]][top_left[1]].rgbtBlue;

                gy_red += -1.0 * image_copy[top_left[0]][top_left[1]].rgbtRed;
                gy_green += -1.0 * image_copy[top_left[0]][top_left[1]].rgbtGreen;
                gy_blue += -1.0 * image_copy[top_left[0]][top_left[1]].rgbtBlue;
            }
            // top-middle
            if (top_middle[0] >= 0)
            {
                gy_red += -2.0 * image_copy[top_middle[0]][top_middle[1]].rgbtRed;
                gy_green += -2.0 * image_copy[top_middle[0]][top_middle[1]].rgbtGreen;
                gy_blue += -2.0 * image_copy[top_middle[0]][top_middle[1]].rgbtBlue;
            }
            // top-right
            if (top_right[0] >= 0 && top_right[1] < width)
            {
                gx_red += 1.0 * image_copy[top_right[0]][top_right[1]].rgbtRed;
                gx_green += 1.0 * image_copy[top_right[0]][top_right[1]].rgbtGreen;
                gx_blue += 1.0 * image_copy[top_right[0]][top_right[1]].rgbtBlue;

                gy_red += -1.0 * image_copy[top_right[0]][top_right[1]].rgbtRed;
                gy_green += -1.0 * image_copy[top_right[0]][top_right[1]].rgbtGreen;
                gy_blue += -1.0 * image_copy[top_right[0]][top_right[1]].rgbtBlue;
            }
            // middle-left
            if (middle_left[1] >= 0)
            {
                gx_red += -2.0 * image_copy[middle_left[0]][middle_left[1]].rgbtRed;
                gx_green += -2.0 * image_copy[middle_left[0]][middle_left[1]].rgbtGreen;
                gx_blue += -2.0 * image_copy[middle_left[0]][middle_left[1]].rgbtBlue;
            }
            // middle-right
            if (middle_right[1] < width)
            {
                gx_red += 2.0 * image_copy[middle_right[0]][middle_right[1]].rgbtRed;
                gx_green += 2.0 * image_copy[middle_right[0]][middle_right[1]].rgbtGreen;
                gx_blue += 2.0 * image_copy[middle_right[0]][middle_right[1]].rgbtBlue;
            }
            // bottom-left
            if (bottom_left[0] < height && bottom_left[1] >= 0)
            {
                gx_red += -1.0 * image_copy[bottom_left[0]][bottom_left[1]].rgbtRed;
                gx_green += -1.0 * image_copy[bottom_left[0]][bottom_left[1]].rgbtGreen;
                gx_blue += -1.0 * image_copy[bottom_left[0]][bottom_left[1]].rgbtBlue;

                gy_red += 1.0 * image_copy[bottom_left[0]][bottom_left[1]].rgbtRed;
                gy_green += 1.0 * image_copy[bottom_left[0]][bottom_left[1]].rgbtGreen;
                gy_blue += 1.0 * image_copy[bottom_left[0]][bottom_left[1]].rgbtBlue;
            }
            // bottom-middle
            if (bottom_middle[0] < height)
            {
                gy_red += 2.0 * image_copy[bottom_middle[0]][bottom_middle[1]].rgbtRed;
                gy_green += 2.0 * image_copy[bottom_middle[0]][bottom_middle[1]].rgbtGreen;
                gy_blue += 2.0 * image_copy[bottom_middle[0]][bottom_middle[1]].rgbtBlue;
            }
            // bottom-right
            if (bottom_right[0] < height && bottom_right[1] < width)
            {
                gx_red += 1.0 * image_copy[bottom_right[0]][bottom_right[1]].rgbtRed;
                gx_green += 1.0 * image_copy[bottom_right[0]][bottom_right[1]].rgbtGreen;
                gx_blue += 1.0 * image_copy[bottom_right[0]][bottom_right[1]].rgbtBlue;

                gy_red += 1.0 * image_copy[bottom_right[0]][bottom_right[1]].rgbtRed;
                gy_green += 1.0 * image_copy[bottom_right[0]][bottom_right[1]].rgbtGreen;
                gy_blue += 1.0 * image_copy[bottom_right[0]][bottom_right[1]].rgbtBlue;
            }
            // Compute sqrt(Gx^2 + Gy^2)
            int sobel_red = round(sqrt(pow(gx_red, 2) + pow(gy_red, 2)));
            int sobel_green = round(sqrt(pow(gx_green, 2) + pow(gy_green, 2)));
            int sobel_blue = round(sqrt(pow(gx_blue, 2) + pow(gy_blue, 2)));
            // Assign the value back to original pixel, cap at 255
            image[i][j].rgbtRed = sobel_red > 255 ? 255 : sobel_red;
            image[i][j].rgbtGreen = sobel_green > 255 ? 255 : sobel_green;
            image[i][j].rgbtBlue = sobel_blue > 255 ? 255 : sobel_blue;
        }
    }
}
