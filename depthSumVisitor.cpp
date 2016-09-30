/*
 * depthSumVisitor.cpp
 *
 *  Created on: Sep 30, 2016
 *      Author: jianwei
 */

#include "depthSumVisitor.h"
#include "NestedIntOrVec.h"

depthSumVisitor::depthSumVisitor(int a_depth)
	: depth(a_depth), sum(0)
{
	// TODO Auto-generated constructor stub
}

depthSumVisitor::~depthSumVisitor() {
	// TODO Auto-generated destructor stub
}

void depthSumVisitor::visit(const NestedInt& nestedInt) {
	sum += depth * nestedInt.getInteger();
}

void depthSumVisitor::visit(const NestedVec & nestedVec) {
	for (auto elm : nestedVec.getList()) {
		depthSumVisitor vtor(depth+1);
		elm->accept(vtor);
		sum += vtor.getSum();
	}
}

int depthSumVisitor::getSum() const {
	return sum;
}
