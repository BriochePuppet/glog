#
# Copyright (C) YuqiaoZhang(HanetakaChou)
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#

# https://developer.android.com/ndk/guides/android_mk

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := glog

LOCAL_SRC_FILES := \
	$(LOCAL_PATH)/../src/demangle.cc \
	$(LOCAL_PATH)/../src/flags.cc \
	$(LOCAL_PATH)/../src/logging.cc \
	$(LOCAL_PATH)/../src/raw_logging.cc \
	$(LOCAL_PATH)/../src/signalhandler.cc \
	$(LOCAL_PATH)/../src/stacktrace.cc \
	$(LOCAL_PATH)/../src/symbolize.cc \
	$(LOCAL_PATH)/../src/utilities.cc \
	$(LOCAL_PATH)/../src/vlog_is_on.cc

LOCAL_CFLAGS :=

ifeq (armeabi-v7a,$(TARGET_ARCH_ABI))
LOCAL_ARM_MODE := arm
LOCAL_ARM_NEON := true
else ifeq (arm64-v8a,$(TARGET_ARCH_ABI))
LOCAL_CFLAGS +=
else ifeq (x86,$(TARGET_ARCH_ABI))
LOCAL_CFLAGS += -mf16c
LOCAL_CFLAGS += -mfma
LOCAL_CFLAGS += -mavx2
else ifeq (x86_64,$(TARGET_ARCH_ABI))
LOCAL_CFLAGS += -mf16c
LOCAL_CFLAGS += -mfma
LOCAL_CFLAGS += -mavx2
else
LOCAL_CFLAGS +=
endif

LOCAL_CFLAGS += -Wall
LOCAL_CFLAGS += -Werror=return-type

LOCAL_CFLAGS += -DGLOG_USE_GLOG_EXPORT=1
LOCAL_CFLAGS += -DGLOG_NO_ABBREVIATED_SEVERITIES=1
LOCAL_CFLAGS += -DGLOG_NO_SYMBOLIZE_DETECTION=1
LOCAL_CFLAGS += -DGOOGLE_GLOG_IS_A_DLL=1

LOCAL_C_INCLUDES :=
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../src

LOCAL_CPPFLAGS := 
LOCAL_CPPFLAGS += -std=c++17

LOCAL_CPP_FEATURES := 
LOCAL_CPP_FEATURES += rtti

include $(BUILD_STATIC_LIBRARY)
