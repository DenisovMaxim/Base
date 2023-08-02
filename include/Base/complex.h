#ifndef COMPLEX_H
#define COMPLEX_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdint>

namespace Base {

	template < typename Type >
	class Complex {
public:
		Complex( Type Re = 0, Type Im = 0 );
		template < typename TAnother > Complex( const Complex< TAnother >& another );
		~Complex() {
		}

		Type& re();
		Type const& re() const;
		Type& im();
		Type const& im() const;

		float abs() const;
		float arg() const;
		Type argDeg() const;
		Complex< Type > conj() const;

		template < typename TAnother >
		Complex< Type >& operator=( const Complex< TAnother >& another );
		template < typename TAnother >
		Complex< Type >& operator+=( const Complex< TAnother >& another );
		template < typename TAnother >
		Complex< Type >& operator-=( const Complex< TAnother >& another );
		template < typename TAnother >
		Complex< Type >& operator*=( const Complex< TAnother >& another );
		template < typename TAnother >
		Complex< Type >& operator*=( const TAnother& another );
		template < typename TAnother >
		Complex< Type >& operator/=( const Complex< TAnother >& another );
		template < typename TAnother >
		Complex< Type >& operator/=( const TAnother& another );
		Complex< Type > operator-() const;
		template < typename TAnother >
		bool operator==( Complex< TAnother > another ) const;
		template < typename TAnother >
		bool operator!=( Complex< TAnother > another ) const;
		template < typename TAnother >
		bool operator>( Complex< TAnother > another ) const;
		template < typename TAnother >
		bool operator<( Complex< TAnother > another ) const;
		template < typename TAnother >
		bool operator>=( Complex< TAnother > another ) const;
		template < typename TAnother >
		bool operator<=( Complex< TAnother > another ) const;

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

	template < typename Type >
	template < typename TAnother >
	Complex< Type >& Complex< Type >::operator=( const Complex< TAnother >& another ) {
		m_re = another.re();
		m_im = another.im();
		return *this;
	}

	template < typename Type >
	template < typename TAnother >
	Complex< Type >::Complex( const Complex< TAnother >& another ) : m_re( another.re() ), m_im( another.im() ) {
	}

	template < typename Type >
	template < typename TAnother >
	Complex< Type >& Complex< Type >::operator+=( const Complex< TAnother >& another ) {
		m_re += another.re();
		m_im += another.im();
		return *this;
	}

	template < typename Type >
	template < typename TAnother >
	Complex< Type >& Complex< Type >::operator-=( const Complex< TAnother >& another ) {
		m_re -= another.re();
		m_im -= another.im();
		return *this;
	}

	template < typename Type >
	template < typename TAnother >
	Complex< Type >& Complex< Type >::operator*=( const TAnother& another ) {
		m_re *= another;
		m_im *= another;
		return *this;
	}

	template < typename Type >
	template < typename TAnother >
	Complex< Type >& Complex< Type >::operator*=( const Complex< TAnother >& another ) {
		m_re = m_re * another.re() - m_im * another.im();
		m_im = m_re * another.im() + m_im * another.re();
		return *this;
	}

	template < typename Type >
	template < typename TAnother >
	Complex< Type >& Complex< Type >::operator/=( const TAnother& another ) {
		m_re = m_re / another;
		m_im = m_im / another;
		return *this;
	}

	template < typename Type >
	template < typename TAnother >
	Complex< Type >& Complex< Type >::operator/=( const Complex< TAnother >& another ) {
		*this = ( *this ) * another.conj() / another.abs() / another.abs();
		return *this;
	}

	template < typename Type >
	template < typename TAnother >
	bool Complex< Type >::operator==( Complex< TAnother > another ) const {
		return ( m_re == another.re() ) && ( m_im == another.im() );
	}

	template < typename Type >
	template < typename TAnother >
	bool Complex< Type >::operator!=( Complex< TAnother > another ) const {
		return !( *this == another );
	}

	template < typename Type >
	Complex< Type > Complex< Type >::operator-() const {
		return Complex< Type >( -m_re, -m_im );
	}

	template < typename TL,  typename TR >
	Complex< TL >& operator+( const Complex< TL >& left, const Complex< TR >& right ) {
		Complex< TL > tmp( left.re(), left.im() );
		tmp += right;
		return tmp;
	}

	template < typename TL,  typename TR >
	Complex< TL >& operator-( const Complex< TL >& left, const Complex< TR >& right ) {
		Complex< TL > tmp( left.re(), left.im() );
		tmp -= right;
		return tmp;
	}

	template < typename TL,  typename TR >
	Complex< TL >& operator*( const Complex< TL >& left, const TR right ) {
		Complex< TL > tmp( left.re(), left.im() );
		tmp *= right;
		return tmp;
	}

	template < typename TL,  typename TR >
	Complex< TL >& operator*( const TL& left, const Complex< TR > right ) {
		return right * left;
	}

	template < typename TL,  typename TR >
	Complex< TL >& operator*( const Complex< TL >& left, const Complex< TR >& right ) {
		Complex< TL > tmp( left.re(), left.im() );
		tmp *= right;
		return tmp;
	}

	template < typename TL,  typename TR >
	Complex< TL >& operator/( const Complex< TL >& left, const TR right ) {
		Complex< TL > tmp( left.re(), left.im() );
		tmp /= right;
		return tmp;
	}

	template < typename TL,  typename TR >
	Complex< TL >& operator/( const TL& left, const Complex< TR > right ) {
		Complex< TL > tmp( left );
		tmp /= right;
		return tmp;
	}

	template < typename TL,  typename TR >
	Complex< TL >& operator/( const Complex< TL >& left, const Complex< TR >& right ) {
		Complex< TL > tmp( left.re(), left.im() );
		tmp /= right;
		return tmp;
	}
}
#endif // COMPLEX_H


