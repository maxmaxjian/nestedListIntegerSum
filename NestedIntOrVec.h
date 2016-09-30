/*
 * NestedIntOrVec.h
 *
 *  Created on: Sep 30, 2016
 *      Author: jianwei
 */

#ifndef NESTEDINTORVEC_H_
#define NESTEDINTORVEC_H_

#include <vector>
class depthSumVisitor;

using std::vector;

class NestedIntOrVec {
public:
	NestedIntOrVec(bool isInteger);
	virtual ~NestedIntOrVec();
	
	bool isInteger() const;
	virtual void accept(depthSumVisitor & visitor) const = 0;
	
private:
	bool isInt;
};

class NestedInt : public NestedIntOrVec {
public:
	NestedInt(int a_int);
	
	int getInteger() const;
	
	virtual void accept(depthSumVisitor & visitor) const;
	
private:
	int myInt;
};

class NestedVec : public NestedIntOrVec {
public:
	NestedVec(const vector<NestedIntOrVec*> & nestedList);
	
	const vector<NestedIntOrVec*> & getList() const;
	
	virtual void accept(depthSumVisitor & visitor) const;
	
private:
	vector<NestedIntOrVec*> nested;
};

#endif /* NESTEDINTORVEC_H_ */
