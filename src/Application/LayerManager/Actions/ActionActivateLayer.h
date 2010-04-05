/*
 For more information, please see: http://software.sci.utah.edu

 The MIT License

 Copyright (c) 2009 Scientific Computing and Imaging Institute,
 University of Utah.


 Permission is hereby granted, free of charge, to any person obtaining a
 copy of this software and associated documentation files (the "Software"),
 to deal in the Software without restriction, including without limitation
 the rights to use, copy, modify, merge, publish, distribute, sublicense,
 and/or sell copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included
 in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 DEALINGS IN THE SOFTWARE.
 */

#ifndef APPLICATION_TOOL_ACTIONS_ACTIONACTIVATELAYER_H
#define APPLICATION_TOOL_ACTIONS_ACTIONACTIVATELAYER_H

#include <Application/Action/Actions.h>
#include <Application/Interface/Interface.h>
#include <Application/Layer/Layer.h>

namespace Seg3D
{

class ActionActivateLayer : public Action
{
SCI_ACTION_TYPE("ActivateLayer", "ActivateLayer <layer_name>", ActionPropertiesType::LAYER_E)

  // -- Constructor/Destructor --
public:
  ActionActivateLayer()
  {
    add_argument( this->layer_name_ );
  }

  virtual ~ActionActivateLayer()
  {
  }

  // -- Functions that describe action --
public:
  virtual bool validate( ActionContextHandle& context );
  virtual bool run( ActionContextHandle& context, ActionResultHandle& result );
  
  
  // -- Dispatch this action from the interface --
public:

  // DISPATCH
  // Dispatch an action that activates a layer
  static void Dispatch( const LayerHandle layer );
  
  // CREATE
  // Create an action that activates a layer
  static ActionHandle Create( const LayerHandle layer );
  
private:
  ActionParameter< std::string > layer_name_;
    LayerWeakHandle layer_weak_handle_;

};

} // end namespace Seg3D

#endif