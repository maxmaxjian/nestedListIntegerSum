#include "NestedIntOrVec.h"
#include "depthSumVisitor.h"
#include <vector>
#include <iostream>

using std::vector;

class solution {
  public:
    int depthSum(const vector<NestedIntOrVec*> & nested) {
        int sum = 0, depth = 1;
        for (auto & elm : nested) {
        	depthSumVisitor a_visitor(depth);
        	elm->accept(a_visitor);
        	sum += a_visitor.getSum();
        }
        
        return sum;
    }
};

int main() {
	vector<NestedIntOrVec*> nested;
//	nested.push_back(new NestedVec(vector<NestedIntOrVec*>{new NestedInt(1), new NestedInt(1)}));
//	nested.push_back(new NestedInt(2));
//	nested.push_back(new NestedVec(vector<NestedIntOrVec*>{new NestedInt(1), new NestedInt(1)}));
	
	nested.push_back(new NestedInt(1));
	nested.push_back(new NestedVec(vector<NestedIntOrVec*>{new NestedInt(4), new NestedVec(vector<NestedIntOrVec*>{new NestedInt(6)})}));
	
	solution soln;
	int dsum = soln.depthSum(nested);
	
	std::cout << "The depth sum is:" << std::endl;
	std::cout << dsum << std::endl;
}
