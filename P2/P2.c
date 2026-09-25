/* 
 * File: P2.c
 * Copy: Copyright (c) 2026 Conner D. Bevan
 * BlazerID: cdbevan
 * Vers: 1.0.0 09/08/2026 CDB - Original Coding
 * Desc: Calculating circle, annulus, a filled rectangle, and hollow rectangles and displaying outputs. 
 */ 
/* 
 * File:   P2.c
 * Author: conbev
 *
 * Created on September 3, 2026, 4:43 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {

    //circle_3D_v1();
    //annulus_3D_v1();
    //rectangle_filled_3D_v1();
    rectangle_hollow_3D_v1();
    
    return (EXIT_SUCCESS);
}

/* Function Prototypes */ 
void circle_3D_v1(void);
void annulus_3D_v1(void);
void rectangle_filled_3D_v1(void);
void rectangle_hollow_3D_v1(void);

/* 
 * Name: circle_3D_v1
 * Desc: Calculates and displays values for circular cross section
 * Args: radius, length, edge_face, area_face, area_outer_area_inner, and volume
 */
void circle_3D_v1(void) {
    
    // identify the inputs and outpust and their variable types
    // declare all the variables in comments...
    // ex: 
    //      radius, length - inputs, doubles
    //      edge_face, area_face, area_inner, area_outer, volume - outputs, doubles
    printf("Calling circle_3D_v1");
    
    double radius;
    double length;
    double edge_face;
    double area_face;
    double area_outer;
    double area_inner;
    double volume;
    //...
    
    // set variables to 0.0 because its a double
    radius = 0.0;
    length = 0.0;
    edge_face = 0.0;
    area_face = 0.0;
    area_outer = 0.0;
    area_inner = 0.0;
    volume = 0.0;
    
    printf("Please enter radius (in): \n");
    scanf("%lf", &radius);
    
    printf("Please enter length (in): \n");
    scanf("%lf", &length);
    
    //implementation of the formulas
    edge_face = 2 * (2 * M_PI * radius);
    area_face = 2 * (M_PI * pow(radius, 2.0));
    area_outer = (2* M_PI * radius) * length;
    area_inner = 0.0;
    volume = (M_PI * pow(radius, 2.0)) *length ;
    
    // prepare the output table
    printf("Name                    Value\n");
    printf("========================================\n");
    printf("radius (in):              %.4f\n", radius);
    printf("length (in):              %.4f\n", length);
    printf("edge_face(in):            %.4f\n", edge_face);
    printf("area_face(in^2):          %.4f\n", area_face);
    printf("area_outer(in^2):         %.4f\n", area_outer);
    printf("area_inner(in^2):         %.4f\n", area_inner);
    printf("volume (in^3):            %.4f\n", volume);
    printf("========================================\n");

}

/* 
 * Name: annulus_3D_v1
 * Desc: Calculates and displays mathematical determinants of an annulus
 * Args: radius_outter, radius_inner, length, edge_face, area_face, area_outer, area_inner, and volume
 */
void annulus_3D_v1(void) {
    
    // identify problem + variables + types
    printf("Calling annulus_3D_v1...\n");
    double radius_outer;
    double radius_inner;
    double length;
    double edge_face;
    double area_face;
    double area_outer;
    double area_inner;
    double volume;
    
    // set variables to 0.0 because its a double
    radius_outer = 0.0;
    radius_inner = 0.0;
    length = 0.0;
    edge_face = 0.0;
    area_face = 0.0;
    area_outer = 0.0;
    area_inner = 0.0;
    volume = 0.0;
    
    // create prompts and inputs
    printf("Please enter outer radius (in): \n");
    scanf("%lf" , &radius_outer);

    printf("Please enter inner radius (in): \n");
    scanf("%lf", &radius_inner);
    
    printf("Please enter length (in): \n");
    scanf("%lf", &length);
    
    //calculations
    edge_face = (4*M_PI) * (radius_inner + radius_outer);
    area_face = 2*M_PI * (pow(radius_outer,2) - pow(radius_inner,2));
    area_outer = 2*M_PI * radius_outer * length;
    area_inner = 2 * M_PI * radius_inner * length;
    volume = M_PI *(pow(radius_outer,2) - pow(radius_inner,2)) * length;
    
    // create the table/output
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
    
}

