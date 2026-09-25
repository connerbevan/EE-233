/*
 * File: P3.c
 * Copy: Copyright (c) 2026 Conner Bevan
 * BlazerID: cdbevan
 * Vers: 1.0.0 09/20/2026 GCM - Original Coding
 * Desc: Driver for testing concepts
 */

/* Preprocessor */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Function Prototypes */
int circle_3D_v2(double radius, double length);
int annulus_3D_v2(double radius_outer, double radius_inner, double length);
int rectangle_filled_3D_v2(double base, double height, double length);
int rectangle_hollow_3D_v2(double base_outer, double height_outer, double base_inner, double height_inner, double length);
void help(void);

int main(int argc, char *argv[])
{
    printf("argc = %d\n", argc);

    int index;
    int results;

    double radius;
    double length;
    double radius_outer;
    double radius_inner;
    double base;
    double height;
    double base_outer;
    double height_outer;
    double base_inner;
    double height_inner;

    results = EXIT_FAILURE;

    for (index = 0; index < argc; index++)
    {
        printf("argv[%d] = %s\n", index, argv[index]);
    }

    if ((argc == 3) && (strcmpi(argv[1], "/circle") == 0) && (strcmpi(argv[2], "/i") == 0))
    {

        printf("Calling circle interactively: \n");

        printf("Please enter radius: \n");
        scanf("%lf", &radius);
        printf("Please enter length: \n");
        scanf("%lf", &length);
        results = circle_3D_v2(radius, length);

        printf("Results: %d\n", results);
    }
    else if ((argc == 5) && (strcmpi(argv[1], "/circle") == 0) && (strcmpi(argv[2], "/p") == 0))
    {

        printf("Calling Circle parametrically: \n");

        radius = atof(argv[3]);
        length = atof(argv[4]);

        results = circle_3D_v2(radius, length);
        printf("Results: %d\n", results);
    }
    else if ((argc == 3) && (strcmpi(argv[1], "/annulus") == 0) && (strcmpi(argv[2], "/i") == 0))
    {

        printf("Calling circle interactively: \n");

        printf("Please enter outer radius: \n");
        scanf("%lf", &radius_outer);
        printf("Please enter inner radius: \n");
        scanf("%lf", &radius_inner);
        printf("Please enter length: \n");
        scanf("%lf", &length);

        results = annulus_3D_v2(radius_outer, radius_inner, length);
        printf("Results: %d\n", results);
    }
    else if ((argc == 6) && (strcmpi(argv[1], "/annulus") == 0) && (strcmpi(argv[2], "/p") == 0))
    {

        printf("Calling Circle parametrically: \n");

        radius_outer = atof(argv[3]);
        radius_inner = atof(argv[4]);
        length = atof(argv[5]);

        results = annulus_3D_v2(radius_outer, radius_inner, length);
        printf("Results: %d\n", results);
    }
    else if ((argc == 3) && (strcmpi(argv[1], "/rectangle_filled") == 0) && (strcmpi(argv[2], "/i") == 0))
    {

        printf("Calling circle interactively: \n");

        printf("Please enter base: \n");
        scanf("%lf", &base);
        printf("Please enter height: \n");
        scanf("%lf", &height);
        printf("Please enter length: \n");
        scanf("%lf", &length);

        results = rectangle_filled_3D_v2(base, height, length);
        printf("Results: %d\n", results);
    }
    else if ((argc == 6) && (strcmpi(argv[1], "/rectangle_filled") == 0) && (strcmpi(argv[2], "/p") == 0))
    {

        printf("Calling Circle parametrically: \n");

        base = atof(argv[3]);
        height = atof(argv[4]);
        length = atof(argv[5]);

        results = rectangle_filled_3D_v2(base, height, length);
        printf("Results: %d\n", results);
    }
    else if ((argc == 3) && (strcmpi(argv[1], "/rectangle_hollow") == 0) && (strcmpi(argv[2], "/i") == 0))
    {

        printf("Calling circle interactively: \n");

        printf("Please enter outer base: \n");
        scanf("%lf", &base_outer);
        printf("Please enter outer height: \n");
        scanf("%lf", &height_outer);
        printf("Please enter inner base: \n");
        scanf("%lf", &base_inner);
        printf("Please enter inner height: \n");
        scanf("%lf", &height_inner);
        printf("Please enter length: \n");
        scanf("%lf", &length);

        results = rectangle_hollow_3D_v2(base_outer, height_outer, base_inner, height_inner, length);
        printf("Results: %d\n", results);
    }
    else if ((argc == 8) && (strcmpi(argv[1], "/rectangle_hollow") == 0) && (strcmpi(argv[2], "/p") == 0))
    {

        printf("Calling Circle parametrically: \n");

        base_outer = atof(argv[3]);
        height_outer = atof(argv[4]);
        base_inner = atof(argv[5]);
        height_inner = atof(argv[6]);
        length = atof(argv[7]);

        results = rectangle_hollow_3D_v2(base_outer, height_outer, base_inner, height_inner, length);
        printf("Results: %d\n", results);
    }

    else if ((argc == 2) && (strcmpi(argv[1], "/h") == 0))
    {
        printf("Printing help...\n");
        help();
    }
    else
    {
        printf("Printing help...\n");
        help();
    }

    return EXIT_SUCCESS;
}

/*
 * Name: circle_3D_v2
 * Desc: Called function for the circle to do calculations and output
 * Args: edge_face, area_face, area_outer, area_inner, volume, radius, length
 */
int circle_3D_v2(double radius, double length)
{

    printf("circle_3D_v2:\n");

    double edge_face;
    double area_face;
    double area_outer;
    double area_inner;
    double volume;
    int results;

    edge_face = 0.0;
    area_face = 0.0;
    area_outer = 0.0;
    area_inner = 0.0;
    volume = 0.0;

    results = EXIT_FAILURE;

    if (radius < 0.0)
    {
        printf("Error: Invalid Radius:\n");
    }
    else if (length < 0.0)
    {
        printf("Error: Invalid Length\n");
    }
    else
    {
        edge_face = 2 * (2 * M_PI * radius);
        area_face = 2 * (M_PI * pow(radius, 2.0));
        area_outer = (2 * M_PI * radius) * length;
        area_inner = 0.0;
        volume = (M_PI * pow(radius, 2.0)) * length;

        printf("Name                    Value \n");
        printf("========================================\n");
        printf("radius (in):              %.4f\n", radius);
        printf("length (in):              %.4f\n", length);
        printf("edge_face(in):            %.4f\n", edge_face);
        printf("area_face(in^2):          %.4f\n", area_face);
        printf("area_outer(in^2):         %.4f\n", area_outer);
        printf("area_inner(in^2):         %.4f\n", area_inner);
        printf("volume (in^3):            %.4f\n", volume);
        printf("========================================\n");

        results = EXIT_SUCCESS;
    }

    return (results);
}

/*
 * Name: annulus_3D_v2
 * Desc: Desc: Called function for the annulus to do calculations and output
 * Args: edge_face, area_face, area_outer, area_inner, volume, radius_outer, radius_inner, length
 */
int annulus_3D_v2(double radius_outer, double radius_inner, double length)
{

    printf("annulus_3D_v2:\n");

    double edge_face;
    double area_face;
    double area_outer;
    double area_inner;
    double volume;
    int results;

    edge_face = 0.0;
    area_face = 0.0;
    area_outer = 0.0;
    area_inner = 0.0;
    volume = 0.0;
    results = EXIT_FAILURE;

    if (radius_outer < 0.0)
    {
        printf("Error: Invalid radius_outer\n");
    }
    else if (radius_inner < 0)
    {
        printf("Error: Invalid radius_inner\n");
    }
    else if (length < 0)
    {
        printf("Error: Invalid Length\n");
    }
    else if (radius_inner > radius_outer)
    {
        printf("Error: radius_outer must be larger than radius_inner\n");
    }
    else
    {
        // calculations
        edge_face = (4 * M_PI) * (radius_inner + radius_outer);
        area_face = 2 * M_PI * (pow(radius_outer, 2) - pow(radius_inner, 2));
        area_outer = 2 * M_PI * radius_outer * length;
        area_inner = 2 * M_PI * radius_inner * length;
        volume = M_PI * (pow(radius_outer, 2) - pow(radius_inner, 2)) * length;
        // print table
        printf("Name                    Value\n");
        printf("========================================\n");
        printf("radius outer (in):        %.4f\n", radius_outer);
        printf("radius inner(in):         %.4f\n", radius_inner);
        printf("length (in):              %.4f\n", length);
        printf("edge_face(in):            %.4f\n", edge_face);
        printf("area_face(in^2):          %.4f\n", area_face);
        printf("area_outer(in^2):         %.4f\n", area_outer);
        printf("area_inner(in^2):         %.4f\n", area_inner);
        printf("volume (in^3):            %.4f\n", volume);
        printf("========================================\n");
        // set results
        results = EXIT_SUCCESS;
    }

    return (results);
}

/*
 * Name: rectangle_filled_3D_v2
 * Desc: Desc: Called function for the filled rectangle to do calculations and output
 * Args: edge_face, area_face, area_outer, area_inner, volume, base, height, length
 */
