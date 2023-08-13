#include<stdio.h>
#include<stdarg.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<random>
#include<assert.h>
#include<stdarg.h>
#ifdef BOJ
#define LOCAL       0
#define DUMP_SCREEN 0
#define DUMP_TOUCH  0
#define TC_GEN      0
#define TC_GEN_TEST 0
#define TC_SUBTASK  4
#else
#define LOCAL       1 // Whether use freopen(sample_input.txt); in local PC
#define DUMP_SCREEN 0 // For debug
#define DUMP_TOUCH  0 // For debug
#define TC_GEN      0 // 1 : generate tc. 0 : read generated tc.
#define TC_GEN_TEST 0 // only works if TC_GEN is 0
#define TC_SUBTASK  1
#endif
using namespace std;
using pii = pair<int, int>;
using lld = long long int;
using lf = double;
const int MAX_H = 50;
const int MAX_W = 50;
const int MAX_Q = 5000;
const int MIN_H = 3;
const int MIN_W = 3;
const int MIN_Q = 3;
const int MAX_POSITION = 100000;
const int MAX_SIZE = 100000;

//
mt19937 rnd;
void setseed(lld z){
	rnd = mt19937(z);
}
int nextint(int s, int t){
	assert(s <= t);
	return (int)(rnd()%(t-s+1))+s;
}
inline void ensuref(bool cond, const char *format, ...) {
    if (!cond) {
		va_list ap;
		va_start(ap, format);
		vprintf(format, ap);
		va_end(ap);
		assert(false);
    }
}
//

int h, w;
int q;

int orig_h, orig_w;
int orig_q;

namespace {
	unordered_set<string> ss;
	void CleanNameSpace(){
		ss.clear();
		ss.insert("Window");
		if(TC_SUBTASK <= 1){
			ss.insert("SCREEN_POSITION");
		}
		if(TC_SUBTASK <= 2){
			ss.insert("Touch");
			ss.insert("SENSITIVE");
		}
		if(TC_SUBTASK <= 3){
			ss.insert("CLIP_CHILD");
		}
	}
	char RandomChar(){
		constexpr static char charlist[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
		constexpr static int charlen = sizeof(charlist) / sizeof(charlist[0]);
		return charlist[nextint(0, charlen - 2)];
	}
	string GetRandomName(){
		string ret;
		do{
			int sl = nextint(1, 20);
			ret.clear();
			for(int i=0;i<sl;i++){
				ret.push_back(RandomChar());
			}
		}while(ss.find(ret) != ss.end());
		ss.insert(ret);
		return ret;
	}
    bool CheckCharRange(char c)
    {
        if(c>='A' && c <='Z')return true;
        if(c>='a' && c <='z')return true;
        if(c >='0' && c<='9') return true;
        if(c=='_')return true;
        return false;
    }
} // namespace

// Data Area

struct vec2
{
	int x, y;
	vec2():x(0),y(0){}
	vec2(int x, int y):x(x),y(y){}
	vec2 operator+(const vec2& z)const{
		return vec2(x + z.x, y + z.y);
	}
	vec2 operator-(const vec2& z)const{
		return vec2(x - z.x, y - z.y);
	}
	vec2 operator*(const vec2& z)const{
		return vec2(x * z.x, y * z.y);
	}
	vec2 friend operator*(const int& z, const vec2& w){
		return vec2(z * w.x, z * w.y);
	}
	vec2 friend operator*(const vec2& w, const int& z){
		return vec2(z * w.x, z * w.y);
	}
	void print(FILE* fp) const{
		fprintf(fp, "%d %d\n",x, y);
	}
};

enum class Property {
	POSITION = 0,
	SIZE,
	COLOR,
	PARENT_ORIGIN,
	ANCHOR_POINT,
	CLIP_CHILD,
	SENSITIVE,

	SCREEN_POSITION,
};
enum class ValueType
{
	INT = 0,
	VEC2 = 1,
	STRING = 2,
};
struct Value {
	ValueType type;
	int retInt;
	vec2 retVec2;
	string retString;
	
