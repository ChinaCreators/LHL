#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch.hpp"
#include "LML/Lexical/Automata.h"

#define MATCH( S ) REQUIRE( nfa.Match( S ))
#define UNMATCH( S ) REQUIRE_FALSE( nfa.Match(S))

TEST_CASE( "Test NFA that only matches one char", "[LML][Lexical][Automata][NFA]" )
{
	LML::Lexical::NFA nfa = LML::Lexical::ConstructSingleCharNFA( 'a' );

	MATCH( "a" );

	UNMATCH( "b" );
	UNMATCH( "c" );
	UNMATCH( "d" );
	UNMATCH( "e" );
	UNMATCH( "1" );
	UNMATCH( "2" );
	UNMATCH( "0" );
	UNMATCH( "" );
	UNMATCH( "1231" );
	UNMATCH( "afsdfa" );
}

TEST_CASE( "Test NFA that matches a string", "[LML][Lexical][Automata][NFA]" )
{
	LML::Lexical::NFA nfa = LML::Lexical::ConstructPureStringNFA( "aabbccdd" );

	MATCH( "aabbccdd" );

	UNMATCH( "a" );
	UNMATCH( "aa" );
	UNMATCH( "dd" );
	UNMATCH( "cc" );
	UNMATCH( "aasdfadsdsafad" );
	UNMATCH( "111111111111111111" );
	UNMATCH( "" );
	UNMATCH( "a132sa1f3as1f" );
	UNMATCH( "afsdjs" );
	UNMATCH( "00" );
}

TEST_CASE( "Test NFA Or", "[LML][Lexical][Automata][NFA]" )
{
	LML::Lexical::NFA nfa1 = LML::Lexical::ConstructSingleCharNFA( 'a' );
	LML::Lexical::NFA nfa2 = LML::Lexical::ConstructSingleCharNFA( 'b' );
	LML::Lexical::NFA nfa = LML::Lexical::NFAOr( nfa1, nfa2 );

	MATCH( "a" );
	MATCH( "b" );

	UNMATCH( "c" );
	UNMATCH( "A" );
	UNMATCH( "B" );
	UNMATCH( "" );
	UNMATCH( "143412" );
	UNMATCH( "adfs" );
	UNMATCH( "csfasdfasfsadf" );
	UNMATCH( "131" );
}