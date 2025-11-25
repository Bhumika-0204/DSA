class BrowserHistory {
public:
    stack<string> backStack;
    stack<string> forwardStack;
    string curr;

    BrowserHistory(string homepage) {
        curr = homepage;
    }

    void visit(string url) {
        backStack.push(curr);
        curr = url;

        // clear forward stack
        while (!forwardStack.empty()) 
            forwardStack.pop();
    }

    string back(int steps) {
        while (steps-- > 0 && !backStack.empty()) {
            forwardStack.push(curr);
            curr = backStack.top();
            backStack.pop();
        }
        return curr;
    }

    string forward(int steps) {
        while (steps-- > 0 && !forwardStack.empty()) {
            backStack.push(curr);
            curr = forwardStack.top();
            forwardStack.pop();
        }
        return curr;
    }
};
