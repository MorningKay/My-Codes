#include "helpers.h"
#include <math.h>

int clamp(int value);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE red = image[i][j].rgbtRed;
            BYTE green = image[i][j].rgbtGreen;
            BYTE blue = image[i][j].rgbtBlue;
            BYTE average = (red + green + blue + 1.5) / 3;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            BYTE temp_red = image[i][j].rgbtRed;
            BYTE temp_green = image[i][j].rgbtGreen;
            BYTE temp_blue = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtRed = temp_red;
            image[i][width - j - 1].rgbtGreen = temp_green;
            image[i][width - j - 1].rgbtBlue = temp_blue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blur_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum_red = 0, sum_green = 0, sum_blue = 0;
            int count = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        sum_red += image[ni][nj].rgbtRed;
                        sum_green += image[ni][nj].rgbtGreen;
                        sum_blue += image[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }
            blur_image[i][j].rgbtRed = clamp((int) (sum_red + count * 0.5) / count);
            blur_image[i][j].rgbtGreen = clamp((int) (sum_green + count * 0.5) / count);
            blur_image[i][j].rgbtBlue = clamp((int) (sum_blue + count * 0.5) / count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = blur_image[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE edges_image[height][width];
    int gx_weight[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy_weight[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gx_sum_red = 0, gx_sum_green = 0, gx_sum_blue = 0;
            int gy_sum_red = 0, gy_sum_green = 0, gy_sum_blue = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;
                    int wi = di + 1;
                    int wj = dj + 1;

                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        gx_sum_red += gx_weight[wi][wj] * image[ni][nj].rgbtRed;
                        gx_sum_green += gx_weight[wi][wj] * image[ni][nj].rgbtGreen;
                        gx_sum_blue += gx_weight[wi][wj] * image[ni][nj].rgbtBlue;
                        gy_sum_red += gy_weight[wi][wj] * image[ni][nj].rgbtRed;
                        gy_sum_green += gy_weight[wi][wj] * image[ni][nj].rgbtGreen;
                        gy_sum_blue += gy_weight[wi][wj] * image[ni][nj].rgbtBlue;
                    }
                }
            }

            edges_image[i][j].rgbtRed =
                clamp(round(sqrt(gx_sum_red * gx_sum_red + gy_sum_red * gy_sum_red)));
            edges_image[i][j].rgbtGreen =
                clamp(round(sqrt(gx_sum_green * gx_sum_green + gy_sum_green * gy_sum_green)));
            edges_image[i][j].rgbtBlue =
                clamp(round(sqrt(gx_sum_blue * gx_sum_blue + gy_sum_blue * gy_sum_blue)));
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = edges_image[i][j];
        }
    }
    return;
}

int clamp(int value)
{
    if (value > 255)
    {
        return 255;
    }
    if (value < 0)
    {
        return 0;
    }
    return value;
}
