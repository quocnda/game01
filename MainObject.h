#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_
#include "CommonFunc.h"
#include "BaseObject.h"

class MainObject:public BaseObject
{
public:
   MainObject();
   ~MainObject() {;}
   bool LoadImg(std::string path,SDL_Renderer* screen);
   void Show(SDL_Renderer* screen);
   void handle(SDL_Event e,SDL_Renderer* screen);
   void SetClip();
   void SetToaDo(const int &x,const int &y) {x_pos_=x;y_pos_=y;}
   void InputAction();
private:
     float x_val_;
     float y_val_;

     float x_pos_;
     float y_pos_;

     int Main_width;
     int Main_height;

     Input input_type;
     int frame_;
     int status_;
     SDL_Rect clip_[5];
};
#endif // MAIN_OBJECT_H_
