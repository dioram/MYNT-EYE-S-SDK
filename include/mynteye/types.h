// Copyright 2018 Slightech Co., Ltd. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef MYNTEYE_TYPES_H_
#define MYNTEYE_TYPES_H_
#pragma once

#include <memory.h>

#include <cstdint>

#include <algorithm>
#include <iostream>
#include <type_traits>

#include "mynteye/mynteye.h"

MYNTEYE_BEGIN_NAMESPACE

/**
 * @defgroup enumerations Enumerations
 * @brief Public enumeration types.
 */

/**
 * @ingroup enumerations
 * @brief Device model.
 */
enum class Model : std::uint8_t {
  /** Standard */
  STANDARD,
  /** Standard 2 */
  STANDARD2,
  /** Standard 210a */
  STANDARD210A,
  /** Last guard */
  LAST
};

/**
 * @ingroup enumerations
 * @brief Streams define different type of data.
 */
enum class Stream : std::uint8_t {
  /** Left stream */
  LEFT,
  /** Right stream */
  RIGHT,
  /** Left stream, rectified */
  LEFT_RECTIFIED,
  /** Right stream, rectified */
  RIGHT_RECTIFIED,
  /** Disparity stream */
  DISPARITY,
  /** Disparity stream, normalized */
  DISPARITY_NORMALIZED,
  /** Depth stream */
  DEPTH,
  /** Point cloud stream */
  POINTS,
  /** Last guard */
  LAST
};

/**
 * @ingroup enumerations
 * @brief Capabilities define the full set of functionality that the device
 * might provide.
 */
enum class Capabilities : std::uint8_t {
  /** Provides stereo stream */
  STEREO,
  /** Provide stereo color stream */
  STEREO_COLOR,
  /** Provides color stream */
  COLOR,
  /** Provides depth stream */
  DEPTH,
  /** Provides point cloud stream */
  POINTS,
  /** Provides fisheye stream */
  FISHEYE,
  /** Provides infrared stream */
  INFRARED,
  /** Provides second infrared stream */
  INFRARED2,
  /** Provides IMU (accelerometer, gyroscope) data */
  IMU,
  /** Last guard */
  LAST
};

/**
 * @ingroup enumerations
 * @brief Camera info fields are read-only strings that can be queried from the
 * device.
 */
enum class Info : std::uint8_t {
  /** Device name */
  DEVICE_NAME,
  /** Serial number */
  SERIAL_NUMBER,
  /** Firmware version */
  FIRMWARE_VERSION,
  /** Hardware version */
  HARDWARE_VERSION,
  /** Spec version */
  SPEC_VERSION,
  /** Lens type */
  LENS_TYPE,
  /** IMU type */
  IMU_TYPE,
  /** Nominal baseline */
  NOMINAL_BASELINE,
  /** Last guard */
  LAST
};

/**
 * @ingroup enumerations
 * @brief Camera control options define general configuration controls.
 */
enum class Option : std::uint8_t {
  /**
   * Image gain, valid if manual-exposure
   *
   *   range: [0,48], default: 24
   */
  GAIN,
  /**
   * Image brightness, valid if manual-exposure
   *
   *   range: [0,240], default: 120
   */
  BRIGHTNESS,
  /**
   * Image contrast, valid if manual-exposure
   *
   *   range: [0,255], default: 127
   */
  CONTRAST,

  /**
   * Image frame rate, must set IMU_FREQUENCY together
   *
   *   values: {10,15,20,25,30,35,40,45,50,55,60}, default: 25
   */
  FRAME_RATE,
  /**
   * IMU frequency, must set FRAME_RATE together
   *
   *   values: {100,200,250,333,500}, default: 200
   */
  IMU_FREQUENCY,

  /**
   * Exposure mode
   *
   *   0: enable auto-exposure
   *   1: disable auto-exposure (manual-exposure)
   */
  EXPOSURE_MODE,
  /**
   * Max gain, valid if auto-exposure
   *
   *   range of standard 1: [0,48], default: 48
   *   range of standard 2: [0,255], default: 8
   */
  MAX_GAIN,
  /**
   * Max exposure time, valid if auto-exposure
   *
   *   range of standard 1: [0,240], default: 240
   *   range of standard 2: [0,1000], default: 333
   */
  MAX_EXPOSURE_TIME,
  /**
   * min exposure time, valid if auto-exposure
   *
   *   range: [0,1000], default: 0
   */
  MIN_EXPOSURE_TIME,
  /**
   * Desired brightness, valid if auto-exposure
   *
   *   range of standard 1: [0,255], default: 192
   *   range of standard 2: [1,255], default: 122
   */
  DESIRED_BRIGHTNESS,

