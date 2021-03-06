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

// Teem includes
#include <teem/nrrd.h>

// Core includes
#include <Core/DataBlock/NrrdDataBlock.h>
#include <Core/DataBlock/DataBlockManager.h>

namespace Core
{


class NrrdDataBlockPrivate : public boost::noncopyable
{
public:
  // Location where the original nrrd is stored
  NrrdDataHandle nrrd_data_;
};


NrrdDataBlock::NrrdDataBlock( NrrdDataHandle nrrd_data ) :
  private_( new NrrdDataBlockPrivate )
{
  this->private_->nrrd_data_ = nrrd_data;

  set_nx( nrrd_data->get_nx() );
  set_ny( nrrd_data->get_ny() );
  set_nz( nrrd_data->get_nz() );
  set_type( nrrd_data->get_data_type() );
  set_data( nrrd_data->get_data() );
}

NrrdDataBlock::~NrrdDataBlock()
{
}

DataBlockHandle NrrdDataBlock::New( NrrdDataHandle nrrd_data )
{
  try
  {
    DataBlockHandle data_block( new NrrdDataBlock( nrrd_data ) );
    return data_block;
  }
  catch ( ... )
  {
    // Return an empty handle
    DataBlockHandle data_block;
    return data_block;
  } 
}



} // end namespace Core
