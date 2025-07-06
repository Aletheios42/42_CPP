#include "../Inc/Fixed.hpp"

void testSubject() {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed const c( 5.05f );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
}

void testArithmetic() {
    Fixed const c1( Fixed( 5.05f ) + Fixed( 2 ) );
    std::cout << "Suma: " << c1 << std::endl;

    Fixed const c2( Fixed( 5.05f ) - Fixed( 2 ) );
    std::cout << "Resta: " << c2 << std::endl;

    Fixed const c3( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << "Multiplicacion: " << c3 << std::endl;

    Fixed const c4( Fixed( 5.05f ) / Fixed( 2 ) );
    std::cout << "Division: " << c4 << std::endl;
}

void testComparison() {
    Fixed const d1( Fixed( 5.05f ) + Fixed( 2 ) );
    Fixed const d2( Fixed( 2.05f ) + Fixed( 2 ) );

    std::cout << "d1 == d1: " << (d1 == d1 ? "TRUE" : "FALSE") << std::endl;
    std::cout << "d1 == d2: " << (d1 == d2 ? "TRUE" : "FALSE") << std::endl;
    std::cout << "d1 != d2: " << (d1 != d2 ? "TRUE" : "FALSE") << std::endl;
    std::cout << "d1 > d2: "  << (d1 > d2 ? "TRUE" : "FALSE") << std::endl;
    std::cout << "d1 < d2: "  << (d1 < d2 ? "TRUE" : "FALSE") << std::endl;
    std::cout << "d1 >= d2: " << (d1 >= d2 ? "TRUE" : "FALSE") << std::endl;
    std::cout << "d1 <= d2: " << (d1 <= d2 ? "TRUE" : "FALSE") << std::endl;
}


void testIncrementDecrement() {
    Fixed a;

    std::cout << "Initial a: " << a << std::endl;

    std::cout << "Pre-increment: " << ++a << std::endl;   // modifica y devuelve
    std::cout << "After pre-increment a: " << a << std::endl;

    std::cout << "Post-increment: " << a++ << std::endl; // devuelve valor anterior
    std::cout << "After post-increment a: " << a << std::endl;

    std::cout << "Pre-decrement: " << --a << std::endl;
    std::cout << "After pre-decrement a: " << a << std::endl;

    std::cout << "Post-decrement: " << a-- << std::endl;
    std::cout << "After post-decrement a: " << a << std::endl;
}


void testMinMax() {
    Fixed a(2.5f);
    Fixed b(3.75f);
    Fixed c(2.5f);

    std::cout << "--- Min/Max Test ---" << std::endl;

    // Versiones no constantes
    Fixed &minRef = Fixed::min(a, b);
    Fixed &maxRef = Fixed::max(a, b);
    std::cout << "min(a, b): " << minRef << std::endl;
    std::cout << "max(a, b): " << maxRef << std::endl;

    // Versiones constantes
    const Fixed &minConstRef = Fixed::min(static_cast<const Fixed&>(a), static_cast<const Fixed&>(c));
    const Fixed &maxConstRef = Fixed::max(static_cast<const Fixed&>(a), static_cast<const Fixed&>(c));
    std::cout << "min(const a, const c): " << minConstRef << std::endl;
    std::cout << "max(const a, const c): " << maxConstRef << std::endl;

    // Verificación básica
    if (&minRef == &a)
        std::cout << "min(a,b) is a" << std::endl;
    if (&maxRef == &b)
        std::cout << "max(a,b) is b" << std::endl;
    if (&minConstRef == &a)
        std::cout << "min(const a,const c) is a" << std::endl;
    if (&maxConstRef == &c)
        std::cout << "max(const a,const c) is c" << std::endl;
}

int main() {
    std::cout << "\n--- Subject Test ---" << std::endl;
    testSubject();

    std::cout << "\n--- Arithmetic Test ---" << std::endl;
    testArithmetic();

    std::cout << "\n--- Comparison Test ---" << std::endl;
    testComparison();

    std::cout << "\n--- De/increment Test ---" << std::endl;
    testIncrementDecrement();

    std::cout << "\n--- Min/max Test ---" << std::endl;
    testMinMax();

    return 0;
}
