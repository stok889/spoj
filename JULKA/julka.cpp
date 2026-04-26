#include <cstdio>
#include <string>
#include <cassert>

class BigInteger
{
private:

	char *dig_;
	int capacity_;
	int size_;
	int sign_; //-1, 0 - NULL, +1

public:

	BigInteger();
	BigInteger( const char *const );
	BigInteger( const BigInteger & );

	BigInteger& operator +=( const BigInteger & );
	BigInteger operator +( const BigInteger & );

	BigInteger& operator -=( const BigInteger & );
	BigInteger operator -( const BigInteger & );

	BigInteger& operator /=( const int );
	BigInteger operator /( const int );

	std::string toString() const;
	void normalize();
	void grow( const int );
};

BigInteger::BigInteger()
{
	dig_ = NULL;
	sign_ = size_ = capacity_ = 0;
}

BigInteger::BigInteger( const char *const arg )
{
	size_ = capacity_ = strlen( arg );
	dig_ = new char[ size_ ];
	sign_ = 0;
	
	for (int i = 0; i < size_; ++i) dig_[i] = 0;
	for (int i = size_ - 1; i > 0; --i) dig_[ size_ - i - 1 ] = arg[i];

	if (arg[0] == '-') sign_ = -1;
	else dig_[ size_ - 1 ] = arg[0];

	normalize();

	if (size_ > 0) sign_ = 1;
}

BigInteger::BigInteger( const BigInteger &arg )
{
	size_ = arg.size_;
	capacity_ = arg.capacity_;
	sign_ = arg.sign_;

	dig_ = new char [ capacity_ ];

	memcpy( dig_, arg.dig_, sizeof( arg.dig_[0] ) * capacity_ );
}

BigInteger& BigInteger::operator +=( const BigInteger &arg )
{
	int cCap = std::max( size_, arg.size_ ) + 1;

	if ( cCap > capacity_ ) grow( cCap - capacity_ );

	if ( !arg.sign_ ) return *this;
	if ( !sign_ ) sign_ = arg.sign_;
	if ( sign_ == arg.sign_ )
	{
		int i, t = 0;

		for (i = 0; i < cCap - 1 || t; ++i)
		{
			int cd = t;

			if ( i < size_ ) cd += dig_[i] - '0';
			if ( i < arg.size_ ) cd += arg.dig_[i] - '0';

			t = 0;

			if ( cd >= 10 )
			{
				t = 1;
				cd -= 10;
			}

			dig_[i] = cd + '0';
		}

		size_ = i;
	}
	else
	{
	}

	return *this;
}

BigInteger BigInteger::operator +( const BigInteger &arg ) 
{
	BigInteger ret( *this );
	ret += arg;
	return ret;
}

BigInteger& BigInteger::operator -=( const BigInteger &arg )
{
	for (int i = 0; i < std::max( size_, arg.size_ ); ++i)
	{
		int cd = 0;

		if ( i < size_ ) cd = dig_[i] - '0';
		if ( i < arg.size_ ) cd -= arg.dig_[i] - '0';

		if (cd < 0) 
		{
			--dig_[ i + 1 ];
			cd += 10;
		}

		dig_[i] = cd + '0';
	}

	normalize();

	return *this;
}

BigInteger BigInteger::operator -( const BigInteger &arg ) 
{
	BigInteger ret( *this );
	ret -= arg;
	return ret;
}

BigInteger& BigInteger::operator /=( const int arg )
{
	if ( !sign_ ) return *this;

	int argSign = arg > 0 ? 1 : -1;
	sign_ *= argSign;

	int tmp = 0;
	for (int i = size_ - 1; i >= 0; --i)
	{
		tmp *= 10;
		tmp += dig_[i] - '0';
		dig_[i] = ( tmp / arg ) + '0';
		tmp -= ( dig_[i] - '0' ) * arg;
	}

	normalize();
	return *this;
}

BigInteger BigInteger::operator /( const int arg )
{
	assert( arg != 0 );

	BigInteger ret( *this );
	ret /= arg;
	return ret;
}

std::string BigInteger::toString() const
{	
	std::string ret;

	if ( !sign_ ) return ret;
	if ( sign_ < 0 ) ret.push_back( '-' );

	for (int i = size_ - 1; i >= 0; --i) ret.push_back( this->dig_[i] );
	
	return ret;
}

void BigInteger::normalize()
{
	for (; dig_[ size_ - 1 ] == '0'; --size_);
}

void BigInteger::grow( const int d )
{
	char *oldDig = dig_;
	int oldCapacity = capacity_;

	capacity_ += d;
	dig_ = new char [ capacity_ ];

	for (int i = 0; i < capacity_; ++i) dig_[i] = 0;

	memcpy( dig_, oldDig, sizeof( oldDig[0] ) * oldCapacity );

	delete[] oldDig;
}

int main()
{
	for (int t = 0; t < 10; ++t)
	{
		char s1[500], s2[500];

		scanf("%s\n", s1);
		scanf("%s\n", s2);

		BigInteger X( s1 ), Y( s2 );
		BigInteger K, N;

		K = (X + Y) / 2;
		N = (X - Y) / 2;

		printf("%s\n", K.toString().c_str());
		printf("%s\n", N.toString().c_str());
	}

	return 0;
}