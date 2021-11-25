#include <iostream>
#include <assert.h>

#include "../../Production/include/Production.h"
#include "cppunit/TestCase.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestRunner.h"
#include "cppunit/TestResult.h"
#include <cppunit/ui/text/TestRunner.h>

using namespace std;

class LotteryNumberTest : public CppUnit::TestCase { 
public:
	Production* testProd;
	void setUp()
	{
		std::cout << "setup";
		testProd = new Production();
	}

	void tearDown() 
	{
		std::cout << " teardown";
		delete testProd;
	}
	
	void testGeneration()
	{
		testProd->generateLottery();
		CPPUNIT_ASSERT( testProd->genSet.size() == 6 );
	}

	void testRange()
	{
		testProd->generateLottery();
		CPPUNIT_ASSERT( testProd->checkRange() );
	}

	void testDuplicates()
	{
		testProd->generateLottery();
		CPPUNIT_ASSERT( testProd->checkDuplicates() );
	}

	static CppUnit::Test *suite()
  	{
		CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "ComplexNumberTest" );
		suiteOfTests->addTest( new CppUnit::TestCaller<LotteryNumberTest>(
							"testGeneration", 
							&LotteryNumberTest::testGeneration ));
		suiteOfTests->addTest( new CppUnit::TestCaller<LotteryNumberTest>(
							"testRange", 
							&LotteryNumberTest::testRange ));
		suiteOfTests->addTest( new CppUnit::TestCaller<LotteryNumberTest>(
							"testDuplicates", 
							&LotteryNumberTest::testDuplicates ));
		return suiteOfTests;
  	}
};

int main(int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
  	runner.addTest( LotteryNumberTest::suite() );
  	runner.run();
}