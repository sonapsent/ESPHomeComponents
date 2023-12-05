#include "tas5806.h"

#include "esphome/core/application.h"
#include "esphome/core/hal.h"
#include "esphome/core/log.h"

namespace esphome {
namespace tas5806 {

static const uint8_t TAS5806_ADDRESS = 0x2D;
static const uint8_t TAS5806_CTRL_REG = 0x03;

static const uint8_t TAS5806_CTRL_REG_HIZ = 0x02;
static const uint8_t TAS5806_CTRL_REG_PLAY = 0x03;

static const uint8_t TAS5806_VOL_REG = 0x4C;

static const uint8_t TAS5806_DEVICE_CTRL_1_REG = 0x02;

static const uint8_t DEVICE_CTRL_1_PBTL = (1) << 2;

static const uint8_t TAS5806_CONFIGURE_HIZ[2] = {TAS5806_CTRL_REG, TAS5806_CTRL_REG_HIZ};
static const uint8_t TAS5806_CONFIGURE_PLAY[2] = {TAS5806_CTRL_REG, TAS5806_CTRL_REG_PLAY};
static const uint8_t TAS5806_CONFIGURE_PBTL[2] = {TAS5806_DEVICE_CTRL_1_REG, DEVICE_CTRL_1_PBTL};

static const char *const TAG = "tas5806";

void TAS5806::dump_config() {
  ESP_LOGCONFIG(TAG, "TAS5806:");
  LOG_I2C_DEVICE(this);
  if (this->is_failed()) {
    ESP_LOGE(TAG, "Communication with TAS5806 failed!");
  }
}

void TAS5806::setup() {
  ESP_LOGCONFIG(TAG, "Setting up TAS5806 (0x%02X)...", this->address_);
  auto err = this->write(nullptr, 0);
  if (err != i2c::ERROR_OK) {
    this->mark_failed();
    return;
  }

  // Set HiZ
  if (this->write(TAS5806_CONFIGURE_HIZ, 2) != i2c::ERROR_OK) {
    this->status_set_warning();
    return;
  } else {
    ESP_LOGCONFIG(TAG, "Configured to HiZ");
  }

  // Set PBTL
  if (this->write(TAS5806_CONFIGURE_PBTL, 2) != i2c::ERROR_OK) {
    this->status_set_warning();
    return;
  } else {
    ESP_LOGCONFIG(TAG, "Set PBTL");
  }

  //Set default volume
  this->setVolume(20);

  // Set PLAY
  if (this->write(TAS5806_CONFIGURE_PLAY, 2) != i2c::ERROR_OK) {
    this->status_set_warning();
    return;
  } else {
    ESP_LOGCONFIG(TAG, "Configured to Play - Ready");
  }
}

void TAS5806::setVolume(uint8_t vol) {
  if (this->write_bytes(TAS5806_VOL_REG, &vol, 1) != i2c::ERROR_OK) {
    this->status_set_warning();
    return;
  } else {
    ESP_LOGCONFIG(TAG, "Volume set to %d", vol);
  }
}

}  // namespace tas5806
}  // namespace esphome
