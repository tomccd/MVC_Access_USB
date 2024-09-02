#ifndef __MVC_USB
#define __MVC_USB
#include <iostream>
#include <vector>
#include <experimental/filesystem>
#include <unistd.h>
#include <string>
namespace fs=std::experimental::filesystem;
typedef std::experimental::filesystem::__cxx11::directory_entry directory_entry;
/*Model*/
class USB_Model{
    private:
        std::vector<directory_entry>list_usb;
        std::string path;
    public:
        /*Set path*/
        void setPath(std::string _path);
        /*Get all USB in /media folder*/
        std::vector<directory_entry>get_USB();
        /*Get USB with specific index in list_usb*/
        std::string get_USB(int option);
};

/*View*/
class USB_View{
    public:
        void display_Dir(std::vector<directory_entry>list_usb) const;
        void display_File_In_Dir(std::string usb);
};

/*Controller*/
class USB_Controller{
    private:
        USB_Model *model;
        USB_View *view;
    public:
        USB_Controller(USB_Model *_model, USB_View *_view){
            model = _model;
            view = _view;
        }
        /*Set Path*/
        void setPath(std::string _path="/media/"+ (std::string)getlogin());
        /*Get USB with specific index*/
        std::string get_USB(int option) const;
        /*Get all USB in /media*/
        std::vector<directory_entry>get_USB() const;
        /*Update all USB input detail in View*/
        void updateView(std::vector<directory_entry>list_usb) const;
        /*Update all USB's data detail in View*/
        void updateView(std::string usb);
        ~USB_Controller(){
            delete(model);
            delete(view);
        }
};

#endif