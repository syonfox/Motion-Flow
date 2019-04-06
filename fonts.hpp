//
// Created by syonfox on 05/04/19.
//

#ifndef MOTION_FLOW_FONTS_HPP
#define MOTION_FLOW_FONTS_HPP



#include <imgui-sfml/imgui.h>
#include <vector>
#include <SFML/Graphics/Font.hpp>


//namespace Font {
//    struct Font{
//        ImFont* imfont;
//        sf::Font sffont;
//        std::string name;
//    };
//
//    void load(const std::string& path, const int size = 12, const std::string& name = "");
//    Font* findFont(const std::string& name);
//    Font getFont(int i);
//};

class Font{
public:
    ImFont* imfont;
    sf::Font sffont;
    std::string name;
    int size;

    Font(const std::string& path, const int size, std::string name ="");
};
#endif //MOTION_FLOW_FONTS_HPP
