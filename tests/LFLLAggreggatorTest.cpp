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
#include <lfll/LFLLAggregator.h>
#include <lfll/LFLLMaxOperator.h>
#include <lfll/LFLLMath.h>

#include "LFLLTests.h"

using namespace math;

TEST(LFLLAggregatorTest, Agregator)
{
    const size_t NR = 3;
    const size_t NT = 2;

    LFLLAggregator<LFLLMaxOperator> aggregator;

    LFLLConsequence<NR, NT> consequence;

    consequence.membershipValue(0, 0) = scalarToDom(0.25f);
    consequence.membershipValue(0, 1) = scalarToDom(0.f);
    consequence.membershipValue(0, 2) = scalarToDom(0.f);

    consequence.membershipValue(1, 0) = scalarToDom(0.f);
    consequence.membershipValue(1, 1) = scalarToDom(0.75f);
    consequence.membershipValue(1, 2) = scalarToDom(0.10f);

    LFLLMembership<NT> membership = aggregator.aggregateConsequence(consequence);

    ASSERT_EQ(membership[0], scalarToDom(0.25f));
    ASSERT_EQ(membership[1], scalarToDom(0.75f));
}