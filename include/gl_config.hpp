#ifndef KRAKEN_GL_CONFIG
#define KRAKEN_GL_CONFIG

#include <array>
#include <map>
#include <string>

#include <GL/glew.h>
#include <GL/freeglut.h>

namespace kraken {

struct shader_stage {

   inline shader_stage(GLuint id,GLenum type) :
   id_(id),
   type_(type)
   {}

   GLuint id_;
   GLenum type_;
};

class gl_config {

   public :

   gl_config(std::string const& = "shader");

   void enable_program(std::string const&) const;
   void add_shader(std::string const&,GLenum);
   void add_program(std::string const&,std::array<std::string,3> const&);

   void reload_shader() const;

   private :

   bool  valid_stage(GLenum) const;
   char* load_shader(std::string const&,GLenum type) const;
   void  compile_feedback(std::string const&) const;

   std::string const shader_suffix(GLenum) const;

   std::string shader_path_;
   std::map<std::string,shader_stage> shader_store_;
   std::map<std::string,GLuint> program_store_;
};

}

#endif
