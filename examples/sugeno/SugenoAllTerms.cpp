/*
The MIT License (MIT)

Copyright (c) 2013 Nicolas Pauss

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
/*
	This file was automatically generated by python/LFLLFisExporter.py
*/
#include "SugenoAllTerms.h"

namespace
{
	LFLL_USING_NAMESPACE

	const size_t NbInputs = 1;
	const size_t NbOutputs = 1;
	const size_t NbRules = 16;

	const size_t NbMfsForInput1 = 16;

	const LFLLBell i1mf1(0.4, 3.0, 0.0);
	const LFLLBoolean i1mf2(1);
	const LFLLGaussian i1mf3(0.3, 0.0);
	const LFLLGaussianProduct i1mf4(0.239, -0.197, 0.28, 0.0645);
	const LFLLLRamp i1mf5(-1.0, 1.0);
	const LFLLPiShape i1mf6(-1.0, -0.05, 0.1, 1.0);
	const LFLLRectangle i1mf7(-0.75, 0.4);
	const LFLLRRamp i1mf8(-1.0, 1.0);
	const LFLLSigmoid i1mf9(5.0, 0.0);
	const LFLLSigmoidDifference i1mf10(8.77, -0.442, 12.5, 0.468);
	const LFLLSigmoidProduct i1mf11(8.14, -0.336, -8.82, 0.421);
	const LFLLSingleton i1mf12(0.2);
	const LFLLSShape i1mf13(-1.0, 1.0);
	const LFLLTrapezoid i1mf14(-1.0, 0.01, 0.15, 1.0);
	const LFLLTriangle i1mf15(-1.0, 0.01, 1.0);
	const LFLLZShape i1mf16(-1.0, 1.0);

	const LFLLSugenoZeroOrderTerm o1t1 = {0.4};
	const LFLLSugenoFirstOrderTerm<1> o1t2 = {0.2, -0.8};
	const LFLLSugenoZeroOrderTerm o1t3 = {0.3};
	const LFLLSugenoFirstOrderTerm<1> o1t4 = {0.239, 0.0645};
	const LFLLSugenoZeroOrderTerm o1t5 = {-1.0};
	const LFLLSugenoFirstOrderTerm<1> o1t6 = {-1.0, -0.05};
	const LFLLSugenoZeroOrderTerm o1t7 = {-0.75};
	const LFLLSugenoFirstOrderTerm<1> o1t8 = {-1.0, 1.0};
	const LFLLSugenoZeroOrderTerm o1t9 = {0.15};
	const LFLLSugenoFirstOrderTerm<1> o1t10 = {0.77, -0.442};
	const LFLLSugenoZeroOrderTerm o1t11 = {0.14};
	const LFLLSugenoFirstOrderTerm<1> o1t12 = {0.2, -0.8};
	const LFLLSugenoZeroOrderTerm o1t13 = {1.0};
	const LFLLSugenoFirstOrderTerm<1> o1t14 = {-1.0, 0.01};
	const LFLLSugenoZeroOrderTerm o1t15 = {-0.25};
	const LFLLSugenoFirstOrderTerm<1> o1t16 = {-1.0, 1.0};

	const LFLLRules<NbInputs, NbRules, NbOutputs> rules = {{
		{{1}, {16}, 1, false},
		{{2}, {15}, 0.9, false},
		{{3}, {14}, 0.8, false},
		{{4}, {13}, 0.7, false},
		{{5}, {12}, 0.6, false},
		{{6}, {11}, 0.5, false},
		{{7}, {10}, 0.4, false},
		{{8}, {9}, 0.3, false},
		{{9}, {8}, 0.3, false},
		{{10}, {7}, 0.4, false},
		{{11}, {6}, 0.5, false},
		{{12}, {5}, 0.6, false},
		{{13}, {4}, 0.7, false},
		{{14}, {3}, 0.8, false},
		{{15}, {2}, 0.9, false},
		{{16}, {1}, 1, false}
	}};
	const LFLLRulesEngine<NbInputs, NbRules, NbOutputs> rulesEngine(rules);


	typedef LFLLTuple<
		const LFLLBell,
		const LFLLBoolean,
		const LFLLGaussian,
		const LFLLGaussianProduct,
		const LFLLLRamp,
		const LFLLPiShape,
		const LFLLRectangle,
		const LFLLRRamp,
		const LFLLSigmoid,
		const LFLLSigmoidDifference,
		const LFLLSigmoidProduct,
		const LFLLSingleton,
		const LFLLSShape,
		const LFLLTrapezoid,
		const LFLLTriangle,
		const LFLLZShape
	> Input1Tuple;
	const Input1Tuple input1Tuple = makeLFLLTuple(
		i1mf1, i1mf2, i1mf3, i1mf4, i1mf5, i1mf6, i1mf7, i1mf8, 
		i1mf9, i1mf10, i1mf11, i1mf12, i1mf13, i1mf14, i1mf15, i1mf16);
	const LFLLInputFuzzifier<Input1Tuple> input1Fuzzifier(input1Tuple);


	typedef LFLLTuple<
		const LFLLSugenoZeroOrderTerm,
		const LFLLSugenoFirstOrderTerm<1>,
		const LFLLSugenoZeroOrderTerm,
		const LFLLSugenoFirstOrderTerm<1>,
		const LFLLSugenoZeroOrderTerm,
		const LFLLSugenoFirstOrderTerm<1>,
		const LFLLSugenoZeroOrderTerm,
		const LFLLSugenoFirstOrderTerm<1>,
		const LFLLSugenoZeroOrderTerm,
		const LFLLSugenoFirstOrderTerm<1>,
		const LFLLSugenoZeroOrderTerm,
		const LFLLSugenoFirstOrderTerm<1>,
		const LFLLSugenoZeroOrderTerm,
		const LFLLSugenoFirstOrderTerm<1>,
		const LFLLSugenoZeroOrderTerm,
		const LFLLSugenoFirstOrderTerm<1>
	> Output1Tuple;
	const Output1Tuple output1Tuple = makeLFLLTuple(
		o1t1, o1t2, o1t3, o1t4, o1t5, o1t6, o1t7, o1t8, 
		o1t9, o1t10, o1t11, o1t12, o1t13, o1t14, o1t15, o1t16);
	const LFLLSugenoDefuzzifier<Output1Tuple, LFLLSugenoWeightedAverage>
		output1Defuzzifier(output1Tuple);

}


void SugenoAllTerms::process(
		const LFLLArray<1>& inputs,
		LFLLArray<1>& outputs)
{
	const LFLLMembership<NbMfsForInput1> antecedent1 =
		input1Fuzzifier.fuzzifyVariable(inputs[0]);

	LFLLConsequence<NbRules> consequence1;

	typedef LFLLTuple<
		const LFLLMembership<NbMfsForInput1>
	> AntecedentTuple;

	typedef LFLLTuple<
		LFLLConsequence<NbRules>
	> ConsequenceTuple;

	const AntecedentTuple antecedents = makeLFLLTuple(
		antecedent1);

	ConsequenceTuple consequences = makeLFLLTuple(
		consequence1);

	rulesEngine.applyRules(antecedents, consequences);

	outputs[0] = output1Defuzzifier.defuzzifyConsequence(inputs, consequence1);
}