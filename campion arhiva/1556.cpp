#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define LGMAX 12000
using namespace std;

const int base = 1000000000;
const int base_digits = 9;
struct bigint {
	vector<int> a;
	int sign;
	/*<arpa>*/
	int size(){
		if(a.empty())return 0;
		int ans=(a.size()-1)*base_digits;
		int ca=a.back();
		while(ca)
			ans++,ca/=10;
		return ans;
	}
	/*</arpa>*/
	bigint() :
		sign(1) {
	}

	bigint(long long v) {
		*this = v;
	}

	bigint(const string &s) {
		read(s);
	}

	void operator=(const bigint &v) {
		sign = v.sign;
		a = v.a;
	}

	void operator=(long long v) {
		sign = 1;
		a.clear();
		if (v < 0)
			sign = -1, v = -v;
		for (; v > 0; v = v / base)
			a.push_back(v % base);
	}

	bigint operator*(int v) const {
		bigint res = *this;
		res *= v;
		return res;
	}

	void operator*=(long long v) {
		if (v < 0)
			sign = -sign, v = -v;
		for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
			if (i == (int) a.size())
				a.push_back(0);
			long long cur = a[i] * (long long) v + carry;
			carry = (int) (cur / base);
			a[i] = (int) (cur % base);
			//asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
		}
		trim();
	}

	bigint operator*(long long v) const {
		bigint res = *this;
		res *= v;
		return res;
	}

	void operator*=(const bigint &v) {
		*this = *this * v;
	}
	void trim() {
		while (!a.empty() && !a.back())
			a.pop_back();
		if (a.empty())
			sign = 1;
	}

	bool isZero() const {
		return a.empty() || (a.size() == 1 && !a[0]);
	}

	void read(const string &s) {
		sign = 1;
		a.clear();
		int pos = 0;
		while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
			if (s[pos] == '-')
				sign = -sign;
			++pos;
		}
		for (int i = s.size() - 1; i >= pos; i -= base_digits) {
			int x = 0;
			for (int j = max(pos, i - base_digits + 1); j <= i; j++)
				x = x * 10 + s[j] - '0';
			a.push_back(x);
		}
		trim();
	}

	friend istream& operator>>(istream &stream, bigint &v) {
		string s;
		stream >> s;
		v.read(s);
		return stream;
	}

	friend ostream& operator<<(ostream &stream, const bigint &v) {
		if (v.sign == -1)
			stream << '-';
		stream << (v.a.empty() ? 0 : v.a.back());
		for (int i = (int) v.a.size() - 2; i >= 0; --i)
			stream << setw(base_digits) << setfill('0') << v.a[i];
		return stream;
	}

	static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
		vector<long long> p(max(old_digits, new_digits) + 1);
		p[0] = 1;
		for (int i = 1; i < (int) p.size(); i++)
			p[i] = p[i - 1] * 10;
		vector<int> res;
		long long cur = 0;
		int cur_digits = 0;
		for (int i = 0; i < (int) a.size(); i++) {
			cur += a[i] * p[cur_digits];
			cur_digits += old_digits;
			while (cur_digits >= new_digits) {
				res.push_back(int(cur % p[new_digits]));
				cur /= p[new_digits];
				cur_digits -= new_digits;
			}
		}
		res.push_back((int) cur);
		while (!res.empty() && !res.back())
			res.pop_back();
		return res;
	}

	typedef vector<long long> vll;

	static vll karatsubaMultiply(const vll &a, const vll &b) {
		int n = a.size();
		vll res(n + n);
		if (n <= 32) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					res[i + j] += a[i] * b[j];
			return res;
		}

		int k = n >> 1;
		vll a1(a.begin(), a.begin() + k);
		vll a2(a.begin() + k, a.end());
		vll b1(b.begin(), b.begin() + k);
		vll b2(b.begin() + k, b.end());

		vll a1b1 = karatsubaMultiply(a1, b1);
		vll a2b2 = karatsubaMultiply(a2, b2);

		for (int i = 0; i < k; i++)
			a2[i] += a1[i];
		for (int i = 0; i < k; i++)
			b2[i] += b1[i];

		vll r = karatsubaMultiply(a2, b2);
		for (int i = 0; i < (int) a1b1.size(); i++)
			r[i] -= a1b1[i];
		for (int i = 0; i < (int) a2b2.size(); i++)
			r[i] -= a2b2[i];

		for (int i = 0; i < (int) r.size(); i++)
			res[i + k] += r[i];
		for (int i = 0; i < (int) a1b1.size(); i++)
			res[i] += a1b1[i];
		for (int i = 0; i < (int) a2b2.size(); i++)
			res[i + n] += a2b2[i];
		return res;
	}

	bigint operator*(const bigint &v) const {
		vector<int> a6 = convert_base(this->a, base_digits, 6);
		vector<int> b6 = convert_base(v.a, base_digits, 6);
		vll a(a6.begin(), a6.end());
		vll b(b6.begin(), b6.end());
		while (a.size() < b.size())
			a.push_back(0);
		while (b.size() < a.size())
			b.push_back(0);
		while (a.size() & (a.size() - 1))
			a.push_back(0), b.push_back(0);
		vll c = karatsubaMultiply(a, b);
		bigint res;
		res.sign = sign * v.sign;
		for (int i = 0, carry = 0; i < (int) c.size(); i++) {
			long long cur = c[i] + carry;
			res.a.push_back((int) (cur % 1000000));
			carry = (int) (cur / 1000000);
		}
		res.a = convert_base(res.a, 6, base_digits);
		res.trim();
		return res;
	}
};

