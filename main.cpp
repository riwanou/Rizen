#include "rizen/rizen.h"

/*
    Init
*/

Shader basic_shader2D, custom_shader2D, basic_shader;
Texture texture;
FrameBuffer frame_buffer;

Square fbuffer_square;
Square square;

CameraTPS camera_tps;
Material material;
Mesh mesh;
Model model;

void init()
{
    basic_shader2D.init("2d/basic.vr", "2d/basic.fa");
    custom_shader2D.init("2d/basic.vr", "2d/custom.fa");
    texture.init_jpg("noise.jpg");

    glm::vec2 d_size = Input::display_size();

    square.set_pos(d_size * 0.5f);
    square.set_size(d_size);
    square.set_origin(glm::vec2(0.5));
    square.update_transform();

    frame_buffer.init(d_size);

    fbuffer_square.set_origin(glm::vec2(0.5));
    fbuffer_square.set_pos(d_size * 0.5f);
    fbuffer_square.set_size(d_size * 0.8f);
    fbuffer_square.update_transform();

    /*
        3D
    */

    // camera
    camera_tps.init(Input::display_size());
    basic_shader.init("basic.vr", "basic.fa");
    mesh.init("cube.obj");
    
    material.init();
    material.set_color(glm::vec4(1.0, 0.0, 0.0, 0.0));
    material.set_ambient(0.4);
    material.set_reflectivity(1.0);
    material.set_shine_damper(4);
    material.set_texture(&texture);

    model.init(&mesh, &material);
}

/*
    Update
*/

void update(App* app)
{
    if (Input::key_pressed(SDLK_RETURN)) {
        init();
        return;
    }
    
    // update camera
    camera_tps.move_angle_around(0.5);
    camera_tps.update();

    // render 3D objects
    frame_buffer.bind();
    app->clear(glm::vec4(0.1));    
    app->renderer()->begin(&camera_tps, &basic_shader);

    app->renderer()->render(&model);

    app->renderer()->end();
    frame_buffer.unbind();
    
    // first frame buffer
    app->renderer_2d()->begin(Input::display_size(), &basic_shader2D);
    app->renderer_2d()->render_square(fbuffer_square, frame_buffer.texture());
    app->renderer_2d()->end();
}

int main()
{
    App* app = new App();
    AppInfo info;
    info.size_x = 820;
    info.size_y = 620;
    app->init(info);

    init();

    while(!app->on_quit()) {
        app->begin();
        app->clear(glm::vec4(0.2));
        update(app);
        app->end();
    }

    delete app;
    return 0;
}