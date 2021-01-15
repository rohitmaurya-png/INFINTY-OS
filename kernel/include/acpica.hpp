//=======================================================================
// Copyright Baptiste Wicht 2013-2018.
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://www.opensource.org/licenses/MIT)
//=======================================================================

#ifndef INFINTY_ACPICA_HPP
#define INFINTY_ACPICA_HPP

extern "C" {

#include "infinity_acenv.hpp"
#include "infinity_acenvex.hpp"

//ACPICA
#include <acpi.h>
#include <accommon.h>

} //end of extern "C"

#include <types.hpp>

constexpr const size_t FADT2_REVISION_ID = 3;

#endif
