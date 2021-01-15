//=======================================================================
// Copyright Baptiste Wicht 2013-2018.
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://www.opensource.org/licenses/MIT)
//=======================================================================

#ifndef ASSERT_HPP
#define ASSERT_HPP

void __infinity_assert(bool condition);
void __infinity_assert(bool condition, const char* message);
void __infinity_unreachable(const char* message);

#ifdef NASSERT
inline void infinity_assert(bool){}
inline void infinity_assert(bool, const char*){}
#else
inline void infinity_assert(bool condition){
    __infinity_assert(condition);
}

inline void infinity_assert(bool condition, const char* message){
    __infinity_assert(condition, message);
}
#endif

inline void infinity_unreachable(const char* message) __attribute__((noreturn));
inline void infinity_unreachable(const char* message){
    __infinity_unreachable(message);
    __builtin_unreachable();
}

#endif