/* 
 * Name: rectangle_filled_3D_v1
 * Desc: Calculates and displays mathematical determinants of a filled rectangle
 * Args: base, height, length, edge_face, area_face, area_outer, area_inner, and volume
 */
void rectangle_filled_3D_v1(void) {
    printf("Calling rectangle_filled_3D_v1 \n");
    
    double base;
    double height;
    double length;
    double edge_face;
    double area_face;
    double area_outer;
    double area_inner;
    double volume;
    
    // set variables to 0.0 because its a double
    base = 0.0;
    height = 0.0;
    length = 0.0;
    edge_face = 0.0;
    area_face = 0.0;
    area_outer = 0.0;
    area_inner = 0.0;
    volume = 0.0;
    
    //prompting
    printf("Please enter base (in): \n");
    scanf("%lf" , &base);

    printf("Please enter height (in): \n");
    scanf("%lf", &height);
    
    printf("Please enter length (in): \n");
    scanf("%lf", &length);
    
    //Calculations
    edge_face = 4 * (base + height);
    area_face = 2* (base * height);
    area_outer = 2 * (base + height) * length;
    area_inner = 0.0;
    volume = base * height * length;
    
    // create the table/output
    printf("Name                    Value\n");
    printf("========================================\n");
    printf("base (in):                 %.4f\n", base);
    printf("height (in):               %.4f\n", height);
    printf("length (in):               %.4f\n", length);
    printf("edge face(in):             %.4f\n", edge_face);
    printf("area face(in^2):           %.4f\n", area_face);
    printf("area inner (in^2):         %.4f\n", area_inner);
    printf("area outer (in^2):         %.4f\n", area_outer);
    printf("volume (in^3):             %.4f\n", volume);
    printf("========================================\n");
    
}

/* 
 * Name: rectangle_hollow_3D_v1
 * Desc: Calculates and displays mathematical determinants of a hollow rectangle
 * Args: base_outer, height_outer, base_inner, height_inner, length, edge_face, area_face, ...
 *       area_outer, area_inner, and volume
 */
void rectangle_hollow_3D_v1(void) {
    
    printf("Calling rectangle_hollow_3D_v1\n");
    double base_outer;
    double height_outer;
    double base_inner;
    double height_inner;
    double length;
    double edge_face;
    double area_face;
    double area_outer;
    double area_inner;
    double volume;
    
    base_outer = 0.0;
    height_outer = 0.0;
    base_inner = 0.0;
    height_inner = 0.0;
    length = 0.0;
    edge_face = 0.0;
    area_face = 0.0;
    area_outer = 0.0;
    area_inner = 0.0;
    volume = 0.0;
    
    printf("Please enter outer base (in): \n");
    scanf("%lf" , &base_outer);
    
    printf("Please enter inner base (in): \n");
    scanf("%lf", &base_inner);
    
    printf("Please enter outer height (in): \n");
    scanf("%lf", &height_outer);
    
    printf("Please enter inner height (in): \n");
    scanf("%lf" , &height_inner);
    
    printf("Please enter length (in): \n");
    scanf("%lf", &length);
    
    //Calculations
    edge_face = 4 * (base_outer + height_outer + base_inner + height_inner);
    area_face = 2 * ((base_outer * height_outer) - (base_inner * height_inner));
    area_outer = 2 * (base_outer + height_outer) * length;
    area_inner = 2 * (base_inner + height_inner) * length;
    volume = ((base_outer * height_outer) - (base_inner * height_inner)) * length;
    
    // create the table/output
    printf("Name                    Value\n");
    printf("========================================\n");
    printf("base outer (in):          %.4f\n", base_outer);
    printf("height outer(in):         %.4f\n", height_outer);
    printf("base inner (in):          %.4f\n", base_inner);
    printf("height inner (in):        %.4f\n", height_inner);
    printf("length (in):              %.4f\n", length);
    printf("edge_face(in):            %.4f\n", edge_face);
    printf("area_face(in^2):          %.4f\n", area_face);
    printf("area inner(in^2):         %.4f\n", area_inner);
    printf("area outer(in^2):         %.4f\n", area_outer);
    printf("volume (in^3):            %.4f\n", volume);
    printf("========================================\n");
    
}

