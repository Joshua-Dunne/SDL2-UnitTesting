#include <iostream>
#include <assert.h>

#include "../../Production/include/Production.h"
#include "cppunit/TestCase.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestRunner.h"
#include "cppunit/TestResult.h"
#include "cppunit/ui/text/TestRunner.h"

using namespace std;

class LotteryNumberTest : public CppUnit::TestCase {
public:
	Production* testProd;
	void setUp()
	{
		testProd = new Production();
	}

	void tearDown()
	{
		delete testProd;
	}

	void testGeneration()
	{
		testProd->generateLottery();
		CPPUNIT_ASSERT( testProd->genSet.size() != 0 );
		CPPUNIT_ASSERT( testProd->genSet.size() == 6 );

		// make sure the size isn't at some random size that isn't exactly 6 or 0
		CPPUNIT_ASSERT( !(testProd->genSet.size() > 6));
		CPPUNIT_ASSERT( !(testProd->genSet.size() < 6) );
	}

	void testRange()
	{
		testProd->generateLottery();

		std::set<int>::iterator it = testProd->genSet.begin();

		// check to make sure every number is at a min of 1, and a max of 46
		while (it != testProd->genSet.end())
		{
			CPPUNIT_ASSERT( (*it) >= 1 );
			CPPUNIT_ASSERT( (*it) <= 46 );

			it++;
		}

		it = testProd->genSet.begin();

		// secondary check to make sure no number is less than 1, and no number is greater than 46
		while (it != testProd->genSet.end())
		{
			CPPUNIT_ASSERT( !((*it) < 1) );
			CPPUNIT_ASSERT( !((*it) > 46) );

			it++;
		}
	}

	void testDuplicates()
	{
		testProd->generateLottery();

		// first we will do the normal duplicate check, since we use a Set
		CPPUNIT_ASSERT( testProd->genSet.size() == 6 );

		// now we will do an in-depth comparison too
		// just to make sure no number is duplicated
		for(auto num : testProd->genSet)
		{
			std::set<int>::iterator it = testProd->genSet.begin();

			while(it != testProd->genSet.end())
			{
				if(*it == num)
				{
					it++;
					continue;
				}

				CPPUNIT_ASSERT(num != *it);
				it++;
			}
		}
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