/*
 * depthSumVisitor.h
 *
 *  Created on: Sep 30, 2016
 *      Author: jianwei
 */

#ifndef DEPTHSUMVISITOR_H_
#define DEPTHSUMVISITOR_H_

class NestedInt;
class NestedVec;

class depthSumVisitor {
public:
	depthSumVisitor(int a_depth);
	virtual ~depthSumVisitor();
	
	void visit(const NestedInt & nestedInt);
	void visit(const NestedVec & nestedVec);
	
	int getSum() const;
	
private:
	int sum;
	int depth;
};

#endif /* DEPTHSUMVISITOR_H_ */
