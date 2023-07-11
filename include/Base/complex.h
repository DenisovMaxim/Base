#ifndef COMPLEX_H
#define COMPLEX_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdint>

template < typename Type >
class Complex {
public:
	Complex( Type Re = 0, Type Im = 0 );

	Type& re();
	Type const& re() const;
	Type& im();
	Type const& im() const;

	float abs() const;
	float arg() const;
	Type argDeg() const;
	Complex< Type > conj() const;

private:
	Type m_re;
	Type m_im;
};

template < typename Type >
Complex< Type >::Complex( Type Re, Type Im ) : m_re( Re ), m_im( Im ) {
}

template < typename Type >
Type& Complex< Type >::re() {
	return m_re;
}

template < typename Type >
Type const& Complex< Type >::re() const {
	return m_re;
}

template < typename Type >
Type& Complex< Type >::im() {
	return m_im;
}

template < typename Type >
Type const& Complex< Type >::im() const {
	return m_im;
}

template < typename Type >
float Complex< Type >::abs() const {
	return sqrt( m_re * m_re + m_im * m_im );
}

template < typename Type >
float Complex< Type >::arg() const {
	return atan2( m_im, m_re );
}

template < typename Type >
Type Complex< Type >::argDeg() const {
	return this->arg() * 180 * M_1_PI;
}

template < typename Type >
Complex< Type > Complex< Type >::conj() const {
	Complex< Type > NewComp( m_re, -m_im );
	return NewComp;
}

#endif // COMPLEX_H


