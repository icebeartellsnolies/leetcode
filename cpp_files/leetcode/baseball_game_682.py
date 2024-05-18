
        stack <int> st;
        for(string i:operations){
            if (i == "C"){
                st.pop();
                
            }
            else if (i=="+"){
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                int sum = val1+val2;
                st.push(val2);
                st.push(sum);
            }
            else if (i=="D"){
                int new_record = 2* st.top();
                st.push(new_record);
            }
            else{
                st.push(stoi(i));
            }
        }
        int sum = 0;
        for (int i=0;i<st.size(); i++){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};