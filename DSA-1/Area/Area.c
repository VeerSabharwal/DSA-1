#include <stdio.h>
#include <math.h>
float rectangleArea(float length, float width)
{
    return length * width;
}

float triangleArea(float base, float height)
{
    return 0.5 * base * height;
}

float circleArea(float radius)
{
    return M_PI * radius * radius;
}

int main()
{
    int choice;
    float result, side1, side2, base, height, radius;
    FILE *outputFile;
    printf("Select a shape to calculate its area:\n");
    printf("1. Rectangle\n");
    printf("2. Triangle\n");
    printf("3. Circle\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            printf("Enter the length and width of the rectangle: ");
            scanf("%f %f", &side1, &side2);
            result = rectangleArea(side1, side2);
            break;

        case 2:
            printf("Enter the base and height of the triangle: ");
            scanf("%f %f", &base, &height);
            result = triangleArea(base, height);
            break;

        case 3:
            printf("Enter the radius of the circle: ");
            scanf("%f", &radius);
            result = circleArea(radius);
            break;

        default:
            printf("Invalid choice!\n");
            return 1;
    }

    outputFile = fopen("areaoutput.txt", "w");
    if (outputFile == NULL)
    {
        printf("Error: Unable to open area_output.txt for writing.\n");
        return 1;
    }
    fprintf(outputFile, "Area = %.2f\n", result);
    fclose(outputFile);

    return 0;
}

