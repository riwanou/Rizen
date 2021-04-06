#ifndef SHADER_H
#define SHADER_H

#include <fstream>
#include <string>

#include "../utils/glew_utils.h"
#include "../utils/glm_utils.h"

const std::string shaderPath = "../shaders/";

class Shader {
public:
    Shader();
    ~Shader();

    bool init(const std::string& vertexFile, const std::string& fragmentFile);
    void bind();

	void set_mat4(const std::string& name, const glm::mat4& value);
    void set_vec2(const std::string& name, const glm::vec2& value);
    void set_vec3(const std::string& name, const glm::vec3& value);
	void set_bool(const std::string& name, bool value);
	void set_int(const std::string& name, int value);
	void set_float(const std::string& name, float value);

private:
    GLuint m_program;
    GLuint m_vertex;
    GLuint m_fragment;

    bool load_vertex(const std::string& filename);
    bool load_fragment(const std::string& filename);
    bool compile_shader(const char* source, GLuint shader, const std::string& name); 
	bool read_from_file(const std::string& filename, std::string* source);
	bool check_link();
	GLuint uniform_loc(const char* name);    
};

#endif //SHADER_H