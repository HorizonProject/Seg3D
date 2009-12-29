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

SET(QTRESOURCE_LIBRARY_LIST "" CACHE INTERNAL "list of qt resource libraries" FORCE)

MACRO(ADD_LIBRARY_QTRESOURCES library)
  SET(QTRESOURCE_LIBRARY_LIST_TEMP ${QTRESOURCE_LIBRARY_LIST} ${library})
  SET(QTRESOURCE_LIBRARY_LIST ${QTRESOURCE_LIBRARY_LIST_TEMP} CACHE INTERNAL "list of qt resource libraries")
ENDMACRO(ADD_LIBRARY_QTRESOURCES)


MACRO(BUILD_REGISTER_QTRESOURCES_LIBRARY)

  SET(QTRESOURCELIST "")
  FOREACH(QTRESOURCE ${QTRESOURCE_LIBRARY_LIST})
    GET_FILENAME_COMPONENT(QTRESOURCEFILE ${QTRESOURCE} NAME_WE)
    SET(QTRESOURCELIST ${QTRESOURCELIST} ${QTRESOURCEFILE})
  ENDFOREACH(QTRESOURCE ${QTRESOURCE_LIBRARY_LIST})
  LIST(REMOVE_DUPLICATES QTRESOURCELIST)

  SET(DECLARATIONS "")
  SET(IMPLEMENTATIONS "")

  FOREACH(QTRESOURCE ${QTRESOURCELIST})
    STRING(CONFIGURE "Q_INIT_RESOURCE(@QTRESOURCE@);\n" IMPLEMENTATION)
    SET(IMPLEMENTATIONS "${IMPLEMENTATIONS} ${IMPLEMENTATION}")
  ENDFOREACH(QTRESOURCE ${QTRESOURCELIST})
  
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/Configuration/QtResourcesLibraryInit.h.in
                 ${CMAKE_CURRENT_BINARY_DIR}/Init/QtResourcesLibraryInit.h
                 @ONLY)
                 
ENDMACRO(BUILD_REGISTER_QTRESOURCES_LIBRARY)