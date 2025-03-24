class MyCalendarTwo {
public:
    map<int,int> mp;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        int bookings = 0;
        for(auto [key, val] : mp){
            bookings+=val;
            if(bookings==3){
                //count--;
                mp[startTime]--;
                mp[endTime]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */