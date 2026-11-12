class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        deque<int> students_q(students.begin(),students.end());
        deque<int> sandwiches_stack(sandwiches.begin(),sandwiches.end());
        int diff = 0;

        int s = students_q.size();

        while(!students_q.empty() and diff != s){
            if (students_q.front() == sandwiches_stack.front()){
                students_q.pop_front();
                sandwiches_stack.pop_front();
                s--;
                diff = 0;
            } else{
                // int el = students_q.front();
                students_q.push_back(students_q.front());
                students_q.pop_front();
                diff++;
            }
        }
        return diff;
    }
};