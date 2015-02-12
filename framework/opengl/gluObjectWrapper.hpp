#ifndef _GLUOBJECTWRAPPER_HPP
#define _GLUOBJECTWRAPPER_HPP
/*-------------------------------------------------------------------------
 * drawElements Quality Program OpenGL ES Utilities
 * ------------------------------------------------
 *
 * Copyright 2014 The Android Open Source Project
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
 *//*!
 * \file
 * \brief API object wrapper.
 *//*--------------------------------------------------------------------*/

#include "gluDefs.hpp"
#include "gluRenderContext.hpp"
#include "glwFunctions.hpp"

#include <vector>

namespace glu
{

/*--------------------------------------------------------------------*//*!
 * \brief API object type.
 *
 * API object type is used to choose allocation and deallocation routines
 * for objects.
 *//*--------------------------------------------------------------------*/
enum ObjectType
{
	OBJECTTYPE_TEXTURE = 0,
	OBJECTTYPE_BUFFER,
	OBJECTTYPE_RENDERBUFFER,
	OBJECTTYPE_FRAMEBUFFER,
	OBJECTTYPE_TRANSFORM_FEEDBACK,
	OBJECTTYPE_VERTEX_ARRAY,
	OBJECTTYPE_QUERY,
	OBJECTTYPE_SAMPLER,

	OBJECTTYPE_LAST
};

struct ObjectTraits
{
	const char*					name;
	glw::glGenBuffersFunc		glw::Functions::*genFunc;
	glw::glDeleteBuffersFunc	glw::Functions::*deleteFunc;
};

const ObjectTraits& objectTraits (ObjectType type);

class ObjectWrapper
{
public:
							ObjectWrapper		(const glw::Functions& gl, const ObjectTraits& traits);
							ObjectWrapper		(const glw::Functions& gl, const ObjectTraits& traits, deUint32 object);
							~ObjectWrapper		(void);

	inline deUint32			get					(void) const { return m_object; }
	inline deUint32			operator*			(void) const { return m_object; }

protected:
	const glw::Functions&	m_gl;
	const ObjectTraits&		m_traits;
	deUint32				m_object;

private:
							ObjectWrapper		(const ObjectWrapper& other);
	ObjectWrapper&			operator=			(const ObjectWrapper& other);
};

/*--------------------------------------------------------------------*//*!
 * \brief API object wrapper template.
 *//*--------------------------------------------------------------------*/
template<ObjectType Type> class TypedObjectWrapper : public ObjectWrapper
{
public:
				TypedObjectWrapper (const glw::Functions& gl, deUint32 object) : ObjectWrapper(gl, objectTraits(Type), object) {}
	explicit	TypedObjectWrapper (const RenderContext& context) : ObjectWrapper(context.getFunctions(), objectTraits(Type)) {}
	explicit	TypedObjectWrapper (const glw::Functions& gl) : ObjectWrapper(gl, objectTraits(Type)) {}
};

/*--------------------------------------------------------------------*//*!
 * \brief API object vector.
 *//*--------------------------------------------------------------------*/
class ObjectVector
{
public:
										ObjectVector		(const glw::Functions& gl, const ObjectTraits& traits, size_t numObjects = 0);
										~ObjectVector		(void);

	size_t								size				(void) const		{ return m_objects.size();	}

	void								resize				(size_t newSize);
	void								clear				(void);

	bool								empty				(void) const		{ return m_objects.empty();	}

	deUint32							get					(size_t ndx) const	{ return m_objects[ndx];	}
	deUint32							operator[]			(size_t ndx) const	{ return get(ndx);			}

private:
										ObjectVector		(const ObjectVector& other);
	ObjectVector&						operator=			(const ObjectVector& other);

	const glw::Functions&				m_gl;
	const ObjectTraits&					m_traits;
	std::vector<deUint32>				m_objects;
};

template<ObjectType Type> class TypedObjectVector : public ObjectVector
{
public:
	explicit	TypedObjectVector (const RenderContext& context, size_t numObjects = 0) : ObjectVector(context.getFunctions(), objectTraits(Type), numObjects) {}
	explicit	TypedObjectVector (const glw::Functions& gl, size_t numObjects = 0) : ObjectVector(gl, objectTraits(Type), numObjects) {}
};

// Typedefs for simple wrappers without functionality.

typedef TypedObjectWrapper<OBJECTTYPE_TEXTURE>				Texture;
typedef TypedObjectWrapper<OBJECTTYPE_BUFFER>				Buffer;
typedef TypedObjectWrapper<OBJECTTYPE_RENDERBUFFER>			Renderbuffer;
typedef TypedObjectWrapper<OBJECTTYPE_FRAMEBUFFER>			Framebuffer;
typedef TypedObjectWrapper<OBJECTTYPE_TRANSFORM_FEEDBACK>	TransformFeedback;
typedef TypedObjectWrapper<OBJECTTYPE_VERTEX_ARRAY>			VertexArray;
typedef TypedObjectWrapper<OBJECTTYPE_QUERY>				Query;
typedef TypedObjectWrapper<OBJECTTYPE_SAMPLER>				Sampler;

typedef TypedObjectVector<OBJECTTYPE_TEXTURE>				TextureVector;
typedef TypedObjectVector<OBJECTTYPE_BUFFER>				BufferVector;
typedef TypedObjectVector<OBJECTTYPE_RENDERBUFFER>			RenderbufferVector;

} // glu

#endif // _GLUOBJECTWRAPPER_HPP
