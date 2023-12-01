#pragma once


#include "../tas5806.h"

#include "esphome/core/component.h"
#include "esphome/components/output/float_output.h"

namespace esphome {
namespace tas5806 {


class TAS5806Volume : public Component, public output::FloatOutput {
 public:
  TAS5806Volume(TAS5806 *parent)  {
    parent_ = parent;
    parent_-> setVolume(10);
    }  
  
 protected:
  void write_state(float state) override;
  TAS5806 *parent_;
 private: 

};

}  // namespace tas5806volume
}  // namespace esphome
