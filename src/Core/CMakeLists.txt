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

ADD_SUBDIRECTORY(Action)
ADD_SUBDIRECTORY(Application)
ADD_SUBDIRECTORY(DataBlock)
ADD_SUBDIRECTORY(EventHandler)
ADD_SUBDIRECTORY(Geometry)
ADD_SUBDIRECTORY(Interface)
ADD_SUBDIRECTORY(Isosurface)
ADD_SUBDIRECTORY(LargeVolume)
ADD_SUBDIRECTORY(Log)
ADD_SUBDIRECTORY(Parser)
ADD_SUBDIRECTORY(State)
ADD_SUBDIRECTORY(TextRenderer)
ADD_SUBDIRECTORY(Utils)
ADD_SUBDIRECTORY(Viewer)
ADD_SUBDIRECTORY(Volume)

# These next three depend on OpenGL and should only be compiled when the renderer is compiled
ADD_SUBDIRECTORY(Graphics)
ADD_SUBDIRECTORY(RenderResources)
ADD_SUBDIRECTORY(Renderer)
ADD_SUBDIRECTORY(VolumeRenderer)

IF(BUILD_MOSAIC_TOOLS)
  ADD_SUBDIRECTORY(ITKCommon)
ENDIF()

IF(BUILD_WITH_PYTHON)
  ADD_SUBDIRECTORY(Python)
ENDIF()
