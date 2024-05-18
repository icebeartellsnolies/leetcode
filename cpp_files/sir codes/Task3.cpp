#include <iostream>
#include <vector>

using namespace std;

int main(){
	string s = "Joe Root and Harry Brook have just batted on and on and on for England. It's basically just been a matter of counting \
				 the records they tick off. From 492-3 overnight England have progressed to 658-3. They now lead by 102. Root, who was\
				 dropped this morning on 186, now has his highest Test score. Brook does too. It's the first time he has scored 200 in\
				 a Test. The Yorkshire pair are now closing on England's all-time highest partnership in Tests. The record is held by\
				 Colin Cowdrey and Peter May, who put on 411 against West Indies in 1957 and Brook and Root's partnership is worth 408.";
	vector<int> count(26);
	for (char c : s){
		c = c | 32;	//covert all characters into small alphabets
		if (c >= 'a' && c <= 'z')
			count[c - 'a']++;
	}
	for (int i = 0 ; i < count.size() ; i++)
		// i+'a' gives ascii of the alphabet. (char) converts it to letter 
		cout << (char)(i + 'a') << ':' << count[i] << '\n';
    return 0;
}

