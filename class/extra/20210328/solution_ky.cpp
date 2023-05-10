#include "main.cpp"
typedef long long ll;
typedef unsigned long long ull;

ll A[2501];
ll B[2501];
ll sum[2501];
ll sub[2501];
ull ret[5010];
ull carry = 1 << 30;

char rev_ret[33000];

inline ll atol(char v)
{
    if (v <= '9') return v - '0';
    else return v - 'A' + 10;
}

inline char ltoa(int v)
{
    if (v < 10) return v + '0';
    else return v + 'A' - 10;
}
inline bool check_a_bigger(char *a, char *b)
{
    register int i = 0;
    while (1)
    {
        if (a[i] > b[i]) return true;
        else if (a[i] < b[i]) return false;
        ++i;
    }
    return true;
}

void init()
{
    register int i;
    for (i = 0; i < 2501; ++i)A[i] = B[i] = sum[i] = sub[i] = 0;
    for (i = 0; i < 5010; ++i)ret[i] = 0;
    for (i = 0; i < 33000; ++i)rev_ret[i] = 0;
}
void set_big_number(char *a, ll *comp_a)
{
    register int i;
    int base, target;
    for (i = 2499; i >= 0; --i)
    {
        base = i * 6;
        target = 2499 - i;
        comp_a[target] = (atol(a[base]) << 25) + (atol(a[base + 1]) << 20) + (atol(a[base + 2]) << 15) + (atol(a[base + 3]) << 10) + (atol(a[base + 4]) << 5) + atol(a[base + 5]);
        sum[target] = comp_a[target];
        sub[target] = comp_a[target];
    }
}

void set_small_number(char *b, ll *comp_b)
{
    register int i, j, base, target;
    base = 14994;
    for (i = 2499; i >= 0 ; --i)
    {
        target = 2499 - i;
        comp_b[target] = (atol(b[base]) << 25) + (atol(b[base + 1]) << 20) + (atol(b[base + 2]) << 15) + (atol(b[base + 3]) << 10) + (atol(b[base + 4]) << 5) + atol(b[base + 5]);
        sum[target] += comp_b[target];
        sub[target] -= comp_b[target];
        base -= 6;
    }

    for (i = 0; i < 2500; ++i)
    {
        sum[i + 1] += sum[i] >> 30;
        sum[i] = sum[i] & 0x3fffffff;

        if (sub[i] < 0) {
            sub[i] += carry;
            sub[i + 1] -= 1;
        }
    }
}

void mul()
{
    register int i, j;
    for (i = 0; i < 2501; ++i)
    {
        for (j = 0; j < 2500; ++j)
        {
            ret[i + j] += sum[i] * sub[j];
        }
        if (i % 15 == 14)
        {
            for (j = 0; j < 2500; ++j)
            {
                ret[i + j + 1] += ret[i + j] >> 30;
                ret[i + j] &= 0x3fffffff;
            }
        }
    }

    for (i = 0; i < 5000; ++i)
    {
        ret[i + 1] += ret[i] >> 30;
        ret[i] &= 0x3fffffff;
    }
}

void answer(char* result)
{
    register int i, j;
    int base;
    for (i = 0; i <= 5000; ++i)
    {
        base = i * 6;
        for (j = 0; j < 6; ++j)
        {
            rev_ret[base + j] = ltoa(ret[i] & 0x1f);
            ret[i] = ret[i] >> 5;
        }
    }

    register int lastIdx = 30001;
    while (rev_ret[lastIdx] == '\0' || rev_ret[lastIdx] == '0') lastIdx--;

    for (i = 0; i <= lastIdx; ++i)
    {
        result[i] = rev_ret[lastIdx - i];
    }
    result[lastIdx + 1] = '\0';
}
void solution(char* result, char *a, char *b)
{
    init();
    if (check_a_bigger(a, b))
    {
        set_big_number(a, A);
        set_small_number(b, B);
    }
    else
    {
        set_big_number(b, B);
        set_small_number(a, A);
    }
    mul();
    answer(result);
}
