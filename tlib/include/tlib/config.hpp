//=======================================================================
// Copyright Baptiste Wicht 2013-2018.
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://www.opensource.org/licenses/MIT)
//=======================================================================

#ifndef TLIB_CONFIG_HPP
#define TLIB_CONFIG_HPP

namespace tlib {

constexpr bool is_infinity_program(){
#ifdef INFINTY_PROGRAM
    return true;
#else
    return false;
#endif
}

constexpr bool is_infinity_lib(){
#ifdef INFINTY_TLIB
    return true;
#else
    return false;
#endif
}

} // end of namespace tlib

#define ASSERT_ONLY_INFINTY_PROGRAM static_assert(tlib::is_infinity_program() || tlib::is_infinity_lib(), __FILE__ " can only be used in Infinity programs");

// Conditional namespace

#ifdef INFINTY_TLIB
#define INFINTY_NAMESPACE_NAME(LIB_NS,INFINTY_NS) LIB_NS
#elif defined(INFINTY_PROGRAM)
#define INFINTY_NAMESPACE_NAME(LIB_NS,INFINTY_NS) LIB_NS
#else
#define INFINTY_NAMESPACE_NAME(LIB_NS,INFINTY_NS) INFINTY_NS
#endif

#define INFINTY_NAMESPACE(LIB_NS,INFINTY_NS) namespace INFINTY_NAMESPACE_NAME(LIB_NS, INFINTY_NS)

// Namespaces in kernel

#ifdef INFINTY_TLIB
#define KERNEL_NAMESPACE_BEGIN(INFINTY_NS)
#define KERNEL_NAMESPACE_END
#elif defined(INFINTY_PROGRAM)
#define KERNEL_NAMESPACE_BEGIN(INFINTY_NS)
#define KERNEL_NAMESPACE_END
#else
#define KERNEL_NAMESPACE_BEGIN(INFINTY_NS) namespace INFINTY_NS {
#define KERNEL_NAMESPACE_END }
#endif

// Conditional prefixing

#ifdef INFINTY_TLIB
#define INFINTY_PREFIX(prefix) prefix
#elif defined(INFINTY_PROGRAM)
#define INFINTY_PREFIX(prefix) prefix
#else
#define INFINTY_PREFIX(prefix)
#endif

#endif
