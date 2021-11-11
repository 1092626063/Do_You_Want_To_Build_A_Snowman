#include <iostream>
#include <queue>
 
using namespace std;
 
int main(){
    priority_queue<int, vector<int>, greater<int> > q;
    
    for( int i= 0; i< 10; ++i ) q.push( rand() );
    while( !q.empty() ){
        cout << q.top() << endl;
        q.pop();
    }
    
    return 0;
}