	void print(FILE* fp)const{
		switch(type)
		{
			case ValueType::INT:{ fprintf(fp, "%d\n", retInt); break;}
			case ValueType::VEC2:{ retVec2.print(fp); break;}
			case ValueType::STRING:{ fprintf(fp, "%s\n", retString.c_str()); break;}
		}
	}
};

struct QueryResult
{
	void SetValue(const int& z)
	{
		valid = true;
		ret.type = ValueType::INT;
		ret.retInt = z;
	}
	void SetValue(const vec2& z)
	{
		valid = true;
		ret.type = ValueType::VEC2;
		ret.retVec2 = z;
	}
	void SetValue(const string& z)
	{
		valid = true;
		ret.type = ValueType::STRING;
		ret.retString = z;
	}
	void print(FILE* fp)const{
		if(valid){
			ret.print(fp);
		}
	}
	bool valid{false};
	Value ret;
};

struct Actor
{
	string name;

	int parent;
	int id;
	vector<int> children;

	int clip_child;
	int sensitive;
	int color;

	vec2 position;
	vec2 size;
	vec2 parent_origin;
	vec2 anchor_point;

	void clear()
	{
		parent = 0;
		children.clear();
		clip_child = 0;
		sensitive = 1;
		color = 1;

		position = vec2();
		size = vec2();
		parent_origin = vec2();
		anchor_point = vec2();
	}

	// API level

	static void New(const string& name);

	void SetProperty(Property index, Value value);
	void GetProperty(Property index, QueryResult& result) const;

	void Add(int cid);
	void Remove(int cid);
	void Unparent();

private:
	vec2 CalculateScreenPosition(int id) const;
	bool IsInside(const vec2& pos, vec2 parentAnchor) const;

public:
	// For touch and render
	static int HitTest(int id, const vec2& pos, const vec2& parentAnchor);
	static int RenderTest(int id, const vec2& pos, const vec2& parentAnchor);
}actor[MAX_Q + 1];
int al;
unordered_map<string, int> reva;

enum class QueryType{
	NEW = 0,
	ADD,
	REMOVE,
	UNPARENT,
	SET_PROPERTY,
	GET_PROPERTY,
	TOUCH
};

struct Query
{
	QueryType type;
	QueryResult result;

	void parse(string line);
	void process();
	void clear()
	{
		result.valid = false;
		actor.clear();
		param.clear();
	}

	string actor;
	string param;
	Property paramProperty;
	Value paramValue;

	void printQuery(FILE* fp);

private:
	void ReadActor(string line, int& i);
	void ReadParam(string line, int& i);
	void ReadInt(string line, int& i);
	void ReadVec2(string line, int& i);
}query[MAX_Q];

// Helper 
namespace {
	void inil()
	{
		int i, j, k;
		reva.clear();

		al = 1;
		Actor::New("Window");
		// Apply window info.
		actor[1].position = vec2();
		actor[1].size = vec2(w, h);
		actor[1].color = 0;

		actor[1].parent_origin = vec2();
		actor[1].anchor_point = vec2();
		actor[1].clip_child = 1;
		actor[1].sensitive = 1;
	}
	string PropertyToString(Property property)
	{
		switch(property){
			case Property::POSITION: return "POSITION";
			case Property::SIZE: return "SIZE";
			case Property::COLOR: return "COLOR";
			case Property::PARENT_ORIGIN: return "PARENT_ORIGIN";
			case Property::ANCHOR_POINT: return "ANCHOR_POINT";
			case Property::CLIP_CHILD: return "CLIP_CHILD";
			case Property::SENSITIVE: return "SENSITIVE";
			case Property::SCREEN_POSITION: return "SCREEN_POSITION";
		}
		{assert(false && "Unknwon get property");}
		return "";
	}
	Property StringToProperty(string param)
	{
		Property paramProperty;
		if(param == "POSITION"){ paramProperty = Property::POSITION;}
		else if(param == "SIZE"){ paramProperty = Property::SIZE;}
		else if(param == "COLOR"){ paramProperty = Property::COLOR;}
		else if(param == "ANCHOR_POINT"){ paramProperty = Property::ANCHOR_POINT;}
		else if(param == "PARENT_ORIGIN"){ paramProperty = Property::PARENT_ORIGIN;}
		else if(param == "CLIP_CHILD"){ paramProperty = Property::CLIP_CHILD;}
		else if(param == "SENSITIVE"){ paramProperty = Property::SENSITIVE;}
		else if(param == "SCREEN_POSITION"){ paramProperty = Property::SCREEN_POSITION;}
		else {
			printf("?? param : %s\n",param.c_str());
			assert(false && "Unknwon get property");
		}
		return paramProperty;
	}

