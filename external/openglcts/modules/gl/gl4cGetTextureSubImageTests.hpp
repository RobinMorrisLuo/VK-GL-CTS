#ifndef _GL4CGETTEXTURESUBIMAGETESTS_HPP
#define _GL4CGETTEXTURESUBIMAGETESTS_HPP
/*-------------------------------------------------------------------------
 * OpenGL Conformance Test Suite
 * -----------------------------
 *
 * Copyright (c) 2015-2016 The Khronos Group Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */ /*!
 * \file
 * \brief
 */ /*-------------------------------------------------------------------*/

/**
 */ /*!
 * \file  gl4cGetTextureSubImageTests.hpp
 * \brief Get Texture Sub Image Tests Suite Interface
 */ /*-------------------------------------------------------------------*/

/* Includes. */

#include "glcTestCase.hpp"
#include "glwDefs.hpp"
#include "tcuDefs.hpp"

#include "glwEnums.hpp"
#include "glwFunctions.hpp"

/* Interface. */

namespace gl4cts
{
namespace GetTextureSubImage
{
/** Tests group for GetTextureSubImage tests.
 *
 *  Following tests will be run:
 *  -   Errors Test
 *  -   Functional Test
 */
class Tests : public deqp::TestCaseGroup
{
public:
    Tests(deqp::Context &context);
    ~Tests(void);
    virtual void init(void);

private:
    /* Private member functions. */
    Tests(const Tests &other);
    Tests &operator=(const Tests &other);
};
/* Tests class. */

/** Error Generation Tests
 *
 *  The Errors test verifies that functions glGetTextureSubImage and
 *  glGetCompressedTextureSubImage generate proper error values if used
 *  improperly. For reference see OpenGL 4.5 Core Specification chapter
 *  8.11.4.

 *  *   Check that GL_INVALID_VALUE error is generated by
 *      glGetTextureSubImage if texture is not the name of an existing
 *      texture object.
 *
 *  *   Check that GL_INVALID_VALUE error is generated by
 *      glGetCompressedTextureSubImage if texture is not the name
 *      of an existingtexture object.
 *
 *  *   Check that GL_INVALID_OPERATION error is generated if texture is the
 *      name of a buffer or multisample texture.
 *
 *  *   Check that GL_INVALID_VALUE is generated if xoffset, yoffset or
 *      zoffset are negative.
 *
 *  *   Check that GL_INVALID_VALUE is generated if xoffset + width is
 *      greater than the texture's width, yoffset + height is greater than
 *      the texture's height, or zoffset + depth is greater than the
 *      texture's depth.
 *
 *  *   Check that GL_INVALID_VALUE error is generated if the effective
 *      target is GL_TEXTURE_1D and either yoffset is not zero, or height
 *      is not one.
 *
 *  *   Check that GL_INVALID_VALUE error is generated if the effective
 *      target is GL_TEXTURE_1D, GL_TEXTURE_1D_ARRAY, GL_TEXTURE_2D or
 *      GL_TEXTURE_RECTANGLE and either zoffset is not zero, or depth
 *      is not one.
 *
 *  *   Check that GL_INVALID_OPERATION error is generated if the buffer
 *      size required to store the requested data is greater than bufSize.
 */
class Errors : public deqp::TestCase
{
public:
    Errors(deqp::Context &context);
    ~Errors(void);
    IterateResult iterate(void);

private:
    /* Private member variables. */
    deqp::Context &m_context;
    glw::GLuint m_texture_1D;
    glw::GLuint m_texture_1D_array;
    glw::GLuint m_texture_2D;
    glw::GLuint m_texture_rectangle;
    glw::GLuint m_texture_2D_compressed;
    glw::GLuint m_texture_2D_multisampled;
    glw::GLubyte *m_destination_buffer;

    /* Get(Compressed)TextureSubImage function pointer and type declarations. */
    typedef void(GLW_APIENTRY *PFNGLGETTEXTURESUBIMAGEPROC)(glw::GLuint texture, glw::GLint level, glw::GLint xoffset,
                                                            glw::GLint yoffset, glw::GLint zoffset, glw::GLsizei width,
                                                            glw::GLsizei height, glw::GLsizei depth, glw::GLenum format,
                                                            glw::GLenum type, glw::GLsizei bufSize, void *pixels);

    typedef void(GLW_APIENTRY *PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)(glw::GLuint texture, glw::GLint level,
                                                                      glw::GLint xoffset, glw::GLint yoffset,
                                                                      glw::GLint zoffset, glw::GLsizei width,
                                                                      glw::GLsizei height, glw::GLsizei depth,
                                                                      glw::GLsizei bufSize, void *pixels);

