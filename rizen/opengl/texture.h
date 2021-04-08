#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>

#include "../utils/log.h"

const std::string texture_path = "../textures/";

class Texture {
public:
	Texture();
	~Texture();

	bool init_png(const std::string& filename);
    bool init_jpg(const std::string& filename);
	void init_framebuffer(const glm::vec2& size);

	void bind(GLenum sampler = GL_TEXTURE0);
	void resize(const glm::vec2& size);

	int width() { return m_width; }
	int height() { return m_height; }
	int nr_channels() { return m_nr_channels;}

	GLuint texture_id() { return m_texture_id; }

	//void set_lighting(float ambient = 0.3, float reflectivity = 1.0, float shine_damper = 8);
	//float shine_damper() { return m_shine_damper; }
	//float ambient() { return m_ambient; }
	//float reflectivity() { return m_reflectivity; }

private:
	GLuint m_texture_id;
	unsigned char* m_data;
	
	int m_width;
	int m_height;
	int m_nr_channels;
	
	//float m_shine_damper;
	//float m_ambient;
	//float m_reflectivity;

	bool init(const std::string& filename, GLint internal_format);
	void setup_texture(GLint internal_format);
};

#endif //TEXTURE_H