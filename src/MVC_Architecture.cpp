#include "../header/MVC_Architecture.hpp"

/*Model*/

//set the location that manage the removable device
void USB_Model::setPath(std::string _path){
    path = _path;
}

//Get USB
std::vector<directory_entry>USB_Model::get_USB(){
    /*Delete all information in list_usb*/
    list_usb.clear();
    if(fs::is_directory(path)){
        for(auto &entry: fs::directory_iterator(path)){
            if(fs::is_directory(entry)){
                list_usb.push_back(entry);
            }
        }
        return list_usb;
    }
    else{
        throw std::invalid_argument(path + " is not valid path");
    }
    return {};
}

std::string USB_Model::get_USB(int option){
    if(list_usb.size()!=0){
        //Back up Previous Path: Avoid choosen USB is taken off
        if(option < list_usb.size()){
            auto previous_Path = list_usb[option];
            //Update list USB again
            this->get_USB();
            if(list_usb.size()!=0){
                for(auto &entry:list_usb){
                    if(entry == previous_Path){
                        return entry.path();
                    }
                }
            }
        }
        else{
            std::cout << "Invalid Index\n";
        }
    }
    return "";
}

/*View*/
//Display all USB in /media
void USB_View::display_Dir(std::vector<directory_entry>list_usb) const{
    if(list_usb.size()!=0){
        for(int i=0;i<list_usb.size();i++){
            std::cout << i << ": " << list_usb[0].path().stem() << std::endl;
        }
    }
    else{
        std::cout << "Make sure you insert your USB\n";
    }
}
//Display all file in choosen USB
void USB_View::display_File_In_Dir(std::string usb){
    if(fs::is_directory(usb)){
        for(auto &entry:fs::directory_iterator(usb)){
            std::cout << entry.path().filename() << std::endl;
        }
    }
    else{
        throw std::invalid_argument("Please check the state of USB inserted in your Laptop\n");
    }
}

/*Controller*/

//set the location that manage the removable device
void USB_Controller::setPath(std::string _path){
    model->setPath(_path);
}

/*Get all USB in /media*/
std::vector<directory_entry>USB_Controller::get_USB() const{
    return model->get_USB();
}

/*Get USB with specific index*/
std::string USB_Controller::get_USB(int option) const{
    return model->get_USB(option);
}

/*Update all USB input in detail in View*/
void USB_Controller::updateView(std::vector<directory_entry>list_usb) const{
    view->display_Dir(list_usb);
}

/*Update all USB's data in detail in View*/
void USB_Controller::updateView(std::string usb){
    view->display_File_In_Dir(usb);
}