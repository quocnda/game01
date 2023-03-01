#include "CommonFunc.h"
#include "BaseObject.h"
#include "MainObject.h"
using namespace std;

MainObject main_obj;
bool init() {
   gWindow=SDL_CreateWindow("quoc",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,600,600,SDL_WINDOW_SHOWN);
   gScreen=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
   return gScreen!=NULL;
}
bool loadmedia() {
   SDL_Surface* tmp=IMG_Load("bkgr.jpg");
   gText=SDL_CreateTextureFromSurface(gScreen,tmp);
   SDL_FreeSurface(tmp);
   return gText!=NULL;
}
void close() {
   SDL_DestroyRenderer(gScreen);
   gScreen=NULL;
   SDL_DestroyWindow(gWindow);
   gWindow=NULL;
   SDL_DestroyTexture(gText);
   gText=NULL;
}
int main(int argc,char* args[])
{
    if(init()) {
        if(loadmedia())
        {

            main_obj.LoadImg("play_right.png",gScreen);
            main_obj.SetClip();

            bool quit=false;
            while(!quit)
            {
                while(SDL_PollEvent(&gevent)!=0) {
                    if(gevent.type==SDL_QUIT)
                    {
                        quit=true;
                    }
                  main_obj.handle(gevent,gScreen);

                }
                 SDL_RenderClear(gScreen);
                SDL_RenderCopy(gScreen,gText,NULL,NULL);
                //main_obj.InputAction();
                main_obj.Show(gScreen);
                SDL_Delay(100);
                SDL_RenderPresent(gScreen);
            }
        }
        else {cout<<"loi day ne";}
    }
    else {cout<<"losi day";}
    close();
    return 0;
}
