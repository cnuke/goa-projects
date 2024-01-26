/*
 * Copyright 2006-2012 Haiku, Inc. All Rights Reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		Stephan Aßmus <superstippi@gmx.de>
 *		John Scipione <jscipione@gmail.com>
 *		Ingo Weinhold <bonefish@cs.tu-berlin.de>
 */

#include <ExpressionParser.h>

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

static const int32 kMaxDecimalPlaces = 32;


struct MAPM
{
	unsigned value;

	MAPM() { }
	MAPM(unsigned v) : value(0) { }
};


enum {
	TOKEN_NONE					= 0,
	TOKEN_IDENTIFIER,
	TOKEN_CONSTANT,

	TOKEN_END_OF_LINE			= '\n',

	TOKEN_PLUS					= '+',
	TOKEN_MINUS					= '-',

	TOKEN_STAR					= '*',
	TOKEN_SLASH					= '/',
	TOKEN_MODULO				= '%',

	TOKEN_POWER					= '^',
	TOKEN_FACTORIAL				= '!',

	TOKEN_OPENING_BRACKET		= '(',
	TOKEN_CLOSING_BRACKET		= ')',

	TOKEN_AND					= '&',
	TOKEN_OR					= '|',
	TOKEN_NOT					= '~'
};


struct ExpressionParser::Token {
	Token()
		: string(""),
		  type(TOKEN_NONE),
		  value(0),
		  position(0)
	{
	}

	Token(const Token& other)
		: string(other.string),
		  type(other.type),
		  value(other.value),
		  position(other.position)
	{
	}

	Token(const char* string, int32 length, int32 position, int32 type)
		: string(string, length),
		  type(type),
		  value(0),
		  position(position)
	{
	}

	Token& operator=(const Token& other)
	{
		string = other.string;
		type = other.type;
		value = other.value;
		position = other.position;
		return *this;
	}

	BString		string;
	int32		type;
	MAPM		value;

	int32		position;
};


class ExpressionParser::Tokenizer {
 public:
	Tokenizer()
		: fString(""),
		  fCurrentChar(NULL),
		  fCurrentToken(),
		  fReuseToken(false),
		  fHexSupport(false)
	{
	}

	void SetSupportHexInput(bool enabled)
	{
		fHexSupport = enabled;
	}

	void SetTo(const char* string)
	{
		fString = string;
		fCurrentChar = fString.String();
		fCurrentToken = Token();
		fReuseToken = false;
	}

	const Token& NextToken()
	{
		return fCurrentToken;
	}

	void RewindToken()
	{
		fReuseToken = true;
	}

 private:
	static bool _IsHexDigit(char c)
	{
		return isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
	}

	Token& _ParseHexNumber()
	{
		return fCurrentToken;
	}

	int32 _CurrentPos() const
	{
		return fCurrentChar - fString.String();
	}

	BString		fString;
	const char*	fCurrentChar;
	Token		fCurrentToken;
	bool		fReuseToken;
	bool		fHexSupport;
};


ExpressionParser::ExpressionParser()
	:	fTokenizer(new Tokenizer()),
		fDegreeMode(false)
{
}


ExpressionParser::~ExpressionParser()
{
	delete fTokenizer;
}


bool
ExpressionParser::DegreeMode()
{
	return fDegreeMode;
}


void
ExpressionParser::SetDegreeMode(bool degrees)
{
	fDegreeMode = degrees;
}


void
ExpressionParser::SetSupportHexInput(bool enabled)
{
	fTokenizer->SetSupportHexInput(enabled);
}


BString
ExpressionParser::Evaluate(const char* expressionString)
{
	BString result("bad");
	return result;
}


int64
ExpressionParser::EvaluateToInt64(const char* expressionString)
{
	return 0;
}


double
ExpressionParser::EvaluateToDouble(const char* expressionString)
{
	return 0.0;
}


MAPM
ExpressionParser::_ParseBinary()
{
	return MAPM();
}


MAPM
ExpressionParser::_ParseSum()
{
	return MAPM();
}


MAPM
ExpressionParser::_ParseProduct()
{
	return MAPM();
}


MAPM
ExpressionParser::_ParsePower()
{
	return MAPM();
}


MAPM
ExpressionParser::_ParseUnary()
{
	return MAPM();
}


void
ExpressionParser::_InitArguments(MAPM [], int32)
{
}


MAPM
ExpressionParser::_ParseFunction(const Token&)
{
	return MAPM();
}


MAPM
ExpressionParser::_ParseAtom()
{
	return MAPM();
}


MAPM
ExpressionParser::_ParseFactorial(MAPM value)
{
	return MAPM();
}


void
ExpressionParser::_EatToken(int32 type)
{
}
