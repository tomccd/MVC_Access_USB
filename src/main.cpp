#include "../header/MVC_Architecture.hpp"

int main(){
    USB_Controller controller(new USB_Model(),new USB_View());
    controller.setPath();
    std::string path_optional;
    while(1){
        std::cout << "\n---------------------------------\n";
        std::cout << "Application Show Files in USB\n";
        std::cout << "Select 1: To Change Default Mounted Location\n";
        std::cout << "Select 2: To List all Mounted USB\n";
        std::cout << "Select 3: To Select and List all File in selected USB\n";
        std::cout << "Select 4: To exit\n";
        std::cout << "Your choice: ";
        int option;
        std::cin >> option;
        switch (option){
            case 1:
                std::cout << "\n---------------------------------\n";
                std::cout << "Enter Custom Path: ";
                std::cin.ignore();
                std::getline(std::cin,path_optional);
                controller.setPath(path_optional);
                break;
            case 2:
                std::cout << "\n---------------------------------\n";
                std::cout << "List of USB in that directory\n";
                controller.updateView(controller.get_USB());
                break;
            case 3:
                std::cout << "\n---------------------------------\n";
                std::cout << "List of USB in that directory\n";
                controller.updateView(controller.get_USB());
                int option_1;
                std::cout << "Your choice: ";
                std::cin>>option_1;
                controller.updateView(controller.get_USB(option_1));
                break;
            case 4:
                std::cout << "\n---------------------------------\n";
                std::cout << "Exit\n";
                return 0;
        }
    }
}