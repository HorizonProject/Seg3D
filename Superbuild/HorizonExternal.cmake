#  For more information, please see: http://software.sci.utah.edu
# 
#  The MIT License
# 
#  Copyright (c) 2015 Scientific Computing and Imaging Institute,
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

SET_PROPERTY(DIRECTORY PROPERTY "EP_BASE" ${ep_base})

SET(horizon_GIT_URL "https://aylakhan@bitbucket.org/gveni/horizonsegmentation.git")
SET(horizon_GIT_TAG "master")

SET(horizon_DIR "${SEG3D_SOURCE_DIR}/Plugins/horizonsegmentation")
IF(EXISTS ${horizon_DIR})
  MESSAGE(FATAL_ERROR "Cannot clone horizon repository. ${horizon_DIR} already exists.")
ENDIF()

# If CMake ever allows overriding the checkout command or adding flags,
# git checkout -q will silence message about detached head (harmless).
ExternalProject_Add(Horizon_external
  GIT_REPOSITORY ${horizon_GIT_URL}
  GIT_TAG ${horizon_GIT_TAG}
  SOURCE_DIR ${horizon_DIR}
  BUILD_COMMAND ""
  CONFIGURE_COMMAND ""
  PATCH_COMMAND ""
  INSTALL_COMMAND ""
)
