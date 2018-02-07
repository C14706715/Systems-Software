myprog : main.o areaOfRectangle.o areaOfSquare.0 areaOfCircle.o area_of_triangle.0
        gcc -o areaProg main.c areaOfRectangle.o areaOfSquare.o areaOfCircle.o area_of_Triangle.o -lm

main.o : myprog : main.c areaOfRectangle.h areaOfSquare.h areaOfCircle.h area_of_triangle.h
         gcc -c main.c

areaOfRectangle.o : areaOfRectangle.c 
    gcc -c areaOfRectangle.c

areaOfSquare.o : areaOfSquare.c areaOfrectangle.h
    gcc -c areaOfSquare.c
    
areaOfCircle.o : areaOfCircle.c
    gcc -c areaOfCircle.c

area_of_triangle.o : area_of_triangle.c
    gcc -c area_of_triangle.c -lm
    
clean: 
    rm areaProg main.o areaOfRectangle.o areaOfSquare.o areaOfCircle.o area_of_triangle.o