bigint unu(1);
bigint logPow(bigint a, int pw){
    if (!pw){
        return unu;
    }
    if (pw&1){
        return a*logPow(a*a,pw>>1);
    }
    return logPow(a*a,pw>>1);
}

int main()
{
    freopen("subsets.in","r",stdin);
    freopen("subsets.out","w",stdout);
    int n;
    scanf("%d",&n);
    bigint doi(2);
    bigint ans = logPow(doi,n-1);
    ans *= (long long)n;
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
7 apr 2017, 10:31
80 puncte

#include <fstream>
#define LMAX 30000

using namespace std;
ifstream fin("subsets.in");
ofstream fout("subsets.out");

typedef short int NrMare[LMAX];
NrMare a, b, c;
int lga, lgb, lgc;
int n;

void prod(NrMare a, int lga, int x, NrMare b, int& lgb);
void afisare(NrMare a,int lga);
void pune0 (NrMare x, int lgx);
void produs (NrMare a, int lga, NrMare b, int lgb, NrMare c, int &lgc);
void copiez(NrMare a,int lga, NrMare b,int& lgb);

int main()
{
int i;
int p;
fin>>n;
if (n<=1000){
a[0]=1;
lga=1;
for (i=1;i<n;i++)
     {prod(a,lga,2,a,lga);}
prod(a,lga,n,a,lga);
afisare(a,lga);}
 else {
  p=1;
  a[0]=2;
  lga=1;
  while (p+p<=n)
     {
      p=p+p;
      produs(a,lga,a,lga,b,lgb);
      copiez(b,lgb,a,lga);
     }
  for (;p<=n;p++)
     prod(a,lga,2,a,lga);
  afisare(a,lga);
 }
fin.close();
fout.close();
return 0;
}

void copiez(NrMare a,int lga, NrMare b,int& lgb)
    {
      int i;
     lgb=lga;
     for (i=0;i<lga;i++)
        b[i]=a[i];
    }

void prod (NrMare a, int lga, int b, NrMare c, int &lgc)
{
    int i, t=0, v;
    for (i=0;i<lga;i++)
    {
        v=a[i]*b+t;
        c[i]=v%10;
        t=v/10;
    }
    lgc=lga;
    while (t!=0)
    {
        c[lgc++]=t%10;
        t=t/10;
    }
}

void afisare(NrMare a,int lga)
    {
     int i;
     for (i=lga-1;i>=0;i--)
         fout<<a[i];
     fout<<'\n';
    }

void produs (NrMare a, int lga, NrMare b, int lgb, NrMare c, int &lgc)
{
    int i, j, t=0, v;
    pune0 (c, 0);
    for (i=0;i<lga;i++)
        for (j=0;j<lgb;j++)
            c[i+j]=c[i+j]+a[i]*b[j];
    //transform in cifre
    for (i=t=0; i<lga+lgb-1 || t; i++)
    {
        v=c[i]+t;
        c[i]=v%10;
        t=v/10;
    }
    lgc=i;
}


void pune0 (NrMare x, int lgx)
{
    int i;
    for (i=lgx; i<LMAX; i++)
        x[i]=0;
}
*/
