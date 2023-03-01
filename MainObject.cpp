
#include "MainObject.h"

MainObject::MainObject() {
 frame_=0;
 x_pos_=0;
 y_pos_=0;
 y_val_=0;
 x_val_=0;
 Main_width=0;
 Main_height=0;
 status_=-1;
 input_type.left=0;
 input_type.right=0;
 input_type.down=0;
 input_type.up=0;
}
bool MainObject::LoadImg(std::string path,SDL_Renderer* screen)
{
    bool ret=BaseObject::LoadImg(path,screen);
    if(ret) {
         Main_width=rect_.w/5;
         Main_height=rect_.h;
    }
    return ret;
}
void MainObject::Show(SDL_Renderer* screen)
{
    if(status_==3) {
        LoadImg("play_left.png",screen);
    }
    else if(status_==4) {
        LoadImg("play_right.png",screen);
    }
    else if(status_==1) {
        LoadImg("play_up.png",screen);

    }
    else if(status_==2) {
        LoadImg("play_down.png",screen);
    }
    //else if(status_==3)
    if(input_type.left==1||input_type.right==1||input_type.up==1||input_type.down==1) {
        frame_++;
    }
    else {
        frame_=0;
    }
    if(frame_>=5) {
        frame_=0;
    }
    x_pos_+=x_val_;
    y_pos_+=y_val_;

    rect_.x=x_pos_;
    rect_.y=y_pos_;
    SDL_Rect *current_clip=&clip_[frame_];
    SDL_Rect renderquad={rect_.x,rect_.y,Main_width,Main_height};
    SDL_RenderCopy(screen,p_object_,current_clip,&renderquad);
}
void MainObject::handle(SDL_Event e,SDL_Renderer* screen)
{
     if(e.type==SDL_KEYDOWN &&e.key.repeat==0)
    {
         switch( e.key.keysym.sym )
        {
            case SDLK_w:
                {status_=1;input_type.up=1;input_type.down=0;input_type.left=0;input_type.right=0;y_val_-=5;x_val_=0; break;}
            case SDLK_s: status_=2;input_type.up=0;input_type.down=1;input_type.left=0;input_type.right=0;y_val_+=5;x_val_=0; break;
            case SDLK_a: status_=3;input_type.up=0;input_type.down=0;input_type.left=1;input_type.right=0;x_val_-=5;y_val_=0; break;
            case SDLK_d: status_=4;input_type.up=0;input_type.down=0;input_type.left=0;input_type.right=1;x_val_+=5;y_val_=0; break;

        }
    }
     else if (e.type==SDL_KEYUP&&e.key.repeat==0)
    {
         switch( e.key.keysym.sym )
        {
           case SDLK_w: input_type.up=0;x_val_=0;y_val_=0;break;
            case SDLK_s: input_type.down=0;x_val_=0;y_val_=0; break;
            case SDLK_a: input_type.left=0;x_val_=0;y_val_=0; break;
            case SDLK_d: input_type.right=0; x_val_=0;y_val_=0;break;

        }
    }
}
void MainObject::SetClip()
{
    clip_[0].x=0;
    clip_[0].y=0;
    clip_[0].w=Main_width;
    clip_[0].h=Main_height;

    clip_[1].x=Main_width;
    clip_[1].y=0;
    clip_[1].w=Main_width;
    clip_[1].h=Main_height;

    clip_[2].x=2*Main_width;
    clip_[2].y=0;
    clip_[2].w=Main_width;
    clip_[2].h=Main_height;

    clip_[3].x=3*Main_width;
    clip_[3].y=0;
    clip_[3].w=Main_width;
    clip_[3].h=Main_height;

    clip_[4].x=4*Main_width;
    clip_[4].y=0;
    clip_[4].w=Main_width;
    clip_[4].h=Main_height;

    clip_[5].x=5*Main_width;
    clip_[5].y=0;
    clip_[5].w=Main_width;
    clip_[5].h=Main_height;


}
void MainObject::InputAction()
{
    if(input_type.left==1) {
        x_val_-=2;

    }
    else if(input_type.right==1) {
        x_val_+=2;

    }
    else if(input_type.down==1)
    {
        y_val_+=2;

    }
    else if(input_type.up==1) {
        y_val_-=2;
    }
    if(x_val_>2) {
        x_val_=2;
    }
    if(y_val_>2) {
        y_val_=2;
    }
}
