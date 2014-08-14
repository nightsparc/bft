//          Copyright Marek Kurdej 2011 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_BELIEF_RULE_DEMPSTER_HPP
#define BOOST_BELIEF_RULE_DEMPSTER_HPP

#include <boost/belief/mass.hpp>
#include <boost/belief/rule_base.hpp>
#include <boost/belief/rule_conjunctive.hpp>
#include <boost/belief/rule_normalization.hpp>

namespace boost { namespace belief {

struct rule_dempster
        : public rule_base
{
    std::string to_string() const
    {
        return "Dempster rule";
    }

    template <class FOD, typename T>
    mass<FOD, T> operator()(const mass<FOD, T> & m1, const mass<FOD, T> & m2) const
    {
        mass<FOD> m_result = m1.apply(rule_conjunctive(), m2);
        m_result = m_result.apply(rule_normalization());
        return m_result;
    }
};

} // namespace belief

} // namespace boost

#endif // BOOST_BELIEF_RULE_DEMPSTER_HPP