  /**
   * IR control
   *
   *   range: [0,160], default: 0
   */
  IR_CONTROL,
  /**
   * HDR mode
   *
   *   0: 10-bit
   *   1: 12-bit
   */
  HDR_MODE,

  /**
   * The range of accelerometer
   *
   *   value of standard 1: {4,8,16,32}, default: 8
   *   value of standard 2: {6,12,24,48}, default: 12
   */
  ACCELEROMETER_RANGE,
  /**
   * The range of gyroscope
   *
   *   value of standard 1: {500,1000,2000,4000}, default: 1000
   *   value of standard 2: {250,500,1000,2000,4000}, default: 1000
   */
  GYROSCOPE_RANGE,
  /**
   * The parameter of accelerometer low pass filter
   *
   *   values: {0,1,2}, default: 2
   */
  ACCELEROMETER_LOW_PASS_FILTER,
  /**
   * The parameter of gyroscope low pass filter
   *
   *   values: {23,64}, default: 64
   */
  GYROSCOPE_LOW_PASS_FILTER,

  /** Zero drift calibration */
  ZERO_DRIFT_CALIBRATION,
  /** Erase chip */
  ERASE_CHIP,

  /** Last guard */
  LAST
};

/**
 * @ingroup enumerations
 * @brief Source allows the user to choose which data to be captured.
 */
enum class Source : std::uint8_t {
  /** Video streaming of stereo, color, depth, etc. */
  VIDEO_STREAMING,
  /** Motion tracking of IMU (accelerometer, gyroscope) */
  MOTION_TRACKING,
  /** Enable everything together */
  ALL,
  /** Last guard */
  LAST
};

/**
 * @ingroup enumerations
 * @brief Add-Ons are peripheral modules of our hardware.
 */
enum class AddOns : std::uint8_t {
  /** Infrared */
  INFRARED,
  /** Second infrared */
  INFRARED2,
  /** Last guard */
  LAST
};

#define MYNTEYE_ENUM_HELPERS(TYPE)                                       \
  MYNTEYE_API const char *to_string(const TYPE &value);                  \
  inline bool is_valid(const TYPE &value) {                              \
    using utype = std::underlying_type<TYPE>::type;                      \
    utype val = static_cast<utype>(value);                               \
    utype max = static_cast<utype>(TYPE::LAST);                          \
    return /*val >= 0 &&*/ val < max;                                    \
  }                                                                      \
  inline std::ostream &operator<<(std::ostream &os, const TYPE &value) { \
    using utype = std::underlying_type<TYPE>::type;                      \
    if (is_valid(value))                                                 \
      return os << to_string(value);                                     \
    else                                                                 \
      return os << static_cast<utype>(value);                            \
  }

MYNTEYE_ENUM_HELPERS(Model)
MYNTEYE_ENUM_HELPERS(Stream)
MYNTEYE_ENUM_HELPERS(Capabilities)
MYNTEYE_ENUM_HELPERS(Info)
MYNTEYE_ENUM_HELPERS(Option)
MYNTEYE_ENUM_HELPERS(Source)
MYNTEYE_ENUM_HELPERS(AddOns)

#undef MYNTEYE_ENUM_HELPERS

#define MYNTEYE_FOURCC(a, b, c, d)                  \
  ((std::uint32_t)(a) | ((std::uint32_t)(b) << 8) | \
   ((std::uint32_t)(c) << 16) | ((std::uint32_t)(d) << 24))  // NOLINT

/**
 * @ingroup enumerations
 * @brief Formats define how each stream can be encoded.
 */
enum class Format : std::uint32_t {
  /** Greyscale, 8 bits per pixel */
  GREY = MYNTEYE_FOURCC('G', 'R', 'E', 'Y'),
  /** YUV 4:2:2, 16 bits per pixel */
  YUYV = MYNTEYE_FOURCC('Y', 'U', 'Y', 'V'),
  /** BGR 8:8:8, 24 bits per pixel */
  BGR888 = MYNTEYE_FOURCC('B', 'G', 'R', '3'),
  /** RGB 8:8:8, 24 bits per pixel */
  RGB888 = MYNTEYE_FOURCC('R', 'G', 'B', '3'),
  /** Last guard */
  LAST
};

#undef MYNTEYE_FOURCC

MYNTEYE_API const char *to_string(const Format &value);

inline std::ostream &operator<<(std::ostream &os, const Format &value) {
  return os << to_string(value);
}

MYNTEYE_API std::size_t bytes_per_pixel(const Format &value);

/**
 * Resolution.
 */
