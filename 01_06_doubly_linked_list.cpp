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
class doubly_list{
public:
	doubly_list *prev;
	int data;
	doubly_list* next;
};
doubly_list* insert_in_end(doubly_list* head,int elem)
{
	
	doubly_list* new_node=new doubly_list;
	new_node->data=elem;
	new_node->next=NULL;
	new_node->prev=NULL;
    if(head==NULL){
		head=new_node;
		return head;
    }
	doubly_list* curr=head;
	if(head!=NULL)
	{
		while(curr->next!=NULL)
		{debug(curr->data);
			curr=curr->next;
		}

		debug(curr->data);
		curr->next=new_node;
		new_node->prev=curr;
		debug(curr->data);
		return head;
	}
}

doubly_list *insertion_in_list(doubly_list *head,int n){
	doubly_list* temp=head;

	while(n--)
	{ int elem;
	  cin>>elem;
	  debug(elem);
     head=insert_in_end(head, elem);
	}
	return head;
}

doubly_list *insertion_in_begin(doubly_list *head,int elem){
 doubly_list* new_node=new doubly_list;
  new_node->next=NULL;
  new_node->prev=NULL;
   new_node->data=elem;
   if(head==NULL){
		head=new_node;
		return head;
  }
  else{
  	new_node->next=head;
  	head->prev=new_node;
  	head=new_node;
  	return head;
  }


}

void display_list(doubly_list *head){
	while(head!=NULL)
	{
		cout<<head->data<<" <=> ";
		head=head->next;
	}cout<<"NULL"<<endl;
}

// #define int long long
void solve(){
    doubly_list *head=NULL;
    head= insertion_in_list(head,5);
    display_list(head);
    head=insertion_in_begin(head, 0);
    display_list(head);
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

