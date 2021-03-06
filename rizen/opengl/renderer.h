#ifndef RENDERER_H
#define RENDERER_H

#include <queue>
#include <unordered_map>

#include "camera.h"
#include "model.h"

/*
    Renderer
*/

#define MATRICES_SIZE 64
#define MATRICES_INDEX 0
#define LIGHT_DIR_SIZE 16
#define LIGHT_DIR_INDEX 1
#define SKY_COLOR_SIZE 16
#define SKY_COLOR_INDEX 2

class Renderer {
public:
    ~Renderer();

    /**
     * @brief Init the uniform buffer object
     */
    void init();
    
    /**
     * @brief Bind the uniform buffer to the shader
     * @param shader
     */
    void bind_ubo(Shader* shader);

    /**
     * @brief Begin rendering sequence.
     * @param camera
     * @param sun_direction
     */
    void begin(Camera* camera, const glm::vec3& sun_direction, const glm::vec3& sky_color);

    /**
     * @brief End rendering sequence.
     */
    void end();
    

    /**
     * @brief Simply render the object and bind the transform matrix.
     * @param render_model
     * @param model
     */
    void simple_render(Model* render_model, const glm::mat4& model);

    void render_depth(Shader* depth_shader, Model* render_model, const glm::mat4& model);

    /**
     * @brief Render the object with the render model and material.
     * @param render_model
     * @param model
     */
    void render(Model* render_model, const glm::mat4& model);


    /**
     * @brief Update the instanced vbo for the render model
     * Call this method before any instanced rendering
     * @param render_model 
     * @param models array of model matrices
     * @param num_models num of model matrices
     */
    void update_instanced(Model* render_model, glm::mat4* models, int num_models);

    /**
    * @brief Simply render the instanced object.
    * Don't forget to call update_instanced if needed.
    * @param render_model
    * @param num_object number of objects
    */
    void simple_render_instanced(Model* render_model, int num_objects);

    /**
     * @brief Call this method for depth rendering
     * Don't forget to call update_instanced if needed.
     * @param render_model 
     * @param num_objects numbe rof objects
     */
    void render_instanced_depth(Shader* depth_shader, Model* render_model, int num_objects);
    
    /**
     * @brief Render the instanced object with the render model and material.
     * Don't forget to call update_instanced if needed.
     * @param render_model
     * @param num_objects number of objects
     */
    void render_instanced(Model* render_model, int num_objects);

private:
    GLuint m_ubo;

    void set_ubo();
};

#endif //RENDERER_H