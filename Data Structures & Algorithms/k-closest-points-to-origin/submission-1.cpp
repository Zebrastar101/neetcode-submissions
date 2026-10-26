class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> min_heap;
        
        for( int i=0; i< points.size();i++){
            min_heap.push_back(points[i]);
            sort_heap(min_heap);
        }
        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            res.push_back(min_heap[0]);
            pop_heap(min_heap);
        }
        return res;
    }
    double dist(vector<int> point){
        return sqrt(pow(point[1],2)+pow(point[0],2));
    }
    void sort_heap(vector<vector<int>>& min_heap){
        int index= min_heap.size()-1;
        while(index>0){
            double child_dist= dist(min_heap[index]);
            double parent_dist= dist(min_heap[(index-1)/2]);
            if(child_dist>=parent_dist){
                break;
            }
            swap(min_heap[index],min_heap[(index-1)/2]);
            index=(index-1)/2;
        }
    }
    void pop_heap(vector<vector<int>>& min_heap) {
        min_heap[0] = min_heap.back();
        min_heap.pop_back();

        int index = 0;
        int n = min_heap.size();

        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < n &&
                dist(min_heap[left]) < dist(min_heap[smallest])) {
                smallest = left;
            }

            if (right < n &&
                dist(min_heap[right]) < dist(min_heap[smallest])) {
                smallest = right;
            }

            if (smallest == index) {
                break;
            }

            swap(min_heap[index], min_heap[smallest]);
            index = smallest;
        }
    }

};
