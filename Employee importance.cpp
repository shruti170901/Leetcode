// https://leetcode.com/problems/employee-importance/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
int getImportance(vector<Employee*> employees, int id) {
  unordered_map<int,Employee*> m;
  queue<Employee*> q;
  int sum = 0;
  for(auto &e:employees) m[e->id] = e;
  q.push(m[id]);
  while(!q.empty()){
	Employee *cur = q.front();
	q.pop();
	sum+= cur->importance;
	for(auto &elem: cur->subordinates)  q.push(m[elem]);
  }
  return sum;  
    }
};