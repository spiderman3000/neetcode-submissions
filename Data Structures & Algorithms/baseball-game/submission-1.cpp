class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string>  st;
        for(int i=0;i<operations.size();i++){
            string curr = operations[i];
            if(curr == "+"){
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();
                // cout << a << " " << b << endl;
                int answer = stoi(a)+stoi(b);
                st.push(b);
                st.push(a);
                st.push(to_string(answer));
            } else if (curr == "D"){
                string t = st.top();
                st.push(to_string(stoi(t)*2));
            } else if (curr == "C"){
                st.pop();
            } else {
                st.push(curr);
            }
            // cout << st.top() << endl;
        }

        int res = 0;
        while(!st.empty()){
            res += stoi(st.top());
            st.pop();
        }
        return res;
    }
};

// 5 , -2, -4, 9, 5, 14