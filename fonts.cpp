//
// Created by syonfox on 05/04/19.
//

#include <imgui-sfml/imgui-SFML.h>
#include "fonts.hpp"

//void Font::loadFont(const std::string& path, int size){
//    Font font();
//    ImGuiIO io = ImGui::GetIO();
//    font.
//
//}


//static std::vector<Font::Font> Fonts;

Font::Font(const std::string& path, int size, std::string name) {


    ImGuiIO io = ImGui::GetIO();
    imfont = io.Fonts->AddFontFromFileTTF(path.c_str(), size);
    ImGui::SFML::UpdateFontTexture();

    sffont.loadFromFile(path);

    this->size = size;

    if(name == "")
        name = path;
    else
        this->name = name;

}

//Font* Font::findFont(const std::string& name) {
//    for(int i=0; i< Fonts.size(); i++) {
//        if(name.compare(Fonts[i].name))
//            return &Fonts[i];
//    }
//    return NULL;
//}
//
//Font Font::getFont(int i) {
//    return Fonts[i];
//}