struct MYNTEYE_API Resolution {
  /** Width */
  std::uint16_t width;
  /** Height */
  std::uint16_t height;

  bool operator==(const Resolution &other) const {
    return width == other.width && height == other.height;
  }
  bool operator!=(const Resolution &other) const {
    return !(*this == other);
  }
  bool operator<(const Resolution &other) const {
    return (width * height) < (other.width * other.height);
  }
};

/**
 * Stream request.
 */
struct MYNTEYE_API StreamRequest {
  /** Stream width in pixels */
  std::uint16_t width;
  /** Stream height in pixels */
  std::uint16_t height;
  /** Stream pixel format */
  Format format;
  /** Stream frames per second */
  std::uint16_t fps;

  StreamRequest() {}

  StreamRequest(
      std::uint16_t width, std::uint16_t height, Format format,
      std::uint16_t fps)
      : width(width), height(height), format(format), fps(fps) {}

  StreamRequest(const Resolution &res, Format format, std::uint16_t fps)
      : width(res.width), height(res.height), format(format), fps(fps) {}

  Resolution GetResolution() const { return {width, height}; }

  bool operator==(const StreamRequest &other) const {
    return width == other.width && height == other.height &&
           format == other.format && fps == other.fps;
  }
  bool operator!=(const StreamRequest &other) const {
    return !(*this == other);
  }
};

MYNTEYE_API
std::ostream &operator<<(std::ostream &os, const StreamRequest &request);

/**
 * @defgroup calibration Intrinsics & Extrinsics
 * @brief Intrinsic and extrinsic properties.
 */

/** different model of camera calibration */
typedef enum CalibrationModel {
  /** pinhole camera */
  CALIB_MODEL_PINHOLE = 0,
  /** equidistant camera */
  CALIB_MODEL_KANNALA_BRANDT = 1,

  CALIB_MODEL_UNKNOW,
  // CALIB_MODEL_SCARAMUZZA,
  // CALIB_MODEL_MEI
}CALIB_MODEL;

/**
 * @ingroup calibration
 * Stream intrinsics,
 */
struct MYNTEYE_API IntrinsicsBase {
  IntrinsicsBase() {
    calib_model_ = CALIB_MODEL_UNKNOW;
  }
  CALIB_MODEL calib_model_;
};

struct MYNTEYE_API Intrinsics : public IntrinsicsBase {
  Intrinsics() {
    calib_model_ = CALIB_MODEL_PINHOLE;
  }
  /** The width of the image in pixels */
  std::uint16_t width;
  /** The height of the image in pixels */
  std::uint16_t height;
  /** The focal length of the image plane, as a multiple of pixel width */
  double fx;
  /** The focal length of the image plane, as a multiple of pixel height */
  double fy;
  /** The horizontal coordinate of the principal point of the image */
  double cx;
  /** The vertical coordinate of the principal point of the image */
  double cy;
  /** The distortion model of the image */
  std::uint8_t model;
  /** The distortion coefficients: k1,k2,p1,p2,k3 */
  double coeffs[5];
};

/*
model_type:  KANNALA_BRANDT
camera_name: KANNALA_BRANDT
image_width: 640
image_height: 400
projection_parameters:
k2: 4.9972342319338209e-01
k3: 4.3314206872885375e-01
k4: -9.2064699153680563e-01
k5: 4.1211925379358533e-01
mu: 2.0077513040612871e+02
mv: 2.0099851605062454e+02
u0: 3.1079403134153824e+02
v0: 2.1225649273618896e+02 
*/

struct MYNTEYE_API Intrinsics2 : public IntrinsicsBase {
  Intrinsics2() {
    calib_model_ = CALIB_MODEL_KANNALA_BRANDT;
  }
  /** The width of the image in pixels */
  std::uint16_t width;
  /** The height of the image in pixels */
  std::uint16_t height;
  /** The distortion coefficients */
  double k2;
  double k3;
  double k4;
  double k5;
  double mu;
  double mv;
  double u0;
  double v0;
};

// union MYNTEYE_API CameraParameters {
//   struct IntrinsicsBase intrinsics_base;
//   struct Intrinsics intrinsics10;
//   struct Intrinsics2 intrinsics20;
//   unsigned char raw[];
//   CameraParameters(struct IntrinsicsBase& base) {
//     memset(raw, 0, sizeof(union CameraParameters));
//     switch (base.calib_model_) {
//       case CALIB_MODEL_10:
//         intrinsics10 = static_cast<struct Intrinsics&>(base);
//       break;
//       case CALIB_MODEL_20:
//         intrinsics20 = static_cast<struct Intrinsics2&>(base);
//       break;
//       default:
//         // warning!!! no impl!!!
//         intrinsics_base = base;
//       return;
//     }
//   }
//   CALIB_MODEL getModelType() {return intrinsics_base.calib_model_;}
// };
// MYNTEYE_API
// std::ostream &operator<<(std::ostream &os, const CameraParameters &in);

