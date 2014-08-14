//          Copyright Marek Kurdej 2011 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_BELIEF_MARGINALIZATION_HPP
#define BOOST_BELIEF_MARGINALIZATION_HPP

#include <boost/belief/fod_minus.hpp>
#include <boost/belief/mass.hpp>

namespace boost { namespace belief {

/// Vacuous extension of a mass function.
template <typename FOD2, typename FOD1, typename T>
mass<typename fod_minus<FOD1, FOD2>::type, T> marginalization(const mass<FOD1, T> & m)
{
    typedef typename fod_minus<FOD1, FOD2>::type FOD_MINUS;
    mass<FOD_MINUS, T> m_marginalized;

    // FIXME: works only when FOD1 is equivalent to *FOD_MINUS.append(FOD2)*
    std::size_t fod_diff = set_xor(FOD_MINUS::powerset_size - 1, FOD1::powerset_size - 1);
    for(std::size_t A = 0; A < FOD_MINUS::powerset_size; ++A) {
        std::size_t B = A | fod_diff;
        m_marginalized[A] = m[B];
    }

    return m_marginalized;
}

} // namespace belief

} // namespace boost

#endif // BOOST_BELIEF_MARGINALIZATION_HPP
