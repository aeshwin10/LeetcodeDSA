class ProductOfNumbers {
public:
    vector<int> products;
    ProductOfNumbers() {
    
    }
    
    void add(int num) {
        if(num==0){
            products.clear();
        }
        else{
            if(products.empty()){
                products.push_back(num);
            }
            else{
                products.push_back(num*products.back());
            }
        }
    }
    
    int getProduct(int k) {
        int n = products.size();
        if (n == 0 || k > n) return 0;
        if (k == n) return products.back();
        return (products[n-1] / products[n-k-1]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */