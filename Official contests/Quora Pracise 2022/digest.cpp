//				بِسْمِ اللَّـهِ الرَّحْمَـٰنِ الرَّحِيمِ

#include <bits/stdc++.h>
using namespace std;

#define all(v) begin(v), end(v)
#define lol                                \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0);
#define PREC(n) cout << fixed << setprecision(n);
#define eps 1E-10
#define sz(v) int(sizeof(v) / sizeof(v[0]))
#define pi 2 * acos(0.0)
#define inf 1.797E308
#define elapsed cerr << "\n"                                      \
                     << float(clock()) / CLOCKS_PER_SEC << " sec" \
                     << "\n\n"
#define ll long long
#define vi vector<int>
#define qi queue<int>
#define pii pair<int, int>
#define ss second
#define ff first

const int MAX = 207;
int N, M;

bool follow_user[MAX][MAX];  // follow_user[follower][followed]
bool follow_story[MAX][MAX]; // follow_story[user][story]
int score[MAX][MAX];         // score[user][story]

map<int, int> create; // first(story) created by second(user)

vector<int> get_followed_stories(int user)
{
    vector<int> stories;
    for (int i = 0; i < MAX; ++i)
    {
        if (follow_story[user][i])
            stories.push_back(i);
    }
    return stories;
}

int a(int i, int j)
{
    int value = 0;
    if (i == j)
        return 0;
    if (follow_user[i][j])
        return 3;

    vector<int> followed_stories = get_followed_stories(i);
    for (int story : followed_stories)
    {
        if (create[story] == j)
            return 2;
    }

    // if they have a common followed story
    for (int story = 1; story < MAX; ++story)
    {
        if (follow_story[i][story] && follow_story[j][story])
            return 1;
    }

    return 0;
}

int b(int j, int k)
{
    if (create[k] == j)
        return 2;
    if (follow_story[j][k])
        return 1;
    else
        return 0;
}

int get_score(int i, int k)
{
    int sum = 0;
    for (int j = 1; j <= M; ++j)
    {
        sum += a(i, j) * b(j, k);
    }
    return sum;
}


int main()
{
    int i, j, k;
    cin >> N >> M;
    for (int k = 1; k <= N; ++k)
    {
        cin >> j; // user j created story k
        create[k] = j;
    }
    int p, q;
    cin >> p >> q;

    while (p--)
    {
        cin >> i >> j;
        follow_user[i][j] = true;
    }

    while (q--)
    {
        cin >> i >> k;
        follow_story[i][k] = true;
    }

    for (int user = 1; user <= M; ++user)
    {
        for (int story = 1; story <= N; ++story)
        {
            if (create[story] == user or follow_story[user][story])
                score[user][story] = -1;
            else
            {
                score[user][story] = get_score(user, story);
            }
        }
    }

    for (int user = 1; user <= M; ++user)
    {
        vector<pair<int, int>> stories_score; // score, story_number
        for (int story = 1; story < N; ++story)
        {
            stories_score.push_back({score[user][story], story});
        }
        stable_sort(all(stories_score), [](const auto &s1, const auto &s2)
                    { return s1.ff > s2.ff; });
        cout << stories_score[0].ss << ' ' << stories_score[1].ss << ' '
             << stories_score[2].ss << '\n';
    }

    elapsed;
    return 0;
}
