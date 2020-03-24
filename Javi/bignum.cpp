
#include <iostream>
#include <cstdio>

class Bignum
{
private:
	static const int	MAXDIGITS=200;
	static const int	PLUS=1;
	static const int	MINUS=-1;

public:

	char	digits[ MAXDIGITS ];
	int		signbit,
			lastdigit;

	Bignum()
	{
		int_to_bignum( 0 );
	}
	Bignum( int i )
	{
		int_to_bignum( i );
	}

	inline int max( int a, int b )
	{
		return ( a > b ) ? a : b;
	}
	inline int min( int a, int b )
	{
		return ( a < b ) ? a : b;
	}

	void assigna( int i )
	{
		int_to_bignum( i );
	}

	void int_to_bignum( int s )
	{
		int i;				/* counter */
		int t;				/* int to work with */

		if ( s >= 0 )
			signbit = PLUS;
		else
			signbit = MINUS;

		for( i=0; i < MAXDIGITS; i++ ) digits[i] = (char)0;

		lastdigit = -1;

		t = abs(s);

		while( t > 0 ) {
			lastdigit++;
			digits[ lastdigit ] = (t % 10);
			t = t / 10;
		}

		if (s == 0) lastdigit = 0;
	}

	void print()
	{
		if ( signbit == MINUS ) putchar( '-' );

		for( int i=lastdigit; i >= 0; i-- )
			putchar( ('0'+digits[i]) );

		putchar( '\n' );
	}

	void zero_justify()
	{
		while( (lastdigit > 0) && (digits[lastdigit] == 0))
			lastdigit--;

		if ( (lastdigit == 0) && (digits[0] == 0))
			signbit = PLUS;	/* hack to avoid -0 */
	}


	static int compara( Bignum *a, Bignum *b )
	{
		int i;				/* counter */

		if ( (a->signbit == MINUS) && (b->signbit == PLUS) ) return PLUS;
		if ( (a->signbit == PLUS) && (b->signbit == MINUS) ) return MINUS;

		if ( b->lastdigit > a->lastdigit ) return PLUS * a->signbit;
		if ( a->lastdigit > b->lastdigit ) return MINUS * a->signbit;

		for( i = a->lastdigit; i >=0; i-- ) {
			if ( a->digits[i] > b->digits[i] ) return MINUS * a->signbit;
			if ( b->digits[i] > a->digits[i] ) return PLUS * a->signbit;
		}

		return 0;
	}

	void assigna( Bignum & otro )
	{
		lastdigit = otro.lastdigit;
		signbit = otro.signbit;
		for( int i=0; i < MAXDIGITS; i++ )
			digits[i] = otro.digits[i];
	}
	void assigna( Bignum * otro )
	{
		this->lastdigit = otro->lastdigit;
		this->signbit = otro->signbit;
		for( int i=0; i < MAXDIGITS; i++ )
			this->digits[i] = otro->digits[i];
	}

	/*	this = a + b;	*/
	void suma( Bignum * a, Bignum * b )
	{
		int carry;			/* carry digit */
		int i;				/* counter */

		this->assigna(0);

		if ( a->signbit == b->signbit )
			this->signbit = a->signbit;
		else {
			if ( a->signbit == MINUS ) {
				a->signbit = PLUS;
				this->resta( b, a );
				a->signbit = MINUS;
			} else {
				b->signbit = PLUS;
				this->resta( a, b );
				b->signbit = MINUS;
			}
			return;
		}

		this->lastdigit = max( a->lastdigit, b->lastdigit )+1;
		carry = 0;

		for( i=0; i <= this->lastdigit; i++ ) {
			int x = carry + a->digits[i] + b->digits[i];
			this->digits[i] = (char)(x % 10);
			carry = x / 10;
		}

		zero_justify();
	}


	/*	c = a - b;	*/
	void resta( Bignum *a, Bignum *b )
	{
		int borrow;			/* has anything been borrowed? */
		int v;				/* placeholder digit */
		int i;				/* counter */

		this->assigna(0);

		if ( ( a->signbit == MINUS) || (b->signbit == MINUS) ) {
			b->signbit = -1 * b->signbit;
			this->suma( a, b );
			b->signbit = -1 * b->signbit;
			return;
		}

		if ( compara( a, b ) == PLUS ) {
			this->resta( b, a );
			this->signbit = MINUS;
			return;
		}

		this->lastdigit = max( a->lastdigit, b->lastdigit );
		borrow = 0;

		for( i=0; i <= this->lastdigit; i++ ) {
			v = ( a->digits[i] - borrow - b->digits[i] );
			if ( a->digits[i] > 0 ) borrow = 0;
			if ( v < 0 ) {
				v = v + 10;
				borrow = 1;
			}
			this->digits[i] = (char) v % 10;
		}

		zero_justify();
	}


	void digit_shift( int d )		/* multiply n by 10^d */
	{
		int i;				/* counter */

		if ( (lastdigit == 0) && (digits[0] == 0) ) return;

		for( i=lastdigit; i >= 0; i-- )
			digits[i+d] = digits[i];

		for( i=0; i<d; i++ ) digits[i] = 0;

		lastdigit = lastdigit + d;
	}



/*	c = a * b;	*/
	void multiplica( Bignum *a, Bignum *b )
	{
		Bignum row;			/* represent shifted row */
		Bignum tmp;			/* placeholder bignum */
		int i,j;			/* counters */

		this->assigna(0);
		row.assigna( a );

		for( i=0; i <= b->lastdigit; i++ ) {
			for( j=1; j <= b->digits[i]; j++ ) {
				tmp.suma( this, &row );
				this->assigna( tmp );
			}
			row.digit_shift(1);
		}

		this->signbit = a->signbit * b->signbit;

		zero_justify();
	}


/*	c = a / b;	*/
	void divide( Bignum * num, Bignum * den )
	{
		Bignum row;             /* represent shifted row */
		Bignum tmp;             /* placeholder bignum */
		int asign, bsign;		/* temporary signs */
		int i;                  /* counters */

		this->assigna( 0 );

		this->signbit = num->signbit * den->signbit;

		asign = num->signbit;
		bsign = den->signbit;

		num->signbit = PLUS;
		den->signbit = PLUS;

		row.assigna(0);
		tmp.assigna(0);

		this->lastdigit = num->lastdigit;

		for( i=num->lastdigit; i>=0; i-- ) {

			row.digit_shift(1);
			row.digits[0] = num->digits[i];
			this->digits[i] = 0;
			while( compara( &row, den ) != PLUS ) {
				this->digits[i]++;
				tmp.resta( &row, den );
				row.assigna( tmp );
			}
		}

		zero_justify();

		num->signbit = asign;
		den->signbit = bsign;
	}

};


int main()
{
	Bignum	a(10), b(20);

	Bignum	c;

	c.suma( &a, &b );
	c.print();

	for( int i=0; i < 100; i++ ) {
		a.assigna( c );
		c.suma( &a, &b );
		c.print();
	}


	return 0;
}

