//=====================================================================
//
// utils_test.h -
//
// Created by liubang on 2023/06/04 20:06
// Last Modified: 2023/06/04 20:06
//
//=====================================================================

#include "cpp/meta/utils.h"

namespace playground::cpp::meta {

template <typename T>
using sizeLess4 = std::bool_constant<(sizeof(T) < 4)>;

}
