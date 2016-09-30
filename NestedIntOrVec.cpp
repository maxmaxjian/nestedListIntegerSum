/*
 * NestedIntOrVec.cpp
 *
 *  Created on: Sep 30, 2016
 *      Author: jianwei
 */

#include "NestedIntOrVec.h"
#include "depthSumVisitor.h"

NestedIntOrVec::NestedIntOrVec(bool isInteger)
	: isInt(isInteger)
{
	// TODO Auto-generated constructor stub
}

NestedIntOrVec::~NestedIntOrVec() {
	// TODO Auto-generated destructor stub
}

bool NestedIntOrVec::isInteger() const {
	return isInt;
}


// NesttedInt
NestedInt::NestedInt(int a_int)
	: NestedIntOrVec(true), myInt(a_int)
{	
}

int NestedInt::getInteger() const
{
	return myInt;
}

void NestedInt::accept(depthSumVisitor & visitor) const
{
	visitor.visit(*this);
}

// NestedVec
NestedVec::NestedVec(const vector<NestedIntOrVec*> & nestedList)
	: NestedIntOrVec(false), nested(nestedList)
{	
}

const vector<NestedIntOrVec*> & NestedVec::getList() const {
	return nested;
}

void NestedVec::accept(depthSumVisitor & visitor) const {
	visitor.visit(*this);
}
