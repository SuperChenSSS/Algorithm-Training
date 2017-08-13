#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

namespace fastIO {
	#define BUF_SIZE 100000
	// fread -> read
	FILE *fin;
	bool IOerror = 0;
	inline char nc() {
		static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
		if(p1 == pend) {
			p1 = buf;
			pend = buf + fread(buf, 1, BUF_SIZE, fin);
			if(pend == p1) {
				IOerror = 1;
				return -1;
			}
		}
		return *p1++;
	}
	inline bool blank(char ch) {
		return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
	}
	template<class T> inline void read(T& x) {
		char ch;
		while(blank(ch = nc()));
		if(!IOerror)
			for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = (x << 3) + (x << 1) + (ch - '0'));
	}
	// fwrite -> write
	struct Ostream_fwrite {
		char *buf, *p1, *pend;
		Ostream_fwrite() {
			buf = new char[BUF_SIZE];
			p1 = buf;
			pend = buf + BUF_SIZE;
		}
		void out(char ch) {
			if (p1 == pend) {
				fwrite(buf, 1, BUF_SIZE, stdout);
				p1 = buf;
			}
			*p1++ = ch;
		}
		void print(char *s) {
			for( ; *s; out(*s++));
		}
		void flush() {
			if(p1 != buf) {
				fwrite(buf, 1, p1 - buf, stdout);
				p1 = buf;
			}
		}
		~Ostream_fwrite() {
			flush();
		}
	} Ostream;
	inline void print(char ch) {
		Ostream.out(ch);
	}
	inline void print(char *s) {
		Ostream.print(s);
	}
	inline void print(double x) {
		static char s[15];
		sprintf(s, "%.10f", x);
		Ostream.print(s);
	}
	#undef BUF_SIZE
}

const int maxm = 19, pr[maxm] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
const int maxe = 80, maxs = 172513;
const __int128_t maxn = (__int128_t)1e24;
struct HashTable {
	int Counter;
	std::map<__int128_t, int> Index;
	HashTable() : Counter(0), Index(std::map<__int128_t, int>()) {
		newID(1);
	}
	bool count(__int128_t const& key) const {
		return Index.count(key);
	}
	int getID(__int128_t const& key) const {
		return Index.at(key);
	}
	int newID(__int128_t const& key) {
		return Index[key] = Counter++;
	}
} Hash;
struct FactExp {
	__int128_t value; // minimum represent
	int size, exp[maxm];
	int parse(__int128_t val, int sz, int p[]) { // parse and calculate
		int sigma = 1;
		for(size = 0; size < sz; ++size) {
			for(exp[size] = 0; val % p[size] == 0; ++exp[size], val /= p[size]);
			sigma *= exp[size] + 1;
		}
		exp[size] = 0;
		std::sort(exp, exp + size, std::greater<int>());
		for(value = 1; sz--; )
			for(int i = 0; i < exp[sz]; ++i, value *= pr[sz]);
		return sigma;
	}
} cur;
typedef double DB; // be careful, standard code use long double as DB instead.
DB f[maxs], g[maxs][maxm];
int dfs(int sigma) { // dfs(cur)
	if(Hash.count(cur.value))
		return Hash.getID(cur.value);
	int cID = Hash.newID(cur.value), pID;
	DB sum = 0;
	for(int i = 0, k = cur.size, j = k - 1; i < cur.size; ++i, --j) {
		if(cur.exp[j] != cur.exp[k]) {
			k = j;
			int nxt = sigma - sigma / (cur.exp[k] + 1);
			cur.value /= pr[k];
			if(!(--cur.exp[k]))
				--cur.size;
			pID = dfs(nxt); // different part
			if(!(cur.exp[k]++))
				++cur.size;
			cur.value *= pr[k];
		}
		int o = i - (cur.exp[k] == 1);
		g[cID][i] = (sum += o < 0 ? f[pID] : g[pID][o]);
	}
	f[cID] = (sigma + sum) / (sigma - 1);
	for(int i = 0; i < cur.size; ++i)
		g[cID][i] += f[cID];
	return cID;
}
int main(int argc, char *argv[]) {
	const int BUFSIZE = 1 << 10;
	using namespace fastIO;
	fin = fopen(argv[1], "r");
	static char buf[BUFSIZE | 1], tmp[BUFSIZE | 1], prefix[BUFSIZE | 1];
	__int128_t n;
	int m, p[maxm];
	for(int Case = 1; read(n), read(m), !IOerror; ++Case) {
		for(int i = 0; i < m; ++i)
			read(p[i]);
		int plen = sprintf(prefix, "Case #%d: ", Case);
		double std_ans = (double)f[dfs(cur.parse(n, m, p))], user_ans;
		if(fgets(buf, BUFSIZE, stdin) != NULL
		&& !strncmp(buf, prefix, plen)
		&& sscanf(buf + plen, "%s", tmp) == 1
		&& sscanf(tmp, "%lf", &user_ans) == 1
		&& !std::isnan(user_ans)
		&& (fabs(std_ans - user_ans) <= 1e-9
		|| fabs((std_ans - user_ans) / std_ans) <= 1e-9)) {
			int len = strlen(tmp);
			tmp[len] = '\n';
			tmp[len + 1] = '\0';
			char endl = strcmp(buf + plen, tmp) == 0 ? '\n' : '\t';
			print(prefix);
			print(std_ans);
			print(endl);
		} else {
			print(prefix);
			strcpy(tmp, "WA\n");
			print(tmp);
			return 0;
		}
	}
	fclose(fin);
	if(fgets(buf, BUFSIZE, stdin) != NULL)
		print('\t');
	return 0;
}
