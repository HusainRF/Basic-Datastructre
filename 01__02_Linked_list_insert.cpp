#include<bits/stdc++.h>

using namespace std;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

bool comp(int a, int b)
{
    return (a < b);
}
// #define int long long
class node{
public:
	int data;
	node *next;
};
void insert_in_begning(node* &head_ref,int x)
{
	node *new_node=new node();
	new_node->data=x;
	new_node->next=head_ref;
	head_ref=new_node;
}

void insert_in_end(node *head_ref,int x)
{ 
	node*new_node=new node();
	node *temp=head_ref;
	new_node->next=NULL;
	new_node->data=x;
	if(head_ref==NULL)
	{
		head_ref=new_node;
		return;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new_node;
	return;

}
 void print_list(node *temp)
{
	while(temp!=NULL)
	{
	cout<<" "<<temp->data;
		temp=temp->next;
	}
}
void insert_after(node *temp,int x)
{
	node *new_node=new node;
    new_node->next=NULL;
    new_node->data=x;
   if(temp==NULL)
   {
   	cout<<"node can not be null";
   	 return;
   }
    new_node->next=temp->next;
    temp->next=new_node;
    return;
}
void solve(){
    // int n;
    // cin>>n;
    node *head=NULL;
    
  insert_in_begning(head,3+2);
  insert_in_end(head,3);
  insert_in_end(head,3+3);
  insert_after(head->next,7);
    print_list(head);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif // ONLINE_JUDGE

    // int t;
    // cin >> t;
    // while(t--){
     solve();
    //  cout<<endl;
    // }
    return 0;
}

