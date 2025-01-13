 #include <iostream>
 #include <SDL2/SDL.h>
#include <math.h>


#define WHITE 0xFFFF
// note:  used a class (as opposed to struct) here as I intend to use different shapes that derive from this classwq 
class Shape{

  
public:

double x_pos;
double y_pos;
double dim;

Shape(double x_pos, double y_pos , double dim){
   this->x_pos = x_pos;
   this->y_pos = y_pos;
   this->dim = dim;
} 


};


class Circle : public Shape{

     public:
    
     Circle(double x_pos, double y_pos, double dim)    : Shape(x_pos, y_pos, dim){
     
     };


};


void drawCircle(SDL_Surface *s, Circle * c,uint32_t colour){

	double x_lower_bound = c->x_pos -  c->dim;
	double x_upper_bound = c->x_pos + c->dim;

	double y_lower_bound = c->y_pos - c->dim;
        double y_upper_bound = c->y_pos + c->dim;

        double radius_sq   =  pow(c->dim,2); //  calculate radius squared

	for(double x  =  x_lower_bound; x <= x_upper_bound ; x=+1){
	 

	     for(double y = y_lower_bound; y<= y_upper_bound; y+=1)
	     {
	     
	        double distance_sq =   pow(x - c->x_pos, 2) + pow(y - c->y_pos,2);
	              if(distance_sq < radius_sq ){
		            // draw the pixel  
		      SDL_Rect pxl  = SDL_Rect{x,y,1,1};
		      SDL_FillRect(s, &pxl,WHITE);

		      } 
	     }
	       
	
	}

}




int main(){


// intislize the SDL windows 
if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout<<"Could not initializeeverything: !!!"<< SDL_GetError();
        return 1;
    }

SDL_Window* window = SDL_CreateWindow("GAME", // creates a window
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    1000, 1000, 0);





SDL_Surface * surface = SDL_GetWindowSurface(window);



Circle c  = Circle(300,300, 40);



SDL_Delay(5000);
}