    PFNGLGETTEXTURESUBIMAGEPROC m_gl_GetTextureSubImage;
    PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC m_gl_GetCompressedTextureSubImage;

    /* Private member functions. */
    void prepare();

    bool testExistingTextureObjectError();

    bool testBufferOrMultisampledTargetError();

    bool testNegativeOffsetError();

    bool testBoundsError();

    bool testOneDimmensionalTextureErrors();

    bool testTwoDimmensionalTextureErrors();

    bool testBufferSizeError();

    void clean();

    /* Private static constants. */
    static const glw::GLubyte s_texture_data[];
    static const glw::GLuint s_texture_data_size;
    static const glw::GLuint s_texture_data_width;
    static const glw::GLuint s_texture_data_height;

    static const glw::GLubyte s_texture_data_compressed[];
    static const glw::GLuint s_texture_data_compressed_size;
    static const glw::GLuint s_texture_data_compressed_width;
    static const glw::GLuint s_texture_data_compressed_height;

    static const glw::GLuint s_destination_buffer_size;
};
/* Errors class. */

/** Functional
 *
 *  The Functional test verifies that functions glGetTextureSubImage and
 *  glGetCompressedTextureSubImage works properly. The whole test shall be
 *  constructed as follows:
 *
 *      for each tested function
 *          for each supported texture target
 *              prepare and upload texture
 *              download texture using the function
 *              compare uploaded texture with downloaded texture
 *              clean up
 *
 *  where:
 *  *   tested functions are:
 *      - GetTextureSubImage,
 *      - GetCompressedTextureSubImage;
 *  *   supported uncompressed texture targets are:
 *      - GL_TEXTURE_1D,
 *      - GL_TEXTURE_1D_ARRAY,
 *      - GL_TEXTURE_2D,
 *      - GL_TEXTURE_2D_ARRAY,
 *      - GL_TEXTURE_3D,
 *      - GL_TEXTURE_CUBE_MAP,
 *      - GL_TEXTURE_CUBE_MAP_ARRAY,
 *      - GL_TEXTURE_RECTANGLE;
 *  *   supported compressed texture targets are:
 *      - GL_TEXTURE_2D,
 *      - GL_TEXTURE_2D_ARRAY,
 *      - GL_TEXTURE_CUBE_MAP,
 *      - GL_TEXTURE_CUBE_MAP_ARRAY;
 *  *   texture internal format shall be GL_RGBA8 and
 *      GL_COMPRESSED_RGB8_ETC2;
 *  *   use linear dimmension of texture equal to 8;
 *  *   use offset of 4 (if dimmension is available);
 *  *   use width/height/depth of 4 (if dimmension is available).
 */
class Functional : public deqp::TestCase
{
public:
    Functional(deqp::Context &context);
    ~Functional(void);
    IterateResult iterate(void);

private:
    /* Private member variables. */
    deqp::Context &m_context;
    glw::GLuint m_texture;

    /* Private member functions. */
    void prepare(glw::GLenum target, bool is_compressed);
    bool check(glw::GLenum target, bool is_compressed);
    void clean();

    /* Get(Compressed)TextureSubImage function pointer and type declarations. */
    typedef void(GLW_APIENTRY *PFNGLGETTEXTURESUBIMAGEPROC)(glw::GLuint texture, glw::GLint level, glw::GLint xoffset,
                                                            glw::GLint yoffset, glw::GLint zoffset, glw::GLsizei width,
                                                            glw::GLsizei height, glw::GLsizei depth, glw::GLenum format,
                                                            glw::GLenum type, glw::GLsizei bufSize, void *pixels);

    typedef void(GLW_APIENTRY *PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)(glw::GLuint texture, glw::GLint level,
                                                                      glw::GLint xoffset, glw::GLint yoffset,
                                                                      glw::GLint zoffset, glw::GLsizei width,
                                                                      glw::GLsizei height, glw::GLsizei depth,
                                                                      glw::GLsizei bufSize, void *pixels);

    PFNGLGETTEXTURESUBIMAGEPROC m_gl_GetTextureSubImage;
    PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC m_gl_GetCompressedTextureSubImage;

    /* Static constants. */
    static const glw::GLubyte s_texture_data[];
    static const glw::GLsizei s_texture_data_size;
    static const glw::GLsizei s_texture_data_width;
    static const glw::GLsizei s_texture_data_height;
    static const glw::GLsizei s_texture_data_depth;

    static const glw::GLubyte s_texture_data_compressed[];
    static const glw::GLsizei s_texture_data_compressed_size;
};

/* Functional class */
} /* namespace GetTextureSubImage */
} /* namespace gl4cts */

#endif // _GL4CGETTEXTURESUBIMAGETESTS_HPP