MYNTEYE_API
std::ostream &operator<<(std::ostream &os, const Intrinsics &in);

/**
 * @ingroup calibration
 * IMU intrinsics: scale, drift and variances.
 */
struct MYNTEYE_API ImuIntrinsics {
  /**
   * Scale matrix.
   * \code
   *   Scale X     cross axis  cross axis
   *   cross axis  Scale Y     cross axis
   *   cross axis  cross axis  Scale Z
   * \endcode
   */
  double scale[3][3];
  /* Zero-drift: X, Y, Z */
  double drift[3];

  /** Noise density variances */
  double noise[3];
  /** Random walk variances */
  double bias[3];
};

MYNTEYE_API
std::ostream &operator<<(std::ostream &os, const ImuIntrinsics &in);

/**
 * @ingroup calibration
 * Motion intrinsics, including accelerometer and gyroscope.
 */
struct MYNTEYE_API MotionIntrinsics {
  ImuIntrinsics accel; /**< Accelerometer intrinsics */
  ImuIntrinsics gyro;  /**< Gyroscope intrinsics */
};

MYNTEYE_API
std::ostream &operator<<(std::ostream &os, const MotionIntrinsics &in);

/**
 * @ingroup calibration
 * Extrinsics, represent how the different datas are connected.
 */
struct MYNTEYE_API Extrinsics {
  double rotation[3][3]; /**< Rotation matrix */
  double translation[3]; /**< Translation vector */

  /**
   * Inverse this extrinsics.
   * @return the inversed extrinsics.
   */
  Extrinsics Inverse() const {
    return {{{rotation[0][0], rotation[1][0], rotation[2][0]},
             {rotation[0][1], rotation[1][1], rotation[2][1]},
             {rotation[0][2], rotation[1][2], rotation[2][2]}},
            {-translation[0], -translation[1], -translation[2]}};
  }
};

MYNTEYE_API
std::ostream &operator<<(std::ostream &os, const Extrinsics &ex);

/**
 * @defgroup datatypes Datatypes
 * @brief Public data types.
 */

/**
 * @ingroup datatypes
 * Image data.
 */
struct MYNTEYE_API ImgData {
  /** Image frame id */
  std::uint16_t frame_id;
  /** Image timestamp in 1us */
  std::uint64_t timestamp;
  /** Image exposure time, virtual value in [1, 480] */
  std::uint16_t exposure_time;

  void Reset() {
    frame_id = 0;
    timestamp = 0;
    exposure_time = 0;
  }

  ImgData() {
    Reset();
  }
  ImgData(const ImgData &other) {
    frame_id = other.frame_id;
    timestamp = other.timestamp;
    exposure_time = other.exposure_time;
  }
  ImgData &operator=(const ImgData &other) {
    frame_id = other.frame_id;
    timestamp = other.timestamp;
    exposure_time = other.exposure_time;
    return *this;
  }
};

/**
 * @ingroup datatypes
 * IMU data.
 */
struct MYNTEYE_API ImuData {
  /** IMU frame id */
  std::uint32_t frame_id;
  /**
   * IMU accel or gyro flag
   *
   *   0: accel and gyro are both valid
   *   1: accel is valid
   *   2: gyro is valid
   */
  std::uint8_t flag;
  /** IMU timestamp in 1us */
  std::uint64_t timestamp;
  /** IMU accelerometer data for 3-axis: X, Y, Z. */
  double accel[3];
  /** IMU gyroscope data for 3-axis: X, Y, Z. */
  double gyro[3];
  /** IMU temperature */
  double temperature;

  void Reset() {
    flag = 0;
    timestamp = 0;
    std::fill(accel, accel + 3, 0);
    std::fill(gyro, gyro + 3, 0);
    temperature = 0;
  }

  ImuData() {
    Reset();
  }
};

/**
 * @ingroup datatypes
 * Option info.
 */
struct MYNTEYE_API OptionInfo {
  /** Minimum value */
  std::int32_t min;
  /** Maximum value */
  std::int32_t max;
  /** Default value */
  std::int32_t def;
};

MYNTEYE_API
std::ostream &operator<<(std::ostream &os, const OptionInfo &info);

MYNTEYE_END_NAMESPACE

#endif  // MYNTEYE_TYPES_H_
