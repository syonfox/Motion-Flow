#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
//#include <SFML/Graphics/CircleShape.hpp>
#include "SFML/Graphics/CircleShape.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include "engine.hpp"
#include "motion.hpp"
#include "fonts.hpp"
#include <iostream>


int main()
{


    sf::RenderWindow window(sf::VideoMode(1366, 720), "Motion Flow");
    window.setFramerateLimit(120);
    ImGui::SFML::Init(window);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);
    static bool hasFocus = true;


    ImGuiIO io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.NavActive = true;

    //ImFont* font1 = io.Fonts->AddFontDefault();
    //ImFont* font1 = io.Fonts->AddFontFromFileTTF("../imgui-sfml/misc/fonts/DroidSans.ttf", 32);
//    ImFont* font1 = io.Fonts->AddFontFromFileTTF("../res/FFF_Tusj.ttf", 13);
//    ImGui::SFML::UpdateFontTexture();
//
//    sf::Font sfFont1;
//    sfFont1.loadFromFile("../res/FFF_Tusj.ttf");


    //Font::load("../res/FFF_Tusj.ttf", 13, "trsj");
    Engine::Fonts.push_back(Font("../res/fonts/FFF_Tusj.ttf", 13, "tusj"));
    Engine::Fonts.push_back(Font("../res/fonts/FFF_Tusj.ttf", 32, "tusj_big"));
    Engine::Fonts.push_back(Font("../res/fonts/PermanentMarker.ttf", 32, "marker"));
    bool showimguiDemo = false;
    // timing
    /*
    how the game timing works
    tickTime is the number of sim time per tick

    */



    Engine e = Engine(window.getSize());

    //Motion::init();

    uint tick = 0;
    sf::Time tickTime = sf::seconds(0.01f); // the amount of time to simulate
    // every tick (adjust this to change
    // the acuracy of the sim)
    int ticksPerSecond = 120; // number of ticks to simulate evry second (adjust
    // this to change the speed (kind of)
    float simTimePerSecond = tickTime.asSeconds() * ticksPerSecond;
    sf::Time secondsPerTick = sf::seconds(1.0f / (float) ticksPerSecond);

    int framesPerSecond = 120; // desired render rate
    int ticksPerFrame =
            ticksPerSecond /
            framesPerSecond; // todo: make it adgust fps for valid ratio
    sf::Time secondsPerFrame = sf::seconds(1.0f / framesPerSecond);

    /*
    clock.resart()
    tick++;
    engine.update()
    if(tick% ticksPerFrame = 0)
      render();

    if(clock.time() < secondsPerTick )
      sleep(secondsPerTick -clock.time());
    */

    sf::Clock deltaClock;

    sf::Time frameTime;
    while (window.isOpen()) {

        frameTime = deltaClock.restart();
        tick++;

        ////Update engine////
        e.update(tickTime);


        if (tick % ticksPerFrame == 0) {// if we are rendering do gui and draw
            // handleEvents( ) //TODO: break out event handler so input is more responsive
            sf::Event event{};
            while (window.pollEvent(event)) {
                ImGui::SFML::ProcessEvent(event);

                // if the window has focuse and Imgui dose not
                // if (hasFocus && !ImGui::IsMouseHoveringAnyWindow()) {
                if (hasFocus) {
                     // nonimgui event handling
                    e.handleEvent(event);
                    //printf("Sending event to engine\n");
                }

                switch (event.type) {
                    case sf::Event::LostFocus:
                        hasFocus = false;
                        break;
                    case sf::Event::GainedFocus:
                        hasFocus = true;
                        break;


                        break;
                }

                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }



            ImGui::SFML::Update(window, deltaClock.restart());



            if (ImGui::BeginMainMenuBar()) {
                if (ImGui::BeginMenu("Debug")) {

                    if (ImGui::MenuItem("Toggle Debug Window", nullptr, &Engine::showDebugWindow)) {
                    }
                    if (ImGui::MenuItem("Toggle ImGUI Demo", nullptr, &showimguiDemo)) {
                    }

                    ImGui::EndMenu();
                }
            }
            ImGui::EndMainMenuBar();

            if (showimguiDemo) {
                ImGui::ShowTestWindow();
            }

            if (Engine::showDebugWindow) {


                ImGui::Begin("Debug", &Engine::showDebugWindow, ImVec2(400,400) );
//                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
//                            1000.0f / ImGui::GetIO().Framerate,
//                            ImGui::GetIO().Framerate);
                ImGui::PushFont(Engine::Fonts[0].imfont);
                ImGui::Text("Tick Time: %fs , TPS: %f", frameTime.asSeconds(), 1.f / (float) frameTime.asSeconds());
                ImGui::Text("Has Focus %d, ImGui Has Focus %d", hasFocus, ImGui::IsMouseHoveringAnyWindow());
                ImGui::PopFont();

                if (ImGui::CollapsingHeader("Time")) {
                    /// ImGui::InputFloat("Time Simulated per Tick",
                    /// &(tickTime.asSeconds(), 1);
                    //ImGui::InputFloat("Speed (sim seconds/second)", &simTimePerSecond, 1);
                    //ImGui::Text("Ticks/Second: %d", ticksPerSecond);
                    ImGui::Text("Tick: %d   , Seconds/Tick: %f", tick, secondsPerTick.asSeconds());
                    ImGui::Text("Fps: %d   , Tps: %d   , Tpf: %d", framesPerSecond, ticksPerSecond, ticksPerFrame);
                    ImGui::Text("Engine Time per Second: %f   , Engine Time per Tick: %f s", simTimePerSecond,
                                tickTime.asSeconds());

//                    ticksPerSecond = (int)simTimePerSecond / tickTime.asSeconds();
//                    simTimePerSecond = tickTime.asSeconds() * ticksPerSecond;
//                    secondsPerTick = sf::seconds(1.0f / ticksPerSecond);
//                    ticksPerFrame = ticksPerSecond / framesPerSecond;
                }
                ImGui::End();
            }


            window.clear(sf::Color(135, 206, 235, 256)); //background colour
            //window.draw(shape);
            e.render(window);



            ImGui::SFML::Render(window);
            window.display();
        }

        sf::sleep(secondsPerTick - deltaClock.getElapsedTime());

    }

    Motion::shutdown();
    ImGui::SFML::Shutdown();

    return 0;
}