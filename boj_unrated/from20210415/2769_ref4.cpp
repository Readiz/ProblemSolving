#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
using namespace std;

class Formula
{
public:
	virtual bool evaluate(map<char, bool> vmap) = 0;
	virtual string to_string() = 0;
};

class Variable : public Formula
{
public:	
	Variable(char v)
	{
		this->v = v;
	}
	char v;
	
	virtual bool evaluate(map<char, bool> vmap)
	{
		return vmap[v];
	}
	
	virtual string to_string()
	{
		return "Var("+string(1,v)+")";
	}
};

class Or : public Formula
{
public:	
	Or(Formula *sub1, Formula *sub2)
	{
		this->sub1 = sub1;
		this->sub2 = sub2;
	}
	Formula *sub1, *sub2;
	
	virtual bool evaluate(map<char, bool> vmap)
	{
		return sub1->evaluate(vmap) || sub2->evaluate(vmap);
	}
	
	virtual string to_string()
	{
		return "Or("+sub1->to_string()+","+sub2->to_string()+")";
	}
};

class And : public Formula
{
public:	
	And(Formula *sub1, Formula *sub2)
	{
		this->sub1 = sub1;
		this->sub2 = sub2;
	}
	Formula *sub1, *sub2;
	
	virtual bool evaluate(map<char, bool> vmap)
	{
		return sub1->evaluate(vmap) && sub2->evaluate(vmap);
	}
	
	virtual string to_string()
	{
		return "And("+sub1->to_string()+","+sub2->to_string()+")";
	}
};

class Xor : public Formula
{
public:	
	Xor(Formula *sub1, Formula *sub2)
	{
		this->sub1 = sub1;
		this->sub2 = sub2;
	}
	Formula *sub1, *sub2;
	
	virtual bool evaluate(map<char, bool> vmap)
	{
		bool p = sub1->evaluate(vmap);
		bool q = sub2->evaluate(vmap);
		return (p && !q) || (!p && q);
	}
	
	virtual string to_string()
	{
		return "Xor("+sub1->to_string()+","+sub2->to_string()+")";
	}
};

class Not : public Formula
{
public:	
	Not(Formula *sub)
	{
		this->sub = sub;
	}
	Formula *sub;
	
	virtual bool evaluate(map<char, bool> vmap)
	{
		return !sub->evaluate(vmap);
	}
	
	virtual string to_string()
	{
		return "Not("+sub->to_string()+")";
	}
};

bool is_regular(string s)
{
	if(s=="") return false;
	if(s.length() == 1) return 'a' <= s[0] && s[0] <= 'z';
	
	int len = s.length();
	
	for(int i = 0; i < len; i++)
	{
		if(s[i] == '|' || s[i] == '&' || s[i] == '^')
		{
			if(is_regular(s.substr(0,i)) && is_regular(s.substr(i+1))) return true;
		}
	}
	
	if(s[0] == '~') return is_regular(s.substr(1));
	
	if(s[0] == '(' && s[len-1] == ')') return is_regular(s.substr(1,len-2));
	
	return false;
}

Formula* str2for(string s)
{
	if(s.length() == 1)
	{
		return new Variable(s[0]);
	}
	
	int len = s.length();
	for(int i = 0; i < len; i++)
	{
		if(s[i] == '|')
		{
			string s1 = s.substr(0, i);
			string s2 = s.substr(i+1);
			if(is_regular(s1) && is_regular(s2)) return new Or(str2for(s1), str2for(s2));
		}
	}
	
	for(int i = 0; i < len; i++)
	{
		if(s[i] == '^')
		{
			string s1 = s.substr(0, i);
			string s2 = s.substr(i+1);
			if(is_regular(s1) && is_regular(s2)) return new Xor(str2for(s1), str2for(s2));
		}
	}
	
	for(int i = 0; i < len; i++)
	{
		if(s[i] == '&')
		{
			string s1 = s.substr(0, i);
			string s2 = s.substr(i+1);
			if(is_regular(s1) && is_regular(s2)) return new And(str2for(s1), str2for(s2));
		}
	}
	
	if(s[0] == '~') return new Not(str2for(s.substr(1)));
			
	return str2for(s.substr(1,len-2));
}

string clean(string s)
{
	vector<char> v;
	int len = s.length();
	for(int i = 0; i < len; i++)
	{
		char c = s[i];
		if(('a'<=c&&c<='z') || c=='|' || c=='&' || c=='^' || c=='~' || c == '(' || c == ')') v.push_back(c);
	}
	return string(v.begin(), v.end());
}

bool is_equivalent(Formula *f1, Formula *f2, vector<char> vvec)
{
	int size = vvec.size();
	for(int i = 0; i < (1<<size); i++)
	{
		map<char, bool> vmap;
		for(int j = 0; j < size; j++)
		{
			vmap[vvec[j]] = (i >> j) % 2;
			//cout << vvec[j] << ' ' << (i >> j) % 2 << endl;
		}
		//cout << f1->evaluate(vmap) << ' ' << f2->evaluate(vmap) << endl << endl;
		if(f1->evaluate(vmap) != f2->evaluate(vmap)) return false;
	}
	
	return true;
}


int main()
{
	//cout << is_regular("~(~a");
	//return 0;
	
	int T;
	cin >> T;
	getchar();
	for(int t = 1; t <= T; t++)
	{
		string s;
		getline(cin, s);
		s = clean(s);
		
		set<char> vset;
		int len = s.length();
		for(int i = 0; i < len; i++)
		{
			if('a' <= s[i] && s[i] <= 'z') vset.insert(s[i]);
		}
		
		vector<char> vvec(vset.begin(), vset.end());
		
		Formula *f1, *f2;
		
		for(int i = 0; i < len; i++)
		{
			string s1 = s.substr(0,i+1);
			string s2 = s.substr(i+1);
			if(is_regular(s1) && is_regular(s2))
			{
				//cout << s1 << " // " << s2 << endl;
				f1 = str2for(s1);
				f2 = str2for(s2);
				//cout << f1->to_string() << " // " << f2->to_string() << endl;
				break;
			}
		}
		bool equiv = is_equivalent(f1, f2, vvec);
		cout << "Data set " << t << ": " << (equiv ? "Equivalent" : "Different") << endl;
	}
}

