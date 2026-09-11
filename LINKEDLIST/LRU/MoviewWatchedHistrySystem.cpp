#include <bits/stdc++.h>
using namespace std;


// ============================================================
// Node
// ============================================================
// Each node represents one movie.
//
// key  -> movieId
// val  -> movie title
//
// prev -> previous movie
// next -> next movie
// ============================================================

class Node {
public:

    int key;
    string val;

    Node* prev;
    Node* next;


    // Constructor
    Node(int k, string v) {

        key = k;
        val = v;

        prev = NULL;
        next = NULL;
    }
};


// ============================================================
// Movie Watch History
// ============================================================

class MovieWatchHistory {

private:

    // --------------------------------------------------------
    // HashMap
    // movieId -> address of Node
    //
    // Allows us to find a movie in O(1) average time.
    // --------------------------------------------------------

    unordered_map<int, Node*> mpp;


    // Dummy head and tail
    Node* head;
    Node* tail;


public:

    // ========================================================
    // Constructor
    // ========================================================

    MovieWatchHistory() {

        head = new Node(-1, "");
        tail = new Node(-1, "");

        // Connect dummy nodes
        head->next = tail;
        tail->prev = head;
    }


    // ========================================================
    // deleteNode()
    // ========================================================
    // Removes a node from the linked list.
    //
    // IMPORTANT:
    // We don't delete the node from memory here because
    // WATCH may remove a node and insert the SAME node again.
    // ========================================================

    void deleteNode(Node* node) {

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }


    // ========================================================
    // insert()
    // ========================================================
    // Insert a node immediately after HEAD.
    //
    // Therefore, it becomes the MOST RECENTLY WATCHED movie.
    // ========================================================

    void insert(Node* node) {

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }


    // ========================================================
    // WATCH
    // ========================================================
    // WATCH movieId title
    //
    // If movie already exists:
    //      1. Update title
    //      2. Remove from current position
    //      3. Move it to front
    //
    // If movie doesn't exist:
    //      Create a new node and insert at front.
    // ========================================================

    void watch(int movieId, string title) {

        // Movie already exists
        if (mpp.find(movieId) != mpp.end()) {

            Node* movie = mpp[movieId];

            // Update title
            movie->val = title;

            // Move movie to front
            deleteNode(movie);
            insert(movie);

            return;
        }


        // Movie doesn't exist
        Node* newNode = new Node(movieId, title);

        // Add to HashMap
        mpp[movieId] = newNode;

        // Add to front
        insert(newNode);
    }


    // ========================================================
    // REMOVE
    // ========================================================
    // Remove a movie from watch history.
    // ========================================================

    void removeMovie(int movieId) {

        // Movie doesn't exist
        if (mpp.find(movieId) == mpp.end()) {
            return;
        }


        // Get node
        Node* movie = mpp[movieId];


        // Remove from linked list
        deleteNode(movie);


        // Remove from HashMap
        mpp.erase(movieId);


        // Free memory
        delete movie;
    }


    // ========================================================
    // SEARCH
    // ========================================================
    // Search for a movie.
    //
    // IMPORTANT:
    // SEARCH does NOT change the movie's position.
    // ========================================================

    void searchMovie(int movieId) {

        // Movie doesn't exist
        if (mpp.find(movieId) == mpp.end()) {

            cout << "NOT_FOUND" << endl;
            return;
        }


        // Get movie node
        Node* movie = mpp[movieId];


        // Print title
        cout << movie->val << endl;
    }


    // ========================================================
    // RECENT
    // ========================================================
    // Display movies from:
    //
    // Most Recently Watched
    //          ↓
    // Least Recently Watched
    // ========================================================

    void recent() {

        Node* curr = head->next;


        // No movies
        if (curr == tail) {

            cout << "EMPTY" << endl;
            return;
        }


        // Traverse from front to back
        while (curr != tail) {

            cout << curr->key;

            if (curr->next != tail) {
                cout << " ";
            }

            curr = curr->next;
        }


        cout << endl;
    }


    // ========================================================
    // CLEAR
    // ========================================================
    // Remove all movies from history.
    // ========================================================

    void clearHistory() {

        Node* curr = head->next;


        while (curr != tail) {

            Node* nextNode = curr->next;

            delete curr;

            curr = nextNode;
        }


        // Reconnect head and tail
        head->next = tail;
        tail->prev = head;


        // Clear HashMap
        mpp.clear();
    }
};


// ============================================================
// MAIN
// ============================================================

int main() {

    int N;

    // Number of operations
    cin >> N;


    MovieWatchHistory obj;


    while (N--) {

        string command;

        cin >> command;


        // ----------------------------------------------------
        // WATCH movieId title
        // ----------------------------------------------------

        if (command == "WATCH") {

            int movieId;
            string title;

            cin >> movieId >> title;

            obj.watch(movieId, title);
        }


        // ----------------------------------------------------
        // REMOVE movieId
        // ----------------------------------------------------

        else if (command == "REMOVE") {

            int movieId;

            cin >> movieId;

            obj.removeMovie(movieId);
        }


        // ----------------------------------------------------
        // SEARCH movieId
        // ----------------------------------------------------

        else if (command == "SEARCH") {

            int movieId;

            cin >> movieId;

            obj.searchMovie(movieId);
        }


        // ----------------------------------------------------
        // RECENT
        // ----------------------------------------------------

        else if (command == "RECENT") {

            obj.recent();
        }


        // ----------------------------------------------------
        // CLEAR
        // ----------------------------------------------------

        else if (command == "CLEAR") {

            obj.clearHistory();
        }
    }


    return 0;
}