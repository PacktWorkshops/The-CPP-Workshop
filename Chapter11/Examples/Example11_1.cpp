int main()
{
    Queue<int> testQueue;
    testQueue.push(1);
    testQueue.push(2);
    cout << "queue contains values: ";
    for (auto it = testQueue.front(); it != testQueue.back() + 1; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "queue contains " << testQueue.size() << " elements" << endl;
    testQueue.pop();
    cout << "queue contains values: ";
    for (auto it = testQueue.front(); it != testQueue.back() + 1; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "queue contains " << testQueue.size() << " elements" << endl;
    testQueue.push(9);
    testQueue.push(50);
    cout << "queue contains values: ";
    for (auto it = testQueue.front(); it != testQueue.back() + 1; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "queue contains " << testQueue.size() << " elements" << endl;
    testQueue.pop();
    cout << "queue contains values: ";
    for (auto it = testQueue.front(); it != testQueue.back() + 1; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Is the Queue empty: " << (testQueue.empty() == 1 ? "YES" : "NO") << endl;
    cout << "value of first element is: " << *testQueue.front() << endl;
    cout << "value of last element is: " << *testQueue.back() << endl;
    return 0;
}