int rectangle_filled_3D_v2(double base, double height, double length)
{

    printf("rectangle_filled_3D_v2:\n");

    double edge_face;
    double area_face;
    double area_outer;
    double area_inner;
    double volume;
    int results;

    edge_face = 0.0;
    area_face = 0.0;
    area_outer = 0.0;
    area_inner = 0.0;
    volume = 0.0;
    results = EXIT_FAILURE;

    if (base < 0.0)
    {
        printf("Error: Invalid base\n");
    }
    else if (height < 0.0)
    {
        printf("Error: Invalid height\n");
    }
    else if (length < 0.0)
    {
        printf("Error: Invalid length\n");
    }
    else
    {

        edge_face = 4 * (base + height);
        area_face = 2 * (base * height);
        area_outer = 2 * (base + height) * length;
        area_inner = 0.0;
        volume = base * height * length;

        printf("Name                    Value\n");
        printf("========================================\n");
        printf("base (in):                %.4f\n", base);
        printf("height (in):              %.4f\n", height);
        printf("length (in):              %.4f\n", length);
        printf("edge_face(in):            %.4f\n", edge_face);
        printf("area_face(in^2):          %.4f\n", area_face);
        printf("area_outer(in^2):         %.4f\n", area_outer);
        printf("area_inner(in^2):         %.4f\n", area_inner);
        printf("volume (in^3):            %.4f\n", volume);
        printf("========================================\n");

        results = EXIT_SUCCESS;
    }

    return (results);
}

/*
 * Name: rectangle_hollow_3D_v2
 * Desc: Desc: Called function for the hollow rectangle to do calculations and output
 * Args: edge_face, area_face, area_outer, area_inner, volume, base_outer, height_outer, base_inner...
 *       height_inner, length
 */
int rectangle_hollow_3D_v2(double base_outer, double height_outer, double base_inner, double height_inner, double length)
{

    printf("rectangle_hollow_3D_v2:\n");

    double edge_face;
    double area_face;
    double area_outer;
    double area_inner;
    double volume;
    int results;

    edge_face = 0.0;
    area_face = 0.0;
    area_outer = 0.0;
    area_inner = 0.0;
    volume = 0.0;
    results = EXIT_FAILURE;

    if (base_outer < 0.0)
    {
        printf("Error: Invalid base_outer\n");
    }
    else if (height_outer < 0.0)
    {
        printf("Error: Invalid height_outer\n");
    }
    else if (base_inner < 0.0)
    {
        printf("Error: Invalid base_inner\n");
    }
    else if (height_inner < 0.0)
    {
        printf("Error: Invalid height_inner\n");
    }
    else if (length < 0.0)
    {
        printf("Error: Invalid length\n");
    }
    else if (base_inner > base_outer)
    {
        printf("Error: base_outer must be larger than base_inner\n");
    }
    else if (height_inner > height_outer)
    {
        printf("Error: height_outer must be larger than height_inner\n");
    }
    else
    {

        edge_face = 4 * (base_outer + height_outer + base_inner + height_inner);
        area_face = 2 * ((base_outer * height_outer) - (base_inner * height_inner));
        area_outer = 2 * (base_outer + height_outer) * length;
        area_inner = 2 * (base_inner + height_inner) * length;
        volume = ((base_outer * height_outer) - (base_inner * height_inner)) * length;

        printf("Name                    Value\n");
        printf("========================================\n");
        printf("base_outer (in):          %.4f\n", base_outer);
        printf("height_outer (in):        %.4f\n", height_outer);
        printf("base_inner (in):          %.4f\n", base_inner);
        printf("height_inner (in):        %.4f\n", height_inner);
        printf("length (in):              %.4f\n", length);
        printf("edge_face(in):            %.4f\n", edge_face);
        printf("area_face(in^2):          %.4f\n", area_face);
        printf("area_outer(in^2):         %.4f\n", area_outer);
        printf("area_inner(in^2):         %.4f\n", area_inner);
        printf("volume (in^3):            %.4f\n", volume);
        printf("========================================\n");

        results = EXIT_SUCCESS;
    }

    return (results);
}

void help(void)
{
    printf("Usage:\n");
    printf("P3.exe /h                                                           ...calls help\n");
    printf("P3.exe /circle /i                                                   ...calls circle interactively\n");
    printf("P3.exe /circle /p 1.0 10.0                                          ...calls circle parametrically\n");
    printf("P3.exe /annulus /i                                                  ...calls annulus interactively\n");
    printf("P3.exe /annulus /p /1.0 0.5 10.0                                    ...calls annulus parametrically\n");
    printf("P3.exe /rectangle_filled /i                                         ...calls rectangle_filled interactively\n");
    printf("P3.exe /rectangle_filled /p /1.0 2.0 10.0                           ...calls rectangle_filled parametrically\n");
    printf("P3.exe /rectangle_hollow /i                                         ...calls rectangle_hollow interactively\n");
    printf("P3.exe /rectangle_hollow /p /1.0 0.75 2.0 1.5 10.0                  ...calls rectangle_hollow parametrically\n");
}

