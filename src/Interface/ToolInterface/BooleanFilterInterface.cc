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



#include "BooleanFilterInterface.h"
#include "ui_BooleanFilterInterface.h"


namespace Seg3D {
  
  SCI_REGISTER_TOOLINTERFACE(BooleanFilterInterface)
  
  class BooleanFilterInterfacePrivate {
  public:
    Ui::BooleanFilterInterface ui_;
  };
  
  BooleanFilterInterface::BooleanFilterInterface() :
  private_(new BooleanFilterInterfacePrivate)
  {
    
  }
  
  BooleanFilterInterface::~BooleanFilterInterface()
  {
  }
  
  
  bool
  BooleanFilterInterface::build_widget(QFrame* frame)
  {
    private_->ui_.setupUi(frame);
    SCI_LOG_DEBUG("Finished Building an Median Interface Filter");
    
//    radiusSizeAdjuster = new SliderSpinCombo();
//    private_->ui_.radiusHLayout_bottom->addWidget(radiusSizeAdjuster);
    
    return (true);
    
  }
  
  //  --- Function for making signal slots connections ---  //
  void 
  BooleanFilterInterface::makeConnections()
  {
    //connect(private_->ui_.activeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(senseActiveChanged(int)));
    connect(radiusSizeAdjuster, SIGNAL(valueAdjusted(double)), this, SLOT(senseRadiusSizeChanged(double)));
  }
  
  
  //  --- Private slots for custom signals ---  //
  void BooleanFilterInterface::senseActiveChanged(int active)
  {
    Q_EMIT activeChanged(active);
  }
  
  
  //  --- Public slots for setting widget values ---  //
  void BooleanFilterInterface::setActive(int active)
  {
    //private_->ui_.activeComboBox->setCurrentIndex(active);
  }
  
  void BooleanFilterInterface::addToActive(QStringList &items)
  {
    //private_->ui_.activeComboBox->addItems(items);
  }
  

  
  
} // namespace Seg3D