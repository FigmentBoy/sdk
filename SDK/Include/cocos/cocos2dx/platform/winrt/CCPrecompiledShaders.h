/****************************************************************************
Copyright (c) 2010-2013 cocos2d-x.org
Copyright (c) Microsoft Open Technologies, Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#ifndef __CC_PRECOMPILED_SHADERS_H__
#define __CC_PRECOMPILED_SHADERS_H__

#include "platform/CCCommon.h"
#include "CCGL.h"

#include <string>
#include <vector>
#include <map>

NS_CC_BEGIN

typedef struct _PrecompiledProgram
{
    const char* key;
    const unsigned char* program;
    int    length;
} PrecompiledProgram;

typedef struct _CompiledProgram
{
    gd::string key;
    gd::vector<unsigned char> program;
    int    length;
} CompiledProgram;

#if 0

const unsigned char gKey[] = "hello";
const unsigned char gProgram[] = "world";
PrecompiledShader gFoo = {gKey, gProgram, 100};

PrecompiledShader shaders[]  = {gFoo, gFoo};
#endif

class CC_DLL CCPrecompiledShaders
{
    GEODE_ADD(friend struct geode::interfaces;)
public:
    CCPrecompiledShaders();
    virtual ~CCPrecompiledShaders();


    /**
    @brief    Get current precompiled shaders instance.
    @return Current precompiled shaders instance pointer.
    */
    static CCPrecompiledShaders* sharedPrecompiledShaders();

    gd::string addShaders(const GLchar* vShaderByteArray, const GLchar* fShaderByteArray);
    bool addProgram(GLuint program, const gd::string& id);

    bool loadProgram(GLuint program, const GLchar* vShaderByteArray, const GLchar* fShaderByteArray);


#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    void savePrecompiledShaders();
#endif

public:
    void savePrecompiledPrograms(Windows::Storage::StorageFolder^ folder);
    void loadPrecompiledPrograms();

    void                Init();

    gd::map<gd::string, CompiledProgram*> m_programs;
    gd::map<gd::string, PrecompiledProgram*> m_precompiledPrograms;
    
    bool                m_isDirty;
};

NS_CC_END

#endif    // __CC_PRECOMPILED_SHADERS_H__
