/*
 
 Note:
 You read the code in L02_Strings.cpp file and understand the behaviour.
 And replace the blanks with correct expected output in this file.
 
 */

#include "stdafx.h"

#include "../src/L02_Strings.cpp"
#include "TestHelperMethods.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class L02_StringsSpec
	{
	private:
		TestContext^ testContextInstance;

	public:
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};
        
        // test methods
		[TestMethod, Timeout(3000)]
		void TestnumberOfFormatSpecifiers(){
			char *str;
			int res;

			str = "%d %d";
			res = numberOfFormatSpecifiers(str);
			Assert::AreEqual(2, res, L"numberOfFormatSpecifiers() failed", 1, 2);

			str = "testing";
			res = numberOfFormatSpecifiers(str);
			Assert::AreEqual(0, res, L"numberOfFormatSpecifiers() failed", 1, 2);

			str = "testing%d";
			res = numberOfFormatSpecifiers(str);
			Assert::AreEqual(1, res, L"numberOfFormatSpecifiers() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TeststringLength(){
			char *str;
			int res;

			str = "What you cannot count does not count.";
			res = stringLength(str);
			Assert::AreEqual(37, res, L"stringLength() failed", 1, 2);

			str = "No, only what you cannot count, counts.";
			res = stringLength(str);
			Assert::AreEqual(39, res, L"stringLength() failed", 1, 2);

			char s[10] = { 'a', 'b', ' ', '\0', 'd', 'e', 'f', 'g', 'h', 'i' };
			res = stringLength(s);
			Assert::AreEqual(3, res, L"stringLength() failed", 1, 2);
            
            str = "First Line.\n Second Line A.\t Second Line B.";
            res = stringLength(str);
            Assert::AreEqual(43, res, L"stringLength() failed", 1, 2);
            
		}
        
        // string mystery
		[TestMethod, Timeout(3000)]
		void TeststringMystery(){
			char *str = (char *)malloc(100);

			strcopy(str, "recursive");
			stringMystery(str);
			Assert::AreEqual(true, areEqualStrings("rec-\0siv?", str), L"stringMystery() failed", 1, 2);

			strcopy(str, "higher-order-functions");
			stringMystery(str);
			Assert::AreEqual(true, areEqualStrings("higher--rde\0-function?", str), L"stringMystery() failed", 1, 2);

			strcopy(str, "string-literals");
			stringMystery(str);
			Assert::AreEqual(true, areEqualStrings("strin--\0iteral?", str), L"stringMystery() failed", 1, 2);
            
            strcopy(str, "1234567890");
            stringMystery(str);
            Assert::AreEqual(true, areEqualStrings("123-5", str), L"stringMystery() failed", 1, 2);
		}

        // string Mystery Add
		[TestMethod, Timeout(3000)]
		void TeststringMysteryAdd(){
			char *str = (char *)malloc(100);

			strcopy(str, "goodVariableNamingConvention");
			stringMysteryAdd(str);
			Assert::AreEqual(true, areEqualStrings("gpqgZariableNamingConvention", str), L"stringMysteryAdd() failed", 1, 2);
            
            strcopy(str, "badvariable");
            stringMysteryAdd(str);
            Assert::AreEqual(true, areEqualStrings("bbfyeriable", str), L"stringMysteryAdd() failed", 1, 2);
            
            strcopy(str, "digDeeper");
            stringMysteryAdd(str);
            Assert::AreEqual(true, areEqualStrings("djiGieper", str), L"stringMysteryAdd() failed", 1, 2);
            
            strcopy(str, "ThinkBigAndScale");
            stringMysteryAdd(str);
            Assert::AreEqual(true, areEqualStrings("TikqoBigAndScale", str), L"stringMysteryAdd() failed", 1, 2);
		}
        
        // string mystery create
		[TestMethod, Timeout(3000)]
		void TeststringMysteryCreate(){
			char *str;

			str = stringMysteryCreate(2);
			Assert::AreEqual(true, areEqualStrings("?B", str), L"stringMysteryCreate() failed", 1, 2);

			str = stringMysteryCreate(9);
			Assert::AreEqual(true, areEqualStrings("012?E5678", str), L"stringMysteryCreate() failed", 1, 2);

			str = stringMysteryCreate(14);
			Assert::AreEqual(true, areEqualStrings("0123?56H89:;<=", str), L"stringMysteryCreate() failed", 1, 2);
		}
        
        // number char mystery
		[TestMethod, Timeout(3000)]
		void TestnumberCharMystery(){
			char *str = (char *)malloc(100);

			strcopy(str, "code-r");
			numberCharMystery(str);
			Assert::AreEqual(true, areEqualStrings("012", str), L"numberCharMystery() failed", 1, 2);

			strcopy(str, "hack-er");
			numberCharMystery(str);
			Assert::AreEqual(true, areEqualStrings("012", str), L"numberCharMystery() failed", 1, 2);

			strcopy(str, "program-mer");
			numberCharMystery(str);
			Assert::AreEqual(true, areEqualStrings("012", str), L"numberCharMystery() failed", 1, 2);
		}

        
        // abc mystery
		[TestMethod, Timeout(3000)]
		void TestabcMystery(){
			char *str = (char *)malloc(100);

			strcopy(str, "plantrees");
			abcMystery(str);
			Assert::AreEqual(true, areEqualStrings("0l1n2r", str), L"abcMystery() failed", 1, 2);

			strcopy(str, "vrukshaalu");
			abcMystery(str);
			Assert::AreEqual(true, areEqualStrings("0r1k2h", str), L"abcMystery() failed", 1, 2);
		}

		// add mystery
		[TestMethod, Timeout(3000)]
		void TestaddMystery(){
			CustomString *one = (CustomString *)malloc(sizeof(CustomString));
			CustomString *two = (CustomString *)malloc(sizeof(CustomString));
			CustomString *res;
			one->str = (char *)malloc(100);
			two->str = (char *)malloc(100);

			strcopy(one->str, "stack");
			strcopy(two->str, "top");
			one->length = 5;
			two->length = 3;
			res = addMystery(one, two);
			Assert::AreEqual(13, res->length, L"addMystery() failed length incorrect", 1, 2);
			Assert::AreEqual(true, areEqualCharArrays("stacktopstack", res->str, res->length), L"addMystery() failed", 1, 2);

			strcopy(one->str, "CallStack");
			strcopy(two->str, "ActivationRecord");
			one->length = 9;
			two->length = 16;
			res = addMystery(one, two);
			Assert::AreEqual(34, res->length, L"addMystery() failed length incorrect", 1, 2);
			Assert::AreEqual(true, areEqualCharArrays("CallStackActivationRecordCallStack", res->str, res->length), L"addMystery() failed", 1, 2);
			
			strcopy(one->str, "local");
			strcopy(two->str, "globe");
			one->length = 5;
			two->length = 5;
			res = addMystery(one, two);
			Assert::AreEqual(15, res->length, L"addMystery() failed length incorrect", 1, 2);
			Assert::AreEqual(true, areEqualCharArrays("localglobelocal", res->str, res->length), L"addMystery() failed", 1, 2);
		}
        
        // concat mystery
        [TestMethod, Timeout(3000)]
        void TestconcatMystery(){
            char *a,*b,*c;
            
            a = "MMU";
            b = "ALU";
            c = concatMystery(a, b);
            Assert::AreEqual(true, areEqualStrings("MMU", c), L"abcMystery() failed", 1, 2);
            free(c);
            
            a = "thread";
            b = "lock";
            c = concatMystery(a, b);
            Assert::AreEqual(true, areEqualStrings("thread", c), L"abcMystery() failed", 1, 2);
            free(c);
        }

	};
}
