class Solution {
    public List<String> generateParenthesis(int n) {
        
        ArrayList<String> res = new ArrayList<String>();
        recurse(res, 0, 0, "", n); 
        return res;         
    }
    static void recurse(List<String> res, int left, int right, String s, int n){
        if (s.length()== n*2){
            res.add(s);
            return;
        }
        if (left<n){
            recurse(res, left+1, right, s+"(",n);
        }
        if (right<left){
            recurse(res, left, right+1, s+")", n);
        }
        //When it reaches the end of the fucntion, it backtracks automatically 
        //without a return. 
    }
}