	string QueryToString(QueryType query)
	{
		switch(query){
			case QueryType::NEW: return "New";
			case QueryType::ADD: return "Add";
			case QueryType::REMOVE: return "Remove";
			case QueryType::UNPARENT: return "Unparent";
			case QueryType::SET_PROPERTY: return "SetProperty";
			case QueryType::GET_PROPERTY: return "GetProperty";
			case QueryType::TOUCH: return "Touch";
		}
		assert(false && " Unknown command");
		return "";
	}
	QueryType StringToQuery(string cmd)
	{
		QueryType type;		
		if(cmd == "New"){type = QueryType::NEW;}
		else if(cmd == "Add"){type = QueryType::ADD;}
		else if(cmd == "Remove"){type = QueryType::REMOVE;}
		else if(cmd == "Unparent"){type = QueryType::UNPARENT;}
		else if(cmd == "SetProperty"){type = QueryType::SET_PROPERTY;}
		else if(cmd == "GetProperty"){type = QueryType::GET_PROPERTY;}
		else if(cmd == "Touch"){type = QueryType::TOUCH;}
		else{
			assert(false && " Unknown command");
		}
		return type;
	}
	
	struct ScreenBuffer
	{
		void SwapBuffer()
		{
			bufferIndex ^= 1;
		}
		int bufferIndex{0u};

		int a[2][MAX_H + 2][MAX_W + 2];

