

class Solution {
  public:
    // Helper function: check if we can allocate with maxPages = mid
    bool isPossible(vector<int>& arr, int k, int mid) {
        int studentCount = 1;  // start with first student
        int pages = 0;

        for (int pagesInBook : arr) {
            if (pages + pagesInBook > mid) {
                studentCount++;
                pages = pagesInBook; // assign this book to new student
                if (studentCount > k) return false;
            } else {
                pages += pagesInBook;
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1;  // more students than books

        int low = *max_element(arr.begin(), arr.end()); // at least one book
        int high = accumulate(arr.begin(), arr.end(), 0); // all books to one
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid)) {
                result = mid;       // valid allocation found
                high = mid - 1;     // try for smaller max
            } else {
                low = mid + 1;      // increase max limit
            }
        }
        return result;
    }
};
