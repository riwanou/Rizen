#ifndef APP_H
#define APP_H

#include "input.h"
#include "../opengl/opengl_2d.h"
#include "ressource_manager.h"
#include "../utils/rizen_math.h"

#include "../../extern/imgui/imgui.h"
#include "../../extern/imgui/imgui_impl_opengl3.h"

//#define APP_DEBUG

struct AppInfo {
    const char* title = "rizen";
    int pos_x = SDL_WINDOWPOS_CENTERED;
    int pos_y = SDL_WINDOWPOS_CENTERED;
    int size_x = 400;
    int size_y = 400;
    int flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_INIT_JOYSTICK;
};

class App {
public:
    App();
    ~App();

    bool init(const AppInfo& info);;
    void clear(const glm::vec4& color = glm::vec4(0.0));
    void begin();
    void end();
    
    Renderer* renderer() const { return m_renderer; }
    Renderer2D* renderer_2d() const { return m_renderer_2d; }
    RessourceManager* ressource_manager() const { return m_ressource_manager; }
    
    bool on_quit() {
        return Input::on_quit() || Input::key_pressed(SDLK_ESCAPE);
    }
    
private:
    SDL_Window* m_window;
    SDL_GLContext m_gl_context;
    Renderer2D* m_renderer_2d;
    RessourceManager* m_ressource_manager;
    Renderer* m_renderer;
};

#endif //APP_H