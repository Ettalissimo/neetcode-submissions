class Solution {
public:
    bool isValid(string s) {
        vector<char> mystack = {'0'};

        
        for (char c : s){
            mystack.push_back(c);
            char* ptr = &mystack.back();
            char* ptr_1 = ptr - 1;
            if (*ptr_1 == '{' and *ptr =='}'){
                mystack.pop_back();
                mystack.pop_back();
            } else if (*ptr_1 == '(' and *ptr ==')'){
                mystack.pop_back();
                mystack.pop_back();
            } else if (*ptr_1 == '[' and *ptr ==']'){
                mystack.pop_back();
                mystack.pop_back();
            };
        };
        if (mystack.back() == '0')
            return true;
        return false;

        /*
        stack append all the brackets
        if { or } : append 0
        if [ or ] : append 1
        if ( or ) : append 2
        2 pointeurs last, first
        while last < first:
            if last.value == first.value
                continue
            else: 
                return False
        return True

        thing about grouping by g et droite 
        group by type {} , [] ..
         */
    }
};
