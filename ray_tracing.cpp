 #include <iostream>
 #include <SDL2/SDL.h>



// note:  used a class (as opposed to struct) here as I intend to use different shapes that derive from this classwq 
class Shape{

 public:
  Shape(int x_pos, int y_pos , int dim){
   this->x_pos = x_pos;
   this->y_pos = y_pos;
   this->dim = dim;
} 





private:
  int x_pos;
  int y_pos;
  int dim;
};



class Circle : public Shape {

public:
    // Constructor that initializes a Circle using the x and y position for its center, and its radius as dim
    Circle(int x_pos, int y_pos, int radius) : Shape(x_pos, y_pos, radius) {}
};



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




SDL_Delay(5000);




return 0;
}
