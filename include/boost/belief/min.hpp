//          Copyright Marek Kurdej 2011 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_BELIEF_MIN_HPP
#define BOOST_BELIEF_MIN_HPP

#include <boost/belief/dst_function.hpp>

namespace boost { namespace belief {

template <class FOD, typename T>
dst_function<FOD, T> min(const dst_function<FOD, T> & f1, const dst_function<FOD, T> & f2)
{
    dst_function<FOD, T> f_result;
    for(std::size_t A = 0; A < FOD::powerset_size; ++A) {
        f_result[A] = std::min(f1[A], f2[A]);
    }
    return f_result;
}

} // namespace belief

} // namespace boost

#endif // BOOST_BELIEF_MIN_HPP