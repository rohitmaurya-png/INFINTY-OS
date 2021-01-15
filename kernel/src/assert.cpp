//=======================================================================
// Copyright Baptiste Wicht 2013-2018.
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://www.opensource.org/licenses/MIT)
//=======================================================================

#include "assert.hpp"

#ifndef INFINTY_NO_ASSERT
#include "print.hpp"
#include "kernel.hpp"
#include "logging.hpp"
#endif

void __infinity_assert(bool condition){
    __infinity_assert(condition, "assertion failed");
}

void __infinity_assert(bool condition, const char* message){
#ifndef INFINTY_NO_ASSERT
    if(!condition){
        logging::logf(logging::log_level::ERROR, "Assertion failed: %s\n", message);
        k_print_line(message);
        suspend_kernel();
    }
#else
    (void) condition;
    (void) message;
#endif
}

void __infinity_unreachable(const char* message){
#ifndef INFINTY_NO_ASSERT
    logging::logf(logging::log_level::ERROR, "Reached unreachable block: %s\n", message);
    k_print_line(message);
    suspend_kernel();
#else
    (void) message;
#endif
}
