
#
#  For more information, please see: http://software.sci.utah.edu
# 
#  The MIT License
# 
#  Copyright (c) 2009 Scientific Computing and Imaging Institute,
#  University of Utah.
# 
#  
#  Permission is hereby granted, free of charge, to any person obtaining a
#  copy of this software and associated documentation files (the "Software"),
#  to deal in the Software without restriction, including without limitation
#  the rights to use, copy, modify, merge, publish, distribute, sublicense,
#  and/or sell copies of the Software, and to permit persons to whom the
#  Software is furnished to do so, subject to the following conditions:
# 
#  The above copyright notice and this permission notice shall be included
#  in all copies or substantial portions of the Software. 
# 
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
#  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
#  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
#  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
#  DEALINGS IN THE SOFTWARE.
#

##################################################
# Import shaders into source files
##################################################

SET(APPLICATION_RENDERER_SHADER_SRCS
  Lighting.vert
  Lighting.frag
  Fog.vert
  Fog.frag
  SliceShader.frag
  SliceShader.vert
  IsosurfaceShader.frag
  IsosurfaceShader.vert
  OrientationArrowsShader.vert
  OrientationArrowsShader.frag
  )
  
CORE_IMPORT_SHADER(APPLICATION_RENDERER_SHADER_STRING_SRCS
          ${APPLICATION_RENDERER_SHADER_SRCS})
          
##################################################
# Set sources
##################################################

SET(APPLICATION_RENDERER_SRCS
  Renderer.h
  Renderer.cc
  SliceShader.h
  SliceShader.cc
  IsosurfaceShader.h
  IsosurfaceShader.cc
  OrientationArrows.h
  OrientationArrows.cc
  OrientationArrowsShader.h
  OrientationArrowsShader.cc
  )
  
CORE_ADD_LIBRARY(Application_Renderer ${APPLICATION_RENDERER_SRCS}
      ${APPLICATION_RENDERER_SHADER_SRCS}
      ${APPLICATION_RENDERER_SHADER_STRING_SRCS})
            
TARGET_LINK_LIBRARIES(Application_Renderer
                      Core_Utils
                      Core_EventHandler
            Core_TextRenderer
            Core_Graphics
            Core_RenderResources
            Core_Renderer
            Core_VolumeRenderer
                      Application_Viewer
                      ${SCI_GLEW_LIBRARY}
                      ${SCI_BOOST_LIBRARY})