		void Dump(int root, int (*func)(int id, const vec2 &pos, const vec2& screenPosition))
		{
			for(int i=0; i<h; i++){
				for(int j=0; j<w; j++){
					a[bufferIndex][i][j] = func(1, vec2(j, i), vec2(0, 0));
				}
			}
		}
	}screenBuffer, touchBuffer;
}

// API level

void Actor::New(const string& name)
{
	actor[al].clear();
	actor[al].id = al;
	actor[al].name = name;

    ensuref(reva.count(name) == 0, "Duplicate name!");
    if(TC_SUBTASK <= 1)
	{
		ensuref(name != "SCREEN_POSITION", "asdf");
	}
    if(TC_SUBTASK <= 2)
	{
		ensuref(name != "Touch", "asdf");
		ensuref(name != "SENSITIVE", "asdf");
	}
    if(TC_SUBTASK <= 3)
	{
		ensuref(name != "CLIP_CHILD", "asdf");
	}
	reva[name] = al;

	al++;
}

void Actor::SetProperty(Property index, Value value)
{
	switch(index)
	{
        case Property::POSITION:        {ensuref(value.type == ValueType::VEC2, "position sould use vec2");position = value.retVec2; break;}
		case Property::SIZE:            {ensuref(value.type == ValueType::VEC2, "size sould use vec2");size = value.retVec2; break;}
		case Property::COLOR:           {ensuref(value.type == ValueType::INT, "color sould use int");color = value.retInt; break;}
		case Property::PARENT_ORIGIN:   {ensuref(value.type == ValueType::VEC2, "parent_origin sould use vec2");parent_origin = value.retVec2; break;}
		case Property::ANCHOR_POINT:    {ensuref(value.type == ValueType::VEC2, "anchor_point sould use vec2");anchor_point = value.retVec2; break;}
		case Property::CLIP_CHILD:      {
            if(TC_SUBTASK <= 3)break;ensuref(value.type == ValueType::INT, "clip_child sould use int");clip_child = value.retInt; break;}
		case Property::SENSITIVE:       {
            if(TC_SUBTASK <= 2)break;ensuref(value.type == ValueType::INT, "sensitive sould use int");sensitive = value.retInt; break;}
		case Property::SCREEN_POSITION: {ensuref(false, "Screen Position is  read-only"); break;}
	}
}

void Actor::GetProperty(Property index, QueryResult& result) const
{
	switch(index)
	{
		case Property::POSITION:        {result.SetValue(position); break;}
		case Property::SIZE:            {result.SetValue(size); break;}
		case Property::COLOR:           {result.SetValue(color); break;}
		case Property::PARENT_ORIGIN:   {result.SetValue(parent_origin); break;}
		case Property::ANCHOR_POINT:    {result.SetValue(anchor_point); break;}
		case Property::CLIP_CHILD:      {
			if(TC_SUBTASK <= 3){result.SetValue(0);break;}
			result.SetValue(clip_child); break;}
		case Property::SENSITIVE:       {
            if(TC_SUBTASK <= 2){result.SetValue(1);break;}
			result.SetValue(sensitive); break;}
		case Property::SCREEN_POSITION:
		{
            if(TC_SUBTASK <= 1){result.SetValue(vec2(0, 0));break;}
			vec2 ret = vec2();
			ret = CalculateScreenPosition(id);
			result.SetValue(ret);
			break;
		}
	}
}

void Actor::Add(int cid)
{
	int i, j, k;
	if(actor[cid].parent != 0){
		actor[cid].Unparent();
	}
	children.push_back(cid);
	actor[cid].parent = id;
}

void Actor::Remove(int cid)
{
	int i, j, k;
	for(i=0;i<children.size();i++){
		if(children[i] == cid)
		{
			actor[cid].parent = 0;
			for(j=i+1;j<children.size();j++){
				children[j-1] = children[j];
			}
			children.pop_back();
			break;
		}
	}
}

void Actor::Unparent()
{
	if(parent != 0){
		actor[parent].Remove(id);
		parent = 0;
	}
}

// private API

vec2 Actor::CalculateScreenPosition(int me) const
{
	vec2 ret;

	vector<int> p;
	while(me >= 0){
		if(me == 1){
			break;
		}
		if(me == 0){
			return ret;
		}
		p.push_back(me);
		me = actor[me].parent;
	}
	int pe = 1;
	while(!p.empty()){
		me = p.back();
		p.pop_back();
		ret = ret + (actor[me].parent_origin - actor[pe].anchor_point) * actor[pe].size;
		ret = ret + actor[me].position;
		pe = me;
	}

	return ret;
}
bool Actor::IsInside(const vec2& pos, vec2 screenPosition) const
{
	vec2 topLeft = screenPosition - anchor_point * size;
	int xl = topLeft.x;
	int xr = topLeft.x + size.x;
	int yl = topLeft.y;
	int yr = topLeft.y + size.y;
	return xl <= pos.x && pos.x < xr && yl <= pos.y && pos.y < yr;
}

int Actor::HitTest(int id, const vec2 &pos, const vec2& screenPosition)
{
	int ret = 0;
	Actor& me = actor[id];
	if(me.clip_child == 1)
	{
		if(!me.IsInside(pos, screenPosition)){
			return ret;
		}
	}
	if(me.children.size() > 0){
		for(int i=me.children.size() - 1; i>=0; i--)
		{
			Actor& you = actor[me.children[i]];
			vec2 youAnchorPoint = screenPosition + (you.parent_origin - me.anchor_point) * me.size + you.position;
			ret = HitTest(me.children[i], pos, youAnchorPoint);
			if(ret != 0){
				// Hit success
				break;
			}
		}
	}
	if(ret == 0){
		if(me.sensitive && me.IsInside(pos, screenPosition)){
			ret = id;
		}
	}
	return ret;
}

int Actor::RenderTest(int id, const vec2 &pos,  const vec2& screenPosition)
{
	int color = 0;
	Actor& me = actor[id];
	if(me.clip_child == 1)
	{
		if(!me.IsInside(pos, screenPosition)){
			return color;
		}
	}
	if(me.children.size() > 0){
		for(int i=me.children.size() - 1; i>=0; i--)
		{
			Actor& you = actor[me.children[i]];
			vec2 youAnchorPoint = screenPosition + (you.parent_origin - me.anchor_point) * me.size + you.position;
			color = RenderTest(me.children[i], pos, youAnchorPoint);
			if(color != 0){
				// Render success
				break;
			}
		}
	}
	if(color == 0){
		if(me.IsInside(pos, screenPosition)){
			color = me.color;
		}
	}
	return color;
}

////

void Query::parse(string line)
{
	clear();
	int i, j, k;
	string cmd;
	if(line.back() == '\n')line.pop_back();
	int sl = line.size();
    i=0;
	for(;i<sl;i++){
		if(line[i] == ' ')break;
        ensuref(CheckCharRange(line[i]), "ASDF");
		cmd.push_back(line[i]);
	}
	type = StringToQuery(cmd);
	switch(type){
		case QueryType::NEW:
		{
			ReadActor(line, i);
			break;
		}
		case QueryType::ADD:
		{
			ReadActor(line, i);
			ReadParam(line, i);
			break;
		}
		case QueryType::REMOVE:
		{
			ReadActor(line, i);
			ReadParam(line, i);
			break;
		}
		case QueryType::UNPARENT:
		{
			ReadActor(line, i);
			break;
		}
		case QueryType::SET_PROPERTY:
		{
			ReadActor(line, i);
			ReadParam(line, i);
			paramProperty = StringToProperty(param);
			switch(paramProperty)
			{
				case Property::POSITION:
				{
					ReadVec2(line, i);
					ensuref(paramValue.retVec2.x >= -MAX_POSITION && paramValue.retVec2.x <= MAX_POSITION, "position x range");
					ensuref(paramValue.retVec2.y >= -MAX_POSITION && paramValue.retVec2.y <= MAX_POSITION, "position y range");
					break;
				}
				case Property::SIZE:
				{
					ReadVec2(line, i);
					ensuref(paramValue.retVec2.x >= 0 && paramValue.retVec2.x <= MAX_SIZE, "size w range");
					ensuref(paramValue.retVec2.y >= 0 && paramValue.retVec2.y <= MAX_SIZE, "size h range");
					break;
				}
				case Property::PARENT_ORIGIN:
				case Property::ANCHOR_POINT:
				{
					ReadVec2(line, i);
					ensuref(paramValue.retVec2.x >= 0 && paramValue.retVec2.x <= 1, "zz");
					ensuref(paramValue.retVec2.y >= 0 && paramValue.retVec2.y <= 1, "ww");
					break;
				}
				case Property::COLOR:
				{
					ReadInt(line, i);
					ensuref(paramValue.retInt >= 1 && paramValue.retInt <= 9, "color range");
					break;
				}
				case Property::CLIP_CHILD:
				case Property::SENSITIVE:
				{
					ReadInt(line, i);
					ensuref(paramValue.retInt >= 0 && paramValue.retInt <= 1, "zz");
					break;
				}
				default:
				{
					assert(false && "SetProperty can't use SCREEN_POSITION");
				}
			}
			param.clear();
			break;
		}
		case QueryType::GET_PROPERTY:
		{
			ReadActor(line, i);
			ReadParam(line, i);
			paramProperty = StringToProperty(param);
			param.clear();
			break;
		}
		case QueryType::TOUCH:
		{
			ReadVec2(line, i);
			break;
		}
	}
    ensuref(i == sl, "Should parse all words");
}

void Query::ReadActor(string line, int& i)
{
	int sl = line.size();
	actor.clear();
    ensuref(line[i] == ' ', "actor not seperate with space");i++;
	for(;i<sl;i++){
		if(line[i] == ' ')break;
        ensuref(CheckCharRange(line[i]), "ASDF");
		actor.push_back(line[i]);
	}
    ensuref(actor.size() > 0, "Must not empty string");
}
void Query::ReadParam(string line, int& i)
{
	int sl = line.size();
	param.clear();
    ensuref(line[i] == ' ', "param not seperate with space");i++;
	for(;i<sl;i++){
		if(line[i] == ' ')break;
        ensuref(CheckCharRange(line[i]), "ASDF");
		param.push_back(line[i]);
	}
    ensuref(param.size() > 0, "Must not empty string");
}
void Query::ReadInt(string line, int& i)
{
	int sl = line.size();
	paramValue.type = ValueType::INT;
	int& paramInt = paramValue.retInt;
	paramInt = 0;
    ensuref(line[i] == ' ', "int not seperate with space");i++;
	bool is_minus = false;
	if(line[i] == '-') {is_minus = true; i++;}
    bool not_zero_length = false;
	for(;i<sl;i++){
		if(line[i] == ' ')break;
        ensuref(CheckCharRange(line[i]), "ASDF");
		paramInt *= 10;
		paramInt += line[i] - '0';
        not_zero_length = true;
	}
    ensuref(not_zero_length, "Number must not be zero length");
	if(is_minus)paramInt = -paramInt;
}
void Query::ReadVec2(string line, int& i)
{
	int sl = line.size();
	paramValue.type = ValueType::VEC2;
	vec2& paramVec2 = paramValue.retVec2;
	paramVec2.x = 0;
    ensuref(line[i] == ' ', "Vec2 X not seperate with space");i++;
	bool is_minus = false;
	if(line[i] == '-') {is_minus = true; i++;}
    bool not_zero_length = false;
	for(;i<sl;i++){
		if(line[i] == ' ')break;
        ensuref(CheckCharRange(line[i]), "ASDF");
		paramVec2.x *= 10;
		paramVec2.x += line[i] - '0';
        not_zero_length = true;
	}
	if(is_minus)paramVec2.x = -paramVec2.x;
    ensuref(not_zero_length, "Number must not be zero length");
	paramVec2.y = 0;
    ensuref(line[i] == ' ', "Vec2 y not seperate with space");i++;
	is_minus = false;
	if(line[i] == '-') {is_minus = true; i++;}
    not_zero_length = false;
	for(;i<sl;i++){
		if(line[i] == ' ')break;
        ensuref(CheckCharRange(line[i]), "ASDF");
		paramVec2.y *= 10;
		paramVec2.y += line[i] - '0';
        not_zero_length = true;
	}
    ensuref(not_zero_length, "Number must not be zero length");
	if(is_minus)paramVec2.y = -paramVec2.y;
}

void Query::process()
{
	switch(type)
	{
		case QueryType::NEW:
		{
			Actor::New(actor);
			break;
		}
		case QueryType::ADD:
		{
            ensuref(reva.count(actor) != 0, "Must use exist actor");
            ensuref(reva.count(param) != 0, "Must use exist actor");
            ensuref(param != "Window", "Window should not be added");
			int id = reva[actor];
            {
                int me = id;
                while(me > 0){
                    ensuref(me != reva[param], "Cannot add your acient");
                    me = ::actor[me].parent;
                }
            }
			::actor[id].Add(reva[param]);
			break;
		}
		case QueryType::REMOVE:
		{
            ensuref(reva.count(actor) != 0, "Must use exist actor");
            ensuref(reva.count(param) != 0, "Must use exist actor");
            ensuref(param != "Window", "Window should not be removed");
			int id = reva[actor];
            ensuref(id != reva[param], "don't need to remove itselft");
			::actor[id].Remove(reva[param]);
			break;
		}
		case QueryType::UNPARENT:
		{
            ensuref(reva.count(actor) != 0, "Must use exist actor");
            ensuref(actor != "Window", "Window should not be unparent");
			int id = reva[actor];
			::actor[id].Unparent();
			break;
		}
		case QueryType::SET_PROPERTY:
		{
            ensuref(reva.count(actor) != 0, "Must use exist actor");
            ensuref(actor != "Window", "Window should not call setproperty");
			int id = reva[actor];
			::actor[id].SetProperty(paramProperty, paramValue);
			break;
		}
		case QueryType::GET_PROPERTY:
		{
            ensuref(reva.count(actor) != 0, "Must use exist actor");
            ensuref(actor != "Window", "Window should not call getproperty");
			int id = reva[actor];
			::actor[id].GetProperty(paramProperty, result);
			break;
		}
		case QueryType::TOUCH:
		{
            if(TC_SUBTASK <= 2)break;
            ensuref(paramValue.type == ValueType::VEC2, "type match");
            ensuref(paramValue.retVec2.x >= 0 && paramValue.retVec2.x < w, "value range match");
            ensuref(paramValue.retVec2.y >= 0 && paramValue.retVec2.y < h, "value range match");
			int actorId = Actor::HitTest(1, paramValue.retVec2, vec2(0, 0));
            ensuref(actorId >= 1 && actorId < al, "Must touch some actor");
			result.SetValue(::actor[actorId].name);
			break;
		}
	}
	{
	#if DUMP_SCREEN || DUMP_TOUCH
		printQuery(stdout);
		static int frameCount = 0;
	#if DUMP_SCREEN
		screenBuffer.SwapBuffer();
		screenBuffer.Dump(1, Actor::RenderTest);
		printf("[Screen] after process %d\n", frameCount);
		{
			int bufferIndex = screenBuffer.bufferIndex;
			for(int i=0;i<h;i++){
				for(int j=0;j<w;j++){
					printf("%d",screenBuffer.a[bufferIndex][i][j]);
				}
				printf("\n");
			}
		}
	#endif
	#if DUMP_TOUCH
		touchBuffer.SwapBuffer();
		touchBuffer.Dump(1, Actor::HitTest);
		printf("[Touch] after process %d\n", frameCount);
		{
			int bufferIndex = touchBuffer.bufferIndex;
			for(int i=0;i<h;i++){
				for(int j=0;j<w;j++){
					printf("%4d ",touchBuffer.a[bufferIndex][i][j]);
				}
				printf("\n");
			}
		}
	#endif
		frameCount++;
	#endif
	}
}

void Query::printQuery(FILE *fp)
{
	fprintf(fp,"%s ",QueryToString(type).c_str());
	switch(type){
		case QueryType::NEW:
		case QueryType::UNPARENT:
		{
			fprintf(fp, "%s\n",actor.c_str());
			break;
		}
		case QueryType::ADD:
		case QueryType::REMOVE:
		{
			fprintf(fp, "%s %s\n",actor.c_str(), param.c_str());
			break;
		}
		case QueryType::SET_PROPERTY:
		{
			fprintf(fp, "%s %s ",actor.c_str(), PropertyToString(paramProperty).c_str());
			paramValue.print(fp);
			break;
		}
		case QueryType::GET_PROPERTY:
		{
			fprintf(fp, "%s %s\n",actor.c_str(), PropertyToString(paramProperty).c_str());
			break;
		}
		case QueryType::TOUCH:
		{
			paramValue.print(fp);
		}
	}
}

// INPUT AREA

void input_stdin()
{
	int i, j, k;
	scanf("%d %d",&orig_w,&orig_h);
	scanf("%d",&orig_q);
	
	char line[1009];
	for(i=0;i<orig_q;i++)
	{
		assert(fgets(line, 1008, stdin));
		if(line[0] == 10){i--;continue;}
		query[i].parse(line);
	}
}
void input_file(int subtask, int tv)
{
	int i, j, k;
	char filename[199];
	sprintf(filename, "input/subtask%d-%03d.in", subtask, tv);
	FILE *fp = fopen(filename, "rt");
	if(fp == NULL){
		printf("No such file %s\n",filename);
		return;
	}
	auto read_check = [&fp](int& res, char eow){
		char c;
		fscanf(fp,"%d%c",&res,&c);
		if(eow != c){
			printf("Validate fail!\n");
			assert(false);
		}
	};
	

	read_check(orig_w, 32);
	read_check(orig_h, 10);
	read_check(orig_q, 10);

	char line[1009];
	for(i=0;i<orig_q;i++)
	{
		assert(fgets(line, 1008, fp));
		query[i].parse(line);
	}

	{
		char c;
		if(fscanf(fp,"%c",&c) == 1){
			printf("c : %d %c\n",c, c);
			printf("Validate file! not finished with EOF!\n");
			assert(false);
		}
	}

	fclose(fp);
}
void print_input_file(int subtask, int tv)
{
	char filename[199];
	sprintf(filename, "input/subtask%d-%03d.in", subtask, tv);
	FILE *fp = fopen(filename, "wb");

	fprintf(fp,"%d %d%c", orig_w, orig_h, 10);
	fprintf(fp,"%d%c", orig_q, 10);
	
	int i, j, k;
	for(i=0;i<orig_q;i++){
		query[i].printQuery(fp);
	}
	fclose(fp);
}

void copy_origin_data(){
	h = orig_h;
	w = orig_w;
	q = orig_q;
}

namespace VALIDATE{
void validate_input(){
	copy_origin_data();
	auto check_assert = [](bool as, const char* msg){
		if(!as){
			printf("Validate fail! %s\n",msg);
			assert(false);
		}
	};
	check_assert((1 <= w && w <= MAX_W) , "W range check failed");
	check_assert((1 <= h && h <= MAX_H) , "H range check failed");
	check_assert((1 <= q && q <= MAX_Q) , "Q range check failed");
}
} // namespace VALIDATE

void input(int tv){
	input_stdin();
	copy_origin_data();
}

// OUTPUT AREA

void print_file(int subtask, int tv)
{
	char filename[199];
	sprintf(filename, "output/subtask%d-%03d.out", subtask, tv);
	FILE *fp = fopen(filename, "wb");

	int i, j, k;
	for(i=0;i<q;i++){
		query[i].result.print(fp);
	}
	int bufferIndex = screenBuffer.bufferIndex;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			fprintf(fp, "%d",screenBuffer.a[bufferIndex][i][j]);
		}
		fprintf(fp, "\n");
	}

	fclose(fp);
}
void output_file(int subtask, int tv)
{
	char filename[199];
	sprintf(filename, "output/subtask%d-%03d.out", subtask, tv);
	FILE *fp = fopen(filename, "rb");

	int i, j, k;
	char eow;
	char word[1009];
	for(i=0;i<q;i++){
		if(query[i].result.valid)
		{
			switch(query[i].result.ret.type)
			{
				case ValueType::INT:
				{
					int ret;
					fscanf(fp,"%d%c",&ret, &eow);
					assert(ret == query[i].result.ret.retInt);
					assert(eow == 10);
					break;
				}
				case ValueType::VEC2:
				{
					int ret;
					fscanf(fp,"%d%c",&ret, &eow);
					assert(ret == query[i].result.ret.retVec2.x);
					assert(eow == 32);
					fscanf(fp,"%d%c",&ret, &eow);
					assert(ret == query[i].result.ret.retVec2.y);
					assert(eow == 10);
					break;
				}
				case ValueType::STRING:
				{

					fscanf(fp,"%s%c",word, &eow);
					assert(word == query[i].result.ret.retString);
					assert(eow == 10);
					break;
				}
			}
		}
	}
	int bufferIndex = screenBuffer.bufferIndex;
	for(i=0;i<h;i++){
		fscanf(fp,"%s%c",word, &eow);
		assert(eow == 10);
		for(j=0;j<w;j++){
			assert(word[j] == screenBuffer.a[bufferIndex][i][j] + '0');
		}
	}

	fclose(fp);
}
void output_stdout(){
	int i, j, k;
	for(i=0;i<q;i++){
		query[i].result.print(stdout);
	}
	int bufferIndex = screenBuffer.bufferIndex;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			printf("%d",screenBuffer.a[bufferIndex][i][j]);
		}
		printf("\n");
	}
}

void output(int tv){
#if TC_GEN
	print_file(TC_SUBTASK, tv);
#else
#if TC_GEN_TEST
	output_file(TC_SUBTASK, tv);
#else
	output_stdout();
#endif
#endif
}
namespace SOL_MAIN
{

void process()
{
	int i, j, k;
	inil();

	for(int i=0; i<q; i++){
		query[i].process();
	}
	screenBuffer.SwapBuffer();
	screenBuffer.Dump(1, Actor::RenderTest);
}
} // namespace SOL_MAIN

int main()
{
	int t = 1, tv = 0;
	int i, j, k, l;

#if LOCAL
	freopen("sample_input.txt","rt",stdin);
	freopen("sample_output.txt","wt",stdout);
#endif
	while(t--){
		input(tv);
		SOL_MAIN::process();
		output(tv);
	}

}